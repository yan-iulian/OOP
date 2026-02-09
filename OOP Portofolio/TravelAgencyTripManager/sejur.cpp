#include <iostream>
using namespace std;

void sortare(int n, float* v)
{
	float aux;
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<n;j++)
			if (v[i] < v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;

			}
	}
}

float gasireMax(int n, float * v)
{
	float max = v[0];
	for (int i = 0; i < n; i++)
		if (v[i] > max)
			max = v[i];
	return max;
}

class Sejur {
	const int id;
	string destinatie;
	float pretBaza;
	int nrExcOpt;
	float* pretExOpt;

public:

	Sejur(int _id) :id(_id) {
		this->destinatie = "--";
		this->pretBaza = 0;
		this->nrExcOpt = 0;
		this->pretExOpt = nullptr;
	}

	Sejur(int _id, string _destinatie, float _pretBaza, int _nrExcOpt, float* _pretExcOpt) :id(_id)
	{
		if (_destinatie != " ") this->destinatie = _destinatie;
		else this->destinatie = "--";
		if (_pretBaza > 0)
			this->pretBaza = _pretBaza;
		else this->pretBaza = 0;
		if (_nrExcOpt != 0 && _pretExcOpt != nullptr)
		{
			this->nrExcOpt = _nrExcOpt;
			this->pretExOpt = new float[this->nrExcOpt];
			for (int i = 0; i < this->nrExcOpt; i++)
				this->pretExOpt[i] = _pretExcOpt[i];
		}
		else
		{
			this->nrExcOpt = 0;
			this->pretExOpt = nullptr;
		}
	}

