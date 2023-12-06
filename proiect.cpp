#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

class Cladire {
private:
	int suprafata;
public:
	virtual string afiseazaInfo() = 0;
	virtual int metoda() = 0;
};

class Biblioteca : public Cladire
{
private:
	const int anInfiintare;
	string numeBiblioteca;
	int nrAngajati;
	int* varsteAngajati;
	bool deschisaInWeekend;
	static int nrTotalCarti;

public:

	virtual string afiseazaInfo() {
		string info;
		info += "Numar angajati: " + to_string(nrAngajati);
		info += "\nDeschis in weekend? - " + to_string(deschisaInWeekend);

		return info;
	}

	virtual int metoda() {
		int nrNouAng = 0;
		if (deschisaInWeekend == true) {
			nrNouAng = nrAngajati + 1;
		}
		else {
			nrNouAng = nrAngajati;
		}
		return nrNouAng;
	}


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
	Biblioteca(const int an, string numeB, int nrAngajati, int* varsteAngajati, bool openWK) : anInfiintare(an) {
		this->numeBiblioteca = numeB;
		this->nrAngajati = nrAngajati;
		this->varsteAngajati = new int[this->nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			this->varsteAngajati[i] = varsteAngajati[i];
		}
		this->deschisaInWeekend = openWK;
	}

	//constr cu p
	Biblioteca(string numeBiblioteca, int nrAngajati, bool openWK) :anInfiintare(2023) {
		this->numeBiblioteca = numeBiblioteca;
		this->nrAngajati = nrAngajati;
		this->varsteAngajati = new int[this->nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			this->varsteAngajati[i] = rand() % 31 + 20;
		}
		this->deschisaInWeekend = openWK;
	}

