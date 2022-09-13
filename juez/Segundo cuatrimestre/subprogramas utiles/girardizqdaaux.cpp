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
tmatriz girar(tmatriz const & m) {
	tmatriz sol(m.size(), std::vector<int>(m[0].size()));
	int i = 0;
	for (int f = 0; f < sol.size(); ++f) {
		for (int c = 0; c < sol[f].size(); ++c) {
			sol[f][c] = m[c][m.size() - 1 - f];
		}
	}
	return sol;
}
int main() {
	int f = 0;
	std::cin >> f;
	tmatriz m(f, std::vector<int>(f));
	tmatriz sol(m.size(), std::vector<int>(m[0].size()));
	leer(m);
	mostrar(m);
	sol=girar(m);
	mostrar(sol);
	system("PAUSE");
	return 0;
}