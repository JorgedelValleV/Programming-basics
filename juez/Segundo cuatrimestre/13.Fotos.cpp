// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
const int DIM = 50;
using tmatriz = std::vector<std::vector<int>>;
struct tFoto {
	std::string titulo;
	std::string tema;
	tmatriz img;
};
using tImagenes = std::vector<tFoto>;
std::string	aMinusculas(std::string	const&	Palabra) {
	std::string	palabra = Palabra;	
	for (size_t	i = 0;	i	<	palabra.length();	++i)
		if ('A' <= palabra[i] && palabra[i] <= 'Z')	
			palabra[i] = 'a' + (palabra[i] - 'A');
	return	palabra;
}
struct comptitulo {
	bool operator() (tFoto * p1, tFoto * p2) {
		return (aMinusculas(p1->titulo) < aMinusculas(p2->titulo));
	} 
};
struct comptema {
	bool operator() (tFoto * p1, tFoto * p2) {
		if(aMinusculas(p1->tema) < aMinusculas(p2->tema)|| (aMinusculas(p1->tema) == aMinusculas(p2->tema))&&(aMinusculas(p1->titulo) < aMinusculas(p2->titulo)))
		return true;
		else return false;
	}
};
template	<typename	T, typename	Comp = std::less<T>>
void	ordenarInsercion(std::vector<T>	&	array, Comp	ord = Comp()) {
	size_t	N = array.size();
	//	parte	ordenada	array[0..i),	parte	por	procesar	array[i..N)	
	for (size_t i = 1; i < N; ++i) {//	desde	el	segundo	hasta	el	último		
		//	parte	ordenada	array[0..i)			
		T	elemento = array[i];		//	elemento	a	insertar	
		size_t	j = i;	//	desplazar	los	mayores	de	la	parte	ordenada	
		while (j > 0 && ord(elemento, array[j - 1])) {
			array[j] = array[j - 1];
			--j;
		}
		if (j != i)	array[j] = elemento;	//	colocar	en	el	hueco		
	}	//	parte	ordenada	array[0..N)	
}


bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (n==0)
		return false;
	std::string aux;
	getline(std::cin, aux);
	tImagenes im(n);
	std::vector<tFoto*> vp1(n);
	std::vector<tFoto*> vp2(n);
	for (size_t i = 0; i < n; ++i) {
		getline(std::cin , im[i].titulo);
	}
	for (size_t i = 0; i < n; ++i) {
		getline(std::cin, im[i].tema);
	}
	for (size_t i = 0; i < n; ++i) {
		tmatriz imgagen(DIM, std::vector<int>(DIM, 3));
		im[i].img = imgagen;
		for (size_t j = 0; j < DIM; ++j) {
			for (size_t k = 0; k < DIM; ++k) {
				im[i].img[j][k] = n;
			}
		}
	}
	for (size_t i = 0; i < n; ++i) {
		vp1[i] = &im[i];
	}
	for (size_t i = 0; i < n; ++i) {
		vp2[i] = &im[i];
	}
	ordenarInsercion(vp1, comptitulo());
	ordenarInsercion(vp2, comptema());
	// escribir sol
	for (int i = 0; i < im.size(); ++i) {
		std::cout << vp1[i]->titulo << '\n';
	}
	std::cout << '\n';
	for (int i = 0; i < im.size(); ++i) {
		std::cout << vp2[i]->tema << " - " << vp2[i]->titulo << '\n';
	}
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}