#include <iostream>
using namespace std;

enum Ambalaj {
	CUTIE , PLIC , GLOB , HARTIE 
};

class Cadou{
	string denumire = "--";
	float pret = 0;
	Ambalaj ambalaj = Ambalaj::PLIC;

public:
	Cadou() {}

	Cadou(string _denumire, float _pret, Ambalaj _ambalaj)
	{
		if (_denumire != " ")
			this->denumire = _denumire;
		if (_pret != 0)
			this->pret = _pret;
		this->ambalaj = _ambalaj;

	}

	friend ostream& operator<<(ostream& out, const Cadou &c)
	{
		
		out << "\nDenumirea cadoului: " << c.denumire <<" , Pretul cadoului : " << c.pret<< " , Ambalajul cadoului: " << c.ambalaj;
		
		return out;
	}

	Cadou(const Cadou& c)
	{
		this->denumire = c.denumire;
		this->pret = c.pret;
		this->ambalaj = c.ambalaj;
	}

	Cadou& operator=(const Cadou& c)
	{
		if (&c != this)
		{
			this->denumire = c.denumire;
			this->pret = c.pret;
			this->ambalaj = c.ambalaj;
		}
		return *this;
	}
};

//vector alocat dinamic de Cadou*
class Wishlist {
	string posesor = "Anonim";
	Cadou** listaCadouri = nullptr;
	int nrCadouri = 0;
	float buget = 0;

public:
	Wishlist() {}

	Wishlist(string _posesor, Cadou** _listaCadouri, int _nrCadouri, float _buget)
	{
		this->posesor = _posesor;
		if (_nrCadouri != 0 && _listaCadouri != nullptr)
		{
			this->nrCadouri = _nrCadouri;
			this->listaCadouri = new Cadou * [this->nrCadouri];
			for (int i = 0; i < this->nrCadouri; i++)
				this->listaCadouri[i] = new Cadou(*_listaCadouri[i]);
			this->buget = _buget;
		}
	}

	~Wishlist()
	{
		if (this->listaCadouri!=nullptr)
		{
			for (int i = 0; i < this->nrCadouri; i++)
				delete this->listaCadouri[i];
	}
		delete[]this->listaCadouri;
		this->listaCadouri = nullptr;
	}

	Wishlist(const Wishlist& w) {
		this->posesor = w.posesor;
		if (w.nrCadouri != 0 && w.listaCadouri != nullptr)
		{
			this->nrCadouri = w.nrCadouri;
			this->listaCadouri = new Cadou * [this->nrCadouri];
			for (int i = 0; i < this->nrCadouri; i++)
				this->listaCadouri[i] = new Cadou(*w.listaCadouri[i]);
			this->buget = w.buget;
		}
	}

	Wishlist& operator=(const Wishlist& w)
	{
		if (this->listaCadouri != nullptr)
		{
			for (int i = 0; i < this->nrCadouri; i++)
				delete this->listaCadouri[i];
		}
		delete[]this->listaCadouri;
		this->listaCadouri = nullptr;
		this->posesor = w.posesor;
		if (w.nrCadouri != 0 && w.listaCadouri != nullptr)
		{
			this->nrCadouri = w.nrCadouri;
			this->listaCadouri = new Cadou * [this->nrCadouri];
			for (int i = 0; i < this->nrCadouri; i++)
				this->listaCadouri[i] = new Cadou(*w.listaCadouri[i]);
			this->buget = w.buget;
		}
		else
		{
			this->nrCadouri = 0;
			this->listaCadouri = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const Wishlist& w)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nNumele posesorului: " << w.posesor;
		out << "\nBugetul posesorului :" << w.buget;
		out << "\nNr de cadouri : " << w.nrCadouri;
		out << "\nLista de cadouri: ";
		for (int i = 0; i < w.nrCadouri; i++)
			out << *w.listaCadouri[i];
		out << "\n~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

};

//vector alocat dinamic de Cadou
class Wishlist2
{
	string posesor="--";
	Cadou* listaCadouri = nullptr;
	int nrCadouri = 0;
public:
	Wishlist2() {}
	Wishlist2(string _posesor, Cadou* _listaCadouri, int _nrCadouri)
	{
		this->posesor = _posesor;
		if (_nrCadouri != 0 && _listaCadouri != nullptr)
		{
			this->nrCadouri = _nrCadouri;
			this->listaCadouri = new Cadou[this->nrCadouri];
			for (int i = 0; i < this->nrCadouri; i++)
				this->listaCadouri[i] = _listaCadouri[i];
		}
	}

	Wishlist2& operator=(const Wishlist2& w)
	{
		if (this->listaCadouri != nullptr)
		delete[]this->listaCadouri;
		this->listaCadouri = nullptr;
		this->posesor = w.posesor;
		if (w.nrCadouri != 0 && w.listaCadouri != nullptr)
		{
			this->nrCadouri = w.nrCadouri;
			this->listaCadouri = new Cadou  [this->nrCadouri];
			for (int i = 0; i < this->nrCadouri; i++)
				this->listaCadouri[i] = w.listaCadouri[i];
		}
		else
		{
			this->nrCadouri = 0;
			this->listaCadouri = nullptr;
		}
	}

	~Wishlist2()
	{
		if (this->listaCadouri != nullptr)
		delete[]this->listaCadouri;
		this->listaCadouri = nullptr;
	}

	Wishlist2(const Wishlist2& w) {
		this->posesor = w.posesor;
		if (w.nrCadouri != 0 && w.listaCadouri != nullptr)
		{
			this->nrCadouri = w.nrCadouri;
			this->listaCadouri = new Cadou  [this->nrCadouri];
			for (int i = 0; i < this->nrCadouri; i++)
				this->listaCadouri[i] = w.listaCadouri[i];
			
		}
	}

