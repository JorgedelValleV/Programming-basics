#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <string>
#include <fstream>
#include <iomanip>

enum piedrasPreciosas { diamante, rubi, esmeralda, zafiro, jade };

struct tPiedras {
	piedrasPreciosas tipo1;
	int num1;
	piedrasPreciosas tipo2;
	int num2;
};
 int resolver(std::vector<piedrasPreciosas>const & v, tPiedras p, int longVentana) {
	 int cont = 0; int numtipo1 = 0; int numtipo2 = 0;
	 for(int i = 0; i < longVentana; ++i) {
		 if (v[i] == p.tipo1)++numtipo1;
		 else if (v[i] == p.tipo2)++numtipo2;
	 }
	 if (numtipo1 >= p.num1&&numtipo2 >= p.num2)++cont;
	 for(int i = longVentana; i < v.size(); ++i) {
		 if (v[i] == p.tipo1)++numtipo1;
		 else if (v[i] == p.tipo2)++numtipo2;
		 if (v[i-longVentana] == p.tipo1)--numtipo1;
		 else if (v[i-longVentana] == p.tipo2)--numtipo2;
		 if (numtipo1 >= p.num1&&numtipo2 >= p.num2)++cont;
	 }
	 return cont;
 }
 std::istream & operator>> (std::istream& entrada, piedrasPreciosas& p) {
	 char num;
	 entrada >> num;
	 switch (num) {
	 case 'd': p = diamante; break;
	 case 'r': p = rubi; break;
	 case 'e': p = esmeralda; break;
	 case 'z': p = zafiro; break;
	 case 'j': p = jade; break;
	 }
	 return entrada;
 }
 void resuelveCaso() {
	 int numElem; int numPiedras;
	 tPiedras p;
	 std::cin >> numElem >> numPiedras >> p.tipo1 >> p.num1 >> p.tipo2 >> p.num2;
	 std::vector<piedrasPreciosas>v(numElem);
	 for (piedrasPreciosas& i : v) std::cin >> i;
	 int cont = resolver(v, p, numPiedras);
	 std::cout << cont << '\n';
 }
 int main() {
	 int numCasos = 0;
	 std::cin >> numCasos;
	 for (int i = 0; i < numCasos; ++i) {
		 resuelveCaso();
	 }
	 system("PAUSE");
	 return 0;
 }