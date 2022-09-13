// Nombre del alumno .....JORGE
// Usuario del Juez ......DG206

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

const int TM = 3;

struct tObjeto {
std::string nomb;
int cant;
};
struct tLista {
tObjeto * objetos;
int	cont;
int capacidad;
};
struct compNomb {
	bool operator() (tObjeto o1, tObjeto o2) {
		return (o1.nomb < o2.nomb);
	}
};
bool buscar(tLista const& lista, std::string const & code, int & pos) { 
	pos = 0; 
	while (pos < lista.cont	&& lista.objetos[pos].nomb != code)	
		++pos;
	return pos < lista.cont;
}
void iniciar(tLista & l) {
	l.cont = 0;
	l.capacidad = TM;
	l.objetos = new tObjeto[TM];
}
void destruir(tLista & l) {
	delete[] l.objetos;
	l.objetos = nullptr;
	l.cont = 0;
	l.capacidad = 0;
}
void aumentarCapacidad(tLista & l) {
	tObjeto* aux = l.objetos;
	l.objetos = new tObjeto[l.capacidad * 2];
	for (int i = 0; i < l.cont;	++i)
		l.objetos[i] = aux[i];
	delete[] aux;
	l.capacidad = l.capacidad * 2;
}
void insertar(tLista & l, tObjeto const & obj) {
	if (l.cont == l.capacidad)aumentarCapacidad(l);
	l.objetos[l.cont] = obj;
	++l.cont;
}
void resuelveCaso() {
	// leer los datos de la entrada
	char c;
	std::cin >> c;
	tLista lista;
	iniciar(lista);
	while (c != 'F') {
		if (c == 'L') {
			for (int i = 0; i < lista.cont; ++i) {
				std::cout << lista.objetos[i].nomb << ' ' << lista.objetos[i].cant << '\n';
			}
			std::cout << "---\n";
		}
		else if (c == 'A') {
			tObjeto o;
			std::cin >> o.nomb >> o.cant;
			int pos;
			if (buscar(lista, o.nomb, pos))lista.objetos[pos].cant += o.cant;
			else insertar(lista, o);
		}
		else if (c == 'R') {
			int pos;
			tObjeto o;
			std::cin >> o.nomb >> o.cant;
			if (buscar(lista, o.nomb, pos)) {
				lista.objetos[pos].cant -= o.cant;
				if (lista.objetos[pos].cant < 0)lista.objetos[pos].cant = 0;
			}
		}
		std::cin >> c;
	}
	destruir(lista);
}

int main() {
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
std::ifstream in("datos1.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


resuelveCaso();


//Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
std::cin.rdbuf(cinbuf);
system("PAUSE");
#endif

return 0;
}


//#ifdef _DEBUG
//#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
//#define new DBG_NE
//_CrtDumpMemoryLeaks();
//#endif