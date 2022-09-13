// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

const int DIMENSION = 8;
const int NUM_CASILLAS = 6;
enum tEstadoCasilla { VACIA, HIELO, MURO, CAJA, JOYA, TORTUGA };
enum tDir { UP, DOWN, RIGHT, LEFT };
struct tTortuga {
	char identificacion;
	tDir direccion;
};
struct tCasilla {
	tEstadoCasilla contenido;
	tTortuga tortuga;
};
using tTablero = std::vector <std::vector<tCasilla>>;


std::istream & operator>>(std::istream & entrada, tTortuga & dato) {
	std::cin >> dato.identificacion;
	switch (dato.identificacion) {
	case 'U':dato.direccion = UP; break;
	case 'D':dato.direccion = DOWN; break;
	case 'R':dato.direccion = RIGHT; break;
	case 'L':dato.direccion = LEFT; break;
	}
	return entrada;
}


//(a) Transformar un caracter en una casilla. La funcion recibira tambien un parametro con el identificador de la tortuga. Este parametro solo llevara valor cuando el caracter corresponda a una tortuga.
tCasilla charTOcasilla(char c) {
	tCasilla cas;
	switch (c) {
	case '#':	cas.contenido = MURO; break;
	case '@':	cas.contenido = HIELO; break;
	case ' ':	cas.contenido = VACIA; break;
	case '$':	cas.contenido = JOYA; break;
	case 'C':	cas.contenido = CAJA; break;
	default:
		cas.contenido = TORTUGA;
		cas.tortuga.identificacion = c;
		switch (c) {
		case 'U':	cas.tortuga.direccion = UP; break;
		case 'D':	cas.tortuga.direccion = DOWN; break;
		case 'R':	cas.tortuga.direccion = RIGHT; break;
		case 'L':	cas.tortuga.direccion = LEFT; break;
		}
	}
	return cas;
}
//(b) Transformar una casilla en una cadena de caracteres.
std::string casillaTOstr(tCasilla c) {
	switch (c.contenido) {
	case VACIA:	return "  ";
	case HIELO:	return "**";
	case MURO:	return "||";
	case CAJA:	return "[]";
	case JOYA:	return "00";
	case TORTUGA:switch (c.tortuga.direccion) {
	case UP:	return"^^";
	case DOWN:	return"VV";
	case RIGHT:	return">>";
	case LEFT:	return"<<";
	}
	}
}
//(c) Mostrar por pantalla o ?chero una casilla. 
void mostrarCasilla(tCasilla cas) {
	std::cout << casillaTOstr(cas);
}
//(d) Mostrar por pantalla o fichero un tablero.
void mostrarTablero(tTablero const t) {
	for (int f = 0; f < t.size(); ++f) {
		for (int c = 0; c < t.size(); ++c) {
			mostrarCasilla(t[f][c]);
		}
		std::cout << '\n';
	}
}
//(e) Cargar un tablero a partir de unos datos dados por teclado o fichero.
void cargar(tTablero & t, int n) {
	std::string linea;
	getline(std::cin, linea);
	std::stringstream ss; ss << linea;
	int numParticipantes;
	ss >> numParticipantes;
	while (numParticipantes != n) {
		int i = 0;
		while (i < 8) {
			getline(std::cin, linea);
			++i;
		}
		getline(std::cin, linea);
		ss.clear();
		ss << linea;
		ss >> numParticipantes;
	}
	for (int f = 0; f < t.size(); ++f) {
		std::string str = "";
		getline(std::cin, str);
		for (int c = 0; c < t.size(); ++c) {
			char aux = ' ';
			aux = str[c];
			t[f][c] = charTOcasilla(aux);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string linea;
	getline(std::cin, linea);
	std::stringstream ss; ss << linea;
	int numJugadores;
	ss >> numJugadores;
	if (numJugadores == 0) return false;
	tTablero tablero(DIMENSION, std::vector<tCasilla>(DIMENSION));
	cargar(tablero, numJugadores);
	mostrarTablero(tablero);
	std::cout << '\n';
	// Para leer los tableros que no se han usado.
	// Son tableros del caso que se encuentran despues del tablero que se carga
	getline(std::cin, linea);
	while (std::cin && linea != "---") getline(std::cin, linea);
	return true;
	// escribir sol

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());
	;


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}