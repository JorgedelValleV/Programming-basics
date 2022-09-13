// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
struct ordenarmenmay {
	bool operator()(int a, int b) {
		return a < b;
	}
};
template <typename T, typename Comp = std::less<T>>
bool buscarBinaria(std::vector<T> const& array, T const& buscado, size_t & pos, Comp ord = Comp()) {
	size_t	ini = 0, fin = array.size(), mitad;
	bool	encontrado = false;
	//	0	<=	ini	<=	fin	<=	N	
	//	array[0..ini)	<	buscado	Y	buscado	<	array[fin..N)
	while (ini	<	fin	&&	!encontrado)	{
		mitad = (ini + fin - 1) / 2;	//	divisiÛn	entera	
		if (ord(buscado, array[mitad]))	fin = mitad;
		else	if (ord(array[mitad], buscado))	ini = mitad + 1;
		else	encontrado = true;
	}
	if (encontrado)	pos = mitad;	//	en	la	posiciÛn	mitad					
	else	pos = ini;		//	No encontrado,	le	corresponde	la	posiciÛn	ini	(=fin)					
	return	encontrado;
}
template <typename T, typename Comp = std::less<T>>
void ordenarInsercion(std::vector<T>	&	array, Comp ord = Comp())	{
	size_t N = array.size();
	//	parte	ordenada	array[0..i),	parte	por	procesar	array[i..N)	
	for (size_t i = 1; i < N; ++i)	{	//	desde	el	segundo	hasta	el	˙ltimo		
		//	parte	ordenada	array[0..i)	
		T	elemento = array[i];		//	elemento	a	insertar		
		size_t j = i;	//	desplazar	los	mayores	de	la	parte	ordenada		
		while (j	>	0 && ord(elemento, array[j - 1]))	{
			array[j] = array[j - 1];
			--j;
		}
		if (j != i)	array[j] = elemento;	//	colocar	en	el hueco		
	}	//	parte ordenada array[0..N)	
}

// funcioÃÅn que resuelve el problema
void resolver(std::vector<int> const & d, std::vector<int> const & dr, std::vector<int>  & dc, std::vector<int> const & a, std::vector<int> const & ar, std::vector<int>  & ac) {
	size_t pos;
	for (size_t i = 0; i < dr.size(); ++i) {
		if (!buscarBinaria(a, dr[i], pos, ordenarmenmay()) && !buscarBinaria(dc, dr[i], pos, ordenarmenmay()))dc.push_back(dr[i]);
	}
	for (size_t i = 0; i < ar.size(); ++i) {
		if (!buscarBinaria(d, ar[i], pos, ordenarmenmay()) && !buscarBinaria(ac, ar[i], pos, ordenarmenmay()))ac.push_back(ar[i]);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÃÅn, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numDavid = 0; int numAna = 0; int numrepDavid = 0; int numrepAna = 0;
	std::cin >> numDavid;
	std::vector<int> dav(numDavid);
	for (size_t i = 0; i < numDavid; ++i) {
		std::cin >> dav[i];
	}
	std::cin >> numrepDavid;
	std::vector<int> repetDav(numrepDavid);
	for (size_t i = 0; i < numrepDavid; ++i) {
		std::cin >> repetDav[i];
	}
	std::cin >> numAna;
	std::vector<int> ana(numAna);
	for (size_t i = 0; i < numAna; ++i) {
		std::cin >> ana[i];
	}
	std::cin >> numrepAna;
	std::vector<int> repetAna(numrepAna);
	for (size_t i = 0; i < numrepAna; ++i) {
		std::cin >> repetAna[i];
	}
	std::vector<int> cambDav;
	std::vector<int> cambAna;
	ordenarInsercion(repetDav, ordenarmenmay());
	ordenarInsercion(repetAna, ordenarmenmay());
	resolver(dav, repetDav, cambDav, ana, repetAna, cambAna);
	// escribir sol
	for (size_t i = 0; i < cambDav.size(); ++i) {
		std::cout << cambDav[i] << ' ';
	}
	std::cout << '\n';
	for (size_t i = 0; i < cambAna.size(); ++i) {
		std::cout << cambAna[i] << ' ';
	}
	std::cout << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}