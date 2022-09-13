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
void girar(tmatriz & m) {
	for (int f = 0; f < (m.size() / 2); ++f) {
		for (int c = 0 ; c < m.size() ; ++c) {
			std::swap(m[f][c], m[m.size() - 1 - f][m.size() - 1 - c]);
		}
	}
	if ((m.size() % 2) == 1) {
		int f = m.size() / 2;
		for (int c = 0; c < (m.size() / 2); ++c) {
			std::swap(m[f][c], m[f][m.size() - 1 - c]);
		}
	}
}

int main() {
	int f = 0;
	std::cin >> f;
	tmatriz m(f, std::vector<int>(f));
	tmatriz sol(m.size(), std::vector<int>(m[0].size()));
	leer(m);
	mostrar(m);
	girar(m);
	mostrar(m);
	system("PAUSE");
	return 0;
}