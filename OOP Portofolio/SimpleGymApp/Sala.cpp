#include <iostream>
using namespace std;

class Sala {
	const int id;
	string denumire;
	int nrEchipamente;
	bool* stareEchipamente;
	string numeP;
	static int greutate;
public:


	Sala(int _id):id(_id)
	{
		this->denumire = "Sala";
		this->nrEchipamente = 0;
		this->stareEchipamente = nullptr;
		/*this->numeP = new char[strlen("Anonim") + 1];
		strcpy_s(this->numeP,strlen("Anonim")+1, "Anonim");*/
		this->numeP = " ";
	}

	Sala(int _id,  string _denumire, int _nrEchipamente, bool *_stareEchipamente, string _numeP):id(_id)
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
		this->numeP = _numeP;
		/*if (_numeP != nullptr)
		{
			this->numeP = new char[strlen(_numeP) + 1]; 
			strcpy_s(this->numeP, strlen(_numeP) + 1, _numeP);
		}
		else
		{
			this->numeP = new char[strlen("Anonim") + 1];
			strcpy_s(this->numeP, strlen("Anonim") + 1, "Anonim");
		}*/
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
};

int Sala::greutate = 20;

int main()
{
	Sala s1(0);
	cout << s1;
	bool valori[5] = { true , true ,true, true, true };
	
	Sala s2(1, "Skifitnes ", 5, valori, "Florin");
		
		return 0;
}