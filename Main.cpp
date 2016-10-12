#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 10000
using namespace std;

long long cnt = 0;
long long cnt2 = 0;
void swap(int * a, int * b) {
	int c = *a;
	*a = *b;
	*b = c;
}
int median(int *a, int * b, int * c) {
	int m[3];
	m[0] = *a;
	m[1] = *b;
	m[2] = *c;
	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++)
			if (m[j] < m[i]) swap(&m[i], &m[j]);
	}
	return m[1];
}
int * ChoosePivot(int * v, const int n) {
	int * n1 = v;
	int * n2 = v + (n + 1) / 2 - 1;
	int * n3 = v + n - 1;
	if (*n1 == median(n1, n2, n3)) return n1;
	if (*n2 == median(n1, n2, n3)) return n2;
	if (*n3 == median(n1, n2, n3)) return n3;
	//	return v+n -1;
	//	return v;
}

int Partition(int * v, const int n, int * p) {
	swap(v, p);
	int * i = v + 1;
	int * j = i;
	while (j != v + n) {
		cnt2++;
		if (*j < *v)
		{
			swap(j, i);
			i++;
		}
		j++;
	}
	i--;
	swap(v, i);
//	for (int i = 0; i < n; i++)
//		cout << v[i] << " ";
//	cout << endl;
	return abs(i - v);
}
void QuickSort(int * v, const int n) {
	if (n <= 1) return;
	int * p = ChoosePivot(v,n);
	int n_left = Partition(v, n, p);
	cnt += n_left - 1;
	QuickSort(v, n_left);
	cnt += n - n_left - 1;
	QuickSort(v + n_left+1, n - n_left - 1);
}

int main() {
	ifstream fin("QuickSort.txt");
	int v[SIZE];
	if (!fin.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
	for (int i = 0; i < SIZE; i++) {
		fin >> v[i];
	}
	cnt += SIZE - 1;
	QuickSort(v, SIZE);
	for (int i = 0; i < SIZE; i++)
		cout << v[i] << " ";
	cout << cnt << " "<< cnt2;
	return 0;
}