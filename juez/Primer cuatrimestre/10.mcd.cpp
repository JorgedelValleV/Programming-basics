// Nombre del alumno ..... Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>


// funcio?n que resuelve el problema
int resolver(int a,int b)
{
	int mcd = 0, aux = 0, aux1 = 0, aux2 = 0, aux3 = 0;
	while (b > a)
	{
		aux2 = b;
		b = a;
		a = aux2;
	}

	aux = a % b;
	aux1 = b;

	while (aux != 0 )
	{
		aux3 = aux;
		aux = aux1;
		aux1 = aux3;
		aux %= aux1;
	}

	if (a == 0)mcd = b;
	else if (b == 0)mcd = a;
	else mcd = aux1;

	return mcd;
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

	int sol = resolver(a,b);

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