// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz = std::vector <std::vector<char>>;
struct tPos {
	int fila;
	int columna;
};

void leer(tmatriz & matriz) {
	for (int f = 0; f < matriz.size(); ++f)
		for (int c = 0; c < matriz[f].size(); ++c)
			std::cin >> matriz[f][c];
}
void mostrar(tmatriz const& matriz) {
	for (int f = 0; f < matriz.size(); ++f) {
		for (int c = 0; c < matriz[f].size(); ++c) {
			std::cout << matriz[f][c] << '	';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}
void transformacion1(tmatriz  & a, tPos p, int tam) {
	//	por	diagonales	recorremos la diagonal principal y despues aquellas que estan por encima
	for (int diag = 0; diag < tam; ++diag)	{
		int cont = diag;//control que nos permite asegurar que no cambiamos valores fuera del tamanyo establecido
		int col = p.columna + cont;//comenzamos en la columna que viene dada por el elemento de la esquina superior izquierda y la diagonal que estamos tratando
		for (int fila = p.fila; fila< a.size()&&  col <a[fila].size()&&cont<tam; ++fila)	{//comprobamos que trabajemos fuera de rango ni hacer mas transformaciones fuera del tamanyo
			a[fila][col] = '*';
			++cont;
			col = p.columna + cont;//movemos la columna por la diagonal, la fila aumenta por el bucle for
		}
	}
}
void transformacion2(tmatriz  & a, tPos p, int tam) {
	//	por	diagonales	recorremos la diagonal principal y despues aquellas que estan por debajo. Es igual a la transformacion 1 pero cambiando fila por columna
	for (int diag = 0; diag < tam; ++diag)	{
		int cont = diag;
		int fila = p.fila + cont;
		for (int col = p.columna; fila < a.size() && col< a[fila].size() && cont<tam; ++col)	{
			a[fila][col] = '*';
			++cont;
			fila = p.fila + cont;
		}
	}
}
void transformacion3(tmatriz  & a, tPos p, int tam) {
	std::vector<char> aux(tam);
	for (int i = 0; i < tam; ++i) {//guardamos la ultima fila en un vector auxiliar
		aux[i] = a[p.fila+tam-1][p.columna + i];
	}
	int contfil = 0;
	for (int f = p.fila + tam - 1; contfil<(tam-1); --f) {//colocamos comenzando en la ultima fila los datos de la anterior
		int contcol = 0;
		for (int c = p.columna ; contcol<tam ; ++c) {
			a[f][c] = a[f-1][c];
			++contcol;
		}
		++contfil;
	}
	for (int i = 0; i < tam; ++i) {//colocamos en la primera fila los datos de la ultima
		a[p.fila][p.columna + i] = aux[i];
	}
}
void transformacion4(tmatriz  & a, tPos p, int tam) {
	std::vector<char> aux(tam);
	for (int i = 0; i < tam; ++i) {//guardamos la ultama fila en un vector auxiliar
		aux[i] = a[p.fila+i][p.columna + tam - 1];
	}
	int contcol = 0;
	for (int c = p.columna + tam - 1; contcol<(tam - 1); --c) {//colocamos comenzando en la ultima columna los datos de la anterior
		int contfil = 0;
		for (int f = p.fila; contfil<tam; ++f) {
			a[f][c] = a[f][c-1];
			++contfil;
		}
		++contcol;
	}
	for (int i = 0; i < tam; ++i) {//colocamos en la primera columna los datos de la ultima
		a[p.fila+i][p.columna] = aux[i];
	}
}

// funcion que resuelve el problema
void resolver(tmatriz  & m,int transformacion, tPos p, int tam) {
	switch (transformacion){
	case 1:transformacion1(m ,p, tam); break;//* por encima diagonal
	case 2:transformacion2(m ,p, tam); break;//* por debajo diagonal
	case 3:transformacion3(m ,p, tam); break;//mover filas
	case 4:transformacion4(m ,p, tam); break;//mover columnas
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int f = 0; int c = 0; int t = 0;
	std::cin >> f >> c >>t;
	if (!std::cin)
		return false;
	tmatriz m(f, std::vector<char>(c));
	leer(m); //lectura matriz
	int k = 0;
	while (k < t){//controla numero de transformaciones
		int tipo = 0; int i = 0; int j = 0; int tam = 0;
		std::cin >> tipo >> i >> j >> tam;
		tPos p;
		p.fila = i; p.columna = j;
		resolver(m,tipo,p,tam);
		++k;
	}

	// escribir sol
	mostrar(m);
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