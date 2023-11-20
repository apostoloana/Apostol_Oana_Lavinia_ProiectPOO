#include<iostream>
#include<string>

using namespace std;

class Biblioteca {
private:
	char* numeBiblioteca;
	const int anInfiintare;
	string adresa;
	int nrAngajati;
	float suprafata;
	bool deschisaInWeekend;
	static int nrTotalCarti;

public:

	//get si set
	char* getNumeB() {
		return numeBiblioteca;
	}

	void setNumeB(const char* numeBNou) {
		if (strlen(numeBNou) > 2) {
			delete[] numeBiblioteca;
			numeBiblioteca = new char[strlen(numeBNou) + 1];
			strcpy_s(numeBiblioteca, strlen(numeBNou) + 1, numeBNou);
		}
	}

	string getAdresa() {
		return this->adresa;
	}

	void setAdresa(string adresa) {
		if (adresa.length() > 2) {
			this->adresa = adresa;
		}
	}

	int getNrAng() {
		return this->nrAngajati;
	}

	void setNrAng(int nrNAng) {
		this->nrAngajati = nrNAng;
	}

	float getSuprafata() {
		return this->suprafata;
	}

	void setSuprafata(float suprafataNoua) {
		this->suprafata = suprafataNoua;
	}

	bool getisOpenWK() {
		return this->deschisaInWeekend;
	}

	void setIsOpenWK(bool isOpenWK) {
		this->deschisaInWeekend = isOpenWK;
	}

	static int getNrTotalCarti() {
		return nrTotalCarti;
	}

	void setNrTotalCarti(static int nrNouCarti) {
		nrTotalCarti = nrNouCarti;
	}


	//constr f param
	Biblioteca() : anInfiintare(1990)
	{
		numeBiblioteca = new char[strlen("Biblioteca") + 1];
		strcpy_s(numeBiblioteca, strlen("Biblioteca") + 1, "Biblioteca");
		adresa = "Necunoscut";
		nrAngajati = 10;
		suprafata = 0;
		deschisaInWeekend = false;
	}

	//constr cu p
	Biblioteca(const char* numeBiblioteca, const int an, int nrAngajati) :anInfiintare(an) {
		this->numeBiblioteca = new char[strlen(numeBiblioteca) + 1];
		strcpy_s(this->numeBiblioteca, strlen(numeBiblioteca) + 1, numeBiblioteca);
		this->adresa = "Necunoscuta";
		this->nrAngajati = nrAngajati;
		this->suprafata = 0;
		this->deschisaInWeekend = false;
	}

	//constr
	Biblioteca(const char* numeB, string adresa, float suprafata, bool openWK) : anInfiintare(1990) {
		this->numeBiblioteca = new char[strlen(numeB) + 1];
		strcpy_s(this->numeBiblioteca, strlen(numeB) + 1, numeB);
		this->adresa = adresa;
		this->nrAngajati = 0;
		this->suprafata = suprafata;
		this->deschisaInWeekend = openWK;
	}

	//copy constr
	Biblioteca(const Biblioteca &b) : anInfiintare(b.anInfiintare)
	{
		if (b.numeBiblioteca != NULL) {
			this->numeBiblioteca = new char(strlen(b.numeBiblioteca)+1);
			strcpy_s(this->numeBiblioteca, strlen(b.numeBiblioteca) + 1, b.numeBiblioteca);
		}
		else {
			delete[]this->numeBiblioteca;
		}
		this->adresa = b.adresa;
		this->nrAngajati = b.nrAngajati;
		this->suprafata = b.suprafata;
		this->deschisaInWeekend = b.deschisaInWeekend;
	}

	friend ostream& operator<<(ostream& ost, const Biblioteca& bib) {
		ost << "Denumire: " << bib.numeBiblioteca << endl;
		ost << "An Infiintare: " << bib.anInfiintare << endl;
		ost << "Adresa: " << bib.adresa << endl;
		ost << "Numar Angajati: " << bib.nrAngajati << endl;
		ost << "Suprafata: " << bib.suprafata << endl;
		ost << "Deschid in weekend: " << (bib.deschisaInWeekend ? "DA":"NU") << endl;
		ost << "Numar Total Carti: " << nrTotalCarti << endl;

		return ost;
	}

	friend void afisareInfoBiblioteca(const Biblioteca& bib);

	//destructor
	~Biblioteca() {
		if (this->numeBiblioteca != NULL) {
			delete[]this->numeBiblioteca;
		}
	}

};
int Biblioteca::nrTotalCarti = 400;

void afisareInfoBiblioteca(const Biblioteca& bib) {
	cout << "Informatii biblioteca: " << bib.numeBiblioteca << " - Nr Angajati: " << bib.nrAngajati;
}


class Carte {
private:
	const int idCarte;
	char* numeCarte;
	string numeAutor;
	float pretCarte;
	string editura;
	bool disponibila;
	int nrPagini;
	static float TVA;

public:
	//constr f param
	Carte() :idCarte(1) {
		numeCarte = new char[strlen("Carte1") + 1];
		strcpy_s(numeCarte, strlen("Carte1") + 1, "Carte1");
		numeAutor = "Necunoscut";
		pretCarte = 0;
		editura = "Necunoscut";
		disponibila = false;
		nrPagini = 0;
	}

