#include <iostream>
using namespace std;


class Sala {
	const int id;
	string denumire;
	int nrEchipamente;
	bool* stareEchipamente;
	char* numeP;
	static int greutate;
public:


	Sala(int _id) :id(_id)
	{
		this->denumire = "Sala";
		this->nrEchipamente = 0;
		this->stareEchipamente = nullptr;
		this->numeP = new char[strlen("Anonim") + 1];
		strcpy_s(this->numeP,strlen("Anonim")+1, "Anonim");
		/*this->numeP = " ";*/
	}

	Sala(int _id, string _denumire, int _nrEchipamente, bool* _stareEchipamente, char* _numeP) :id(_id)
	{
		this->denumire = _denumire;
		if (_nrEchipamente != 0 && _stareEchipamente != nullptr)
		{
			this->nrEchipamente = _nrEchipamente;
			this->stareEchipamente = new bool[this->nrEchipamente];
			for (int i = 0; i < this->nrEchipamente; i++)
				this->stareEchipamente[i] = _stareEchipamente[i];
		}
		else
		{
			this->nrEchipamente = 0;
			this->stareEchipamente = nullptr;
		}
		/*this->numeP = _numeP;*/
		if (_numeP != nullptr)
		{
			this->numeP = new char[strlen(_numeP) + 1];
			strcpy_s(this->numeP, strlen(_numeP) + 1, _numeP);
		}
		else
		{
			this->numeP = new char[strlen("Anonim") + 1];
			strcpy_s(this->numeP, strlen("Anonim") + 1, "Anonim");
		}
	}

	friend ostream& operator<<(ostream& out, const Sala& s)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nId-ul salii: " << s.id;
		out << "\nDenumirea salii : " << s.denumire;
		out << "\nNr de echipamente din sala: " << s.nrEchipamente;
		out << "\nEchipamentele functionale sunt (1 pentru functionale , 0 pentru nefunctionale) :  ";
		for (int i = 0; i < s.nrEchipamente; i++)
			out << s.stareEchipamente[i] << "  ";
		out << "\nNumele patronului : " << s.numeP;
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}
	~Sala()
	{
		cout << "\nS a apelat destructorul!";
		if (this->stareEchipamente != nullptr)
		{
			delete[]this->stareEchipamente;
			this->stareEchipamente = nullptr;
			}
		if (this->numeP != nullptr)
		{
			delete[]this->numeP;
			this->numeP = nullptr;
		}
	}

	int getNrMaxEchFunc()
	{
		int contor = 0;
		for (int i = 0; i < this->nrEchipamente; i++)
			if (this->stareEchipamente[i] == true)
				contor++;
		return contor;
	}

	Sala(const Sala& s):id(s.id)
	{
		this->denumire = s.denumire;
		if (s.nrEchipamente != 0 && s.stareEchipamente != nullptr)
		{
			this->nrEchipamente = s.nrEchipamente;
			this->stareEchipamente = new bool[this->nrEchipamente];
			for (int i = 0; i < this->nrEchipamente; i++)
				this->stareEchipamente[i] = s.stareEchipamente[i];
		}
		else
		{
			this->nrEchipamente = 0;
			this->stareEchipamente = nullptr;
		}
		/*this->numeP = _numeP;*/
		if (s.numeP != nullptr)
		{
			this->numeP = new char[strlen(s.numeP) + 1];
			strcpy_s(this->numeP, strlen(s.numeP) + 1, s.numeP);
		}
		else
		{
			this->numeP = new char[strlen("Anonim") + 1];
			strcpy_s(this->numeP, strlen("Anonim") + 1, "Anonim");
		}
	}

	Sala& operator=(const Sala& s)
	{
		if (this != &s)
		{
			if (this->stareEchipamente != nullptr)
			{
				delete[]this->stareEchipamente;
				this->stareEchipamente = nullptr;
			}
			if (this->numeP != nullptr)
			{
				delete[]this->numeP;
				this->numeP = nullptr;
			}
			this->denumire = s.denumire;
			if (s.nrEchipamente != 0 && s.stareEchipamente != nullptr)
			{
				this->nrEchipamente = s.nrEchipamente;
				this->stareEchipamente = new bool[this->nrEchipamente];
				for (int i = 0; i < this->nrEchipamente; i++)
					this->stareEchipamente[i] = s.stareEchipamente[i];
			}
			else
			{
				this->nrEchipamente = 0;
				this->stareEchipamente = nullptr;
			}
			/*this->numeP = _numeP;*/
			if (s.numeP != nullptr)
			{
				this->numeP = new char[strlen(s.numeP) + 1];
				strcpy_s(this->numeP, strlen(s.numeP) + 1, s.numeP);
			}
			else
			{
				this->numeP = new char[strlen("Anonim") + 1];
				strcpy_s(this->numeP, strlen("Anonim") + 1, "Anonim");
			}
		}
		return *this;
	}

	Sala operator+(bool ech)
	{
		Sala rez = *this;
		if (rez.stareEchipamente != nullptr)
		{
			delete[]rez.stareEchipamente;
			rez.stareEchipamente = nullptr;
		}
		rez.stareEchipamente = new bool[rez.nrEchipamente + 1];
		for (int i = 0; i < rez.nrEchipamente; i++)
			rez.stareEchipamente[i] = this->stareEchipamente[i];
		rez.stareEchipamente[rez.nrEchipamente] = ech;
		rez.nrEchipamente++;

		return rez;
	}
	
	//preincrementare
	Sala& operator++()
	{
		return *this;
	}

	//postincrementare
	Sala operator++(int)
	{
		Sala copie = *this;

		return copie;
	}

	explicit operator string()
	{
		return this->denumire;
	}

	friend istream& operator>>(istream& in, Sala& s)
	{
		cout << "Introduceti denumirea salii: ";
		in >> s.denumire;
		cout << "Introduceti nr de echipamente: ";
		int x;
		in >> x;
		if (x > 0)
		{
			s.nrEchipamente = x;
			cout << "Introduceti starea fiecarui echipament: ";
			if (s.stareEchipamente != nullptr)
			{
				delete[]s.stareEchipamente;
				s.stareEchipamente = nullptr;
			}
			s.stareEchipamente = new bool[s.nrEchipamente];
			for (int i = 0; i < s.nrEchipamente; i++)
			{
				cout << "\nStarea echipamentului " << i + 1 << "este: ";
				in >> s.stareEchipamente[i];
			}

		}
		else
		{
			s.nrEchipamente = 0;
			s.stareEchipamente = nullptr;
		}
		cout << "Introduceti numele posesorului salii :";
		char nume[30];
		in >> nume;
		if (s.numeP != nullptr)
		{
			delete[]s.numeP;
			s.numeP = nullptr;
		}
		s.numeP = new char[strlen(nume) + 1];
		strcpy_s(s.numeP, strlen(nume) + 1, nume);
		return in;
	}
};

int Sala::greutate = 20;

int main()
{
	Sala s1(0);
	cout << s1;
	bool valori[] = { 1,1,1,0,0,0,0,1,0,1,0,0,1,0,1,0,0 };

	Sala s2(1, "Skyfitness ", 5, valori, (char*)"Florin");
	cout << s2;
	cout << endl << s2.getNrMaxEchFunc();

	/*s2 = s2 + 1;
	cout << s2;*/

	Sala s3(2);
	s3 = s2;
	cout << s3;

	s2 = s2 + 0;
	cout << s2;

	cout << endl<<(string)s2;
	Sala s6(9);
	cin >> s6;
	cout << s6;
	return 0;
}