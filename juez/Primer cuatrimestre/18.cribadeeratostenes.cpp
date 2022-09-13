#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void criba(int n){
	std::vector <int> primos;
	std::vector <bool> v(n, true);
	for (int i = 2; i <= n / 2; ++i){
		if (v[i]){
			for (int j = 2; i*j < n; ++j){
				v[i*j] = false;
			}
		}
	}
	for (int i = 2; i < n; ++i){
		if (v[i]){
			primos.push_back(i);
			std::cout << i << '\n';
		}
	}
}
int main(){
	int n;
	std::cin >> n;
	criba(n);
	system("Pause");
	return 0;
}