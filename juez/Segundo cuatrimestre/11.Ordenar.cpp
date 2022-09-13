// Jorge del Valle Vazquez
// DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
struct tLugar {
	std::string nombre;
	int puntuacion;
	int distancia;
	int precio;
};
// ordenación por puntuacion
struct OrdPuntuacion {
	bool operator()(tLugar const& a, tLugar const& b) {
		if(a.puntuacion == b.puntuacion && a.nombre<b.nombre)return true;
		else return a.puntuacion > b.puntuacion;
	}
};
//	ordenación	por	distancia
struct OrdDistancia {
	bool operator()(tLugar const& a, tLugar const& b) {
		if (a.distancia == b.distancia && a.nombre<b.nombre)return true;
		else return a.distancia	< b.distancia;
	}
};
//	ordenación	por	precio
struct OrdPrecio{
	bool operator()(tLugar const& a, tLugar const& b) {
		if (a.precio == b.precio && a.nombre<b.nombre)return true;
		else return a.precio	< b.precio;
	}
};

template	<typename	T, typename	Comp = std::less<T>>
void ordenarInsercion(std::vector<T> & array, Comp ord = Comp()) {
	size_t N = array.size();
	//	parte	ordenada	array[0..i),	parte	por	procesar	array[i..N)
	for	(size_t	i =	1; i < N; ++i){	//	desde	el	segundo	hasta	el	último		
		//	parte	ordenada	array[0..i)	
		T elemento = array[i];		//	elemento	a	insertar
		size_t j =	i;	//	desplazar	los	mayores	de	la	parte	ordenada
		while (j > 0 && ord(elemento, array[j - 1])){	
			array[j] = array[j - 1];		
			--j;							
		}							
		if	(j != i) array[j] =	elemento;	//	colocar	en	el	hueco					
	}	//	parte	ordenada	array[0..N)	
}
void mostrar(std::vector<tLugar> const & v) {
	for (int i = 0; i < v.size(); ++i) {
		std::cout << v[i].nombre << ' ';
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (!std::cin)
		return false;
	std::vector<tLugar> v(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i].nombre>>v[i].puntuacion >> v[i].distancia >> v[i].precio;
	}

	// escribir sol
	ordenarInsercion(v, OrdPuntuacion());
	mostrar(v);
	std::cout << '\n';
	ordenarInsercion(v, OrdDistancia());
	mostrar(v);
	std::cout << '\n';
	ordenarInsercion(v, OrdPrecio());
	mostrar(v);
	std::cout << '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}