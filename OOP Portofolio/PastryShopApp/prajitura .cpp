#include <iostream>
using namespace std;

class Prajitura {
	const int id;
	char* den;
	int nrIng;
	float* grIng;
	bool esteVeg;
	static int pretMin;
public:

	//constructor fara param
	Prajitura():id(++Prajitura::pretMin)
	{
		this->den = new char[strlen("Prajitura") + 1];
		strcpy_s(this->den, strlen("Prajitura") + 1, "Prajitura");
		this->nrIng = 0;
		this->grIng = nullptr;
		this->esteVeg = true;
	}


	//constructor cu param
	Prajitura(char* _den, int _nrIng, float* _grIng, bool _esteVeg) :id(++Prajitura::pretMin)
	{
		if (_den != nullptr) {
			this->den = new char[strlen(_den) + 1];
			strcpy_s(this->den, strlen(_den) + 1, _den);
		}
		else this->den = nullptr;
		if (_nrIng > 0)
			this->nrIng = _nrIng;
		else this->nrIng = 0;
		if (_nrIng > 0 && _grIng != nullptr)
		{
			for(int i=0;i<_nrIng;i++)
				if(_grIng[i]>0)
				{
					this->grIng = new float[this->nrIng];
					for (int i = 0; i < this->nrIng; i++)
						this->grIng[i] = _grIng[i];
				}
		}
		else this->grIng = nullptr;
		this->esteVeg = _esteVeg;
	}

	//destructorul
	~Prajitura()
	{
		cout << endl;
		cout << "\nApel destructor!";
		if (this->den != nullptr)
		{
			delete[]this->den;
			this->den = nullptr;
		}
		if (this->nrIng != 0 && this->grIng != nullptr)
		{
			delete[]this->grIng;
			this->grIng = nullptr;
		}
	}

	//supraincarcarea operatorului cout
	friend ostream& operator<<(ostream& out,const Prajitura& p)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\nId: " << p.id;
		out << "\nDenumire prajitura: " << p.den;
		out << "\nNr ingrediente: " << p.nrIng;
		out << "\nGramaj ingrediente :" << endl;
		for (int i = 0; i < p.nrIng; i++)
			out << p.grIng[i] << "  ";
		out << "\nEste vegana :" << p.esteVeg;
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

	friend istream& operator>>(istream& in, Prajitura& p)
	{
		cout << "\nIntroduceti denumire: ";
		char buffer[100]; // Buffer temporar pentru citirea denumirii
		in >> ws; // Eliminăm caracterele de spațiu rămase
		in.getline(buffer, 100);

		// Eliberăm memoria existentă și copiem noua denumire
		if (p.den != nullptr) {
			delete[] p.den;
			p.den = nullptr;
		}
		p.den = new char[strlen(buffer) + 1];
		strcpy_s(p.den, strlen(buffer) + 1, buffer);

		cout << "Introduceti nr ingrediente: ";
		int x;
		in >> x;

		// Gestionăm memoria pentru grIng
		if (x > 0) {
			p.nrIng = x;
			if (p.grIng != nullptr) {
				delete[] p.grIng; // Eliberăm memoria anterioară
				p.grIng = nullptr;
			}
			p.grIng = new float[p.nrIng]; // Alocăm memoria pentru gramaje
			cout << "Introduceti gramajele ingredientelor: ";
			for (int i = 0; i < x; i++) {
				in >> p.grIng[i];
			}
		}
		else {
			p.nrIng = 0;
			if (p.grIng != nullptr) {
				delete[] p.grIng;
				p.grIng = nullptr;
			}
		}

		cout << "Introduceti valoarea de adevar daca e vegetariana (1 pentru Da, 0 pentru Nu): ";
		in >> p.esteVeg;

		return in;
	}


	Prajitura& operator=(const Prajitura& p)
	{
		if(this!=&p)
		{
			if (this->den != nullptr)
			{
				delete[]this->den;
				this->den = nullptr;
			}
			if (this->nrIng != 0 && this->grIng != nullptr)
			{
				delete[]this->grIng;
				this->grIng = nullptr;
			}
			if (p.den != nullptr) {
				this->den = new char[strlen(p.den) + 1];
				strcpy_s(this->den, strlen(p.den) + 1, p.den);
			}
			else this->den = nullptr;
			if (p.nrIng > 0)
				this->nrIng = p.nrIng;
			else this->nrIng = 0;
			if (p.nrIng > 0 && p.grIng != nullptr)
			{
				for (int i = 0; i < p.nrIng; i++)
					if (p.grIng[i] > 0)
					{
						this->grIng = new float[this->nrIng];
						for (int i = 0; i < this->nrIng; i++)
							this->grIng[i] = p.grIng[i];
					}
			}
			else
			{
				this->grIng = nullptr;
				this->esteVeg = p.esteVeg;
			}
		}
		return *this;
	}
	
	int getId()
	{
		return this->id;
	}
	static int getPretMin()
	{
		return Prajitura::pretMin;
	}
	static void setPretMin(int _pret)
	{
		if (_pret > 100 && _pret < 1000)
			Prajitura::pretMin = _pret;

	}

	float getGramajTotal()
	{
		float gtotal = 0;
		for (int i = 0; i < this->nrIng; i++)
			gtotal += grIng[i];
		return gtotal;
	}

	Prajitura (const Prajitura& p):id(++Prajitura::pretMin)
	{
		if (p.den != nullptr) {
			this->den = new char[strlen(p.den) + 1];
			strcpy_s(this->den, strlen(p.den) + 1, p.den);
		}
		else this->den = nullptr;
		if (p.nrIng > 0)
			this->nrIng = p.nrIng;
		else this->nrIng = 0;
		if (p.nrIng > 0 && p.grIng != nullptr)
		{
			for (int i = 0; i < p.nrIng; i++)
				if (p.grIng[i] > 0)
				{
					this->grIng = new float[this->nrIng];
					for (int i = 0; i < this->nrIng; i++)
						this->grIng[i] = p.grIng[i];
				}
		}
		else
		{
			this->grIng = nullptr;
			this->esteVeg = p.esteVeg;
		}
	}

	Prajitura& operator*=(int _multiplicator)
	{
		if (_multiplicator > 0 && this->grIng != nullptr)
			for (int i = 0; i < this->nrIng; i++)
				this->grIng[i] *= _multiplicator;
		return *this;
	}
};

int Prajitura::pretMin = 100;

int main()
{
	char* den1 = new char[strlen("Amandina") + 1];
	strcpy_s(den1, strlen("Amandina") + 1, "Amandina");
	float* grIng = new float[4] { 100.5, 200.6, 300.7, 400.8 };

	Prajitura p1;
	cout << p1;

	Prajitura p2(den1, 4, grIng, false);
	cout << p2;

	Prajitura p3;
	//cin >> p3;
	cout << p3;
	cout << endl << "Id-ul este :" << p3.getId();
	cout << endl << "Pretul minim este :" << Prajitura::getPretMin();

	Prajitura::setPretMin(200);
	cout << endl << "Pretul minim este :" << Prajitura::getPretMin();

	cout << endl <<"Gramajul total este:"<< p2.getGramajTotal();

	p2 *= 10;
	cout << p2;




	/*p2 = p3;
	cout << p2;*/


	
	return 0;
}