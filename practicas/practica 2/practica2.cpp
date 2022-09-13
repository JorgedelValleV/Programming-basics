//Jorge del Valle Vazquez DG206

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

//Declarar aqui los tipos enumerados
enum tColor { ROJO, AZUL, VERDE, AMARILLO, MARRON, BLANCO };

//Declarar aqui las constantes
const std::string MASTERMIND = "\t\tMASTERMIND\n\t\t==========\n";
const int INTENTOSMAX = 15;
const int NOCONSEGUIDO = 0;
const int NUMTCOLOR = 6;
const int TAM_CODIGO = 4;
const int VALORMAX = 6;
const std::string OPCIONES = "\n1. Jugar con un codigo sin colores repetidos\n2. Jugar con un codigo con colores repetidos\n3. Mostrar los resultados de las partidas anteriores\n0. Salir\n\n\tElige una opcion: ";
const std::string mensajeERROR = "\nOpcion incorrecta. Prueba otra vez:\n";
const std::string INTRODUCE_CODIGO = "Introduce el codigo (palabra de 4 letras con alguna de R, Z, V, A, M o B): ";
const std::string CODIGO_INCORRECTO = "CODIGO INVALIDO!!!!\n";
const std::string ERROR_OBTENERDATOS = "No se pudieron obtener los datos del archivo\n";
const std::string ERROR_GUARDARRDATOS = "No se pudieron guardar los datos en el archivo\n";
using	tCodigo = std::vector<tColor>;



//Declarar aqui las funciones que pasan de un tipo a otro
char color2char(tColor a) {
	switch (a) {
	case ROJO:	return 'R';
	case AZUL:	return 'Z';
	case VERDE:	return 'V';
	case AMARILLO:	return 'A';
	case MARRON:	return 'M';
	case BLANCO:	return 'B';
	}
}
tColor char2color(char c) {
	switch (c) {
	case'R':return ROJO;
	case'Z':return AZUL;
	case'V':return VERDE;
	case'A':return AMARILLO;
	case'M':return MARRON;
	case'B':return BLANCO;
	}
}

void compararCodigos(tCodigo const& codigo, tCodigo const & hipotesis, int&	colocados, int&	descolocados) {
	std::vector<bool> aux(TAM_CODIGO, true);
	for (int i = 0; i < TAM_CODIGO; ++i) {
		if (hipotesis[i] == codigo[i]) {
			++colocados;
			aux[i] = false;
		}
	}
	for (int i = 0; i < TAM_CODIGO; ++i) {
		int j = 0; bool parar = false;
		while (j < TAM_CODIGO && !parar) {
			if (aux[j] && codigo[i] == hipotesis[j] && codigo[i] != hipotesis[i]) {
				++descolocados;
				parar = true;
				aux[j] = false;
			}
			++j;
		}
	}
}

void codigoAleatorio(tCodigo& codigo, bool admiteRepetidos) {
	if (admiteRepetidos) {
		for (int i = 0; i < TAM_CODIGO; ++i) {
			codigo[i] = tColor(rand() % VALORMAX);
		}
	}
	else {
		codigo[0] = tColor(rand() % VALORMAX);
		for (int i = 1; i < TAM_CODIGO; ++i) {
			codigo[i] = tColor(rand() % VALORMAX);
			int j = 0;
			while (j < i) {
				if (codigo[i] == codigo[j]) {
					codigo[i] = tColor(rand() % VALORMAX);
					j = 0;//Si el unico problema era que la j no volvia a ser 0 lo he solucionado asi. De todas formas dejo tu recomendacion debajo.
				}
				else ++j;
			}
		}
		/*
		std::vector<bool> comprobar(NUMTCOLOR,false)
		codigo[0] = tColor(rand() % VALORMAX);
		comprobar[int(codigo[0])]=true;
		for (int i = 1; i < TAM_CODIGO; ++i) {
			codigo[i] = tColor(rand() % VALORMAX);
			while (comprobar[int(codigo[i])]) {
				codigo[i] = tColor(rand() % VALORMAX);
			}
		}*/
	}
}

