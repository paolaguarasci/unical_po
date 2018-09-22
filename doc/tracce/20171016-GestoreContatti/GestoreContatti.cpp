#include "GestoreContatti.h"

void GestoreContatti::stampaContatti() const{
	for(list<Contatto>::const_iterator it=contatti.begin();it!=contatti.end();it++)
		cout<<(*it);
}

int GestoreContatti::numeroContatti() const{
	return contatti.size();
}

bool GestoreContatti::inserisciContatto(const Contatto& c){
	for(list<Contatto>::iterator it=contatti.begin();it!=contatti.end();it++)
		if((*it)==c)
			return false;
	
	contatti.push_back(c);
	return true;
}

bool GestoreContatti::eliminaContattoConRemove(const Contatto& c){
	unsigned size=contatti.size();
	contatti.remove(c);
	return size!=contatti.size();
}


bool GestoreContatti::eliminaContattoConErase(const Contatto& c){
	for(list<Contatto>::iterator it=contatti.begin();it!=contatti.end();it++){
		if(c==(*it)){
			contatti.erase(it);
			return true;
		}
	}
	return false;
}

void GestoreContatti::ordina(){
	contatti.sort();
}

string GestoreContatti::cognomePiuFrequente() const{
	list<string> cognomi;
	for(list<Contatto>::const_iterator it=contatti.begin();it!=contatti.end();it++)
		cognomi.push_back((*it).getCognome());
	cognomi.sort();
	cognomi.unique();

	unsigned max=0;
	string cognome="";
	for(list<string>::const_iterator it=cognomi.begin();it!=cognomi.end();it++){
		unsigned cont=0;
		for(list<Contatto>::const_iterator it2=contatti.begin();it2!=contatti.end();it2++)
			if((*it)==it2->getCognome())
				cont++;
		if(cont>max){
			max=cont;
			cognome=(*it);
		}
	}
	return cognome;
}

vector<string> GestoreContatti::trovaNumeri(const string& nome, const string& cognome){
	vector<string> numeri;
	for(list<Contatto>::const_iterator it=contatti.begin();it!=contatti.end();it++)
		if(it->getNome()==nome && it->getCognome()==cognome)
			numeri.push_back(it->getTelefono());

	sort(numeri.begin(),numeri.end());
	vector<string>::iterator itUltimo=unique(numeri.begin(),numeri.end());
	numeri.resize(distance(numeri.begin(),itUltimo));
	return numeri;
}

bool GestoreContatti::verificaDueContattiStessoTelefono(){
	for(list<Contatto>::const_iterator it=contatti.begin();it!=contatti.end();it++)
		for(list<Contatto>::const_iterator it2=contatti.begin();it2!=contatti.end();it2++)
			if((it->getNome()!=it2->getNome() || it->getCognome()!=it2->getCognome()) && it->getTelefono()==it2->getTelefono())
				return true;
	return false;
}

