// Nombre del alumno .....Jorge del Valle 
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath> 
#include <vector>

// funcion que resuelve el problema
int resolver(int n) {
	std::vector<int> v(10, 0); int num = 0, resto = 0, divisor = 10; int i = 0; int pot = 1;
	while (n>9) {
		resto = n % divisor;
		n /= divisor;
		v[i] = resto;
		++i;
	}
	v[i] = n;
	for (int j = v.size(); j>0; --j) {
		num += v[j - 1] * pot;
		if(num!=0)pot *= 10;
	}
	return num;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n = 0;
	std::cin >> n;
	if (n == 0)
		return false;

	int sol = resolver(n);

	// escribir sol
	std::cout << sol << '\n';
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	//std::ifstream in("datos.txt");
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