	~Sejur()
	{
		cout << "\nS a apelat destructorul!";
		if (this->pretExOpt != nullptr)
		{
			delete[]this->pretExOpt;
			this->pretExOpt = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const Sejur& s)
	{
		out << "\n--------------------------";
		out << "\nDestinatie sejur : " << s.destinatie;
		out << "\nPret sejur: " << s.pretBaza;
		out << "\nNr excursii optionale: " << s.nrExcOpt;
		out << "\nPreturile pentru fiecare excursie optionala : ";
		for (int i = 0; i < s.nrExcOpt; i++)
			out << s.pretExOpt[i] << "  ";
		out << "\n----------------------------";
		return out;
	}

	friend istream& operator>>(istream& in, Sejur& s)
	{
		cout << "\nIntroduceti datele despre obiectul pe care il creeati!" << "\nIntroduceti destinatia de sejur:";
		in >> s.destinatie;
		cout << "\nIntroduceti pretul de la care pleaca sejurul: ";
		in >> s.pretBaza;
		cout << "\nIntroduceti nr de excursii optionale: ";
		int x;
		cin >> x;
		if (x <= 0) {
			s.pretExOpt = nullptr;
			s.nrExcOpt = 0;
		}
		else {
			s.nrExcOpt = x;
			if (s.pretExOpt != nullptr)
			{
				delete[]s.pretExOpt;
				s.pretExOpt = nullptr;
			}
			s.pretExOpt = new float[s.nrExcOpt];
			for (int i = 0; i < s.nrExcOpt; i++)
			{
				cout << "\nPretul excursiei " << i+1 << " este: ";
				in >> s.pretExOpt[i];
			}
		}
		return in;
	}

	Sejur(const  Sejur& s):id(s.id)
	{
		if (s.destinatie != " ") this->destinatie = s.destinatie;
		else this->destinatie = "--";
		if (s.pretBaza > 0)
			this->pretBaza = s.pretBaza;
		else this->pretBaza = 0;
		if (s.nrExcOpt != 0 && s.pretExOpt != nullptr)
		{
			this->nrExcOpt = s.nrExcOpt;
			this->pretExOpt = new float[this->nrExcOpt];
			for (int i = 0; i < this->nrExcOpt; i++)
				this->pretExOpt[i] = s.pretExOpt[i];
		}
		else
		{
			this->nrExcOpt = 0;
			this->pretExOpt = nullptr;
		}
	}

	Sejur& operator=(const Sejur& s)
	{
		if (this->pretExOpt != nullptr)
		{
			delete[]this->pretExOpt;
			this->pretExOpt = nullptr;
		}
		if (s.destinatie != " ") this->destinatie = s.destinatie;
		else this->destinatie = "--";
		if (s.pretBaza > 0)
			this->pretBaza = s.pretBaza;
		else this->pretBaza = 0;
		if (s.nrExcOpt != 0 && s.pretExOpt != nullptr)
		{
			this->nrExcOpt = s.nrExcOpt;
			this->pretExOpt = new float[this->nrExcOpt];
			for (int i = 0; i < this->nrExcOpt; i++)
				this->pretExOpt[i] = s.pretExOpt[i];
		}
		else
		{
			this->nrExcOpt = 0;
			this->pretExOpt = nullptr;
		}
		return *this;
	}

	int getNrMaxExcursii(float bugetMaxSejur)
	{
		if (bugetMaxSejur == this->pretBaza)
			return 0;
		int contor = 0;
		float bugetIntermediar = this->pretBaza;
		sortare(this->nrExcOpt, this->pretExOpt);
		for (int i = 0; i < this->nrExcOpt; i++)
		{
			if (bugetIntermediar + this->pretExOpt[i] < bugetMaxSejur)
			{
				contor++;
				bugetIntermediar += pretExOpt[i];
			}
		}
		return contor;
	}

	explicit operator float ()const
	{
		float suma = 0;
			for (int i = 0; i < this->nrExcOpt; i++)
				suma += this->pretExOpt[i];
			return suma;
	}

	bool operator<(float pret)
	{
		float max = gasireMax(this->nrExcOpt, this->pretExOpt);
		if (max < pret)
			return true;
		else
			return false;
	}


	Sejur& operator++()
	{
		this->pretExOpt[this->nrExcOpt - 1]++;
		return *this;
	}

	/*Sejur operator++(int)
	{
		Sejur copie = *this;
		this->pretExOpt[this->nrExcOpt - 1]++;
		return copie;
	}*/

	 Sejur operator--(int)
	{
		 Sejur rez = *this;
		 if (rez.pretExOpt != nullptr)
		 {
			 delete[]rez.pretExOpt;
			 rez.pretExOpt = nullptr;
		 }
		 rez.pretExOpt = new float[rez.nrExcOpt - 1];
		 float min = rez.pretExOpt[0];
		 for (int i = 0; i < rez.nrExcOpt; i++)
			 if (rez.pretExOpt[i] < min)
				 min = rez.pretExOpt[i];
		 for (int i = 0; i < rez.nrExcOpt; i++)
			 if (rez.pretExOpt[i] != min)
				 rez.pretExOpt[i] = this->pretExOpt[i];
		 rez.nrExcOpt--;




		 return rez;
	}

};

bool operator<=(float pret, Sejur& s)
{
	if (s < pret)
		return false;
	else return true;
 }



int main()
{
	cout << "Apel const fara param";
	Sejur s1(0);

	float valori[5] = { 20,10,30,40,50};
	Sejur s2(1, "Cote d'Azure", 200, 5, valori);
	cout << s1;
	cout << s2;

	//Sejur s3(12);
	///*cin >> s3;
	//cout << s3;*/


	///*sortare(5, valori);
	//for (int i = 0; i < 5; i++)
	//	cout << valori[i] << "  ";*/

	//cout << "\nNr max de excursii pe care le poate face un cumparator al sejurului 2 este : " <<
	//	s2.getNrMaxExcursii(211);
	//cout << s2;
	//cout <<"\nPretul maxim al excursiilor este : "<< float(s2);

	//cout << "\nCumparatoru isi permite toate excursiile? (1 da si 0 nu)" << (s2 < 2000) << "  " << (2000 <= s2);
	//
	/*s1 = s2++;
	cout << s2;
	cout << s1;*/
	
	s1=s2--;
	cout << s1;
	cout << s2;


		
		return 0;
}