	//constr cu param
	Carte(const int idCarte, const char* numeC, string numeA, float pretC, 
		string editura, bool disponibila, int nrPagini) :idCarte(idCarte) {
		this->numeCarte = new char[strlen(numeC) + 1];
		strcpy_s(this->numeCarte, strlen(numeC) + 1, numeC);
		this->numeAutor = numeA;
		this->pretCarte = pretC;
		this->editura = editura;
		this->disponibila = disponibila;
		this->nrPagini = nrPagini;
	}

	Carte(const char* numeC, string numeAutor, float pret) :idCarte(0) {
		this->numeCarte = new char[strlen(numeC) + 1];
		strcpy_s(this->numeCarte, strlen(numeC) + 1, numeC);
		this->numeAutor = numeAutor;
		this->pretCarte = pret;
		this->editura = "Necunoscuta";
		this->disponibila = false;
		this->nrPagini = 0;
	}

	//copy constr
	Carte(const Carte& c) :idCarte(c.idCarte) {
		if (c.numeCarte != NULL) {
			this->numeCarte = new char[strlen(c.numeCarte)+1];
			strcpy_s(this->numeCarte, strlen(c.numeCarte) + 1, c.numeCarte);
		}
		else {
			delete[]this->numeCarte;
		}
		
		this->numeAutor = c.numeAutor;
		this->pretCarte = c.pretCarte;
		this->editura = c.editura;
		this->disponibila = c.disponibila;
		this->nrPagini = c.nrPagini;
	}

	friend ostream& operator<<(ostream& ost, const Carte& c) {
		ost << "Id Carte: " << c.idCarte << endl;
		ost << "Nume Carte: " << c.numeCarte << endl;
		ost << "Nume Autor: " << c.numeAutor << endl;
		ost << "Pret Carte: " << c.pretCarte << endl;
		ost << "Disponibilitate Carte: " << (c.disponibila ? "DA":"NU") << endl;
		ost << "Nr Pagini: " << c.nrPagini << endl;
		ost << "TVA: " << c.TVA << endl;
		
		return ost;
	}

	//destructor
	~Carte() {
		if (this->numeCarte != NULL) {
			delete[]this->numeCarte;
		}
	}
};
float Carte::TVA = 0.19;


class Angajat {
private:
	const int idAngajat;
	char* nume;
	int varsta;
	int salariu;
	string functie;
	bool fullTime;
	static int nrAngajati;

public:
	//constr f param
	Angajat():idAngajat(nrAngajati++){
		nume = new char[strlen("Anonim") + 1];
		strcpy_s(nume, strlen("Anonim") + 1, "Anonim");
		varsta = 0;
		salariu = 0;
		functie = "FUNCTIE0";
		fullTime = false;
	}

	//constr cu param
	Angajat(const char *nume, int varsta, int salariu) : idAngajat(nrAngajati++)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->varsta = varsta;
		this->salariu = salariu;
		this->functie = "Functie0";
		this->fullTime = false;
	}

	Angajat(const char *nume, string functie, bool fullTime) : idAngajat(nrAngajati++)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->varsta = 0;
		this->salariu = 0;
		this->functie = functie;
		this->fullTime = fullTime;
	}

	//copy constr
	Angajat(const Angajat& a) :idAngajat(nrAngajati++) {
		if (a.nume != NULL) {
			this->nume = new char[strlen(a.nume) + 1];
			strcpy_s(this->nume, strlen(a.nume) + 1, a.nume);
		}
		else {
			delete[] this->nume;
		}
		this->varsta = a.varsta;
		this->salariu = a.salariu;
		this->functie = a.functie;
		this->fullTime = a.fullTime;
	}

	friend ostream& operator<<(ostream& ost, const Angajat& a) {
		ost << "Id Angajat: " << a.idAngajat << endl;
		ost << "Nume: " << a.nume << endl;
		ost << "Varsta: " << a.varsta << endl;
		ost << "Salariu: " << a.salariu << endl;
		ost << "Functie: " << a.functie << endl;
		ost << "Full Time: " << (a.fullTime ? "DA" : "NU") << endl;
		ost << "Nr. Total Angajati: " << a.nrAngajati << endl;

		return ost;
	}

	~Angajat() {
		if (this->nume != NULL) {
			delete[]this->nume;
		}
	}
};
int Angajat::nrAngajati = 1;

void main() {
	cout << "------------------BIBLIOTECA-------------------" << endl;
	cout << "--------Faza1---------" << endl;
	Biblioteca b1;
	cout << b1 << endl;

	Biblioteca b2("Biblioteca1", 1995, 5);
	cout << b2 << endl;

	Biblioteca b3("Biblioteca2", "Bucuresti, Sector3", 50.0F, true);
	cout << b3 << endl;

	cout << endl << "--------Faza2---------" << endl;


	cout << "-------------------CARTE-----------------------" << endl;
	cout << "--------Faza1---------" << endl;
	Carte c1;
	cout << c1 << endl;
	Carte c2("Carte1", "Autor1", 39.99F);
	cout << c2 << endl;
	Carte c3(10, "Carte4", "Autor4", 40.99F, "EDITURA4", true, 359);
	cout << c3 << endl;

	cout << endl << "--------Faza2---------" << endl;



	cout << "-------------------ANGAJATI--------------------" << endl;
	cout << "--------Faza1---------" << endl;
	Angajat a1;
	cout << a1 << endl;

	Angajat a2("Angajat1", 20, 3000);
	cout << a2 << endl;

	Angajat a3("Angajat2", "Functie1", false);
	cout << a3 << endl;

	cout << endl << "--------Faza2---------" << endl;



}