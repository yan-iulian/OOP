#include <iostream>
#include <map>
using namespace std;

enum NivelPresiune
{
	MARE, MICA, MIJLOCIE
};

class Marker
{
	string culoare="-";
	float dimensiune=0;
	int nrAc=0;
	float* curentAc=nullptr;
public:
	Marker() {}
	Marker(string _culoare, float _dimensiune, int _nrAc, float* _curentAc)
	{
		this->culoare = _culoare;
		this->dimensiune = _dimensiune;
		if (_nrAc > 0 && _curentAc != nullptr)
		{
			this->nrAc = _nrAc;
			this->curentAc = new float[this->nrAc];
			for (int i = 0; i < this->nrAc; i++)
				this->curentAc[i] = _curentAc[i];
		}
		else
		{
			this->curentAc = nullptr;
			this->nrAc = 0;
		}
	}

	~Marker()
	{
		if (this->curentAc != nullptr)
		{
			delete[]this->curentAc;
			this->curentAc = nullptr;
		}
	}

	Marker(const Marker& m)
	{
		this->culoare = m.culoare;
		this->dimensiune = m.dimensiune;
		if (m.nrAc > 0 && m.curentAc != nullptr)
		{
			this->nrAc = m.nrAc;
			this->curentAc = new float[this->nrAc];
			for (int i = 0; i < this->nrAc; i++)
				this->curentAc[i] = m.curentAc[i];
		}
		else
		{
			this->curentAc = nullptr;
			this->nrAc = 0;
		}
	}

	Marker& operator<<(const Marker& m)
	{
		if (this != &m)
		{
			if (this->curentAc != nullptr)
			{
				delete[]this->curentAc;
				this->curentAc = nullptr;
			}
			this->culoare = m.culoare;
			this->dimensiune = m.dimensiune;
			if (m.nrAc > 0 && m.curentAc != nullptr)
			{
				this->nrAc = m.nrAc;
				this->curentAc = new float[this->nrAc];
				for (int i = 0; i < this->nrAc; i++)
					this->curentAc[i] = m.curentAc[i];
			}
			else
			{
				this->curentAc = nullptr;
				this->nrAc = 0;
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Marker& m)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nCuloare: " << m.culoare;
		out << "\nDimensiune :" << m.dimensiune;
		out << "\nNr acumulatori: " << m.nrAc;
		out << "\nCurentul din fiecare acumulator: ";
		for (int i = 0; i < m.nrAc; i++)
			out << m.curentAc[i]<<"\t";
		
		return out;
	}

	friend istream& operator>>(istream& in, Marker& m) {
		if (m.curentAc != nullptr)
		{
			delete[]m.curentAc;
			m.curentAc = nullptr;
		}

		cout << "\nCuloare :";
		char buffer[50];
		in >> buffer;
		if (strlen(buffer) > 1)
			m.culoare = buffer;

		cout << "\nDimensiunea:";
		in >> m.dimensiune;

		cout << "\nNr acumulatori:";
		int x=0;
		in >> x;
		if (x > 0)
		{
			m.nrAc = x;
			m.curentAc = new float [m.nrAc]; 
			for (int i = 0; i < m.nrAc; i++)
			{
				cout << "\nAcumulatorul " << i << " are :";
				in >> m.curentAc[i];
			}

		}

		return in;
	}

	bool operator==(const Marker& m) const
	{
		bool gasit = 1;
		if (this->culoare != m.culoare)
			gasit = 0;
		if (this->nrAc != m.nrAc)
			gasit = 0;
		return gasit;
	}

	virtual void afisare()
	{
		cout << "\nMarkerul este unul obisnuit!";
	}

	float getDimensiune()
	{
		return this->dimensiune;
	}

	bool operator<(const Marker& m)const
	{
		return this->dimensiune < m.dimensiune;
	 }

};

class MInteligent:public Marker {
	NivelPresiune nI=NivelPresiune::MARE;
	string grosime="-";
	string tipLinie="-";
public:
	MInteligent() {}

	MInteligent(string _culoare, float _dimensiune,int _nrAc, float* _curentAc, NivelPresiune _nI, string _grosime, string _tiplinie):Marker(_culoare, _dimensiune, _nrAc,_curentAc)
	{
		this->nI = _nI;
		this->grosime = _grosime;
		this->tipLinie=_tiplinie;

	}

	MInteligent(const MInteligent& m): Marker( m ){
		this->nI = m.nI;
		this->grosime = m.grosime;
		this->tipLinie = m.tipLinie;
	}


	MInteligent& operator=(const MInteligent& m)
	{
		if (this != &m)
		{
			Marker::operator=(m);
			this->nI = m.nI;
			this->grosime = m.grosime;
			this->tipLinie = m.tipLinie;
		}
			return *this;
	}

	friend ostream& operator<<(ostream& o, const  MInteligent& m)
	{
		o << (Marker)m;
		o << "\nNivel presiune : " << m.nI;
		o << "\nTip linie: " << m.tipLinie;
		o << "\nGrosime: " << m.grosime;
		o << "\n~~~~~~~~~~~~~~~~~~~~~~";
		return o;
	}

	MInteligent(Marker _m, NivelPresiune _nI, string _grosime, string _tiplinie) :Marker(_m)
	{

		this->nI = _nI;
		this->grosime = _grosime;
		this->tipLinie = _tiplinie;

	}

	void afisare() override
	{
		cout << "\nMarkerul inteligent se incarca!";
	}
		
};


class Sala {
	map<int , Marker> mapMarkere;
public:
	void adaugaMarker(int  _idProprietar, const Marker& m)
	{
		mapMarkere[_idProprietar] = m;
	}

	void cautaProprietar(int id)
	{
		if (mapMarkere.find(id) != mapMarkere.end())
			cout << "\nProp detine markerul: " << mapMarkere[id];
		else cout << "\nNu detine niciun marker!";
	}

};

int main()
{
	float vector[4] = { 1,2,3,4 };
	Marker m1;
	Marker m2("Rosu", 20, 2, vector);
	/*cout << m1 << m2;*/
	Marker m3;
	/*cin >> m3;
	cout << m3;*/

	MInteligent m11;
	MInteligent m12(m2, MARE, "mica", "mare");
	cout << m11 << m12;
	MInteligent m14(m2, MARE, "mica", "mare");
	cout << endl << boolalpha << (m12 == m14);

	Marker m6;
	MInteligent m61;
	m6 = m61;
	cout << endl << "\nVIRTUAlIZARE";
	m6.afisare();

	Marker *pm6 = new Marker();
	pm6 = &m61;
	pm6->afisare();


	cout << endl << endl;
	Sala sala;
	sala.adaugaMarker(1, m1);
	sala.adaugaMarker(2, m2);
	sala.adaugaMarker(3, m3);

	sala.cautaProprietar(2);


	return 0;
}