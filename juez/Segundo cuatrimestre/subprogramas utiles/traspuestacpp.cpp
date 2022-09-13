#include <iostream>
#include <vector>
using tmatriz = std::vector<std::vector<int>>;
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
void traspuesta(tmatriz  & m) {
	int i = 0;
	for (int f = 0; f < m.size(); ++f) {
		for (int c = i; c < m[f].size(); ++c) {
			std::swap(m[f][c], m[c][f]);
		}
		++i;
	}
}
int main() {
	int dim = 0;
	std::cin >> dim;
	tmatriz m(dim, std::vector<int>(dim));
	leer(m);
	mostrar(m);
	traspuesta(m);
	mostrar(m);
	system("PAUSE");
	return 0;
}