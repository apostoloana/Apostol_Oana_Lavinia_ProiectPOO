#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Biblioteca {
private:
	const int anInfiintare;
	string numeBiblioteca;
	int nrAngajati;
	int* varsteAngajati;
	bool deschisaInWeekend;
	static int nrTotalCarti;

public:

	//get si set
	string getNumeB() {
		return numeBiblioteca;
	}

	void setNumeB(string numeBNou) {
		if (numeBiblioteca.length() > 2) {
			this->numeBiblioteca = numeBNou;
		}
	}

	int getNrAng() {
		return this->nrAngajati;
	}

	void setNrAng(int nrNAng) {
		this->nrAngajati = nrNAng;
	}

	int* getVarsteAng() {
		return this->varsteAngajati;
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
		this->numeBiblioteca = "Necunoscut";
		this->nrAngajati = 10;
		this->varsteAngajati = new int[this->nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			this->varsteAngajati[i] = rand() % 31 + 20;
		}
		this->deschisaInWeekend = false;
	}

	//constr
	Biblioteca(string numeB, int nrAngajati, int* varsteAngajati, bool openWK) : anInfiintare(1990) {
		this->numeBiblioteca = numeB;
		this->nrAngajati = nrAngajati;
		this->varsteAngajati = new int[this->nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			this->varsteAngajati[i] = varsteAngajati[i];
		}
		this->deschisaInWeekend = openWK;
	}

	//constr cu p
	Biblioteca(string numeBiblioteca, const int an, int nrAngajati) :anInfiintare(an) {
		this->numeBiblioteca = numeBiblioteca;
		this->nrAngajati = nrAngajati;
		this->varsteAngajati = new int[this->nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			this->varsteAngajati[i] = rand() % 31 + 20;
		}
		this->deschisaInWeekend = false;
	}

	//copy constr
	Biblioteca(const Biblioteca &b) : anInfiintare(b.anInfiintare)
	{
		this->numeBiblioteca = b.numeBiblioteca;
		this->nrAngajati = b.nrAngajati;
		if (b.varsteAngajati != nullptr) {
			this->varsteAngajati = new int[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->varsteAngajati[i] = b.varsteAngajati[i];
			}
		}
		else {
			this->varsteAngajati = nullptr;
		}
		this->deschisaInWeekend = b.deschisaInWeekend;
	}


	Biblioteca operator=(const Biblioteca& b) {
		if (this != &b) {
			this->numeBiblioteca = b.numeBiblioteca;
			this->nrAngajati = b.nrAngajati;
			delete[] this->varsteAngajati;
			if (b.varsteAngajati != NULL) {
				this->varsteAngajati = new int[this->nrAngajati];
				for (int i = 0; i < this->nrAngajati; i++) {
					this->varsteAngajati[i] = b.varsteAngajati[i];
				}
			}
			else {
				delete[]this->varsteAngajati;
			}
			this->deschisaInWeekend = b.deschisaInWeekend;
		}
		return *this;
	}


	friend ostream& operator<<(ostream& ost, const Biblioteca& bib) {
		ost << "An Infiintare: " << bib.anInfiintare << endl;
		ost << "Denumire: " << bib.numeBiblioteca << endl;
		ost << "Numar Angajati: " << bib.nrAngajati << endl;
		ost << "Varste: ";
		if (bib.varsteAngajati != NULL) {
			for (int i = 0; i < bib.nrAngajati - 1; i++) {
				ost << bib.varsteAngajati[i] << ", ";
			}
			ost << bib.varsteAngajati[bib.nrAngajati - 1] << endl;
		}
		else {
			ost << "N/A" << endl;
		}
		ost << "Deschis in weekend: " << (bib.deschisaInWeekend ? "DA" : "NU") << endl;
		ost << "Numar Total Carti: " << nrTotalCarti << endl;

		return ost;
	}

	friend void afisareInfoBiblioteca(const Biblioteca& bib);

	//op[]
	int& operator[](int index) {
		if(index >= 0 && index < nrAngajati) {
			return this->varsteAngajati[index];
		}
		throw 404;
	}

	//op()
	int operator()(int indexStart, int indexStop) {
		int suma = 0;
		for (int i = indexStart; i < indexStop; i++) {
			suma += this->varsteAngajati[i];
		}
		return suma;
	}

	//op cast
	Biblioteca operator-(const Biblioteca& b) {
		Biblioteca aux = *this;
		aux.nrAngajati -= b.nrAngajati;
		return aux;
	}


	//destructor
	~Biblioteca() {
		if (this->varsteAngajati != NULL) {
			delete[]this->varsteAngajati;
		}
	}

};
int Biblioteca::nrTotalCarti = 400;

