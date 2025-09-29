#include <iostream>
using namespace std;

enum TipMancare {
	CIORBA, PASTE, PIZZA, DESERT
};

enum Ingredient {
	FAINA , OUA , LAPTE , CARNE , BRANZA
};

class FelMancare
{
	//vector static de caractere
	char cod[10];


	//vector dinamic de caractere 
	//char* denumire2;
	string denumire;


	//vector numeric static 
	int valoriNutritionale[3];//dim fixa ce reprezinta nr de categorii (glucide , lipide , proteine)


	//vector numeric dinamic
	//float* cantitateIngrediente;
	//int nrIngrediente;


	//enumeratie
	TipMancare tipMancare;


	//vector enumeratii static si dinamic
	//Ingredient* listaIngrediente;
	//int nrIngrediente;

	//vector de siruri de caractere
	string* listaAlergeni;
	int nrAlergeni;


	//bool
	//bool esteVegana;


	//vector de bool
	//bool disponibilitate[12];



public:

	void initializare() {
		denumire = "-";
		for (int i = 0; i < 3; i++)
			valoriNutritionale[i] = 0;
		tipMancare = TipMancare::PASTE;
		nrAlergeni = 0;
		listaAlergeni = nullptr;
	}
	void afisare() {
		cout << "\n--------------------";
		cout << "\nDenumire: " << denumire;
		cout << "\nValori nutritionale: ";
		for (int i = 0; i < 3; i++)
			cout << valoriNutritionale[i] << " ";
		cout << "\nTip mancare: " << tipMancare;
		cout << "\nNr alergeni: " << nrAlergeni;
		cout << "\nLista alergeni: ";
		for (int i = 0; i < nrAlergeni; i++)
			cout << listaAlergeni[i] << "  ";
		cout << "\n------------------------";
	}

	string getDenumire() {
		return denumire;
	}

	 void setDenumire(string _denumire) {
		 if(_denumire.size()>=3)
			denumire = _denumire;
	}

	 TipMancare getNumeMancare() {
		 return tipMancare;
	}

	 void setTipMancare(TipMancare _tipMancare) {
		 tipMancare = _tipMancare;
	 }

	 int getNrAlergeni() {
		 return nrAlergeni;
	 }

	 void setAlergeni(int _nrAlergeni, string* _listaAlergeni)
	 {
		 if (_nrAlergeni > 0 && _listaAlergeni != nullptr) {
			 //pentru a nu avea memory leaks , ianinte sa alocam o noua zona de memorie , verificam daca avem deja ceva alocat
			 //daca avem , vom dezaloca
			 if (listaAlergeni != nullptr) {
				 delete[]listaAlergeni;
			 }
			 nrAlergeni = _nrAlergeni;
			 //shalow copy
			 listaAlergeni = _listaAlergeni;//partajam aceeasi memorie
			 //deep copy
			 listaAlergeni = new string[nrAlergeni];
			 for (int i = 0; i < nrAlergeni; i++)
				 listaAlergeni[i] = _listaAlergeni[i];
		 }
	 }
	 string* getListaAlergeni() {
		 return listaAlergeni;
	 }
};

int main()
{
	//initializare obiect 
	FelMancare f1;                //apel constructor implicit
	f1.initializare();
	

	//afisare obiect
	f1.afisare();


	//metode accesor (set si get)
	//get=rol consultare
	cout << endl << f1.getDenumire();
	f1.getDenumire();
	f1.setDenumire("pizza");
	cout << endl << f1.getDenumire();

	cout << endl << f1.getNumeMancare();
	f1.setTipMancare(DESERT);
	cout << endl << f1.getNumeMancare();
	//set=rol modificare/atribuire(ambele pentru a modifica ce e in privat)

	string* listaAlergeni = new string[3]{ "telina","scoici","oua" };
	f1.setAlergeni(3, listaAlergeni);
	cout << endl << f1.getNrAlergeni();
	cout << endl << f1.getListaAlergeni();
	for (int i = 0; i < f1.getNrAlergeni(); i++)
		cout << endl << f1.getListaAlergeni()[i];

	return 0;
}