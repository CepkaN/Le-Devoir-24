#include<iostream>
#include<cstdlib>
#include<ctime>

void fill_arr(int bloc[],int eterno,int ga=10,int dr=23) {
	srand(time(NULL));
	for (int i = 0; i < eterno; i++)
		bloc[i] = rand() % (dr-ga) + ga;
}
template<typename T>
void show_arr(T bloc[], int eterno) {
	std::cout << "[ ";
	for (int i = 0; i < eterno; i++)
		std::cout << bloc[i] << ", ";
	std::cout << "\b\b ]\n";
}
void resize_arr(int *&bloc, int anc, int nouv) {
	if (nouv <= 0)
		return;
	int* tmp = new int[nouv] {};
	if (anc <= nouv)
		for (int i = 0; i < anc; i++)
			tmp[i] = bloc[i];
	else
		for (int i = 0; i < nouv; i++)
			tmp[i] = bloc[i];
	delete[] bloc;
	bloc = tmp;
}
int main() {
	setlocale(LC_ALL, "Russian");
	// Задача 1.
	std::cout << "Задача 1.\n";
	int n, m;
	std::cout << "Введите длины массивов : ";
	std::cin >> n >> m;
	int* A = new int[n];
	int* B = new int[m];
	fill_arr(A, n, 12, 56);
	fill_arr(B, m, 3, 37);
	std::cout << "Массив A : \n";
	show_arr(A, n);
	std::cout << "Массив B : \n";
	show_arr(B, m);
	int* C = new int[n + m];
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = n; i < n + m; i++)
		C[i] = B[i - n];
	std::cout << "Массив C : \n";
	show_arr(C, n+m);
	delete[] A;
	delete[] B;

	// Задача 2.
	std::cout << "\nЗадача 2.\nВведите длину массива : \n";
	int taille;
	std::cin >> taille;
	int* arr = new int[taille];
	fill_arr(arr, taille);
	show_arr(arr, taille);
	std::cout << "\nВведите новую длину массива : \n";
	int ta;
	std::cin >> ta;
	resize_arr(arr, taille, ta);
	taille = ta;
	show_arr(arr, taille);


	return 0;
}