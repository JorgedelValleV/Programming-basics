// Nombre del alumno .....JORGE DEL VALLE VÁZQUEZ
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
void resuelveCaso() {
	// leer los datos de la entrada

	int ancho = 0, alto = 0, largo = 0, ancho2 = 0, alto2 = 0, largo2 = 0;
	std::cin >> ancho >> largo >> alto >> ancho2 >> largo2 >> alto2;

	int sol1 = resolver(ancho, largo, alto, ancho2, largo2, alto2);
	int sol2 = resolver(ancho, largo, alto, largo2, ancho2, alto2);

	// escribir sol
	if (sol1 > sol2)std::cout << sol1 << " EN PARALELO\n";

	else if (sol1 < sol2)std::cout << sol2 << " EN PERPENDICULAR\n";

	else std::cout << sol1 << " DA IGUAL\n";

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