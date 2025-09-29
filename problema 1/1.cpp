#include <iostream>
using namespace std;

void f1(int* v, int dim)
{
	int i, nr=0 , medie=0;  //nr=nr elemente impare
	for (i=0;i<dim;i++)
		if (v[i] % 2 == 1)
		{
			nr++;
			medie = medie + (v[i]);

		}
	medie = medie / nr;
	
	for (i = 0; i < dim; i++) {
		if (v[i] % 2 == 0)
			v[i] = medie;

	}


}

int main() {
	int* v;
	int dim, i;
	cout << "Introdu dimensiunea :" << endl;
	cin >> dim;
	v = new int[dim];
	cout << "Introdu elementele vectorului :" << endl;
	for (i = 0; i < dim; i++)
		cin >> v[i];
	f1(v, dim);

	for (i = 0; i < dim; i++)
		cout << v[i] << "  ";

	return 0;
}