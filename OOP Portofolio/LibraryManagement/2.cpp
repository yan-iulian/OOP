#include <iostream>
#include <fstream>
using namespace std;


class Carte {
	string denumire;
	int nrPag;
	bool esteOcupata;
public:
	Carte()
	{
		this->denumire = '-';
		this->nrPag = 0;
		this->esteOcupata = 0;
	}
	
	Carte(string _denumire, int _nrPag, bool _esteOcupata)
	{
		this->denumire = _denumire;
		this->nrPag = _nrPag;
		this->esteOcupata = _esteOcupata;
	}

	friend ostream& operator<<(ostream& out, const Carte& c)
	{
		
		out << "\n" << c.denumire << "\t" << c.nrPag << "\t" << c.esteOcupata;
		return out;
		
	}

	friend ofstream& operator<<(ofstream& out, const Carte& c)
	{
		out << "\n" << c.denumire << "\t" << c.nrPag << "\t" << c.esteOcupata;
		return out;
	}

	//serializare
	void writeToFile(fstream& f)
	{
		int lg = this->denumire.length()+1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->denumire.data(), lg);

		f.write((char*)&this->nrPag, sizeof(int));
		f.write((char*)&this->esteOcupata, sizeof(bool));
	}

	//deserializare
	void readFromFile(fstream& f)
	{
		
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg + 1];
		f.read(buffer, lg);
		this->denumire = buffer;
		delete[]buffer;

		f.read((char*)&this->nrPag, sizeof(int));
		f.read((char*)&this->esteOcupata, sizeof(bool));
	}

};

class Biblioteca {
	string nume;
	int nrCarti;
	Carte* listaCarti;
public:

	Biblioteca() {
		this->nume = " ";
		this->nrCarti = 0;
		this->listaCarti = nullptr;
	}

	Biblioteca(string _nume , int _nrCarti , Carte* _listaCarti)
	{
		this->nume = _nume;
		if (_nrCarti > 0 && _listaCarti != nullptr)
		{
			this->nrCarti = _nrCarti;
			listaCarti = new Carte[this->nrCarti];
			for (int i = 0; i < this->nrCarti; i++)
				this->listaCarti[i] = _listaCarti[i];
		}
		else
		{
			this->nrCarti = 0;
			this->listaCarti = nullptr;
		}
	}

	Biblioteca(const Biblioteca& b)
	{
		this->nume = b.nume;
		if (b.nrCarti > 0 && b.listaCarti != nullptr)
		{
			this->nrCarti = b.nrCarti;
			listaCarti = new Carte[this->nrCarti];
			for (int i = 0; i < this->nrCarti; i++)
				this->listaCarti[i] = b.listaCarti[i];
		}
		else
		{
			this->nrCarti = 0;
			this->listaCarti = nullptr;
		}
	}

	Biblioteca& operator=(const Biblioteca& b)
	{
		if(this!=&b)
		{
			if (this->listaCarti != nullptr)
			{
				delete[]this->listaCarti;
				this->listaCarti = nullptr;
			}
			this->nume = b.nume;
			if (b.nrCarti > 0 && b.listaCarti != nullptr)
			{
				this->nrCarti = b.nrCarti;
				listaCarti = new Carte[this->nrCarti];
				for (int i = 0; i < this->nrCarti; i++)
					this->listaCarti[i] = b.listaCarti[i];
			}
			else
			{
				this->nrCarti = 0;
				this->listaCarti = nullptr;
			}
		}return *this;
	}
	
	~Biblioteca ()
	{
		if (this->listaCarti != nullptr)
		{
			delete[]this->listaCarti;
			this->listaCarti = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const Biblioteca& b)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~";
		out << "\nDenumire biblioteca: " << b.nume;
		out << "\nNr de carti: " << b.nrCarti;
		for (int i = 0; i < b.nrCarti; i++)
			out << b.listaCarti[i];
		out << "\n~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

};

class Librarie {
	string nume;
	int nrCarti;
	Carte** listaCarti;
public:
	Librarie()
	{
		this->nume = '-';
		this->nrCarti = 0;
		this->listaCarti = nullptr;
	}

	Librarie(string _nume, int _nrCarti, Carte** _listaCarti)
	{
		this->nume = _nume;
		if (_nrCarti > 0 && _listaCarti != nullptr)
		{
			this->nrCarti = _nrCarti;
			this->listaCarti = new Carte * [this->nrCarti];
			for (int i = 0; i < this->nrCarti; i++)
				this->listaCarti[i] = new Carte(*_listaCarti[i]);
		}
		else
		{
			this->listaCarti = nullptr;
			this->nrCarti = 0;
		}
	}

