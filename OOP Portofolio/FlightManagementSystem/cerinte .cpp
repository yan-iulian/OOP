#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Zbor {

	string orasSursa;
	string orasDestinatie;
	char data[11];
	int nrLocuri;
	bool* disponLocuri;
	float* preturi;

public :
	//constructor fara parametrii
	Zbor() {
		this->orasSursa = "0";
		this->orasDestinatie = "0";
		strcpy(this->data , "00/00/0000");
		this->nrLocuri = 0;
		this->disponLocuri = nullptr;
		this->preturi = nullptr;
	
	}


	//constructor cu toti parametrii
	Zbor(string _orasSursa, string _orasDestinatie, char _data[11], int _nrLocuri, bool* _disponLocuri,
		float* _preturi) {

		if (_orasSursa != _orasDestinatie && _orasSursa.length() < 15 && _orasDestinatie.length() < 15) {
			this->orasSursa = _orasSursa;
			this->orasDestinatie = _orasDestinatie;
		}
		else
		{
			this->orasSursa = "0";
			this->orasDestinatie = "0";
		}
		
		if (_data[2] == '/' && _data[5] == '/')
			for (int i = 0; i < 11; i++)
				this->data[i] = _data[i];
		else
		{
			strcpy(this->data, "00/00/0000");
		}


		if (_nrLocuri < 400 && _nrLocuri>0) {
			this->nrLocuri = _nrLocuri;
			this->disponLocuri = new bool[this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++)
				this->disponLocuri[i] = _disponLocuri[i];
			this->preturi = new float[this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++)
				this->preturi[i] = _preturi[i];
		}
		else
		{
			disponLocuri = nullptr;
			preturi = nullptr;
		}
	}
	//constructor cu cativa param
	Zbor(string _orasDestinatie, string _orasSursa, char _data[11], int _nrLocuri,
		float* _preturi)
	{

		if (_orasSursa != _orasDestinatie && _orasSursa.length() < 15 && _orasDestinatie.length() < 15) {
			this->orasSursa = _orasSursa;
			this->orasDestinatie = _orasDestinatie;
		}
		else
		{
			this->orasSursa = "0";
			this->orasDestinatie = "0";
		}

		if (_data[2] == '/' && _data[5] == '/')
			for (int i = 0; i < 10; i++)
				this->data[i] = _data[i];
		else
		{
			strcpy(this->data, "00/00/0000");
		}


		if (_nrLocuri < 400 && _nrLocuri>0) {
			this->nrLocuri = _nrLocuri;
			this->disponLocuri = new bool[this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++)
				this->disponLocuri[i] = true;
			this->preturi = new float[this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++)
				this->preturi[i] = _preturi[i];
		}
		else
		{
			disponLocuri = nullptr;
			preturi = nullptr;
		}
	}

	void afisare()
	{
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\nOrasul sursa: " << this->orasSursa;
		cout << "\nOrasul destinatie: " << this->orasDestinatie;
		cout << "\nData: " << this->data;
		cout << "\nNr locuri : " << this->nrLocuri;
		cout << "\nLista de disponibilitate: ";
		for (int i = 0; i < this->nrLocuri; i++)
			cout << this->disponLocuri[i] << "  ";
		cout << "\nLista de preturi: ";
		for (int i = 0; i < this->nrLocuri; i++)
			cout << this->preturi[i] << "  ";
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	}

	void afisare2()
	{
		cout << "\n************************************";
		cout << "\nOrasul sursa: " << this->orasSursa;
		cout << "\nOrasul destinatie: " << this->orasDestinatie;
		cout << "\nData: " << this->data;
		cout << "\nNr locuri : " << this->nrLocuri;
		cout << "\nNr de locuri disponibile: ";
		int nr = 0;
		float pretTotal= 0;
		for (int i = 0; i < this->nrLocuri; i++)
			if (this->disponLocuri[i] == true)
			{
				nr++;
				pretTotal += this->preturi[i];
			}
		float pretMediu = pretTotal / nr;
		cout << nr;
		cout << "\nPretul mediu pe bilet pentru locurile ramase disponibile este :" << pretMediu;
		cout << "\n************************************";
	}

	void afisare3() {
		cout << "\nOrasul sursa: " << this->orasSursa << " , "
			<< "Orasul destinatie: " << this->orasDestinatie << " , "
			<< "Data: " << this->data << " , "
			<< "Nr locuri : " << this->nrLocuri << " , "
			<< "Nr de locuri disponibile: ";
		int nr = 0;
		float pretTotal = 0;
		for (int i = 0; i < this->nrLocuri; i++)
			if (this->disponLocuri[i] == true)
			{
				nr++;
				pretTotal += this->preturi[i];
			}
		float pretMediu = pretTotal / nr;
		cout << nr << " , iar ";
		cout << "Pretul mediu pe bilet pentru locurile ramase disponibile este :" << pretMediu;
	}


	Zbor(const Zbor& z)
	{
		if (z.orasSursa != z.orasDestinatie && z.orasSursa.length() < 15 && z.orasDestinatie.length() < 15) {
			this->orasSursa = z.orasSursa;
			this->orasDestinatie = z.orasDestinatie;
		}
		else
		{
			this->orasSursa = "0";
			this->orasDestinatie = "0";
		}

		if (z.data[2] == '/' && z.data[5] == '/')
			for (int i = 0; i < 10; i++)
				this->data[i] = z.data[i];
		else
		{
			strcpy(this->data, "00/00/0000");
		}


		if (z.nrLocuri < 400 && z.nrLocuri>0) {
			this->nrLocuri = z.nrLocuri;
			this->disponLocuri = new bool[this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++)
				this->disponLocuri[i] = z.disponLocuri[i];
			this->preturi = new float[this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++)
				this->preturi[i] = z.preturi[i];
		}
		else
		{
			disponLocuri = nullptr;
			preturi = nullptr;
		}
	}

	~Zbor()
	{
		cout << "\n\nS a apelat destructorul!!";
		if (this->nrLocuri != 0 && this->disponLocuri != nullptr && this->preturi != nullptr)
		{
			delete[]this->disponLocuri;
			this->disponLocuri = nullptr;
			delete[]this->preturi;
			this->preturi = nullptr;
		}
	}

	Zbor &operator=(const Zbor& z)
	{
		if (this != &z)
		{
			if (this->nrLocuri != 0 && this->disponLocuri != nullptr && this->preturi != nullptr)
			{
				delete[]this->disponLocuri;
				this->disponLocuri = nullptr;
				delete[]this->preturi;
				this->preturi = nullptr;
			}
			if (z.orasSursa != z.orasDestinatie && z.orasSursa.length() < 15 && z.orasDestinatie.length() < 15) {
				this->orasSursa = z.orasSursa;
				this->orasDestinatie = z.orasDestinatie;
			}
			else
			{
				this->orasSursa = "0";
				this->orasDestinatie = "0";
			}

			if (z.data[2] == '/' && z.data[5] == '/')
				for (int i = 0; i < 10; i++)
					this->data[i] = z.data[i];
			else
			{
				strcpy(this->data, "00/00/0000");
			}


			if (z.nrLocuri < 400 && z.nrLocuri>0) {
				this->nrLocuri = z.nrLocuri;
				this->disponLocuri = new bool[this->nrLocuri];
				for (int i = 0; i < this->nrLocuri; i++)
					this->disponLocuri[i] = z.disponLocuri[i];
				this->preturi = new float[this->nrLocuri];
				for (int i = 0; i < this->nrLocuri; i++)
					this->preturi[i] = z.preturi[i];
			}
			else
			{
				disponLocuri = nullptr;
				preturi = nullptr;
			}
		}
		return *this;
	}
	//getteri si setteri
	int getNrLocuri()
	{
		return this->nrLocuri;
	}

	bool *getDisponibilitateLocuri()
	{
		return this->disponLocuri;
	}

	bool getDisponLoc(int _index)
	{
		return disponLocuri[_index];
	}

	const float *getPreturi()
	{
		return this->preturi;
	}

	const float getPret(int _index)
	{
		return preturi[_index];
	}

	void setLocuri(int _nrLocuri, bool* _disponLocuri, float* _preturi)
	{
		if (_nrLocuri != 0 && _disponLocuri != nullptr && _preturi != nullptr)
		{
			if (this->preturi != nullptr)
			{
				delete[]this->preturi;
				this->preturi = nullptr;
			}
			if (this->disponLocuri != nullptr)
			{
				delete[]disponLocuri;
				this->disponLocuri = nullptr;
			}
			this->nrLocuri = _nrLocuri;
			this->disponLocuri = new bool[this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++)
				this->disponLocuri[i] = _disponLocuri[i];
			this->preturi = new float[this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++)
				this->preturi[i] = _preturi[i];
		}
	}

	void setLoc(int _index , bool _estedisponibil)
	{
		if (_index < this->nrLocuri)
		{
			this->disponLocuri[_index] = _estedisponibil;
		}
	}

	void setPret(int _index, float _pret)
	{
		if (this->disponLocuri[_index] == true)
			this->preturi[_index] = _pret;
	}

	//metoda pentru k bilete alaturate
	bool existaBileteAlaturate(int _k)
	{
		if (_k >= this->nrLocuri)
			return false;
		for (int i = 0; i < this->nrLocuri; i++)
		{
			bool gasit = true;
			for (int j = 0; j < _k; j++)
				if (this->disponLocuri[i + j] == false)
				{
					gasit = false;
					break;
				}
			if (gasit == true)return true;
		}
		return false;
	}

	//metoda care simuleaza vanzarea unui anumit loc primit ca parametru
	void vanzare(int _loc)
	{
		if (_loc < this->nrLocuri)
		{
			if (this->disponLocuri[_loc] == true)
			{
				this->disponLocuri[_loc] = false;
				cout << "\nLocul a fost vandut cu succes!";
			}

			else cout << "\nLocul nu este disponibil!";
		}

	}

	float vanzareLocuriAlaturate(float _locuriAlaturate)
	{
		
			float incasari = 0;
			int i = 0;

			while (existaBileteAlaturate(_locuriAlaturate) && i <= nrLocuri - _locuriAlaturate)
			{
				for (int j = 0; j < _locuriAlaturate; j++)
				{
					incasari += preturi[i + j],
						disponLocuri[i + j] = false;
				}
				i += _locuriAlaturate;
			}
		return incasari;
	}

	//metoda care returneaza totalul incasarilor pentru zborul curent
	float totalIncasari()
	{
		float total = 0;
		for (int i = 0; i < this->nrLocuri; i++)
			if (this->disponLocuri[i] == false)
				total += this->preturi[i];
		return total;
	}

	float pretMediu()
	{
		float media = 0;
		int nr = 0;
		for (int i = 0; i < this->nrLocuri; i++)
			if (this->disponLocuri[i] == false)
			{
				media += this->preturi[i];
				nr++;
			}
		media = media / nr;
		return media;
	}


};

