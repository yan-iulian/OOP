#include <iostream>
using namespace std;

void f10(int*& v, int &n)
{
	int n2 = 0;
	int nr_ap = 0;
	for (int i = 0; i < n; i++) {
		int nr_ap = 0;
		for (int j = 0 ; j < n; j++)
			if (v[i] == v[j])
				nr_ap++;
		if (nr_ap != 2)
				n2++;
	}
	int* aux = new int[n2];
	int k = 0;
	for (int i = 0; i < n; i++) {
		//bool dublura = false;
		int nr_ap = 0;
		for (int j = 0; j < n; j++)
			if (v[i] == v[j])
				nr_ap++;
		//if (nr_ap != 2)
			//	dublura = true;
		//if (dublura == false)
		if(nr_ap!=2)
				aux[k++] = v[i];
	}
	delete[]v;
	v = aux;
	n = n2;
}

int main()
{
	int* v, n;
	cout << "Introdu dimensiunea:" << endl;
	cin >> n;
	v = new int[n];
	cout << "Introdu elementele vectorului:" << endl;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	f10(v, n);
	for (int i = 0; i < n; i++)
		cout << v[i] << "  ";
	delete[]v;
	cout << endl;
	return 0;


}
