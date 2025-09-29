#include <iostream>
using namespace std;


class Animal {
public:
	string denumire;
	virtual void sunet()
	{
		cout << "\nAnimalul general face un sunet !";
	}
};

class Pisica :public Animal {
public:
	void sunet() {
		cout << "\nPisica face miau!";
	}
};

class Caine :public Animal {
public:
	void sunet()
	{
		cout << "\nCainele latra!";
	}
};

int main()
{
	Animal a;
	a.sunet();

	Pisica p;
	p.sunet();

	a = p;
	a.sunet();

	cout << "\nFinal!! Incercare 2!";

	Animal* pa;
	pa = &a;
	pa->sunet();


	Pisica* pp;
	pp = &p;
	pp->sunet();

	cout << "\nCu virtualizare:~~~~~~~~~~~~~~~";

	pa = pp;
	pa->sunet();

	return 0;
}