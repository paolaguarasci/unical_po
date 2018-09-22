#include "Amazon.h"
#include <climits>
/*
	Un venditore si considera affidabile se tutti gli articoli che vende
	hanno una recensione diversa da "NESSUNA" e uguale o superiore a "QUATTRO_STELLE".
	Restituire il venditore affidabile con la somma dei prezzi piu' bassa
	rispetto a tutti gli altri venditori affidabili.
	Se piu' venditori verificano questa proprieta' restituire il primo in ordine alfabetico.

	Se non sono presenti articoli, restituire "-1".
	Se non sono presenti venditori affidabili, restituire "-2".

	Ad esempio, se la lista di articoli contenesse:
		("Articolo1","venditoreA",10,TRE_STELLE,AMAZON_STANDARD)
		("Articolo2","venditoreB",20,QUATTRO_STELLE,AMAZON_STANDARD)
		("Articolo3","venditoreB",20,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo4","venditoreC",40,QUATTRO_STELLE,ALTRO)
		("Articolo5","venditoreD",5,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo6","venditoreD",15,NESSUNA,ALTRO)
	in cui per ogni articolo sono riportati (Nome,Venditore,Prezzo,Recensione,Spedizione),
	si otterrebbe:
		venditoreA	-> NON affidabile, somma prezzi 10
		venditoreB	-> affidabile, somma prezzi 40
		venditoreC	-> affidabile, somma prezzi 40
		venditoreD	-> NON affidabile, somma prezzi 20
	pertanto, il metodo restituirebbe "venditoreB".

*/
string Amazon::metodo1()
{
	if(articoli.empty())
    	return "-1";

	list<string> affidabili;

	for(list<Articolo>::const_iterator it=articoli.begin();it!=articoli.end();it++){
		string v=it->getVenditore();
		bool affidabile=true;
		for(list<Articolo>::const_iterator it2=articoli.begin();it2!=articoli.end();it2++){
			if(v==it2->getVenditore()){
				if(it2->getRecensione()!=QUATTRO_STELLE
					&& it2->getRecensione()!=CINQUE_STELLE){
					affidabile=false;
					break;
				}
			}
		}
		if(affidabile)
			affidabili.push_back(v);
	}

	if(affidabili.empty())
		return "-2";

	int min=INT_MAX;
	string vmin="";

	affidabili.sort();

	for(list<string>::const_iterator it=affidabili.begin();it!=affidabili.end();it++){
		string v=(*it);
		int somma=0;
		for(list<Articolo>::const_iterator it2=articoli.begin();it2!=articoli.end();it2++){
			if(v==it2->getVenditore())
				somma+=it2->getPrezzo();
		}
		if(somma<min)
		{
			min=somma;
			vmin=v;
		}
	}
	return vmin;
}

/*
	Sia R la recensione piu' ricorrente nella lista degli articoli.
	Restituire il prezzo medio degli articoli che hanno recensione R.
	Inoltre, si utilizzi una media intera.

	Se piu' recensioni hanno la stessa ricorrenza considerare
	la prima in ordine di apparizione nella lista.

	Se non sono presenti articoli, restituire -1.

	Ad esempio, se la lista di articoli contenesse:
		("Articolo1","venditoreA",10,TRE_STELLE,AMAZON_STANDARD)
		("Articolo2","venditoreB",20,QUATTRO_STELLE,AMAZON_STANDARD)
		("Articolo3","venditoreB",20,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo4","venditoreC",40,QUATTRO_STELLE,ALTRO)
		("Articolo5","venditoreD",5,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo6","venditoreD",15,NESSUNA,ALTRO)
	in cui per ogni articolo sono riportati (Nome,Venditore,Prezzo,Recensione,Spedizione),
	si otterrebbe:
		NESSUNA		-> 1 occorrenza, media prezzi 15
		UNA_STELLA	-> 0 occorrenze, media prezzi 0
		DUE_STELLE	-> 0 occorrenze, media prezzi 0
		TRE_STELLE	-> 1 occorrenza, media prezzi 10
		QUATTRO_STELLE	-> 2 occorrenze, media prezzi 30
		CINQUE_STELLE	-> 2 occorrenze, media prezzi 12
	pertanto, il metodo restituirebbe 30, ottenuto in corrispondenza di "QUATTRO_STELLE".

*/
int Amazon::metodo2()
{
	if(articoli.empty())
	    return -1;

	Recensione r;
	int max=-1;
	int maxSomma=0;
	for(list<Articolo>::const_iterator it=articoli.begin();it!=articoli.end();it++){
		Recensione r1=it->getRecensione();
		int occorrenze=0;
		int somma=0;
		for(list<Articolo>::const_iterator it2=articoli.begin();it2!=articoli.end();it2++){
			if(r1==it2->getRecensione()){
				somma+=it2->getPrezzo();
				occorrenze++;
			}
		}
		if(occorrenze>max){
			max=occorrenze;
			maxSomma=somma;
			r=r1;
		}
	}
	int media=maxSomma/max;
	return media;
}