char menu() {
	char opt = ' ';
	std::cout << OPCIONES;
	std::cin >> opt;
	std::cin.ignore(100, '\n');
	while (opt < '0' || opt > '3') {
		std::cout << mensajeERROR << OPCIONES;
		std::cin >> opt;
		std::cin.ignore(100, '\n');
	}
	return opt;
}
bool comprobar(char c) {
	return c == 'R' || c == 'Z' || c == 'V' || c == 'A' || c == 'M' || c == 'B';
}
void introducirCodigo(tCodigo& hipotesis) {
	bool ok = false;
	while(!ok){
		ok = true;
		std::cout << INTRODUCE_CODIGO;
		for (size_t i = 0; i < TAM_CODIGO&&ok; ++i) {
			char c = ' ';
			std::cin >> c;
			c = toupper(c);
			ok = comprobar(c);
			hipotesis[i] = char2color(c);
		}
		if (!ok) std::cout << CODIGO_INCORRECTO;
	}
}
std::ostream & operator<<(std::ostream & arch, tCodigo const& dato) {
	for (size_t i = 0; i < TAM_CODIGO; ++i) {
		std::cout << color2char(dato[i]);
	}
	return arch;
}
std::ostream & operator<<(std::ostream & arch, std::vector<int> dato) {
	for (size_t i = 0; i < dato.size(); ++i) {
		if (dato[i] != 0)std::cout << "Partida " << i + 1 << ": Resuelto en " << dato[i] << " intentos\n";
		else if (dato[i] == 0)std::cout << "Partida " << i + 1 << ": No consiguio resolverse\n";
	}
	return arch;
}
void sesionDeJuego(std::vector<int>&inten) {
	tCodigo	codigoSecreto(TAM_CODIGO);
	tCodigo hipotesisCodigo(TAM_CODIGO);
	char c = menu();
	while (c != '0') {
		if (c == '3') {
			std::cout << inten;
		}
		else {
			int col = 0, descol = 0, intentos = 0;
			bool ok = (c == '2');
			//Obtenemos el codigo que debemos adivinar
			codigoAleatorio(codigoSecreto, ok);

			/*Mostramos por pantalla el codigo secreto
			std::cout << codigoSecreto << '\n';*/

			//Comenzamos a averiguar el codigo
			while (col < TAM_CODIGO && intentos < INTENTOSMAX) {//col < 4 && intentos < 15
				introducirCodigo(hipotesisCodigo);
				col = 0; descol = 0;
				compararCodigos(codigoSecreto, hipotesisCodigo, col, descol);
				std::cout << hipotesisCodigo;
				std::cout << " Colocados: " << col << "; mal colocados : " << descol << '\n';
				++intentos;
			}
			if (intentos == INTENTOSMAX && col < TAM_CODIGO) {//intentos == 15 && col < 4
				inten.push_back(NOCONSEGUIDO);//donde NOCONSEGUIDO=0 es el valor que asocio a no haber resuleto el codigo
				std::cout << "Ha agotado usted sus " << INTENTOSMAX << " intentos\n";
			}
			else {//col==4
				inten.push_back(intentos);
				std::cout << "Enhorabuena! Lo encontraste! Te ha costado " << intentos << " intento(s).\n\n";
			}
		}
		c = menu();
	}
}
int main() {
	srand(time(NULL));
	std::cout << MASTERMIND;
	std::vector<int> vintentos;
	std::ifstream entrada;
	entrada.open("partidas.txt");
	if (entrada.is_open()) {
		int n = 0;
		entrada >> n;
		while (!entrada.eof()) {
			vintentos.push_back(n);
			entrada >> n;
		}
	}
	else std::cout << ERROR_OBTENERDATOS;
	entrada.close();
	sesionDeJuego(vintentos);
	std::ofstream salida;
	salida.open("partidas.txt");
	if (salida.is_open()) {
		for (int i = 0; i < vintentos.size(); ++i) {
			salida << vintentos[i] << ' ';
		}
	}
	else std::cout << ERROR_GUARDARRDATOS;
	salida.close();
	system("Pause");
	return 0;
}