// Nombre del alumno .....JORGE DEL VALLE
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

const std::vector<int> incF = { -1, -1, 0, 1, 1, 1, 0, -1 };
const std::vector<int> incC = { 0, 1, 1, 1, 0, -1, -1, -1 };

using tmatriz = std::vector <std::vector<int>>;
using tMatriz = std::vector <std::vector<bool>>;
// función que resuelve el problema
void conectados(tmatriz & m, int x, int y,tMatriz & marcas) {
	if (!marcas[x][y] && m[x][y] > 0)marcas[x][y] = true;
	for (int i = 0; i < 8; ++i){
		if (!marcas[x + incF[i]][y + incC[i]] && m[x + incF[i]][y + incC[i]] > 0){
			marcas[x + incF[i]][y + incC[i]] = true;
			conectados(m, x + incF[i], y + incC[i], marcas);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int fil;
	int col;
	std::cin >> fil;
	if (!std::cin)
		return false;
	std::cin >> col;
	tmatriz m(fil+2, std::vector<int>(col+2,0));
	for (int i = 1; i < fil+1; ++i){
		for (int j = 1; j < col+1; ++j){
			std::cin >> m[i][j];
		}
	}
	int x, y;
	std::cin >> x >> y;
	while (x != -1 && y != -1){
		tMatriz marcas(fil + 2, std::vector<bool>(col + 2, false));
		if (m[x + 1][y + 1]>0)conectados(m, x + 1, y + 1, marcas);
		// escribir sol
		int sol = 0;
		for (int i = 1; i < fil+1; ++i){
			for (int j = 1; j < col+1; ++j){
				if(marcas[i][j])sol+=m[i][j];
			}
		}
		std::cout << sol << '\n';
		std::cin >> x >> y;
	}
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