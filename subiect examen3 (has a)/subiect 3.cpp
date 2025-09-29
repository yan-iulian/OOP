#include <iostream>
using namespace std;

class Scara {
	string denumire="--";
	int nrApartamente=0;
	int nrLocatari=0;
public:
	Scara() {}

	Scara(string _denumire, int _nrApartamente, int _nrLocatari)
	{
		this->denumire = _denumire;
		this->nrApartamente = _nrApartamente;
		this->nrLocatari = _nrLocatari;
	}

	friend ostream& operator<<(ostream& out, const Scara& s)
	{
		out << "\nDenumirea scarei: " << s.denumire << "\tNr de apartamente din scara resp:"
			<< s.nrApartamente << "\tNr de locatari din scara respectiva: " << s.nrLocatari;
		return out;
	}
	
};

class Bloc {
	string denumire = "--";
	string adresa = "--";
	int nrScari = 0;
	Scara* listaScari = nullptr;
	static string tara;

public:
	Bloc() {}

	Bloc(string _denumire, string _adresa, int _nrScari, Scara* _listaScari)
	{
		this->denumire = _denumire;
		this->adresa = _adresa;
		if (_nrScari > 0 && _listaScari != nullptr)
		{
			this->nrScari = _nrScari;
			this->listaScari = new Scara[this->nrScari];
			for (int i = 0; i < this->nrScari; i++)
				this->listaScari[i] = _listaScari[i];
		}
		else
		{
			this->listaScari = nullptr;
			this->nrScari = 0;
		}
	}

	friend ostream& operator<<(ostream& out, const Bloc& b)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nDenumire bloc: " << b.denumire;
		out << "\nAdresa: " << b.adresa;
		out << "\nNr scari: " << b.nrScari << ", care sunt:";
		for (int i = 0; i < b.nrScari; i++)
			out << b.listaScari[i];
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

	Scara operator[](int index)
	{
		if (index < this->nrScari && index>0)
		{
			return this->listaScari[index];
		}
		else throw new exception("\nIndexul nu e valid");
	}

	~Bloc()
	{
		if (this->listaScari != nullptr)
		{
			delete[]this->listaScari;
			this->listaScari = nullptr;
		}
	}

};

string Bloc::tara = "Romania";

int main()
{
	Scara scara1;
	Scara scara2("A", 10, 35);
	Scara scara3("B", 20, 65);
	Scara scara4("C", 5, 20);
	Scara scara5("D", 6, 27);
	Scara listaScari[] = { scara1,scara2,scara3,scara4,scara5 };


	Bloc bloc1;
	Bloc bloc2("Bloc2", "Slatina", 4, listaScari);
	Bloc bloc3("Bloc3", "Bucuresti", 2, listaScari);
	Bloc bloc4("Bloc4", "Galati", 3, listaScari);

	cout << bloc1 << bloc2 << bloc3 << bloc4;

	cout<<bloc2[2];
	return 0;
}