#include <iostream>
#include <set>
#include <fstream>
using namespace std;

class Carte {
	string denumire;
	int nrExemplare;
	int*  codExemplar;
public:
	Carte()
	{
		this->denumire = "-";
		this->nrExemplare = 0;
		this->codExemplar = nullptr;
	}
	Carte(string _denumire, int _nrExemplare, int* _codExemplare)
	{
		this->denumire = _denumire;
		if (_nrExemplare > 0 && _codExemplare != nullptr)
		{
			this->nrExemplare = _nrExemplare;
			this->codExemplar = new int[this->nrExemplare];
			for (int i = 0; i < this->nrExemplare; i++)
				this->codExemplar[i] = _codExemplare[i];
		}
		else {
			this->nrExemplare = 0;
			this->codExemplar = nullptr;
		}
	}

	~Carte()
	{
		if (this->codExemplar != nullptr)
		{
			delete[]this->codExemplar;
			this->codExemplar = nullptr;
		}
	}

	Carte(const Carte& c)
	{
		this->denumire = c.denumire;
		if (c.nrExemplare > 0 && c.codExemplar != nullptr)
		{
			this->nrExemplare = c.nrExemplare;
			this->codExemplar = new int[this->nrExemplare]; 
			for (int i = 0; i < this->nrExemplare; i++)
				this->codExemplar[i] = c.codExemplar[i];
		}
		else {
			this->nrExemplare = 0;
			this->codExemplar = nullptr;
		}
	}

	Carte& operator=(const Carte& c)
	{
		if (this != &c)
		{
			if (this->codExemplar != nullptr)
			{
				delete[]this->codExemplar;
				this->codExemplar = nullptr;
			}
			this->denumire = c.denumire;
			if (c.nrExemplare > 0 && c.codExemplar != nullptr)
			{
				this->nrExemplare = c.nrExemplare;
				this->codExemplar = new int[this->nrExemplare];
				for (int i = 0; i < this->nrExemplare; i++)
					this->codExemplar[i] = c.codExemplar[i];
			}
			else {
				this->nrExemplare = 0;
				this->codExemplar = nullptr;
			}

		}
		return *this;
	}

	friend ostream& operator<<(ostream & out, const Carte& c)
	{
		
		out << "\nDenumire: " << c.denumire << "\tNumar exemplare: " << c.nrExemplare << "\tCodurile pentru fiecare exemplare sunt :";
		for (int i = 0; i < c.nrExemplare; i++)
			out << endl<< c.codExemplar[i] << "\t";
		return out;
	}

	explicit operator int()
	{
		return this->nrExemplare;
	}
	
	explicit operator char* ()
	{
		
		int lg = strlen(this->denumire.data()) + 1;
		char* buffer = new char[lg];
		strcpy_s(buffer, lg, this->denumire.data());
		return buffer;
	}

	void writeToFile(fstream &f)

	{
		int lg = this->denumire.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write((char*)this->denumire.data(), lg);

		f.write((char*)&this->nrExemplare, sizeof(int));
		for (int i = 0; i < this->nrExemplare; i++)
			f.write((char*)&this->codExemplar[i], sizeof(int));

	}

	void readFromFile(fstream& f)
	{
		if (this->codExemplar != nullptr)
		{
			delete[]this->codExemplar;
			this->codExemplar = nullptr;
		}
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg+1 ];
		f.read(buffer, lg);

		this->denumire = buffer;
		

		f.read((char*)&this->nrExemplare, sizeof(int));
		this->codExemplar = new int[this->nrExemplare];
		for (int i = 0; i < this->nrExemplare; i++)
			f.read((char*)&this->codExemplar[i], sizeof(int));
		delete[]buffer;
	}

};

class Cititor {
	const string cnp;
	string nume;
	int nrImp;
	Carte** listaCarti;
public:
	Cititor(string _cnp): cnp("0000000000000")
	{
		this->nume = "-";
		this->nrImp = 0;
		this->listaCarti = nullptr;
	}

	Cititor(string _cnp, string _nume, int _nrImp, Carte** _listaCarti) :cnp(_cnp) {
		this->nume = _nume;
		if (_nrImp > 0 && _listaCarti != nullptr)
		{
			this->nrImp = _nrImp;
			this->listaCarti = new Carte*[this->nrImp];
			for (int i = 0; i < this->nrImp; i++)
				this->listaCarti[i] = new Carte(*_listaCarti[i]);
			
		}
		else
		{
			this->nrImp = 0;
			this->listaCarti = nullptr;
		}
	}

	~Cititor()
	{
		if (this->listaCarti != nullptr)
		{
			for (int i = 0; i < this->nrImp; i++)
			{
				delete this->listaCarti[i];
				this->listaCarti[i] = nullptr;
			}
			delete[]this->listaCarti;
			this->listaCarti = nullptr;
		}
	}

	Cititor(const Cititor& c) : cnp(c.cnp)
	{
		this->nume = c.nume;
		if (c.nrImp > 0 && c.listaCarti != nullptr)
		{
			this->nrImp = c.nrImp;
			this->listaCarti = new Carte * [this->nrImp];
			for (int i = 0; i < this->nrImp; i++)
				this->listaCarti[i] =new Carte(*c.listaCarti[i]);

		}
		else
		{
			this->nrImp = 0;
			this->listaCarti = nullptr;
		}
	}

	Cititor& operator=(const Cititor& c)
	{
		if (this != &c) {
			if (this->listaCarti != nullptr)
			{
				for (int i = 0; i < this->nrImp; i++)
				{
					delete this->listaCarti[i];
					this->listaCarti[i] = nullptr;
				}
				delete[]this->listaCarti;
				this->listaCarti = nullptr;
			}
			this->nume = c.nume;
			if (c.nrImp > 0 && c.listaCarti != nullptr)
			{
				this->nrImp = c.nrImp;
				this->listaCarti = new Carte * [this->nrImp];
				for (int i = 0; i < this->nrImp; i++)
					this->listaCarti[i] = new Carte(*c.listaCarti[i]);

			}
			else
			{
				this->nrImp = 0;
				this->listaCarti = nullptr;
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Cititor& c)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nCNP ul este :" << c.cnp;
		out << "\nNumele este : " << c.nume;
		out << "\nNr de carti imprumutate: " << c.nrImp;
		for (int i = 0; i < c.nrImp; i++)
			out << c.listaCarti[i] << "\t";
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

};


int main()
{
	int coduri[6] = { 1,2,3,4,5,6 };
	Carte c1;
	Carte c2("Data Base SQL", 5, coduri);
	Carte c3("OOP  Programming", 3, coduri);

	cout << endl << (int)c2;
	cout << endl << (char*)c2;


	/*fstream f("Coletie.bin", ios::out | ios::binary);
	c2.writeToFile(f);
	f.close();*/




	fstream g("Coletie.bin", ios::in | ios::binary);

	if(!g.is_open()) {
		cout << "\nEroare la deschiderea fisierului!" << endl;
		return -1;
	}
	Carte c10;
	c10.readFromFile(g);

	cout << c10;



	return 0;


}
