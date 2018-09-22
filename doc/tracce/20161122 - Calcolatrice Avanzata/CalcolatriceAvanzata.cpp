
#include "CalcolatriceAvanzata.h"

/*
	Restituire il numero con piu` occorrenze tra i num1 di tutte le quadruple presenti nella lista.
	Nel caso in cui piu` numeri hanno lo stesso numero di occorrenze restituire il piu` piccolo.

	Se la lista e` vuota restituire -1.

	Ad esempio, se la lista contiene:
	(1,2,4,3) (3,4,7,9) (3,4,7,1) (5,6,2,1) (5,5,2,3)
	Il numero 1 e` il num1 delle quadruple (1,2,4,3) per cui 1 volta.
	Il numero 3 e` il num1 delle quadruple (3,4,7,9) (3,4,7,1) per cui 2 volte.
	Il numero 5 e` il num1 delle quadruple (5,6,2,1) (5,5,2,3) per cui 2 volte.
	Poiche 3 < 5, il metodo deve restituire 3.
		    
*/
int CalcolatriceAvanzata::metodo1()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
	Due numeri A e B sono coprimi tra loro se non hanno nessun divisore comune eccetto 1 e -1.
	Una quadrupla di numeri C=(num1,num2,num3,num4) e` staordinaria se:
		- num1 e num2 sono coprimi,
		- num3 e num4 sono coprimi,
		- num4 e` dispari.
	Restituire il num4 dell'ultima quadrupla straordinaria presente nella lista.

	Se la lista e` vuota restituire -1.
	Se non sono presenti quadruple straordinarie, restituire -2.
	
	Ad esempio, se la lista contiene:
	(1,2,4,3) (3,4,7,9) (3,4,7,1) (5,6,2,1) (5,5,2,3)
	Sono quadruple straordinarie: (1,2,4,3) (3,4,7,9) (3,4,7,1) (5,6,2,1).
	Il metodo deve restituire 1, relativo alla quadrupla (5,6,2,1).
		        
*/
int CalcolatriceAvanzata::metodo2()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
	Sia A il piu` grande numero di 4 cifre COSTRUIBILE utilizzando 
	i num1, num2 e num3 delle quadruple nella lista. 
	In particolare, a questo scopo considerare solo i num1, num2 e num3 
	composti da una sola cifra, ovvero >= 1 e <= 9.
	
	Sia B il piu` piccolo numero di 4 cifre presente tra 
	i num4 delle quadruple nella lista.	
	Restituire A-B.

	Se la lista e` vuota restituire -1.
	Se non esistono num4 di 4 cifre oppure 
	se non e` possibile costruire nessun numero di 4 cifre restituire -2.
	
	Ad esempio, se la lista contiene:
	(1,20,4,1231) (3,4,71,9) (3,4,7,1132) (52,7,2,2123) (51,5,2,3)
	Il numero A corrisponde a 7754.
	Il numero B corrisponde a 1132.
	Il metodo deve restituire 7754-1132 = 6622.
		    
*/
int CalcolatriceAvanzata::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
	Data una quadrupla (num1,num2,num3,num4), la sua somma e` calcolata come:
	 num1 + num2 + num3 + num4.
	Una quadrupla e` unica se:
		- il risultato della somma, S, e` un numero dispari, ed inoltre
		- non esiste alcuna quadrupla nella lista che abbia S come num3.
	Restituire il numero di quadruple uniche distinte nella lista.

	Se la lista e` vuota restituire -1.
	Se non sono presenti quadruple uniche, restituire 0.
	
	Ad esempio, se la lista contiene:
	(1,2,4,3) (3,4,7,9) (3,4,7,1) (3,4,7,9)
	Sono quadruple uniche: (3,4,7,9) (3,4,7,1).
	Il metodo deve restituire 2.
		        
*/
int CalcolatriceAvanzata::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}


