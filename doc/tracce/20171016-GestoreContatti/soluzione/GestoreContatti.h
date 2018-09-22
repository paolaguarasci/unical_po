#ifndef GESTORECONTATTO_H
#define GESTORECONTATTO_H

#include "Contatto.h"
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class GestoreContatti{
	private:
		list<Contatto> contatti;
	public:
		GestoreContatti(){}
		void stampaContatti() const;
		int numeroContatti() const;
		void ordina();
		bool inserisciContatto(const Contatto& c);
		bool eliminaContattoConRemove(const Contatto& c);
		bool eliminaContattoConErase(const Contatto& c);
		vector<string> trovaNumeri(const string& nome, const string& cognome);
		string cognomePiuFrequente() const;
		bool verificaDueContattiStessoTelefono();
};

#endif









