// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int resolver(int j,int a) 
{
	if (j > a) 
	{
		std::cout << "JORGE " << j << " ANA " << a<<'\n';
	}
	else if (a > j)
	{
		std::cout << "ANA " << a << " JORGE " << j<< '\n';
	}
	else std::cout << "EMPATE " << j<< '\n';
	return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int Jdado1 = 0, Jdado2 = 0, Adado1 = 0, Adado2 = 0, Jor = 0, Ana = 0;
	std::cin >> Jdado1 >> Jdado2 >> Adado1 >> Adado2;
	Jor = Jdado1 + Jdado2;
	Ana = Adado1 + Adado2;
    int sol = resolver(Jor, Ana);
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