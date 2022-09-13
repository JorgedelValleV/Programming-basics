// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz = std::vector <std::vector<int>>;
struct tPos {
	int fila;
	int columna;
};

void leer(tmatriz & matriz) {
	for (int f = 0; f < matriz.size(); ++f)
		for (int c = 0; c < matriz[f].size(); ++c)
			std::cin >> matriz[f][c];
}
bool iguales(tmatriz const & a, tmatriz const & b, tPos ini) {
	bool iguales = true;
	for (int f = 0; f <b.size() && iguales; ++f) {
		for (int c = 0; c < b[f].size() && iguales; ++c) {
			if (b[f][c] != a[f + ini.fila][c + ini.columna])iguales = false;
		}
	}
	return iguales;
}
// funcio?n que resuelve el problema
tPos resolver(tmatriz const & a, tmatriz const & b) {
	bool encontrado = false;
	tPos pos;
	pos.fila = -1;
	for (int f = 0; f <= a.size() - b.size() && !encontrado; ++f) {
		for (int c = 0; c <= a[f].size() - b[0].size() && !encontrado; ++c) {
			pos.fila = f;
			pos.columna = c;
			if (iguales(a, b, pos))encontrado = true;
			else pos.fila = -1;
		}
	}
	return pos;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int f1 = 0; int c1 = 0;
	std::cin >> f1 >> c1;
	tmatriz m1(f1, std::vector<int>(c1));
	leer(m1);
	int f2 = 0; int c2 = 0;
	std::cin >> f2 >> c2;
	tmatriz m2(f2, std::vector<int>(c2));
	leer(m2);
	if (!std::cin)
		return false;

	tPos p = resolver(m1, m2);

	// escribir sol
	if (p.fila == -1)std::cout << "NO\n";
	else {
		std::cout << p.fila << ' ' << p.columna << '\n';
	}

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	//std::ifstream in("datos1.txt");
	//auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}