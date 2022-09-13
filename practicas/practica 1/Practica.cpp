#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

// Escribe aqui los tipos enumerados

enum tElemento { PIEDRA, PAPEL, TIJERAS, LAGARTO, SPOCK };

enum tResultado { HUMANO, COMPUTADORA, EMPATE };

// Escribir aqui las funciones leeJugada y toString.

bool verificar(std::string cad)
{
	return
		cad == "piedra" ||
		cad == "papel" ||
		cad == "tijeras" ||
		cad == "lagarto" ||
		cad == "Spock";
}

//Funcion que pasa un valor del tipo string a tElemento

tElemento fromString(std::string str)
{
	tElemento elemento;
	if (str == "piedra")elemento = PIEDRA;
	else if (str == "papel")elemento = PAPEL;
	else if (str == "tijeras")elemento = TIJERAS;
	else if (str == "lagarto")elemento = LAGARTO;
	else elemento = SPOCK;
	return elemento;
}

//Funcion que pasa un valor de tElemento a tipo string

std::string toString(tElemento jug)
{
	std::string cadena = "";
	if (jug == PIEDRA)cadena = "piedra";
	else if (jug == PAPEL)cadena = "papel";
	else if (jug == TIJERAS)cadena = "tijeras";
	else if (jug == LAGARTO)cadena = "lagarto";
	else cadena = "Spock";
	return cadena;
}

//Funcion que pasa un valor de tResultado a tipo string

std::string toString(tResultado jug)
{
	std::string cadena = "";
	if (jug == HUMANO)cadena = "HUMANO";
	else if (jug == COMPUTADORA)cadena = "COMPUTADORA";
	else if (jug == EMPATE)cadena = "EMPATE";
	else;
	return cadena;
}

// Funcion que obtiene la jugada del humano

tElemento leeJugada(std::string pregunta)
{
	std::string str = "";
	std::cout << pregunta;
	std::cin >> str;
	while (!verificar(str))
	{
		std::cout << pregunta;
		std::cin >> str;
	}
	tElemento elem = fromString(str);
	return elem;

}

// Escribir aqui la funcion gana

bool gana(tElemento jugador1, tElemento jugador2)
{
	switch (jugador1) {
	case PIEDRA:	return jugador2 == LAGARTO || jugador2 == TIJERAS;
	case PAPEL:		return jugador2 == PIEDRA || jugador2 == SPOCK;
	case TIJERAS:	return jugador2 == PAPEL || jugador2 == LAGARTO;
	case LAGARTO:	return jugador2 == SPOCK || jugador2 == PAPEL;
	case SPOCK:		return jugador2 == TIJERAS || jugador2 == PIEDRA;
	}
}

tResultado juegaPartida() {
	tElemento jugada1, jugada2;
	int maq = 0, valorMAX = 5;
	maq = rand() % valorMAX;
	jugada1 = tElemento(maq);
	jugada2 = leeJugada("\nRealice su eleccion: ");

	std::cout << "\nEleccion computadora: " << toString(jugada1) << '\n';
	std::cout << "Tu eleccion: " << toString(jugada2) << '\n';

	if (gana(jugada1, jugada2))
		return COMPUTADORA;
	else if (gana(jugada2, jugada1))
		return HUMANO;
	else
		return EMPATE;
}

char menu(std::string opciones, std::string menError) {
	char opt = ' ';
	std::cout << opciones;
	std::cin >> opt;
	std::cin.ignore(100, '\n');
	while (opt != '0' && opt != '1' && opt != '2') {
		std::cout << menError << opciones;
		std::cin >> opt;
		std::cin.ignore(100, '\n');
	}
	return opt;
}

bool localizacionJugador(std::string apodo) {
	std::ifstream registro;
	registro.open("registro.txt");
	if (registro.is_open()) {
		std::string leer;
		registro >> leer;
		while (leer != "XXX" &&leer != apodo) {
			registro >> leer;
		}
		registro.close();
		return leer == apodo;
	}
	else return false;
}

bool escribeFichero(std::string nombreFichero, std::string marcaFin) {
	std::ifstream reglas; 
	bool ok = true; 
	std::string linea = "";
	reglas.open(nombreFichero);
	if (reglas.is_open()) {
		getline(reglas, linea);
		while (linea != marcaFin) {
			std::cout << linea << '\n';
			getline(reglas, linea);
		}
		reglas.close();
	}
	else ok = false;
	return ok;
}

void sesionDeJuego() {
	int ganadas = 0, empatadas = 0, perdidas = 0, total = 0;
	std::string opciones = "1 - Jugar una partida\n2 - Ver instrucciones\n0 - Salir\nOpcion: ", puntos = "................................\n", 
		mensajeError = "\nOpcion incorrecta!!!\n";
	tResultado resul;
	char c = menu(opciones, mensajeError);
	while (c != '0') {
		if (c == '1') {
			resul = juegaPartida();
			std::cout << puntos << toString(resul) << "\n\n";
			switch (resul) {
			case HUMANO:ganadas += 1; break;
			case COMPUTADORA:perdidas += 1; break;
			case EMPATE:empatadas += 1; break;
			}
			total += 1;
		}
		else if (c == '2') {
			bool abrir=escribeFichero("reglas.txt", "XXX");
			if (!abrir)std::cout << "No se pudieron abrir las instrucciones.\n";
		}
		c = menu(opciones, mensajeError);
	}
	std::cout << "\nRonda de " << total << " partida(s)\nPartidas ganadas: " << ganadas << "\nPartidas empatadas: " << empatadas << "\nPartidas perdidas: " << perdidas << '\n';
}

int main() {
	srand(time(NULL));
	std::string apodo = "";
	std::cout << "Introduzca su apodo: ";
	std::cin >> apodo;
	if (localizacionJugador(apodo))
		sesionDeJuego();
	else std::cout << "Jugador no registrado o archivo registro inexistente. Imposible jugar.\n";
	system("Pause");
	return 0;
}
