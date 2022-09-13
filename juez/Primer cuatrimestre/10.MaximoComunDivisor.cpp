// Nombre del alumno ..... Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>


// funcio?n que resuelve el problema
int resolver(int a, int b)
{
	while (b != 0) {
		int aux = a;
		a = b;
		b = aux % b;
	}
	return a;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	int a = 0, b = 0;
	std::cin >> a >> b;
	if (a == 0 && b == 0)
	{
		return false;
	}

	int sol = resolver(a, b);

	// escribir sol

	std::cout << sol << '\n';

	return true;
}

int main()
{
#ifndef DOMJUDGE
#endif 


	while (resuelveCaso())
		;

#ifndef DOMJUDGE 
	system("PAUSE");
#endif

	return 0;
}
