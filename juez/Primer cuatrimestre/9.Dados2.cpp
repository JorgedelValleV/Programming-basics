// Miguel Derecho
// DG06


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int resolver(int j, int an, int am) 
{
	if (j > an && j > am)std::cout << "JORGE " << j << '\n'; 
	else if (an > j && an > am)std::cout << "ANA " << an << '\n';
	else if (am > an && am > j)std::cout << "AMIGO " << am << '\n';
	else if (j == an && j == am)std::cout << "EMPATE AMIGO ANA JORGE " << j << '\n';
	else if (j == an && j > am)std::cout << "EMPATE ANA JORGE " << j << '\n';
	else if (an == am && an > j)std::cout << "EMPATE AMIGO ANA " << an << '\n';
	else if (j == am && j > an)std::cout << "EMPATE AMIGO JORGE " << j << '\n';
	else
		return 0;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int jdado1 = 0, jdado2 = 0, andado1 = 0, andado2 = 0, amdado1 = 0, amdado2 = 0, jorge = 0, ana = 0, amigo = 0;
	std::cin >> jdado1 >> jdado2 >> andado1 >> andado2 >> amdado1 >> amdado2;
	jorge = jdado1 + jdado2;
	ana = andado1 + andado2;
	amigo = amdado1 + amdado2;
    int sol = resolver(jorge, ana, amigo);
    // escribir sol
    
    
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