int main()
{
	Zbor z1;
	bool* listadisponibilitateL = new bool[5] {true, false, true, true, false};
	float* listapreturi = new float[5] {20, 10, 40, 60, 50};
	char data[11] = "10/10/2025";
	z1.afisare();

	cout << endl;

	Zbor z2("Slatina", "MADRID", data, 5, listadisponibilitateL, listapreturi);
	z2.afisare();
	z2.afisare2();
	z1 = z2;
	cout << endl;
	z1.afisare();

	cout << endl;
	cout << "Locul al patrulea este :" << z1.getDisponLoc(3);
	cout << endl << "Preturile sunt :";
	for (int i = 0; i < z2.getNrLocuri(); i++)
		cout << z2.getPreturi()[i] << "  ";
	cout << endl << "Pretul al treilea este :" << z2.getPret(2);

	float* listap2 = new float [3] {100, 200, 300};
	bool* listad2 = new bool [3] {true, true, false};
	z2.setLocuri(3, listad2, listap2);
	z2.afisare();

	Zbor z3("SLATINA", "MADRID", data, 5, listadisponibilitateL, listapreturi);
	z3.afisare();

	z3.setLoc(1, true);
	z3.afisare();

	z3.setPret(0, 1000);
	z3.afisare();
	z3.setPret(4, 1000);
	z3.afisare();
	cout << endl << " EXISTA LOCURI APROPIATE LIBERE?  ";
	cout<<z3.existaBileteAlaturate(3);

	z3.vanzare(0);
	z3.afisare();

	/*cout << "\nS au obtinut urmatoarele incasari: ";
	cout<<z3.vanzareLocuriAlaturate(3);*/

	cout << endl;
	cout << "Totalul pentru calatorie a fost de :" << z3.totalIncasari() << " ,iar media de : " << z3.pretMediu();
	return 0;

}