#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

// Escribir aqui la funcion leeOpcion.

int leeOpcion(std::string pregunta, std::string mensajeError, int valMin, int valMax)
{
	int opt = 0;
	std::cout << pregunta;
	std::cin >> opt;
	while (opt<valMin || opt>valMax)
	{
		std::cout << mensajeError << pregunta;
		std::cin >> opt;
	}
	return opt;
}

// Escribe aqui el tipo enumerado

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
	jugada2 = leeJugada("Introduzca su opcion: ");

	std::cout << "Eleccion computadora: " << toString(jugada1) << '\n';
	std::cout << "Tu eleccion: " << toString(jugada2) << '\n';

	if (gana(jugada1, jugada2))
		return COMPUTADORA;
	else if (gana(jugada2, jugada1))
		return HUMANO;
	else
		return EMPATE;
}
bool comprobar(char c) {
	return c == '0' || c == '1';
}
void sesionDeJuego() {
	int ganadas = 0, empatadas = 0, perdidas = 0, total = 0;
	char c = ' ';
	bool ok;
	tResultado resul;
	std::string menu = "1 - Jugar una partida\n0 - Salir\nOpcion: ", puntos = ".................\n";
	std::cout << menu;
	std::cin >> c;
	while (!comprobar(c)) {
		std::cout << "Opcion incorrecta!!!\n" <<menu;
		std::cin.sync();
		std::cin >> c;
	}
	while (c == '1') {
		resul = juegaPartida();
		std::cout << puntos << toString(resul) << '\n';
		switch (resul) {
		case HUMANO:ganadas += 1; break;
		case COMPUTADORA:perdidas += 1; break;
		case EMPATE:empatadas += 1; break;
		}
		total += 1;
		std::cout << menu;
		std::cin >> c;
		while (!comprobar(c)) {
			std::cout << "Opcion incorrecta!!!\n" << menu;
			std::cin.sync();
			std::cin >> c;
		}
	}
		std::cout << "Ronda de " << total << "partida(s)\nPartidas ganadas: " << ganadas << "\nPartidas empatadas: " << empatadas << "\nPartidas perdidas: " << perdidas;
}

int main() {
	srand(time(NULL));
	sesionDeJuego();
	system("Pause");
	return 0;
}