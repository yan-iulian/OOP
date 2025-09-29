#include <iostream>
#include <string>
using namespace std;

void invitatii(string*& invitat, int& nr_inv)
{
	invitat = new string[nr_inv];
	cin.ignore(50, '\n');
	for (int i = 0; i < nr_inv; i++) {
		cout << "Introdu numele jucatorului " << i + 1 << " : " << endl;

		getline(cin, invitat[i]);
		cout << endl;
	}

}

void afisare_lista(string*& invitat, int& nr_inv)
{
	cout << "             LISTA DE JUCATORI                 \n";
	for (int i = 0; i < nr_inv; i++)
		cout << i + 1 << ".     " << invitat[i] << endl;
}

void cautare_invitat(string*& invitat, int& nr_inv, string inv_cautat)
{
	int i;
	for (i = 0; i < nr_inv; i++)
		if (inv_cautat == invitat[i]) {
			cout << "\nAm gasit jucatorul cautat , acesta are numarul " << i + 1 << endl;
			break;
		}
	if (i == nr_inv)
		cout << "Jucatorul nu este pe lista !!";
}

int main()
{
	string* invitati;
	int nr;
	cout << "Introduceti nr de jucatori :";
	cin >> nr;
	invitatii(invitati, nr);
	afisare_lista(invitati, nr);

	cout << "Cautati vreun jucator ? Scrie da sau nu !\n";
	string raspuns;

	getline(cin, raspuns);

	if (raspuns == "da")
	{
		cout << "Introdu numele jucatorului: \n";
		string inv_cautat;
		getline(cin, inv_cautat);
		cautare_invitat(invitati, nr, inv_cautat);

	}
	else cout << "Programul s-a terminat!";
	delete[] invitati;
	return 0;
}