// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int resolver(int a, int b, int c, int d, int e, int f)
{
	int A = 0, B = 0, C = 0, sol = 0;
	A = a * 100;
	B = b * 100;
	C = c * 100;
	sol = (A / d)*(B / e)*(C / f);
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada

	int an1 = 0, an2 = 0, al1 = 0, al2 = 0, l1 = 0, l2 = 0;
	std::cin >> an1 >> al1 >> l1 >> an2 >> al2 >> l2;
	int sol = resolver(an1, al1, l1, an2, al2, l2);
	// escribir sol
	std::cout << sol << '\n';

}

int main()
{
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