	~Librarie()
	{
		if (this->listaCarti != nullptr)
		{
			delete[]this->listaCarti;
			this->listaCarti = nullptr;
		}
	}

	Librarie(const Librarie& l)
	{
		this->nume = l.nume;
		if (l.nrCarti > 0 && l.listaCarti != nullptr)
		{
			this->nrCarti = l.nrCarti;
			this->listaCarti = new Carte * [this->nrCarti];
			for (int i = 0; i < this->nrCarti; i++)
				this->listaCarti[i] = new Carte(*l.listaCarti[i]);
		}
		else
		{
			this->listaCarti = nullptr;
			this->nrCarti = 0;
		}
	}

	Librarie& operator=(const Librarie& l)
	{
		if(this!=&l)
		{
			if (this->listaCarti != nullptr)
			{
				delete[]this->listaCarti;
				this->listaCarti = nullptr;
			}
			this->nume = l.nume;
			if (l.nrCarti > 0 && l.listaCarti != nullptr)
			{
				this->nrCarti = l.nrCarti;
				this->listaCarti = new Carte * [this->nrCarti];
				for (int i = 0; i < this->nrCarti; i++)
					this->listaCarti[i] = new Carte(*l.listaCarti[i]);
			}
			else
			{
				this->listaCarti = nullptr;
				this->nrCarti = 0;
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Librarie & l)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nDenumire librarie: " << l.nume;
		out << "\nNr carti in stoc: " << l.nrCarti;
		for (int i = 0; i < l.nrCarti; i++)
			out << *l.listaCarti[i];
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}
};

class Persoana {
	string nume;
	Carte carte;
public:

	Persoana()
	{
		this->nume = "-";
	}

	Persoana(string _nume , Carte _carte)
	{
		this->nume = _nume;
		this->carte = _carte;
	}
	friend ostream& operator<<(ostream& out, const Persoana& p)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~";
		out << "\nNumele persoanei: " << p.nume;
		out << "\nCartea persoanei: " << p.carte;
		out << "\n~~~~~~~~~~~~~~~~~~~~";
		return out;
	}
};

class Profesor {
	string nume;
	Carte* carte;
public:
	Profesor()
	{
		this->nume = '-';
		this->carte = nullptr;
	}

	Profesor(string _nume, Carte* _carte)
	{
		this->nume = _nume;
		if (_carte != nullptr)
			this->carte = new Carte(*_carte);
		else this->carte = nullptr;
	}
	Profesor(const Profesor& p)
	{
		this->nume = p.nume;
		if (p.carte != nullptr)
			this->carte = new Carte(*p.carte);
		else this->carte = nullptr;
	}
	Profesor& operator=(const Profesor& p)
	{
		if (this != &p)
		{
			if (this->carte != nullptr)
			{
				delete this->carte;
				this->carte = nullptr;
			}
			this->nume = p.nume;
			if (p.carte != nullptr)
				this->carte = new Carte(*p.carte);
			else this->carte = nullptr;
		}
		return *this;
	}

	~Profesor()
	{
		if (this->carte != nullptr)
		{
			delete this->carte;
			this->carte = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const Profesor& p)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~";
		out << "\nNume profesor: " << p.nume;
		if (p.carte != nullptr)
			out << "\nCartea profesorului :" << *p.carte;
		out << "\n~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

};


int main()
{
	Carte c1;
	Carte c2("Alba Ca Zapada", 30, 0);
	Carte c3("Ursu Pacalit De Vulpe", 40, 1);
	Carte c4("Aveturile Lui Tom Sawyer", 200, 0);
	Carte c5("Piratii Din Caraibe", 210, 1);

	Carte* listaCarti = new Carte[5]{ c1,c2,c3,c4,c5 };
	Carte** listaCarti2 = new Carte * [5] {&c1, & c2, & c3, & c4, & c5};

	Biblioteca b1;
	Biblioteca b2("B_Centrala", 5, listaCarti);
	cout << b1 << b2;

	Librarie l1;
	Librarie l2("L_Centrala", 5, listaCarti2);
	cout << l1 << l2;

	Persoana p1;
	Persoana p2("Mihaela", c2);
	cout << p1 << p2;


	Profesor pr2("Raducu", &c3);
	cout << pr2;

	/*ofstream f("Carti.txt");
	f << c3 << c4;
	cout << endl << "Scrierea in fisier a mers!";*/

	fstream fileOut("Carti.bin", ios::out | ios::binary);
	c2.writeToFile(fileOut);
	fileOut.close();
	cout << endl << "Scrierea in fisierul binar a mers!";

	Carte c100;
	fstream fileIn("Carti.bin", ios::in |ios::binary);
	c100.readFromFile(fileIn);
	cout << endl << "Citirea din fisier a mers , obiectul este: ";
	cout << c100;


	return 0;
}