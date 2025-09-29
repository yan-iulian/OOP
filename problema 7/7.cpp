#include <iostream>
using namespace std;

// functie care sterge ultimele k aparitii ale unei valori a

void f7(int*& v, int& n, int k, int a)
{
	int n2 = n - k;
	int* aux = new int[n2];
	int j = n2;
	for (int i = n; i >=0 ; i--)
		if (v[i] == a && k > 0)
		{
			k--;
		}
		else aux[j--] = v[i];

	delete[]v;
	v = aux;
	n = n2;


}

int main()
{
	int* v;
	int a, k, n;
	cout << "Introdu dim:"; cin >> n;
	v = new int[n];
	cout << "\nIntrodu elementele vectorului:\n";
	for (int i = 0; i < n; i++) {
		cout << "v[" << i << "]="; cin >> v[i]; cout << endl;
	}
	cout << "\nIntrodu valoarea pe care o stergi:";
	cin >> a;
	cout << "Introdu cate valori stergi:";
	cin >> k;

	f7(v, n, k, a);

	cout << "Vectorul dupa prelucrare este :" << endl;
	for (int i = 0; i < n; i++)
		cout << v[i] << "  ";
	delete[]v;


	return 0;

}