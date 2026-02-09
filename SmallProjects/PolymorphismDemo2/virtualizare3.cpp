#include <iostream>
using namespace std;

class Angajat {
public:
	string nume;
	
	virtual void functie()
	{
		cout <<endl<< this->nume<<"  este angajat!";
	}
};

class Director: public Angajat  {
public:
	string nume;
	void functie()
	{
		cout << endl<<this->nume << "  este directorul!";

	}
};

class Executant :public Angajat{
public:
	string nume;
	void functie()
	{
		cout << endl<< this->nume << " este executant!";
	}
};


int main()
{
	Angajat a;
	a.nume = "Gigel";
	a.functie();

	Executant e;
	e.nume = "Costel";
	e.functie();

	Director d;
	d.nume = "Iulian";
	d.functie();

	Angajat* pa = &e;
	pa->functie();

	Angajat* a2 = &d;
	a2->functie();


	return 0;
}