	friend ostream& operator<<(ostream& out, const Wishlist2& w)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nNumele posesorului: " << w.posesor;
		out << "\nNr de cadouri : " << w.nrCadouri;
		out << "\nLista de cadouri: ";
		for (int i = 0; i < w.nrCadouri; i++)
			out << w.listaCadouri[i];
		out << "\n~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}
};

//vector alocat static de Cadou*
class Wishlist3 {
	string posesor = "--";
	Cadou* listaCadouri[100];
	int nrCadouri = 0;
public:
	Wishlist3() {}
	Wishlist3(string _posesor, Cadou* _listaCadouri[100], int _nrCadouri)
	{
		this->posesor = _posesor;
		if (_nrCadouri != 0)
		{
			this->nrCadouri = _nrCadouri;
			for (int i = 0; i < this->nrCadouri; i++)
				this->listaCadouri[i] = new Cadou(*_listaCadouri[i]);
		}
	}

	~Wishlist3()
	{
		for (int i = 0; i < this->nrCadouri; i++)
			delete this->listaCadouri[i];
	}

	friend ostream& operator<<(ostream& out, const Wishlist3& w)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nNumele posesorului: " << w.posesor;
		out << "\nNr de cadouri : " << w.nrCadouri;
		out << "\nLista de cadouri: ";
		for (int i = 0; i < w.nrCadouri; i++)
			out << *w.listaCadouri[i];
		out << "\n~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

	};

//vector alocat static de Cadou
class Wishlist4 {
	string posesor = "--";
	Cadou listaCadouri[100];
	int nrCadouri=0;
public:
	Wishlist4() {}
	Wishlist4(string _posesor, Cadou _listaCadouri[100], int _nrCadouri)
	{
		this->posesor = _posesor;
		if (_nrCadouri != 0)
		{
			this->nrCadouri = _nrCadouri;
			for (int i = 0; i < this->nrCadouri; i++)
				this->listaCadouri[i] = _listaCadouri[i];
		}
	}


	friend ostream& operator<<(ostream& out, const Wishlist4& w)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nNumele posesorului: " << w.posesor;
		out << "\nNr de cadouri : " << w.nrCadouri;
		out << "\nLista de cadouri: ";
		for (int i = 0; i < w.nrCadouri; i++)
			out << w.listaCadouri[i];
		out << "\n~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}
};

//un obj de tip Cadou , relatie de tip 1 to 1
class Wishlist5 {
	string posesor="--";
	Cadou cadouSpecial;
	int nrCadouri=0;

public:
	Wishlist5() {}
	Wishlist5(string _posesor, Cadou _cadouSpecial, int _nrCadouri)
	{
		this->posesor = _posesor;
		if (_nrCadouri != 0)
		{
			this->nrCadouri = _nrCadouri;
		}
		this->cadouSpecial = _cadouSpecial;
	}


	friend ostream& operator<<(ostream& out, const Wishlist5& w)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nNumele posesorului: " << w.posesor;
		out << "\nNr de cadouri : " << w.nrCadouri;
		out << "\nCadoul special: " << w.cadouSpecial;
		out << "\n~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

};


//un pointer la un Cadou
class Wishlist6 {
	string posesor = "--";
	Cadou* cadouSpecial = nullptr;
	int nrCadouri = 0;
	
public:
	Wishlist6() {}
	Wishlist6(string _posesor, Cadou* _cadouSpecial, int _nrCadouri)
	{
		this->posesor = _posesor;
		if (_nrCadouri != 0)
		{
			this->nrCadouri = _nrCadouri;
		}
		if (_cadouSpecial != nullptr)
		{
			this->cadouSpecial = new Cadou(*_cadouSpecial);
		}
	}

	~Wishlist6()
	{
		if (this->cadouSpecial != nullptr)
		{
			delete this->cadouSpecial;
			this->cadouSpecial = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const Wishlist6& w)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nNumele posesorului: " << w.posesor;
		out << "\nNr de cadouri : " << w.nrCadouri;
		out << "\nCadoul special : " << *w.cadouSpecial;
		out << "\n~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

};
	
	int main()
	{	
	Cadou cadou1("Stilou", 100,PLIC);
	Cadou cadou3("Carte", 200, CUTIE);
	Cadou cadou4("Masinuta", 300, CUTIE);
	cout << cadou1;
	Cadou cadou2;
	cout << cadou2;

	cout << endl << "DATELE DESPRE WISHLISTURI::";

	Cadou* listaCadouri[] = { &cadou1, &cadou2, &cadou3 , &cadou4 };  //ptr vector alocat dinamic de Cadou*
	Cadou listaCadouri2[] = { cadou1, cadou2, cadou3,cadou4 };    // ptr vector alocat dinamic de Cadou
	Cadou* listaCadouri3[]= { &cadou1, &cadou3,&cadou4 };	//ptr vector alocat static de Cadou*
	Cadou listaCadouri4[]= { cadou1, cadou2, cadou3,cadou4 };   // ptr vector alocat static de Cadou

	Wishlist wishlist1( "Andrei", listaCadouri, 4 ,1000);
	cout << wishlist1;
	
	Wishlist2 wishlist2("Radu", listaCadouri2, 4);
	cout << wishlist2;

	Wishlist3 wishlist3("Amalia", listaCadouri3, 3);
	cout << wishlist3;

	Wishlist4 wishlist4("Mihaela", listaCadouri4, 4);
	cout << wishlist4;

	Wishlist5 wishlist5("Marius", cadou4, 10);
	cout << wishlist5;

	Wishlist6 wishlist6("Ana", &cadou1, 20);
	cout << wishlist6;

	return 0;
}