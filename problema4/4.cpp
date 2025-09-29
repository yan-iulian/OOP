#include <iostream>
using namespace std;

void f4(int*& v, int& n) {
	int n2 = 0;
	for (int i = 0; i < n; i++)
		if (v[i] % 2 == 1)
			n2++;
	int* aux = new int[n2+n];
	int j = 0;
	for (int i = 0; i < n; i++) {
		aux[j] = v[i];
		j++;
		if (v[i] % 2 == 1)
		{
			aux[j] = v[i];
			aux[j + 1] = v[i];
			j++;
		}
	}
	delete[]v;
	v = aux;
	n = n+n2;

}

int main()
{
	int* v, k, n;
	cout << "Introdu dimensiunea:" << endl;
	cin >> n;
	v = new int[n];
	cout << "Introdu elementele vectorului:" << endl;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	

	f4(v, n);
	for (int i = 0; i < n; i++)
		cout << v[i] << "  ";

	delete[]v;
	cout << endl;
	return 0;

}