// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
const int TM = 200;
const int DIM = 50;
using tmatriz = std::vector<std::vector<int>>;
struct tFoto {
	std::string titulo;
	std::string tema;
	tmatriz img;
};
struct tImagenes {
	tFoto *	tVector[TM];	
	int	cont;
};
std::string	aMinusculas(std::string	const&	Palabra) {
	std::string	palabra = Palabra;
	for (size_t i = 0; i < palabra.length(); ++i)
		if ('A' <= palabra[i] && palabra[i] <= 'Z')
			palabra[i] = 'a' + (palabra[i] - 'A');
	return	palabra;
}
bool comptitulo (tFoto * p1, tFoto * p2) {
	return (aMinusculas(p1->titulo) < aMinusculas(p2->titulo));
}
bool comptema(tFoto * p1, tFoto * p2) {
	if (aMinusculas(p1->tema) < aMinusculas(p2->tema) || (aMinusculas(p1->tema) == aMinusculas(p2->tema)) && (aMinusculas(p1->titulo) < aMinusculas(p2->titulo)))
		return true;
	else return false;
}

void	ordenarInserciontema(tImagenes & array) {
	size_t	N = array.cont;
	//	parte	ordenada	array[0..i),	parte	por	procesar	array[i..N)	
	for (size_t i = 1; i < N; ++i) {//	desde	el	segundo	hasta	el	último		
									//	parte	ordenada	array[0..i)			
		tFoto *	elemento = array.tVector[i];		//	elemento	a	insertar	
		size_t	j = i;	//	desplazar	los	mayores	de	la	parte	ordenada	
		while (j > 0 && comptema(elemento, array.tVector[j - 1])) {
			array.tVector[j] = array.tVector[j - 1];
			--j;
		}
		if (j != i)	array.tVector[j] = elemento;	//	colocar	en	el	hueco		
	}	//	parte	ordenada	array[0..N)	
}

void	ordenarInserciontitulo(tImagenes & array) {
	size_t	N = array.cont;
	//	parte	ordenada	array[0..i),	parte	por	procesar	array[i..N)	
	for (size_t i = 1; i < N; ++i) {//	desde	el	segundo	hasta	el	último		
									//	parte	ordenada	array[0..i)			
		tFoto *	elemento = array.tVector[i];		//	elemento	a	insertar	
		size_t	j = i;	//	desplazar	los	mayores	de	la	parte	ordenada	
		while (j > 0 && comptitulo(elemento, array.tVector[j - 1])) {
			array.tVector[j] = array.tVector[j - 1];
			--j;
		}
		if (j != i)	array.tVector[j] = elemento;	//	colocar	en	el	hueco		
	}	//	parte	ordenada	array[0..N)	
}



bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (n == 0)
		return false;
	std::string aux;
	getline(std::cin, aux);

	tImagenes imag1;
	tImagenes imag2;
	imag1.cont = 0;
	imag2.cont = 0;
	for (size_t i = 0; i < n; ++i) {
		imag1.tVector[i] = new tFoto;
		++imag1.cont;
		imag2.tVector[i] = new tFoto;
		++imag2.cont;
	}
	for (size_t j = 0; j < imag1.cont; ++j) {
		getline(std::cin, imag1.tVector[j]->titulo);
		imag2.tVector[j]->titulo = imag1.tVector[j]->titulo;
	}
	for (size_t k = 0; k < imag1.cont; ++k) {
		getline(std::cin, imag1.tVector[k]->tema);
		imag2.tVector[k]->tema = imag1.tVector[k]->tema;
	}
	for (size_t c = 0; c < imag1.cont; ++c) {
		tmatriz imgagen(DIM, std::vector<int>(DIM, 3));
		imag1.tVector[c]->img = imgagen;
		imag2.tVector[c]->img = imgagen;
		for (size_t j = 0; j < DIM; ++j) {
			for (size_t k = 0; k < DIM; ++k) {
				imag1.tVector[c]->img[j][k] = n;
				imag2.tVector[c]->img[j][k] = n;
			}
		}
	}
	ordenarInserciontitulo(imag1);
	ordenarInserciontema(imag2);
	// escribir sol
	for (int i = 0; i < imag1.cont; ++i) {
		std::cout << imag1.tVector[i]->titulo << '\n';
	}
	std::cout << '\n';
	for (int i = 0; i < imag2.cont; ++i) {
		std::cout << imag2.tVector[i]->tema << " - " << imag2.tVector[i]->titulo << '\n';
	}
	for (size_t i = 0; i < imag1.cont; ++i) {
		delete imag1.tVector[i];
	}
	for (size_t i = 0; i < imag2.cont; ++i) {
		delete imag2.tVector[i];
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