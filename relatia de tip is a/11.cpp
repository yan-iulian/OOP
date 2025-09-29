#include <iostream>
using namespace std;

class Angajat {

protected :
	string nume = "_";
	float salariuBaza = 0;
public:

	Angajat() {}

	Angajat(string _nume, float _salariuBaza)
	{
		this->nume = _nume;
		this->salariuBaza = _salariuBaza;
	}

	Angajat(const Angajat &a) {
		this->nume = a.nume;
		this->salariuBaza = a.salariuBaza;
	}

	Angajat& operator=(const Angajat& a)
	{
		if (&a != this) {
			this->nume = a.nume;
			this->salariuBaza = a.salariuBaza;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Angajat& a) {
		out << "\nNume: " << a.nume;
		out << "\nSalariu baza: " << a.salariuBaza;
		return out;
	}

	float calculSalariu()
	{
		return this->salariuBaza;
	}

};

enum Functie {
	ASISTENT, CONFERENTIAL, LECTOR, PROF
};

class CadruDidactic :public Angajat{
	Functie functie = Functie::ASISTENT;
	int nrOreSuplimentare = 0;
	char* departament = nullptr;
	static float tarifOrar;
public:
	CadruDidactic() {}

	CadruDidactic(string _nume, float _salariuBaza, Functie _functie, int _nrOreSuplimentare, char* _departament) :Angajat(_nume, _salariuBaza)
	{
		this->functie = _functie;
		this->nrOreSuplimentare = _nrOreSuplimentare;
		if (_departament != nullptr)
		{
			this->departament = new char[strlen(_departament) + 1];
			strcpy_s(this->departament, strlen(_departament) + 1, _departament);

		}
	}

	CadruDidactic(const CadruDidactic &c):Angajat(c.nume, c.salariuBaza)
	{
		this->functie = c.functie;
		this->nrOreSuplimentare = c.nrOreSuplimentare;
		if (c.departament != nullptr)
		{
			this->departament = new char[strlen(c.departament) + 1];
			strcpy_s(this->departament, strlen(c.departament) + 1, c.departament);

		}
	}

	CadruDidactic& operator=(const CadruDidactic& c)
	{
		if (&c != this) {
			Angajat::operator=(c);
			if (this->departament != nullptr)
			{
				delete[]this->departament;
				this->departament = nullptr;

			}
			this->functie = c.functie;
			this->nrOreSuplimentare = c.nrOreSuplimentare;
			if (c.departament != nullptr)
			{
				this->departament = new char[strlen(c.departament) + 1];
				strcpy_s(this->departament, strlen(c.departament) + 1, c.departament);

			}
		}
		return *this;
	}
	
	~CadruDidactic()
	{
		if (this->departament != nullptr)
		{
			delete[]this->departament;
			this->departament = nullptr;

		}
	}

	friend ostream& operator<<(ostream& out, const CadruDidactic& c) {
		out << (Angajat)c;
		out << "\nFunctie didactica: " << c.functie;
		out << "\nNr ore suplimentare: " << c.nrOreSuplimentare;
		if (c.departament != nullptr)
			out << "\nDepartament: " << c.departament;
		else
			out << "\nDepartament: -";
		return out;
	}



};


int main()
{

	return 0;
}