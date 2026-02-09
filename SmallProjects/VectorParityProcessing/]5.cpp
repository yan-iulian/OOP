#include <iostream >
using namespace std;
//nr pare se dubleaza , cele negative se elimina iar cele impare se dubleaza la aparitii
void f5(int*& v, int& n) {
	int n2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] >= 0) {
			if (v[i] % 2 != 0)
				n2 = n2 + 2;;
			if (v[i] % 2 == 0)
				n2++;
		}
	}
	int* aux = new int[n2];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] >= 0)
			if (v[i] % 2 == 0)
				aux[j++] = v[i] * 2;
			else
			{
				aux[j++] = v[i];
				aux[j++] = v[i];
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


	f5(v, n);
	for (int i = 0; i < n; i++)
		cout << v[i] << "  ";

	delete[]v;
	cout << endl;
	return 0;

}






























