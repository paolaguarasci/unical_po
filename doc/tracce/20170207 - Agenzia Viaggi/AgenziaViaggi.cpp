
#include "AgenziaViaggi.h"

/*
	Il ricavo di un viaggio e' definito come il prodotto tra numero di prenotazioni e costo a persona.
	Restituire la destinazione del viaggio con il ricavo piu' alto.
	Se non sono presenti viaggi restituire "-1".
	Se due o piu' viaggi hanno come ricavo lo stesso ricavo massimo,
	restituire la destinazione del viaggio con distanza piu' bassa.

	Ad esempio, se la lista di viaggi contenesse:
		("Londra",EUROPA,3000,50,100)
		("Tokyo",ASIA,10000,1000,200) 
		("New York",AMERICA,9000,2000,100)
	in cui per ogni viaggio sono riportati (Destinazione,Continente,Distanza,Costo,Prenotazioni),
	il metodo restituirebbe "New York".

	Infatti, il ricavo massimo e' 200000 e si ottiene su due viaggi con destinazioni "Tokio" e "New York".
	Tuttavia, per il viaggio a "New York" la distanza e' 9000, mentre per il viaggio a "Tokyo" e' 10000.
            
*/
string AgenziaViaggi::metodo1()
{
    /* IMPLEMENTARE QUESTO METODO */
    return "-1";
}

/*
	Sia C il continente con il maggior numero di destinazioni (distinte).
	Se due o piu' continenti hanno lo stesso numero massimo di destinazioni, considerare il primo in ordine alfabetico.
	Restituire il numero di prenotazioni totali per il continente C.
	Se non sono presenti viaggi, restituire "-1".

	Ad esempio, se la lista di viaggi contesse:
		("Londra",EUROPA,3000,50,100)
		("Tokyo",ASIA,10000,1000,200) 
		("New York",AMERICA,9000,2000,100)
		("New York",AMERICA,9000,1500,130)
	in cui per ogni viaggio sono riportati (Destinazione,Continente,Distanza,Costo,Prenotazioni),
	il il metodo restituirebbe 230.

	Il numero di destinazioni per i continenti AMERICA, ASIA e EUROPA e' pari a 1, mentre per OCEANIA e AFRICA e' 0.
	Il maggior numero di destinazioni e' 1, e si deve considerare il continente AMERICA, dal momento che e' il primo in ordine alfabetico.
	Il totale delle prenotazioni per AMERICA e' 230.
            
*/
int AgenziaViaggi::metodo2()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
	Si supponga di classificare i viaggi presenti nella lista in viaggi occidentali e viaggi orientali.
	I viaggi che hanno come continente EUROPA o AMERICA sono occidentali.
	I viaggi che hanno come continente ASIA sono orientali.
	Sia N1 il numero totale di prenotazioni nei viaggi occidentali.
	Sia N2 il numero totale di prenotazioni nei viaggi orientali.
	Se N1 >= N2 restituire la destinazione occidentale piu' ambita,
	ovvero la destinazione occidentale per cui sono presenti piu' prenotazioni.
	Nel caso in cui piu' destinazioni occidentali hanno lo stesso 
	numero massimo di prenotazioni restituire la prima in ordine di apparizione nella lista.	
	Se N1 < N2 restituire la destinazione orientale piu' ambita,
	ovvero la destinazione orientale per cui sono presenti piu' prenotazioni.
	Nel caso in cui piu' destinazioni orientali hanno lo stesso 
	numero massimo di prenotazioni restituire la prima in ordine di apparizione nella lista.
	Se non sono presenti viaggi, oppure se non sono presenti viaggi nei continenti EUROPA, AMERICA e ASIA restituire "-1".
	Inoltre, si noti che alcune destinazioni potrebbero fare parte di piu' continenti (ad esempio Cambridge si trova si in AMERICA sia in EUROPA).

	Ad esempio, se la lista di viaggi contenesse:
	("Londra",EUROPA,3000,50,100)
	("Tokyo",ASIA,10000,1000,200)
	("New York",AMERICA,9000,2000,100)
	("New York",AMERICA,9000,1500,130)
	in cui per ogni viaggio sono riportati (Destinazione,Continente,Distanza,Costo,Prenotazioni),
	il metodo restituirebbe "New York".

	Infatti, N1 = 100 + 100 + 130 = 330, mentre N2 = 200.
	Poiche' N1 >= N2, bisogna restituire la destinazione occidentale con piu' prenotazioni.
	Per "Londra" abbiamo 100 prenotazioni, mentre per "New York" 230.
            
*/
string AgenziaViaggi::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    return "-1";
}

/*
	Costruire una lista L di destinazioni (distinte), in cui le destinazioni sono ordinate come segue:
		- in ordine decrescente rispetto al numero di occorrenze nella lista di viaggi,
		- a parita' di numero di occorrenze in ordine alfabetico (dalla A alla Z).

	Restituire la penultima destinazione presente in L.
	Se non sono presenti almeno due destinazioni distinte o non sono presenti viaggi restituire "-1".

	Ad esempio, se la lista di viaggi contenesse:
		("Londra",EUROPA,3000,50,100)
		("Tokyo",ASIA,10000,1000,200) 
		("New York",AMERICA,9000,2000,100)
		("New York",AMERICA,9000,1500,130)
	in cui per ogni viaggio sono riportati (Destinazione,Continente,Distanza,Costo,Prenotazioni),
	il metodo restituirebbe "Londra".

	Infatti, la lista L contiene le destinazioni nell'ordine:
		New York	(Numero Occorrenze 2)
		Londra		(Numero Occorrenze 1)	
		Tokyo 		(Numero Occorrenze 1)
            
*/
string AgenziaViaggi::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    return "-1";
}


