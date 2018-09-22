
#include "Amazon.h"

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
    /* IMPLEMENTARE QUESTO METODO */
    return "-1";
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
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
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
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
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
    /* IMPLEMENTARE QUESTO METODO */
    return "-1";
}