/*
	Restituire il numero di articoli spediti solamente da Amazon,
	ovvero gli articoli per cui come modalita' di spedizione e' presente AMAZON_PRIME e/o AMAZON_STANDARD.
	Se non sono presenti articoli nella lista, restituire -1.
	Se non sono presenti articoli che soddisfano questa proprieta', restituire -2.

	Ad esempio, se la lista di articoli contenesse:
		("Articolo1","venditoreA",10,TRE_STELLE,AMAZON_PRIME)
		("Articolo1","venditoreB",20,QUATTRO_STELLE,ALTRO)
		("Articolo2","venditoreB",20,CINQUE_STELLE,AMAZON_PRIME)
		("Articolo2","venditoreC",20,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo3","venditoreC",40,QUATTRO_STELLE,ALTRO)
		("Articolo4","venditoreC",40,QUATTRO_STELLE,AMAZON_PRIME)
	in cui per ogni articolo sono riportati (Nome,Venditore,Prezzo,Recensione,Spedizione),
	il metodo restituirebbe 2, poiche' "Articolo2" ed "Articolo4" sono gli unici articoli
	che soddisfano questa proprieta'.

*/
int Amazon::metodo3()
{
	if(articoli.empty())
    	return -1;

	list<string> l;

	for(list<Articolo>::const_iterator it=articoli.begin();it!=articoli.end();it++){
		string a=it->getNome();
		bool ok=true;
		for(list<Articolo>::const_iterator it2=articoli.begin();it2!=articoli.end();it2++){
			if(a==it2->getNome() && it2->getSpedizione()==ALTRO)
				ok=false;
		}
		if(ok)
			l.push_back(a);
	}

	l.sort();
	l.unique();

	if(l.empty())
		return -2;
	return l.size();
}

/*
	Dato un venditore V, siano:
		V1 il numero di prodotti con recensione "UNA_STELLA",
		V2 il numero di prodotti con recensione "DUE_STELLE",
		V3 il numero di prodotti con recensione "TRE_STELLE",
		V4 il numero di prodotti con recensione "QUATTRO_STELLE",
		V5 il numero di prodotti con recensione "CINQUE_STELLE".
	Il punteggio assegnato a V e' pari a:
		5 * V5 + 4 * V4 + 3 * V3 + 2 * V2 + 1 * V1

	Costruire una lista L in cui i venditori sono ordinati:
		- in ordine descrescente per punteggio,
		- a parita' di punteggio in ordine alfabetico (dalla A alla Z).

	Restituire il primo venditore in L.

	Se sono presenti meno di 2 venditori, restituire "-2".
	Se non sono presenti articoli nella lista, restituire "-1".

	Ad esempio, se la lista di articoli contenesse:
		("Articolo1","venditoreA",10,TRE_STELLE,AMAZON_STANDARD)
		("Articolo2","venditoreB",20,QUATTRO_STELLE,AMAZON_STANDARD)
		("Articolo3","venditoreB",20,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo4","venditoreC",40,QUATTRO_STELLE,ALTRO)
		("Articolo5","venditoreD",5,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo6","venditoreD",15,QUATTRO_STELLE,ALTRO)
	in cui per ogni articolo sono riportati (Nome,Venditore,Prezzo,Recensione,Spedizione),
	la lista L sarebbe cosi' costruita:
		venditoreB	-> punteggio 9
		venditoreD	-> punteggio 9
		venditoreC	-> punteggio 4
		venditoreA	-> punteggio 3
	pertanto, il metodo restituirebbe "venditoreB".


*/
string Amazon::metodo4()
{
	if(articoli.empty())
    	return "-1";
	list<string> venditori;
	for(list<Articolo>::const_iterator it=articoli.begin();it!=articoli.end();it++)
		venditori.push_back(it->getVenditore());

	venditori.sort();
	venditori.unique();

	if(venditori.size()<2)
		return "-2";

	string vmax="";
	int pmax=0;
	for(list<string>::const_iterator it=venditori.begin();it!=venditori.end();it++){
		string v=(*it);
		int v1=0,v2=0,v3=0,v4=0,v5=0;
		for(list<Articolo>::const_iterator it2=articoli.begin();it2!=articoli.end();it2++){
			if(it2->getVenditore()==v){
				if(it2->getRecensione()==UNA_STELLA)
					v1++;
				if(it2->getRecensione()==DUE_STELLE)
					v2++;
				if(it2->getRecensione()==TRE_STELLE)
					v3++;
				if(it2->getRecensione()==QUATTRO_STELLE)
					v4++;
				if(it2->getRecensione()==CINQUE_STELLE)
					v5++;
			}
		}
		int p=5*v5+4*v4+3*v3+2*v2+v1;
		if(p>pmax){
			pmax=p;
			vmax=v;
		}
	}
	return vmax;
}



