// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() 
{
    // leer los datos de la entrada
	int num = 0;
	std::cin >> num;
	int a = 0, b = 0, c = 0;
	a = num % 4;
	b = num % 100;
	c = num % 400;
	
    
    // escribir sol
	if (a == 0 && b != 0)std::cout << "Si \n";
	else if (a == 0 && b == 0 && c == 0)std::cout << "Si \n";
	else std::cout << "NO \n";
    
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