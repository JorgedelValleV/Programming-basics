// Nombre del alumno .....Jorge del Valle 
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
long int resolver(long int n) {
	long int suma = 0, resto = 0, divisor = 10;
	while (n>9){
		resto = n % divisor;
		n /= divisor;
		suma += resto;
	}
	suma += n;
	return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	long int tamConj = 0, num = 0;
	std::cin >> tamConj >> num;
	int sol = resolver(num);
	for (int i = 0; i < tamConj; ++i){
		int numConj = 0;
		std::cin >> numConj;
		long int sol1 = resolver(numConj);
		if (sol1 == sol)std::cout << numConj << ' ';
	}
	std::cout << '\n';
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