#include <iostream>
using namespace std;

class Locuinta {
	const int id = 0;
	float suprafata=0;
	int nrCamere=0;
	bool* esteZugravita = nullptr;
	bool areEtaj = 0;
public:

	Locuinta() {}
	
	Locuinta ( const int _id, float _suprafata, int _nrCamere, bool* _esteZugravita, bool _areEtaj):id(_id)
	{
		if (_suprafata > 0)
			this->suprafata = _suprafata;
		if (_nrCamere > 0 && _esteZugravita != nullptr)
		{
			this->nrCamere = _nrCamere;
			this->esteZugravita = new bool[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
				this->esteZugravita[i] = _esteZugravita[i];
		}
		this->areEtaj = _areEtaj;

	}

	~Locuinta()
	{
		if (this->esteZugravita != nullptr)
		{
			delete[]this->esteZugravita;
			this->esteZugravita = nullptr;
		}
	}
	const int getId()
	{
		return this->id;
	}

	const bool* getEsteZugravita()
	{
		return this->esteZugravita;
	}

	int getNrCamere()
	{
		return this->nrCamere;
	}

	float getSuprafata()
	{
		return this->suprafata;
	}

	bool getAreEtaj()
	{
		return this->areEtaj;
	}

	void setParamC(int _nrCamere, bool* _esteZugravita)
	{
		if (this->esteZugravita != nullptr)
		{
			delete[]this->esteZugravita;
			this->esteZugravita = nullptr;
		}
		if (_nrCamere > 0 && _esteZugravita != nullptr)
		{
			this->nrCamere = _nrCamere;
			this->esteZugravita = new bool[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
				this->esteZugravita[i] = _esteZugravita[i];
		}
		else
		{
			this->nrCamere = 0;
			this->esteZugravita = nullptr;
		}

	}

	Locuinta(const Locuinta& l) :id(l.id)
	{

		this->suprafata = l.suprafata;
		this->nrCamere = l.nrCamere;
		this->esteZugravita = new bool[this->nrCamere];
		for (int i = 0; i < this->nrCamere; i++)
			this->esteZugravita[i] = l.esteZugravita[i];
		this->areEtaj = l.areEtaj;
	}

	Locuinta& operator=(const Locuinta& l)
	{
		if (&l != this)
		{
			if (this->esteZugravita != nullptr)
			{
				delete[]this->esteZugravita;
				this->esteZugravita = nullptr;
			}
			this->suprafata = l.suprafata;
			this->nrCamere = l.nrCamere;
			this->esteZugravita = new bool[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
				this->esteZugravita[i] = l.esteZugravita[i];
			this->areEtaj = l.areEtaj;
		}
		return *this;
	}
	
	friend ostream& operator<<(ostream& out, const Locuinta& l)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nId ul locuintei: " << l.id;
		out << "\nSuprafata locuintei: " << l.suprafata;
		out << "\nNr de camere al locuintei: " << l.nrCamere;
		out << "\nLista de camere zugravite : ";
		for (int i = 0; i < l.nrCamere; i++)
			out << l.esteZugravita[i] << ' ';
		out << "\nAre etaj :   " << l.areEtaj;
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

	bool operator()(int nrLocatari)
	{
		if (this->nrCamere != nrLocatari)
			return false;
		else return true;
	}

	bool operator==(const Locuinta& l)
	{
		bool succes = 1;
		if (this->suprafata != l.suprafata)
			succes = 0;
		if (this->nrCamere != l.nrCamere)
			succes = 0;
		else
		{
			for (int i = 0; i < this->nrCamere; i++)
				if (this->esteZugravita[i] != l.esteZugravita[i])
					succes = 0;
		}
		if (this->areEtaj != l.areEtaj)
			succes = 0;
		if (succes == 1) return true;
		else return false;

	}
};

class Apartament:public Locuinta {
	int nrBloc=0;
	string scara="-";
	int etaj=0;
	int nrApartament=0;
public:
	Apartament(){}
	
	Apartament(int _id, float _suprafata, int _nrCamere, bool* _esteZugravit, bool _areEtaj,
		int _nrBloc, string _scara, int _etaj, int _nrApartament):Locuinta(_id, _suprafata, _nrCamere, _esteZugravit, 
			_areEtaj)
	{
		if (_nrBloc > 0)
			this->nrBloc = _nrBloc;
		if (_scara != " ")
			this->scara = _scara;
		if (_etaj >= 0)
			this->etaj = _etaj;
		if (nrApartament > 0)
			this->nrApartament = _nrApartament;

	}

	friend ostream& operator<<(ostream& out, const Apartament& a)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << (Locuinta)a;
		out << "\nNr blocului este :" << a.nrBloc;
		out << "\nDenumirea scarei este : " << a.scara;
		out << "\nNr etajului este : " << a.etaj;
		out << "\nNr apartamentului este : " << a.nrApartament;
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}
};

class Casa {

};


int main()
{
	bool vector[] = { 1,0,1,1,0 };

	Locuinta l1(1, 200, 5, vector, 1);
	Locuinta l2;

	cout << l1 << l2;

	/*Locuinta l3(l1);
	Locuinta l4;
	l4 = l1;
	cout << l3 << l4;*/

	cout << "\nApel operatorul functie :";
	cout <<l1.operator()(8);
	
	cout << endl << "Prima locuinta e aceeasi cu a doua? " << (l2 == l1);

	Apartament a1(3, 120, 3, vector,1, 5, "BC12", 3, 4);
	cout << a1;

	l1 = a1;

	
	return 0;
}