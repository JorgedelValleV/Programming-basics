// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int resolver(int P, int A)
{
	int sol = 0;
	sol = P%A;
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int p1 = 0, p2 = 0, a1 = 0, a2 = 0, sol = 0;
	std::cin >> p1 >> p2 >> a1 >> a2;
    int sol1 = resolver(p1, a1);
	int sol2 = resolver(p2, a2);

    // escribir sol
	if (sol1 != 0 || sol2 != 0) 
	{
		if (sol1 != 0 && sol2 != 0)
		{
			sol = ((p1 / a1) + 1)*((p2 / a2)+1);
			
		}
		if (sol1 == 0)
		{
			sol = (p1 / a1)*((p2 / a2) + 1);
		}
		if (sol2 == 0)
		{
			sol = ((p1 / a1) + 1)*(p2 / a2);
		}
		std::cout << sol << " NECESITA COMPRAR MAQUINA\n";
	}
	else 
	{
		sol = (p1 / a1)*(p2 / a2);
		std::cout << sol << '\n';
	}
    
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