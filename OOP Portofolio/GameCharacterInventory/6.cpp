#include <iostream>
using namespace std;

enum TipPersonaj
{
	BUN , RAU , ADJUVANT
};

class Rucsac
{
	string culoare = "-";
	float capacitateMaxima=0;
public:
	Rucsac()
	{

	}

	Rucsac(string _culoare, float _capacitateMaxima) {
		this->culoare = _culoare;
		this->capacitateMaxima = _capacitateMaxima;
	}

};

class Om {
public:
	void saluta()
	{
		cout << "Salut!";
	}
	virtual void prezinta() = 0;
	

};
class Personaj : public Om{
	string nume="-";
	TipPersonaj tp=TipPersonaj::BUN;
	int nrBagaje=0;
	float* greutate=nullptr;
	Rucsac rucsac;

public:

	Personaj() {}

	Personaj(string _nume, TipPersonaj _tp, int _nrBagaje, float* _greutate)
	{
		this->nume = _nume;
		this->tp = _tp;
		if (_nrBagaje > 0 && _greutate != nullptr)
		{
			this->nrBagaje=_nrBagaje;
			this->greutate = new float[this->nrBagaje];
			for (int i = 0; i < this->nrBagaje; i++)
				this->greutate[i] = _greutate[i];
		}
		else
		{
			this->nrBagaje = 0;
			this->greutate = nullptr;
		}
	}


	Personaj(string _nume, TipPersonaj _tp, int _nrBagaje, float* _greutate,string _culoare, float _cpm):rucsac(_culoare,_cpm)
	{
		this->nume = _nume;
		this->tp = _tp;
		if (_nrBagaje > 0 && _greutate != nullptr)
		{
			this->nrBagaje = _nrBagaje;
			this->greutate = new float[this->nrBagaje];
			for (int i = 0; i < this->nrBagaje; i++)
				this->greutate[i] = _greutate[i];
		}
		else
		{
			this->nrBagaje = 0;
			this->greutate = nullptr;
		}

	}

	~Personaj()
	{
		if (this->greutate != nullptr)
		{
			delete[]this->greutate;
			this->greutate = nullptr;
		}
	}

	Personaj(const Personaj & p)
	{
		this->nume = p.nume;
		this->tp = p.tp;
		if (p.nrBagaje > 0 && p.greutate != nullptr)
		{
			this->nrBagaje = p.nrBagaje;
			this->greutate = new float[this->nrBagaje];
			for (int i = 0; i < this->nrBagaje; i++)
				this->greutate[i] = p.greutate[i];
		}
		else
		{
			this->nrBagaje = 0;
			this->greutate = nullptr;
		}
	}

	Personaj& operator=(const Personaj& p)
	{
		if (this != &p)
		{
			if (this->greutate != nullptr)
			{
				delete[]this->greutate;
				this->greutate = nullptr;
			}
			this->nume = p.nume;
			this->tp = p.tp;
			if (p.nrBagaje > 0 && p.greutate != nullptr)
			{
				this->nrBagaje = p.nrBagaje;
				this->greutate = new float[this->nrBagaje];
				for (int i = 0; i < this->nrBagaje; i++)
					this->greutate[i] = p.greutate[i];
			}
			else
			{
				this->nrBagaje = 0;
				this->greutate = nullptr;
			}
		}
		return *this;
	}

	TipPersonaj getTipPersonaj()
	{
		return this->tp;
	}

	void setTipPersonaj(TipPersonaj t)
	{
		this->tp = t;
	}

	const float* getGreutate()
	{
		return this->greutate;
	}

	void setGreutate(int _nrBagaje , float *_greutate)
	{
		if (this->greutate != nullptr)
		{
			delete[]this->greutate;
			this->greutate = nullptr;
		}
		if (_nrBagaje > 0 && _greutate != nullptr)
		{
			this->nrBagaje = _nrBagaje;
			this->greutate = new float[this->nrBagaje];
			for (int i = 0; i < this->nrBagaje; i++)
				this->greutate[i] = _greutate[i];
		}
		else
		{
			this->nrBagaje = 0;
			this->greutate = nullptr;
		}
	}

	void CodRosu()
	{
		float bagajMax = greutate[0];
		for (int i = 1; i < this->nrBagaje; i++)
			if (this->greutate[i] > bagajMax)
				bagajMax = this->greutate[i];
		delete[]this->greutate;
		this->greutate = new float(bagajMax);
		this->nrBagaje = 1;
	}
	
	friend ostream& operator<<(ostream& out, const Personaj& p)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nNumele personajului: " << p.nume;
		out << "\nTipul personajului :" << p.tp;
		out << "\nNr de bagaje ale personajului :" << p.nrBagaje;
		out << "\nGreutatea bagajelor : ";
		for (int i = 0; i < p.nrBagaje; i++)
			out << p.greutate[i] << " \t";
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

	bool operator>(double nr)
	{
		float masaTotala = 0;
		for (int i = 0; i < this->nrBagaje; i++)
			masaTotala += this->greutate[i];
		return (double)masaTotala > nr;

	}

	void prezinta()
	{
		cout << "Salut! Eu sunt aventurierul " << this->nume << " !";
	}

};

template <typename T>
class Clasa {
	T vector[20];
	int nrElemente=0;
public:
	Clasa()
	{}

	Clasa(T _vector[20], int _nrElemente)
	{
		if (_nrElemente > 0)
		{
			this->nrElemente = _nrElemente;
			for (int i = 0; i < this->nrElemente; i++)
				this->vector[i] = _vector[i];
		}
	}

	T maxValue()
	{
		T max=vector[0];
		for (int i = 0; i < this->nrElemente; i++)
			if (vector[i] > max)
				max = vector[i];
		return max;
	}
};

int main()
{
	float bagaje[] = { 1,2,3,4,5,6,7 };
	Personaj p1("ROBO", BUN, 6, bagaje);
	cout << p1;
	p1.CodRosu();
	cout << p1;

	cout << endl << boolalpha << (p1 > 3.898);


	cout << endl;
	p1.saluta();

	cout << endl;
	p1.prezinta();

	cout << endl;
	Personaj* pp = new Personaj(p1);
	pp->saluta();

	cout << endl;
	pp->prezinta();

	int vector2[] = { 1, 2,3,4,5 };
	Clasa<int> c1(vector2, 3);
	int a = 0;
	a=c1.maxValue();
	cout << endl << a;

	

	return 0;
}