#include <iostream>
using namespace std;

//functie care elimina toate valorile duplicate dintr un vector
void f9(int*& v, int& n)
{
	int n2;
	n2 = n;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (v[i] == v[j])
				n2--;

	int* aux = new int[n2];

	int k = 0;
	
	for (int i = 0; i < n; i++) {
		bool exista_duplicat = false;
		for (int j = 0; j < k; j++) 
			if (v[i] == aux[j])
				exista_duplicat = true;
		
			if (exista_duplicat == false)
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


	f9(v, n);
	for (int i = 0; i < n; i++)
		cout << v[i] << "  ";

	delete[]v;
	cout << endl;
	return 0;

}
