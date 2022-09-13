// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

const int MIN_JUG = 1;
const int MAX_JUG = 4;
const int DIMENSION = 8;
const int NUM_CASILLAS = 6;
const std::vector<int> incF{-1,0,1,0};
const std::vector<int> incC{0,1,0,-1};

enum tEstadoCasilla { VACIA, HIELO, MURO, CAJA, JOYA, TORTUGA };
enum tDir { UP, RIGHT, DOWN, LEFT };
struct tTortuga {
	char identificacion;
	tDir direccion;
};
struct tCasilla {
	tEstadoCasilla contenido;
	tTortuga tortuga;
};
struct tCoordenada {
	int fila;
	int columna;
};
using tTablero = std::vector <std::vector<tCasilla>>;



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
	case DOWN:	return"vv";
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
			t[f][c] = charTOcasilla(str[c]);
		}
	}
}
bool dentroTablero(tTablero const & t, tCoordenada c, tDir d) {
	return (c.fila + incF[d]) < DIMENSION && (c.columna + incC[d])<DIMENSION && (c.fila + incF[d]) >=0 && (c.columna + incC[d]) >= 0;
}
//f) Fucion que reciba un tablero, las coordenadas en que se encuentra la tortuga con la pistola laser y la direccion a la que apunta la tortuga y modiﬁque el tablero de acuerdo con el resultado del disparo
void laser(tTablero & t, tCoordenada pos, tDir disparo) {
	bool ejecutado = false;
	if (dentroTablero(t, pos, t[pos.fila][pos.columna].tortuga.direccion)) {
		int i = 0;
		while (pos.fila < DIMENSION && pos.columna < DIMENSION && !ejecutado && dentroTablero(t, pos, t[pos.fila- (i*incF[disparo])][pos.columna-(i*incC[disparo])].tortuga.direccion)) {
			pos.fila += incF[disparo];
			pos.columna += incC[disparo];
			if (t[pos.fila][pos.columna].contenido == HIELO) {
				t[pos.fila][pos.columna].contenido = VACIA;
				ejecutado = true;
			}
			else if (t[pos.fila][pos.columna].contenido != VACIA) {
				ejecutado = true;
			}
			++i;
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
	int numTortuga;
	ss >> numTortuga;
	tTablero tablero(DIMENSION, std::vector<tCasilla>(DIMENSION));
	// Carga el tablero
	cargar(tablero, numJugadores);
	tCoordenada coor;
	// Busca la tortuga a la que le toca jugar
	bool enc = false;
	int encontradas = 0;
	for (int i = 0; i < DIMENSION && !enc; ++i) {
		for (int j = 0; j < DIMENSION && !enc; ++j) {
			if (tablero[i][j].contenido == TORTUGA) {
				encontradas++;
				if (numTortuga == encontradas) {
					enc = true;
					coor.fila = i;
					coor.columna = j;
				}
			}
		}
	}
	// LLamada a la funcion laser
	laser(tablero, coor, tablero[coor.fila][coor.columna].tortuga.direccion);
	// Mostrar tablero de salida
	mostrarTablero(tablero);
	std::cout << '\n';
	// Para leer los tableros que no se han usado.
	// Son tableros del caso que se encuentran despues del tablero que se carga
	getline(std::cin, linea);
	while (std::cin && linea != "---") getline(std::cin, linea);
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