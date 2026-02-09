#include <iostream>
using namespace std;


enum TipuriDeProduse {
	CARNEPROASPATA, CARNECONGELATA , PRODUSEDINCARNE , PREPARATEINSTANT, PRODUSECUSERVIREINSTANT
};

struct Data {
	int zi=0;
	int luna=0;
	int an=0;

	friend ostream& operator<<(ostream& out, const Data &data)
	{
		out << data.zi << "." << data.luna << '.' << data.an;
		return out;
	}

	bool operator!=(Data d)
	{
		bool succes = 1;
		if (d.an != this->an)
			succes = 0;
		if (d.luna != this->luna)
			succes = 0;
		if (d.zi != this->zi)
			succes = 0;
		return succes;

	 }
};

class TipDeCarne {
	string provenienta = "-";
	float pret = 0;
	Data dataExp;
	static int cantitateMinima;
public:
	TipDeCarne() {}

	TipDeCarne(string _provenienta, float _pret, Data _dataExp)
	{
		this->provenienta = _provenienta;
		this->pret = _pret;
		this->dataExp = _dataExp;
	}

	friend ostream& operator<<(ostream& out, const TipDeCarne& c)
	{
		out << "\nProvienenta: " << c.provenienta << " , Pret: " << c.pret
			<< " , Data expirarii "
			<< c.dataExp;
		return out;
	}

	TipDeCarne operator*=(float reducere)
	{
		if (reducere > 0 && reducere < 1)
		{
			this->pret = this->pret - (this->pret * reducere);
		}
			return *this;
	}

	 bool operator==(TipDeCarne &c)
	{
		 bool succes = 0;
		 if (this->dataExp != c.dataExp)
			 succes = 1;
		 if (this->pret != c.pret)
			 succes = 1;
		 if (c.provenienta != this->provenienta)
			 succes = 1;
		 return succes;
	}
};


class Comanda {
	TipuriDeProduse tipDeProduse[5];
	int nrTipCarne = 0;
	TipDeCarne* tipuriDeCarne = nullptr;
public:

	Comanda() {}

	Comanda(TipuriDeProduse _tipDeProduse[5], int _nrTipCarne, TipDeCarne* _tipuriDeCarne)
	{
		for (int i = 0; i < 5; i++)
			this->tipDeProduse[i] = _tipDeProduse[i];
		if (_nrTipCarne > 0 && _tipuriDeCarne != nullptr)
		{
			this->nrTipCarne = _nrTipCarne;
			this->tipuriDeCarne = new TipDeCarne[this->nrTipCarne];
			for (int i = 0; i < this->nrTipCarne; i++)
				this->tipuriDeCarne[i] = _tipuriDeCarne[i];

		}
		else
		{
			this->nrTipCarne = 0;
			this->tipuriDeCarne = nullptr;
		}

	}

	Comanda(const Comanda& m)
	{
		for (int i = 0; i < 5; i++)
			this->tipDeProduse[i] = m.tipDeProduse[i];
		this->nrTipCarne = m.nrTipCarne;
		this->tipuriDeCarne = new TipDeCarne[this->nrTipCarne];
		for (int i = 0; i < this->nrTipCarne; i++)
			this->tipuriDeCarne[i] = m.tipuriDeCarne[i];
	}

	Comanda& operator=(const Comanda& m)
	{
		if (this != &m)
		{
			if (this->tipuriDeCarne != nullptr)
			{
				delete[]this->tipuriDeCarne;
				this->tipuriDeCarne = nullptr;
			}
			for (int i = 0; i < 5; i++)
				this->tipDeProduse[i] = m.tipDeProduse[i];
			this->nrTipCarne = m.nrTipCarne;
			this->tipuriDeCarne = new TipDeCarne[this->nrTipCarne];
			for (int i = 0; i < this->nrTipCarne; i++)
				this->tipuriDeCarne[i] = m.tipuriDeCarne[i];
		}
		return *this;
	}

	~Comanda()
	{
		if (this->tipuriDeCarne != nullptr)
		{
			delete[]this->tipuriDeCarne;
			this->tipuriDeCarne = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const Comanda& c)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nTipuri de produse ale comenzii:";
		for (int i = 0; i < 5; i++)
			out << c.tipDeProduse[i] << "\t";
		out << "\nNumarul de tipuri de carne ale comenzii este : " << c.nrTipCarne;
		for (int i = 0; i < c.nrTipCarne; i++)
			out << c.tipuriDeCarne[i] << "\t";
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

	
};



int cantitateMinima = 500;

int main()
{
	TipDeCarne c1("Pui", 20, {26,12,2024});
	TipDeCarne c2("Vita", 40, {28,12,2024});
	TipDeCarne c3("Porc", 30, { 29, 12,2024 });
	TipDeCarne c4;
	TipDeCarne c5("Miel", 35, {12,01,2025});

	TipuriDeProduse vector[] = { CARNECONGELATA ,CARNECONGELATA , CARNEPROASPATA , PREPARATEINSTANT , PRODUSECUSERVIREINSTANT,
	CARNEPROASPATA };
	TipDeCarne* vector2 = new TipDeCarne[5]{ c1,c2,c3,c4,c5 };
	TipDeCarne vector3[] = { c1,c2,c3 };
	Comanda p1(vector, 3, new TipDeCarne[3]{c1,c2,c3});

	Comanda p2(vector, 5, new TipDeCarne[5]{ c1,c2,c3,c4,c5 });
	Comanda p3(vector, 2, vector3);
	cout << p1 << p2 << p3;

	cout << endl;
	cout << c2;
	c2 *= 0.1;
	cout << c2;

	TipDeCarne c6(c2);

	cout <<endl<< boolalpha << (c6 == c2);

	return 0;
}