void afisareInfoBiblioteca(const Biblioteca& bib) {
	cout << "Functie globala: " << endl;
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
	//get si set
	char* getNumeC() {
		return numeCarte;
	}

	void setNumeC(char* numeCNou) {
		if (strlen(numeCNou) > 2) {
			delete[] numeCarte;
			numeCarte = new char[strlen(numeCNou) + 1];
			strcpy_s(numeCarte, strlen(numeCNou) + 1, numeCNou);
		}
	}

	string getNumeAutor() {
		return numeAutor;
	}

	void setNumeAutor(string numeAutorNou) {
		if (numeAutor.length() > 2) {
			this->numeAutor = numeAutorNou;
		}
	}

	float getPretCarte() {
		return pretCarte;
	}

	void setPretCarte(float pretNouCarte) {
		this->pretCarte = pretNouCarte;
	}

	string getEditura() {
		return editura;
	}

	void setEditura(string edituraNoua) {
		if (editura.length() > 2) {
			this->editura = edituraNoua;
		}
	}

	bool getDisponibilitate() {
		return disponibila;
	}

	void setDisponibilitate(bool dispNoua) {
		this->disponibila = dispNoua;
	}

	int getNrPag() {
		return nrPagini;
	}

	void setNrPag(int nrNouPag) {
		this->nrPagini = nrNouPag;
	}

	static float getTVA() {
		return TVA;
	}

	void setTVA(static float nouTVA) {
		if (nouTVA >= 0 && nouTVA <= 100) {
			this->TVA = nouTVA;
		}
		else {
			cerr << "Eroare: Valoare TVA invalida." << endl;
		}
		
	}

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

	Carte operator=(const Carte& c) {
		if (this != &c) {
			if (this->numeCarte != NULL) {
				delete[]this->numeCarte;
			}
			this->numeCarte = new char[strlen(c.numeCarte) + 1];
			strcpy_s(this->numeCarte, strlen(c.numeCarte) + 1, c.numeCarte);
			this->numeAutor = c.numeAutor;
			this->pretCarte = c.pretCarte;
			this->editura = c.editura;
			this->disponibila = c.disponibila;
			this->nrPagini = c.nrPagini;
		}
		return *this;
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

	//op++
	Carte operator++() {
		this->pretCarte += 10;
		return *this;
	}

	Carte operator++(int) {
		Carte aux = *this;
		this->pretCarte += 10;
		return aux;
	}

	//op==
	bool operator==(const Carte& c) {
		return this->pretCarte == c.pretCarte;
	}

	//op+
	Carte operator+(const Carte& c) {
		Carte suma;
		suma.pretCarte = this->pretCarte + c.pretCarte;
		return suma;
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
	//get si set
	char* getNume() {
		return this->nume;
	}

	void setNume(char* numeNou) {
		if (strlen(numeNou) > 2) {
			delete[]this->nume;
			nume = new char[strlen(numeNou) + 1];
			strcpy_s(nume, strlen(numeNou) + 1, numeNou);
		}
	}

	int getVarsta(){
		return this->varsta;
	}
	void setVarsta(int varstaNoua) {
		this->varsta = varstaNoua;
	}
	int getSalariu() {
		return this->salariu;
	}
	void setSalariu(int salariuNou) {
		this->salariu = salariuNou;
	}
	string getFunctie() {
		if (functie.length() > 2) {
			return this->functie;
		}
	}
	void setFunctie(string functieNoua){
		if (functie.length() > 2) {
			this->functie = functieNoua;
		}
	}

	bool getFullTime() {
		return fullTime;
	}
	void setFullTime(bool timeNou) {
		this->fullTime = timeNou;
	}

	static int getNrAng() {
		return nrAngajati;
	}
	void setNrAng(static int nrNouAng) {
		this->nrAngajati = nrNouAng;
	}

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

	//op=
	Angajat operator=(const Angajat& a) {
		if (this != &a) {
			if (this->nume != NULL) {
				delete[]this->nume;
				
			}
			this->nume = new char[strlen(a.nume) + 1];
			strcpy_s(this->nume, strlen(a.nume) + 1, a.nume);
			this->varsta = a.varsta;
			this->salariu = a.salariu;
			this->functie = a.functie;
			this->fullTime = a.fullTime;
		}
		return *this;
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

	//op>
	bool operator>(const Angajat& a) {
		return this->salariu > a.salariu;
	}

	Angajat operator+=(int valoare) {
		this->salariu += valoare;
		return *this;
	}

	bool operator!() {
		return !fullTime;
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

	int* varste = new int[10];
	for (int i = 0; i < 10; i++) {
		varste[i] = rand() % 31 + 20;
	}

	cout << "--------Faza1---------" << endl;
	Biblioteca b1;
	cout << b1 << endl;

	Biblioteca b2("Biblioteca2", 1995, 5);
	cout << b2 << endl;

	Biblioteca b3("Biblioteca3", 3, varste, false);
	cout << b3 << endl;

	cout << endl << "--------Faza2---------" << endl;
	Biblioteca b4 = b3;
	cout << b4 << endl;

	afisareInfoBiblioteca(b2);

	cout << endl << "GET & SET: ";
	cout << endl << "Numarul de angajati pentru Biblioteca3: " << b3.getNrAng();
	b4.setNumeB("Humanitas");
	cout << endl << "Noul nume al lui b4: " << b4.getNumeB();

	cout << endl << "--------Faza3---------" << endl;
	Biblioteca b5("Biblioteca5", 2, varste, false);
	Biblioteca b7("Biblioteca6", 1990, 4);
	b7 = b5;
	cout << endl << b7;

	cout << endl << "OP[] :\n";
	try {
		cout << b3[1] << endl;
		b3[1] = 18;
		cout << b3[1] << endl;
	}
	catch (int exceptie) {
		cout << "\nIndex out of range!";
	}
	
	cout << endl << "OP() :\n";
	Biblioteca b8("Biblioteca8", 5, varste, true);
	cout << "Suma: " << b8(2, 4) << endl;

	cout << endl << "OP- :\n";
	Biblioteca rezultat = b3 - b5;
	cout << "Rezultat: " << rezultat.getNrAng();


	cout << "\n-------------------CARTE-----------------------" << endl;
	cout << "--------Faza1---------" << endl;
	Carte c1;
	cout << c1 << endl;
	Carte c2("Carte1", "Autor1", 39.99F);
	cout << c2 << endl;
	Carte c3(10, "Carte4", "Autor4", 40.99F, "EDITURA4", true, 359);
	cout << c3 << endl;

	cout << endl << "--------Faza2---------" << endl;

	Carte c4 = c3;
	cout << c4 << endl;

	cout << endl << "GET & SET: ";
	cout << endl << "Pretul lui c2: " << c2.getPretCarte();
	c3.setTVA(0.2F);
	cout << endl << "c3 - TVA: " << c3.getTVA();


	cout << endl << "--------Faza3---------" << endl;
	Carte c5(10, "Carte5", "Autor5", 46.99F, "Editura5", true, 290);
	Carte c6("Carte6", "Autor6", 38.99F);
	c6 = c5;
	cout << c6 << endl;

	cout << endl << "OP== :\n";
	if (c3 == c6) {
		cout << "Angajatii au acelasi salariu." << endl;
	}
	else {
		cout << "Angajatii NU au acelasi salariu." << endl;

	}

	cout << endl << "OP++ :\n";
	cout << "Pret inainte de marire: " << c5.getPretCarte();
	c5 = c4++;
	c5 = ++c4;
	cout << "Pret dupa marire: " << c5.getPretCarte();

	cout << endl << "OP+ :\n";
	Carte suma = c5 + c6;
	cout << "Pret carte5: " << c5.getPretCarte() << endl;
	cout << "Pret carte6: " << c6.getPretCarte() << endl;
	cout << "Suma: " << suma.getPretCarte();

	

	cout << "\n-------------------ANGAJATI--------------------" << endl;
	cout << "--------Faza1---------" << endl;
	Angajat a1;
	cout << a1 << endl;

	Angajat a2("Angajat1", 20, 3000);
	cout << a2 << endl;

	Angajat a3("Angajat2", "Functie1", false);
	cout << a3 << endl;

	cout << endl << "--------Faza2---------" << endl;

	Angajat a4 = a3;
	cout << a4;

	cout << endl << "GET & SET: ";
	
	cout << endl << "Functia angajatului a4 - " << a4.getFunctie();
	a2.setSalariu(4500);
	cout << endl << "Noul salariu al lui a2: " << a2.getSalariu();

	cout << endl << "--------Faza3---------" << endl;
	Angajat a5("Angajat5", 29, 3600);
	Angajat a6("Angajat6", "Functia6", true);
	a6 = a5;
	cout << a6 << endl;
	cout << endl << "OP> :\n";
	if (a6 > a2) {
		cout << "Angajatul a6 are salariul mai mare decat angajatul a2." << endl;
	}
	else {
		cout << "Angajatul a6 are salariul mai mic decat angajatul a2." << endl;
	}

	cout << endl << "OP+= :\n";

	cout << "Salariul lui a4 inainte de marire: " << a5.getSalariu() << endl;
	a5 += 400;
	cout << "Salariul lui a4 dupa marire: " << a5.getSalariu() << endl;

	cout << endl << "OP! :\n";
	Angajat a7("Angajat7", "Functie7", true);
	cout << a7 << endl;
	if (!a7) {
		cout << "Angajatul7 este full time." << endl;
	}
	else {
		cout << "Angajatul7 NU este full time." << endl;
	}


}