	//copy constr
	Biblioteca(const Biblioteca &b) : anInfiintare(b.anInfiintare)
	{
		this->numeBiblioteca = b.numeBiblioteca;
		this->nrAngajati = b.nrAngajati;
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

	friend ofstream& operator<<(ofstream& ost, const Biblioteca& bib) {
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

	friend istream& operator>>(istream& in, Biblioteca& bib) {
		cout << "Nume: "; in >> bib.numeBiblioteca;
		cout << "Nr angajati: "; in >> bib.nrAngajati;

		if (bib.varsteAngajati != NULL) {
			delete[]bib.varsteAngajati;
		}
		bib.varsteAngajati = new int[bib.nrAngajati];
		cout << "Varste: ";
		for (int i = 0; i < bib.nrAngajati; i++) {
			in >> bib.varsteAngajati[i];
		}
		cout << "Deschis in weekend(1-true, 0-false): "; in >> bib.deschisaInWeekend;
		bib.deschisaInWeekend = (bib.deschisaInWeekend != 0);

		return in;
	}

	friend void afisareInfoBiblioteca(const Biblioteca& bib);

	//op[]
	int& operator[](int index) {
		if (index >= 0 && index < nrAngajati) {
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

class Institutie : public Biblioteca {
private:
	int nrSaliLectura;
	bool areAbonament;
	int* nrStudentiInSala;
public:
	//get si set
	int getNrSaliLectura() {
		return this->nrSaliLectura;
	}

	void setNrSaliLectura(int nrNouSaliL) {
		this->nrSaliLectura = nrNouSaliL;
	}

	bool getAbonament() {
		return this->areAbonament;
	}

	void setAbonament(bool areAbNou) {
		this->areAbonament = areAbNou;
	}

	//constr fara param
	Institutie() : Biblioteca() {
		this->nrSaliLectura = 0;
		this->areAbonament = false;
		this->nrStudentiInSala = NULL;
	}

	//constr cu param
	Institutie(int nrSaliL, bool areAb, int* nrStudInSala) : Biblioteca() {
		this->nrSaliLectura = nrSaliL;
		this->areAbonament = areAb;
		this->nrStudentiInSala = new int[nrSaliLectura];
		for (int i = 0; i < nrSaliLectura; i++) {
			this->nrStudentiInSala[i] = nrStudentiInSala[i];
		}
	}

	Institutie(const int an, string numeB, int nrAngajati, int* varsteAngajati, bool openWK, int nrSaliL, bool areAb, int* nrStudentiInSala) : Biblioteca(an, numeB, nrAngajati, varsteAngajati, openWK) {
		this->nrSaliLectura = nrSaliL;
		this->areAbonament = areAb;
		this->nrStudentiInSala = new int[nrSaliLectura];
		for (int i = 0; i < nrSaliLectura; i++) {
			this->nrStudentiInSala[i] = nrStudentiInSala[i];
		}
	}

	//copy constr
	Institutie(const Institutie& ins) : Biblioteca(ins) {
		this->nrSaliLectura = ins.nrSaliLectura;
		this->areAbonament = ins.areAbonament;
		this->nrStudentiInSala = new int[ins.nrSaliLectura];
		for (int i = 0; i < ins.nrSaliLectura; i++) {
			this->nrStudentiInSala[i] = ins.nrStudentiInSala[i];
		}
	}

	//op=
	Institutie& operator=(const Institutie& ins) {
		if (this != &ins) {
			Biblioteca::operator=(ins);
			this->nrSaliLectura = ins.nrSaliLectura;
			this->areAbonament = ins.areAbonament;
			if (this->nrStudentiInSala != NULL) {
				delete[]this->nrStudentiInSala;
			}
			this->nrStudentiInSala = new int[ins.nrSaliLectura];
			for (int i = 0; i < ins.nrSaliLectura; i++) {
				this->nrStudentiInSala[i] = ins.nrStudentiInSala[i];
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& ost, const Institutie& ins) {
		ost << (Biblioteca)ins;
		ost << "Nr sali lectura: " << ins.nrSaliLectura << endl;
		ost << "Are abonament: " << (ins.areAbonament ? "DA" : "NU") << endl;
		if (ins.nrStudentiInSala != NULL) {
			for (int i = 0; i < ins.nrSaliLectura; i++) {
				ost << "Nr studenti din sala: " << i + 1 << " : " << ins.nrStudentiInSala[i] << endl;
			}
			//ost << ins.nrStudentiInSala[ins.nrSaliLectura] << endl;
		}
		else {
			ost << "Nu sunt studenti in sali!" << endl;
		}

		return ost;
	}

	~Institutie() {
		if (this->nrStudentiInSala != NULL) {
			delete[]this->nrStudentiInSala;
		}
	}
};

class ResursaCulturala {
public:
	virtual float calcPret() = 0;
	virtual void afiseazaInformatii() = 0;

	virtual ~ResursaCulturala(){}
};

class Carte : public ResursaCulturala {
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
	virtual float calcPret(){
		return pretCarte + pretCarte * TVA / 100;
	}

	virtual void afiseazaInformatii() {
		cout << "Informatii Carte: " << "\n\tNume: " << numeCarte  <<  "\n\tAutor: " << numeAutor  << "\n\tPret: " << pretCarte << endl;
	}

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

	Carte& operator=(const Carte& c) {
		if (this != &c) {
			if (this->numeCarte != NULL) {
				this->numeCarte = new char[strlen(c.numeCarte) + 1];
				strcpy_s(this->numeCarte, strlen (c.numeCarte) + 1, c.numeCarte);
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
		return *this;
	}



	friend ostream& operator<<(ostream& ost, const Carte& c) {
		ost << "Id Carte: " << c.idCarte << endl;
		ost << "Nume Carte: " << c.numeCarte << endl;
		ost << "Nume Autor: " << c.numeAutor << endl;
		ost << "Pret Carte: " << c.pretCarte << endl;
		ost << "Editura Carte: " << c.editura << endl;
		ost << "Disponibilitate Carte: " << (c.disponibila ? "DA":"NU") << endl;
		ost << "Nr Pagini: " << c.nrPagini << endl;
		ost << "TVA: " << c.TVA << endl;
		
		return ost;
	}

	void scrieInFisierCarte() {
		ofstream f("carte.bin", ios::binary | ios::app);
		if (!f.is_open()) {
			cerr << "Eroare la deschiderea fisierului." << endl;
			return;
		}
		if (this->numeCarte != nullptr) {
			int lungimeNumeCarte = strlen(this->numeCarte);
			f.write((char*)&lungimeNumeCarte, sizeof(int));
			for (int i = 0; i < lungimeNumeCarte; i++) {
				f.write((char*)&this->numeCarte[i], sizeof(char));
			}
		}
		int lungimeNumeAutor = numeAutor.length();
		f.write((char*)&lungimeNumeAutor, sizeof(int));
		f.write(numeAutor.c_str(), lungimeNumeAutor);
		f.write((char*)&this->pretCarte, sizeof(float));
		int lungimeEditura = editura.length();
		f.write((char*)&lungimeEditura, sizeof(int));
		f.write(editura.c_str(), lungimeEditura);
		f.write((char*)&this->disponibila, sizeof(bool));
		f.close();
	}

	friend istream& operator>>(istream& in, Carte& c) {
		char aux[20];
		cout << endl << "Nume Carte: ";
		in >> aux;
		if (c.numeCarte != NULL)
		{
			delete[] c.numeCarte;
		}
		c.numeCarte = new char[strlen(aux) + 1];
		strcpy_s(c.numeCarte, strlen(aux) + 1, aux);
		cout << "Nume Autor: "; in >> c.numeAutor;
		cout << "Pret Carte: "; in >> c.pretCarte;
		cout << "Editura Carte: "; in >> c.editura;
		cout << "Disponibilitate Carte(1 pentru true, 0 pentru false) : "; in >> c.disponibila;
		c.disponibila = (c.disponibila != 0);
		cout << "Nr pagini: "; 
		in >> c.nrPagini;
		in.ignore();

		return in;

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

class Sectiune : public ResursaCulturala{
private:
	string numeSectiune;
	int nrCarti;
	Carte* cartiSectiune;
	int capacitateMax;
public:
	virtual float calcPret() {
		return nrCarti;
	}

	virtual void afiseazaInformatii() {
		cout << "Sectiune: " << numeSectiune <<endl;
	}
	//constr 
	Sectiune() {
		this->numeSectiune = "Sci-Fi";
		this->nrCarti = 3;
		this->cartiSectiune = nullptr;
		this->capacitateMax = 10;
	}

	//get si set
	string getNumeSectiune() {
		return this->numeSectiune;
	}

	void setNumeSectiune(string numeSNou) {
		if (numeSectiune.length() > 2) {
			this->numeSectiune = numeSNou;
		}
	}

	int getNrCarti() {
		return nrCarti;
	}

	void setNrCarti(int nrNouCarti) {
		this->nrCarti = nrNouCarti;
	}

	Carte* getCartiSectiune() {
		return cartiSectiune;
	}

	int getCapMax() {
		return this->capacitateMax;
	}

	void setCapMax(int capMaxNoua) {
		this->capacitateMax = capMaxNoua;
	}

	//constr 
	Sectiune(string nume, int nrCarti, Carte* cartiS, int capMax) : numeSectiune(nume), nrCarti(nrCarti), capacitateMax(capMax) {
		cartiSectiune = new Carte[nrCarti];
		for (int i = 0; i < nrCarti; i++) {
			cartiSectiune[i] = cartiS[i];
		}
	}

	Sectiune(string nume, int nrCaaarti, int capMax) : numeSectiune(nume), nrCarti(nrCarti), capacitateMax(capMax) {
		cartiSectiune = NULL;
	}

	//copy constr
	Sectiune(const Sectiune& s) {
		this->numeSectiune = s.numeSectiune;
		this->nrCarti = s.nrCarti;
		if (s.cartiSectiune != NULL) {
			this->cartiSectiune = new Carte[s.nrCarti];
			for (int i = 0; i < s.nrCarti; i++) {
				cartiSectiune[i] = s.cartiSectiune[i];
			}
		}
		else {
			delete[]this->cartiSectiune;
		}

		this->capacitateMax = s.capacitateMax;
	}

	//op=
	Sectiune& operator=(const Sectiune& s) {
		if (this != &s) {
			this->numeSectiune = s.numeSectiune;
			this->nrCarti = s.nrCarti;
			if (s.cartiSectiune != NULL) {
				this->cartiSectiune = new Carte[s.nrCarti];
				for (int i = 0; i < s.nrCarti; i++) {
					cartiSectiune[i] = s.cartiSectiune[i];
				}
			}
			else {
				delete[]this->cartiSectiune;
			}

			this->capacitateMax = s.capacitateMax;
		}

		return *this;
	}


	friend ostream& operator<<(ostream& ost, const Sectiune& s) {
		ost << "Nume sectiune: " << s.numeSectiune << endl;
		ost << "Numar carti: " << s.nrCarti << endl;
		ost << "Carti: " << endl;
		for (int i = 0; i < s.nrCarti; i++) {
			ost << s.cartiSectiune[i] << endl;
		}
		//ost << "Capacitate Max: " << s.capacitateMax << endl;

		return ost;
	}

	void scrieInFisierSectiune() {
		ofstream f("sectiune.bin", ios::binary | ios::app);
		if (!f.is_open()) {
			cerr << endl << "Eroare la deschiderea fisierului";
			return;
		}
		int lungimeNumeS = numeSectiune.length();
		f.write((char*)&lungimeNumeS, sizeof(int));
		f.write(numeSectiune.c_str(), lungimeNumeS);
		f.write((char*)&this->nrCarti, sizeof(int));
		//vectorul
		for (int i = 0; i < nrCarti; i++) {
			cartiSectiune[i].scrieInFisierCarte();
		}
		f.close();
	}

	Carte& operator[](int index) {
		if (index >= 0 && index < this->nrCarti) {
			return this->cartiSectiune[index];
		}
		throw 404;
	}


	Sectiune& operator+=(const Carte& carteNoua) {
		if (nrCarti < capacitateMax) {
			if (cartiSectiune == NULL) {
				cartiSectiune = new Carte[capacitateMax];
			}
			cartiSectiune[nrCarti++] = carteNoua;
		}
		else {
			throw overflow_error("Sectiune plina");
		}

		return *this;
	}



	~Sectiune() {
		if (cartiSectiune != NULL) {
			delete[]cartiSectiune;
		}	
	}
};

class Angajat{
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

	int getVarsta() {
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
	void setFunctie(string functieNoua) {
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
	Angajat() :idAngajat(nrAngajati++) {
		nume = new char[strlen("Anonim") + 1];
		strcpy_s(nume, strlen("Anonim") + 1, "Anonim");
		varsta = 0;
		salariu = 0;
		functie = "FUNCTIE0";
		fullTime = false;
	}

	//constr cu toti param
	Angajat(const char *nume, int varsta, int salariu, string functie, bool fullTime) : idAngajat(nrAngajati++)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->varsta = varsta;
		this->salariu = salariu;
		this->functie = functie;
		this->fullTime = fullTime;
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

	friend ofstream& operator<<(ofstream& ost, const Angajat& a) {
		ost << "Id Angajat: " << a.idAngajat << endl;
		ost << "Nume: " << a.nume << endl;
		ost << "Varsta: " << a.varsta << endl;
		ost << "Salariu: " << a.salariu << endl;
		ost << "Functie: " << a.functie << endl;
		ost << "Full Time: " << (a.fullTime ? "DA" : "NU") << endl;
		ost << "Nr. Total Angajati: " << a.nrAngajati << endl;

		return ost;
	}

	void scrieInFisier() {
		ofstream f("angajati.bin", ios::binary | ios::app);
		if (!f.is_open()) {
			cerr << "Eroare la deschiderea fisierului." << endl;
			return;
		}
		int lungime = strlen(this->nume);
		f.write((char*)&lungime, sizeof(int));
		for (int i = 0; i < lungime; i++) {
			f.write((char*)&this->nume[i], sizeof(char));
		}
		f.write((char*)&this->varsta, sizeof(int));
		f.write((char*)&this->salariu, sizeof(float));
		//f.write((char*)&this->functie, sizeof(string));
		int lungimeFunctie = functie.length();
		f.write((char*)&lungimeFunctie, sizeof(int));
		f.write(functie.c_str(), lungimeFunctie);
		f.write((char*)&this->fullTime, sizeof(bool));
		f.close();
	}

	friend istream& operator>>(istream& in, Angajat& a) {
		char aux[20];
		cout << endl << "Nume: ";
		in >> aux;
		if (a.nume != NULL)
		{
			delete[] a.nume;
		}
		a.nume = new char[strlen(aux) + 1];
		strcpy_s(a.nume, strlen(aux) + 1, aux);
		cout << "Varsta: "; in >> a.varsta;
		cout << "Salariu: "; in >> a.salariu;
		cout << "Functie: "; in >> a.functie;
		cout << "Full Time(1-true : 0-false): "; in >> a.fullTime;
		a.fullTime = (a.fullTime != 0);

		return in;
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

class AngajatulLunii : public Angajat{
private:
	int prima;
	bool promovat;

public:

	//get si set
	int getPrima() {
		return this->prima;
	}

	void setPrima(int primaNoua) {
		this->prima = primaNoua;
	}

	bool getPromovat() {
		return this->promovat;
	}

	void setPromovat(bool promovareNoua) {
		this->promovat = promovareNoua;
	}

	//constr f param
	AngajatulLunii() : Angajat("Lavinia A.", 33, 3000, "Manager", true) {
		this->prima = 500;
		this->promovat = false;
	}

	//constr cu param
	AngajatulLunii(const char *nume, int varsta, int salariu, string functie, bool fullTime, int prima, bool promovat) : Angajat(nume, varsta, salariu, functie, fullTime) {
		this->prima = prima;
		this->promovat = promovat;
	}

	AngajatulLunii(int prima, bool promovat) : Angajat() {
		this->prima = prima;
		this->promovat = promovat;
	}

	//copy constr
	AngajatulLunii(const AngajatulLunii& al) : Angajat(al) {
		this->prima = al.prima;
		this->prima = al.promovat;
	}

	//op=
	AngajatulLunii operator=(const AngajatulLunii& al) {
		if (this != &al) {
			Angajat::operator=(al);
			this->prima = al.prima;
			this->prima = al.promovat;
		}

		return *this;
	}

	//op<<
	friend ostream& operator<<(ostream& ost, const AngajatulLunii& al) {
		ost << (Angajat)al;
		ost << "Prima: " << al.prima << endl;
		ost << "Promovat: " << (al.prima ? "DA" : "NU") << endl;

		return ost;
	}



};

void main() {
	cout << "------------------BIBLIOTECA-------------------" << endl;

	int* varste = new int[10];
	for (int i = 0; i < 10; i++) {
		varste[i] = rand() % 31 + 20;
	}

	cout << "--------Faza1---------" << endl;
	Biblioteca b1;
	cout << b1 << endl;

	Biblioteca b2("Biblioteca2", 2, 5);
	cout << b2 << endl;

	Biblioteca b3(2023, "Biblioteca3", 3, varste, false);
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
	Biblioteca b5(1980, "Biblioteca5", 2, varste, false);
	Biblioteca b7("Biblioteca6", 4, 4);
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
	Biblioteca b8(1994, "Biblioteca8", 5, varste, true);
	cout << "Suma: " << b8(2, 4) << endl;

	cout << endl << "OP- :\n";
	Biblioteca rezultat = b3 - b5;
	cout << "Rezultat: " << rezultat.getNrAng();

	cout << endl << "--------Faza4---------" << endl;
	Biblioteca vectBiblioteca[3];
	for (int i = 0; i < 3; i++) {
		cout << "Introduceti informatii biblioteca: " << i + 1 << endl;
		//cin >> vectBiblioteca[i];
	}

	////afisare
	//for (int i = 0; i < 3; i++) {
	//	cout << "Afisare: " << endl << vectBiblioteca[i] << endl;
	//}

	//matrice
	//const int nrBiblioteci = 2;
	//const int nrAngajati = 3;

	//Biblioteca matriceBiblioteci[nrBiblioteci][nrAngajati];
	//for (int i = 0; i < nrBiblioteci; i++) {
	//	cout << "Introduceti informatii pentru biblioteca: " << i + 1 << endl;
	//	for (int j = 0; j < nrAngajati; j++) {
	//		cin >> matriceBiblioteci[i][j];
	//	}	
	//}

	////afisare
	//for (int i = 0; i < nrBiblioteci; i++) {
	//	for (int j = 0; j < nrAngajati; j++) {
	//		cout << "Biblioteca " << i + 1 << ", Angajat " << j + 1 << ":" << endl;
	//		cout << matriceBiblioteci[i][j];
	//	}
	//	
	//}


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

	cout << endl << "--------Faza4---------" << endl;

	Carte c7(10, "Carte7", "Autor7", 65.99F, "Editura7", true, 550);
	Carte vectCarti[3];
	for (int i = 0; i < 3; i++) {
		cout << endl << "Introduceti informatii pentru carte: " << i+1 << endl;
		//cin >> vectCarti[i];
	}

	cout << "\n-------------------ANGAJATI--------------------" << endl;
	cout << "--------Faza1---------" << endl;
	Angajat a1;
	cout << a1 << endl;

	Angajat a2("Angajat1", 20, 3000, "Functie1", true);
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
	Angajat a5("Angajat5", 29, 3600, "Functie5", true);
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
	Angajat a7("Angajat7", 22, 2800, "Functie7", true);
	cout << a7 << endl;
	if (!a7) {
		cout << "Angajatul7 are program full time." << endl;
	}
	else {
		cout << "Angajatul7 NU are program full time." << endl;
	}

	cout << endl << "--------Faza4---------" << endl;
	Angajat vectAngajati[3];
	for (int i = 0; i < 3; i++) {
		cout << endl << "Introduceti informatii pentru angajat: " << i + 1 << endl;
		//cin >> vectAngajati[i];
	}


	cout << endl << "---------------------------FAZA 5------------------------------" << endl;

	Sectiune sectiune;
	Carte c9(90, "Carte9", "Autor9", 60.99F, "Editura9", true, 300);
	Carte c10(100, "Carte10", "Autor10", 139.99F, "Editura10", true, 370);


	cout << "\n---------------OP+=  &  OP<<----------------" << endl;

	sectiune += c9;
	sectiune += c10;

	cout << sectiune << endl;


	cout << "\n---------------OP[]----------------" << endl;
	
	try {
		Carte& carteAccesata = sectiune[4];
		cout << "Carte accesata: " << carteAccesata << endl;
	}
	catch(int exceptie){
		cout << "Index out of range!";
	}

	cout << endl << "---------------------------FAZA 6------------------------------" << endl;
	cout << "--------------BIBLIOTECA-ofstream---------------" << endl;
	Biblioteca b15(1990, "Biblioteca15", 3, varste, true);
	ofstream file("biblioteca.txt", ios::out);
	file << b15;

	
	cout << "\n--------------ANGAJATI-ofstream---------------" << endl;
	Angajat a9("Andrei M.", 33, 3300, "Bibliotecar1", true);
	Angajat a10("Alina R.", 30, 1800, "Bibliotecar2", false);
	Angajat a11("Horia C.", 22, 2900, "Bibliotecar3", true);
	Angajat a12("Iolanda D.", 23, 2000, "Bibliotecar4", false);
	//a9.scrieInFisier();
	//a10.scrieInFisier();
	//a11.scrieInFisier();
	//a12.scrieInFisier();

	ofstream fisierAngajati("angajati.txt", ios::out);
	fisierAngajati << a9;
	fisierAngajati << a10;
	fisierAngajati << a11;
	fisierAngajati << a12;

	cout << "\n--------------CARTE-ofstream---------------" << endl;
	Carte c20(20, "Carte20", "Autor20", 39.99F, "Editura20", true, 400);
	Carte c21(21, "Carte21", "Autor21", 59.99F, "Editura21", true, 300);
	c20.scrieInFisierCarte();
	c21.scrieInFisierCarte();

	cout << "\n--------------SECTIUNE-ofstream---------------" << endl;
	Carte cartiSectiune[] = { c20, c21 };
	Sectiune s2("Drama", 2, cartiSectiune, 5);
	s2.scrieInFisierSectiune();

	cout << endl << "---------------------------FAZA 7------------------------------" << endl;
	cout << "\n--------------ANGAJATUL LUNII---------------" << endl;
	AngajatulLunii al1;
	cout << "Functia angajatului lunii:" << al1.getFunctie() << endl;
	cout << "Prima angajatului lunii inainte de marire: " << al1.getPrima() << endl;
	al1.setPrima(1000);
	cout << "Prima angajatului lunii dupa marire: " << al1.getPrima() << endl;
	AngajatulLunii al2("Oana A.", 20, 2000, "Asistent", false, 100, false);
	cout << endl << al2 << endl;
	AngajatulLunii al3;
	al3 = al2;
	cout << al3;

	cout << "\n--------------INSTITUTIE---------------" << endl;
	int* stud = new int[10];
	for (int i = 0; i < 10; i++) {
		stud[i] = rand() % 11 + 10;
	}
	Institutie ins1(1990, "Biblioteca ASE", 3, varste, false, 2, true, stud);
	cout << endl << ins1 << endl;

	cout << "Numar sali lectura: " << ins1.getNrSaliLectura() << endl;
	ins1.setNumeB("ASE Bucuresti");
	cout << "Noul nume al institutiei ins1: " << ins1.getNumeB() << endl;


	Institutie ins2;
	cout << endl << ins2 << endl;

	Institutie ins3;
	ins3 = ins1;
	cout << endl << ins3;

	cout << endl << "---------------------------FAZA 8------------------------------" << endl;

	cout << "\n--------------Cladire---------------" << endl;

	Biblioteca b;
	cout << b.afiseazaInfo() << endl;
	Cladire** angajati;
	angajati = new Cladire*[10];
	angajati[0] = new Biblioteca("Biblioteca1", 2, true);
	angajati[1] = new Biblioteca("Biblioteca2", 1, true);
	angajati[2] = new Biblioteca("Biblioteca3", 5, false);
	angajati[3] = new Biblioteca("Biblioteca4", 7, true);
	angajati[4] = new Biblioteca("Biblioteca5", 4, true);
	angajati[5] = new Biblioteca("Biblioteca6", 2, false);
	angajati[6] = new Biblioteca("Biblioteca7", 3, true);
	angajati[7] = new Biblioteca("Biblioteca8", 2, false);
	angajati[8] = new Biblioteca("Biblioteca9", 2, false);
	angajati[9] = new Biblioteca("Biblioteca10", 1, true);
	cout << "Daca biblioteca este deschisa si in weekend(1-true : 0-false), crestem nr angajatilor.\n" << endl;
	for (int i = 0; i < 10; i++) {
		cout << angajati[i]->afiseazaInfo();
		cout << "\n\tNr nou angajati: " << angajati[i]->metoda() << "\n\n";
	}



	cout << "\n--------------Resursa Culturala---------------" << endl;


	ResursaCulturala** pointeri;
	pointeri = new ResursaCulturala*[10];
	pointeri[0] = new Carte(1, "Harry Potter 1", "J.K.Rolling", 150, "Ping", true, 700);
	pointeri[1] = new Sectiune("Sci-Fi",  2, 10);
	pointeri[2] = new Carte(2, "Lord of the rings", "R.R.Tolkien", 250, "Pingus", true, 800);
	pointeri[3] = new Sectiune("Sci-Fi", 2, 10);
	pointeri[4] = new Carte(3, "Idiotul", "Dostoievski", 100, "Ping", true, 700);
	pointeri[5] = new Sectiune("Literatura clasica", 3, 10);
	pointeri[6] = new Carte(4, "Ion", "Liviu Rebreanu", 70, "Ping", true, 500);
	pointeri[7] = new Sectiune("Literatura clasica", 3, 10);
	pointeri[8] = new Carte(5, "Maitreyi", "Mircea Eliade", 80, "Ping", true, 350);
	pointeri[9] = new Sectiune("Literatura clasica", 3, 10);
	cout << "INFORMATII: " << endl;
	for (int i = 0; i < 10; i++) {
		pointeri[i]->afiseazaInformatii();
	}

}