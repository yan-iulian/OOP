#include <iostream>
using namespace std;

void f6(int*& v, int& n) {
	int n2=NULL;
	for (int i = 0; i < n; i++)
	{
		if (v[i] >= 0) {
			if (v[i] % 2 == 0)
				n2++;
			if (v[i] % 2 != 0)
				n2 = n2 + 2;
		}
	}
	int* aux = new int[n2];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (v[i] >= 0) {
			if (v[i] % 2 == 0)
				aux[j++] = v[i] / 2;
			if (v[i] % 2 != 0) {
				aux[j++] = v[i] * 3;
				aux[j++] = v[i] * 3;
			}
		}
	delete[]v;
	v = aux;
	n = n2;

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


	f6(v, n);
	for (int i = 0; i < n; i++)
		cout << v[i] << "  ";

	delete[]v;
	cout << endl;
	return 0;

}
