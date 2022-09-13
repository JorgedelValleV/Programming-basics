// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<float> const& v, float n, bool & ok) {
	float media = 0;
	float numvalores = 0;
	int tot = 0;
	for (size_t i = 0; v[i]!=0; ++i) {
		media += v[i];
		++numvalores;
	}
	media /= numvalores;
	if (n < media){
		ok = false;
		for (size_t i = 0; v[i] != 0; ++i) {
			if (v[i] < media)tot += 1;
		}
	}
	else {
		for (size_t i = 0; v[i] != 0; ++i) {
			if (v[i] >= media)tot += 1;
		}
	}
	return tot;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bool ok = true;
	float nino = 0;
	std::cin >> nino;
	std::vector<float>	v(100000, 1);
	size_t i = 0;
	while(v[i] != 0) {
		std::cin >> v[i];
		if(v[i]!=0)++i;
	}
	int sol = resolver(v,nino,ok);
	// escribir sol
	if (ok)std::cout << "MAYOR " << sol << '\n';
	else std::cout << "MENOR " << sol << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	//     std::ifstream in("datos1.txt");
	//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//     std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}