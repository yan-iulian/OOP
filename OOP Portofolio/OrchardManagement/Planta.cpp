#include <iostream>
using namespace std;

class Plantatie {
private:
	const int id;
	string adresa;
	int nrPomi;
	int* varsta;
	static int varstaMinimaRod;
public:
	Plantatie(int _id):id(_id)
	{
		this->adresa = "-";
		this->nrPomi = 0;
		this->varsta = nullptr;
	}

	Plantatie(int _id, string _adresa, int _nrPomi, int* _varsta):id(_id)
	{
		if (_adresa != " ")
			this->adresa = _adresa;
		else this->adresa = "-";
		if (_nrPomi != 0 && _varsta != nullptr)
		{
			if (this->varsta != nullptr)
			{
				delete[]this->varsta;
				this->varsta = nullptr;
			}
			this->nrPomi = _nrPomi;
			this->varsta = new int[this->nrPomi];
			for (int i = 0; i < this->nrPomi; i++)
				this->varsta[i] = _varsta[i];
		}
		else
		{
			this->nrPomi = 0;
			this->varsta = nullptr;
		}
	}

	Plantatie(const Plantatie& p) :id(p.id)
	{
		if (p.adresa != " ")
			this->adresa = p.adresa;
		else this->adresa = "-";
		if (p.nrPomi != 0 && p.varsta != nullptr)
		{
			if (this->varsta != nullptr)
			{
				delete[]this->varsta;
				this->varsta = nullptr;
			}
			this->nrPomi = p.nrPomi;
			this->varsta = new int[this->nrPomi];
			for (int i = 0; i < this->nrPomi; i++)
				this->varsta[i] = p.varsta[i];
		}
		else
		{
			this->nrPomi = 0;
			this->varsta = nullptr;
		}
	}

	Plantatie& operator=(const Plantatie& p)
	{
		if(this!=&p)
		{
			if (this->varsta != nullptr)
			{
				delete[]this->varsta;
				this->varsta = nullptr;
			}
			if (p.adresa != " ")
				this->adresa = p.adresa;
			else this->adresa = "-";
			if (p.nrPomi != 0 && p.varsta != nullptr)
			{
				if (this->varsta != nullptr)
				{
					delete[]this->varsta;
					this->varsta = nullptr;
				}
				this->nrPomi = p.nrPomi;
				this->varsta = new int[this->nrPomi];
				for (int i = 0; i < this->nrPomi; i++)
					this->varsta[i] = p.varsta[i];
			}
			else
			{
				this->nrPomi = 0;
				this->varsta = nullptr;
			}
		}
		return *this;
		
	}


	int* getVarsta()
	{
		return this->varsta;
	}
	string getAdresa()
	{
		return this->adresa;
	}
	void setAdresa(string _adresa)
	{
		if(_adresa!=" ")
			this->adresa = _adresa;
	}
	void setValori(int _nrPomi, int* _varsta)
	{
		if(_nrPomi!=0&&_varsta!=nullptr)
		{
			if (this->varsta != nullptr)
			{
				delete[]this->varsta;
				this->varsta = nullptr;
			}
			this->nrPomi = _nrPomi;
			this->varsta = new int[this->nrPomi];
			for (int i = 0; i < this->nrPomi; i++)
				this->varsta[i] = _varsta[i];
		}
		else
		{
			this->nrPomi = 0;
			this->varsta = nullptr;
		}

	}



	~Plantatie()
	{
		cout << "\nS a apelat destructorul!";
		if (this->varsta != nullptr)
		{
			delete[]this->varsta;
			this->varsta = nullptr;
		}
	}

	int getNrPomiVarstaMinima(int Vmin)
	{
		int nr = 0;
		for (int i = 0; i < this->nrPomi; i++)
			if (this->varsta[i] >= Vmin)
				nr++;
		return nr;
	}

	friend Plantatie operator+(float x, const Plantatie& p)
	{
		Plantatie rez = p;
		if (x > 0)
		{
			if (rez.varsta != nullptr)
			{
				delete[]rez.varsta;
				rez.varsta = nullptr;
			}
			rez.varsta = new int[p.nrPomi + 1];
			for (int i = 0; i < rez.nrPomi; i++)
				rez.varsta[i] = p.varsta[i];
			rez.varsta[rez.nrPomi] = x;
			rez.nrPomi++;
		}
		return rez;
	}

	friend ostream& operator<<(ostream& out, const Plantatie& p)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nId ul este : " << p.id;
		out << "\nAdresa este :" << p.adresa;
		out << "\nPomi :" << p.nrPomi;
		out << "\nVarsta fiecarui pom este:";
		for (int i = 0; i < p.nrPomi; i++)
			out << p.varsta[i] << "   ";
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

	friend istream& operator>>(istream& in, Plantatie& p)
	{
		cout << "\nIntroduceti adresa: ";
		in >> p.adresa;
		cout << "Introduceti nrPomi:";
		int x;
		in >> x;
		if (x > 0)
		{
			p.nrPomi = x;
			p.varsta = new int[p.nrPomi];
			cout << "Introduceti varstele:";
			for (int i = 0; i < p.nrPomi; i++)
				in >> p.varsta[i];

		}
		return in;
	}

};

int Plantatie::varstaMinimaRod = 3;

int main()
{
	cout << "\n~~~~~~~~~~~Apel constructor fara param ~~~~~~~~~~~~~~~";
	Plantatie p1(20);

	cout << "\nSetam valori pentru p1 si adresa!";
	int valori[5] = { 1,2,3,4,5 };
	p1.setValori(5, valori);
	p1.setAdresa("Slatina");
	cout << "\nGetters ptr adresa si varsta:" << p1.getAdresa() << "     " << p1.getVarsta()[3];


	cout << "\n~~~~~~~~~Apel constructor cu toti parametrii!~~~~~~~~";
	int* valori2 = new int [3] {1, 2, 3};
	Plantatie p2(30, "Caracal", 3, valori2);

	cout << "\nMetoda cu nr de pomi cu varsta minima: ";
	cout<<p2.getNrPomiVarstaMinima(2);

	cout << "\nS a apelat constructorul de copiere!";
	Plantatie p3(p2);

	cout << "\nS a apelat supraincarcarea operatorului =";
	Plantatie p4(10);
	p4 = p2;

	cout << "\nAdaugam un nou pom cu o varsta !";
	p2 = 20 + p2;

	cout << p2;

	Plantatie p10(15);
	cin >> p10;
	cout << p10;




	


	




	delete[]valori2;
	return 0;
}