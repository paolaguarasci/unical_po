
#include "AnalizzatoreCerchi.h"

/*
	Siano A e B due cerchi distinti. 
	Sia x1 la coordinata x di A, y1 la coordinata y di A, r1 il raggio di A.
	Sia x2 la coordinata x di B, y2 la coordinata y di B, r2 il raggio di B.
	A e B sono disconessi se:
		(x1-x2)^2 + (y1-y2)^2 > (r1+r2)^2
		
	Un cerchio si dice isolato se e' disconnesso da tutti gli altri cerchi nella lista.
	Restituire il numero di cerchi isolati.
	
	Se non sono presenti cerchi, restituire -1.
	Se non sono presenti cerchi isolati, restituire 0.
	
	Ad esempio, se la lista di cerchi contenesse:
		(3,4,2)
		(10,10,2)
		(10,10,1)
	Il primo ed il secondo cerchio sono disconnessi poiche':
		(3-10)^2+(4-10)^2 = 49+46 = 85 ed inoltre (2+2)^2=16 --> 85 > 16
	Allo stesso modo si puo' notare che anche il primo ed il terzo cerchio sono disconessi.
	Dunque il primo cerchio e' isolato.
	Mentre il secondo ed il terzo cerchio non sono disconnessi, e dunque non sono isolati. 
	Pertanto, il metodo dovrebbe restituire 1.	
            
*/
int AnalizzatoreCerchi::metodo1()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
	Siano A e B due cerchi distinti. 
	Sia x1 la coordinata x di A, y1 la coordinata y di A, r1 il raggio di A.
	Sia x2 la coordinata x di B, y2 la coordinata y di B, r2 il raggio di B.
	Si dice che A e' parte propria di B, se:
		(x1-x2)^2 + (y1-y2)^2 <= (r1-r2)^2 ed inoltre r1 < r2.
	
	Dato un cerchio C, indichiamo con L(C) la lista di cerchi per cui C e' parte propria.
	Sia X il cerchio per cui L(X) contiene il maggior numero di cerchi.
	Se piu' cerchi sono parte propria dello stesso numero massimo di cerchi,
	considerare come cerchio X il primo in ordine di apparizione nella lista.
	Sia Y il cerchio appartenente ad L(X) con raggio minore tra tutti i cerchi in L(X).	
	
	Restituire il raggio di Y.	

	Se non sono presenti cerchi, restituire -1.
	Se nessun cerchio e' parte propria di un altro, restituire 0.

	Ad esempio, se la lista di cerchi contenesse:
		(1,1,4)
		(1,1,3)
		(1,1,2)
		(10,10,3)
		(10,10,1)
	il primo cerchio non e' parte propria di nessun altro cerchio,
	il secondo cerchio e' parte propria del primo cerchio,
	il terzo cerchio e' parte propria del primo e del secondo cerchio,
	il quarto cerchio non e' parte propria di nessun altro cerchio,
	il quinto cerchio e' parte propria del quarto cerchio.
	Per cui il cerchio X e' il terzo cerchio, ed L(X) contiene il primo ed il secondo cerchio.
	Tra di essi, il secondo cerchio ha il raggio minore.
	Pertanto, il metodo dovrebbe restituire 3.
            
*/
int AnalizzatoreCerchi::metodo2()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
	Siano A e B due cerchi distinti. 
	Si dice che A e B sono congruenti se hanno lo stesso raggio.

	Due o piu' cerchi congruenti formano un gruppo congruente.
	
	Sia X il gruppo congruente con raggio minore rispetto a tutti gli altri gruppi congruenti in lista.
	Sia Y il gruppo congruente con raggio maggiore di X ma minore rispetto a tutti gli altri gruppi congruenti in lista.
	
	Restituire la differenza tra il raggio dei cerchi nel gruppo Y e il raggio dei cerchi nel gruppo X.
	
	Se non sono presenti cerchi, restituire -1.
	Se non sono presenti almeno due gruppi congruenti, restituire 0.
	
	Ad esempio, se la lista di cerchi contenesse:
		(1,1,3)
		(2,4,4)
		(4,6,3)
		(10,10,4)
		(5,5,1)
		(5,1,10)
		(1,6,10)
		(1,7,10)
	sono presenti esattamente tre gruppi congruenti, 
	1) un gruppo e' formato dal primo e dal terzo cerchio,
	2) un altro gruppo e' formato dal secondo e dal quarto cerchio,
	3) un altro gruppo e' formato dal sesto, dal settimo e dall'ottavo cerchio.
	Pertanto, il gruppo X corrisponde al gruppo 1 che ha raggio minore in assoluto pari a 3, 
	e il gruppo Y corrisponde al gruppo 2 con raggio pari a 4.
	Pertanto, il metodo restituirebbe 4-3=1.
            
*/
int AnalizzatoreCerchi::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
    	Un cerchio si dice positivo se le sue coordinate x ed y sono positive (> 0).
    	Sia A l'ultimo cerchio positivo presente nella lista.
	Sia M il massimo comune divisore tra la coordinata x di A e la coordinata y di A.

	Restituire il numero di cerchi positivi nella lista
	tali per cui il massimo comune divisore tra le loro coordinate x e y e' inferiore ad M.
	
	Se non sono presenti cerchi o non sono presenti cerchi positivi, restituire -1.
	Se non sono presenti cerchi che soddisfano questa proprieta', restituire M.

	Si ricorda che il massimo comun divisore di due numeri interi a e b, entrambi diversi da zero, 
	corrisponde al numero naturale piu' grande per il quale possono entrambi essere divisi. 	
	
	Ad esempio, se la lista di cerchi contenesse:
		(1,1,3)  --> MCD(1,1) = 1
		(2,4,4)  --> MCD(2,4) = 2
		(4,6,3)  --> MCD(4,6) = 2
		(10,0,4) --> NON POSITIVO
		(0,5,1)  --> NON POSITIVO
 	Il cerchio A corrisponde al terzo cerchio, ed M = MCD(4,6) = 2.
 	Pertanto il metodo restituirebbe 1, poiche' soltanto 
 	il primo cerchio soddista la proprieta' richiesta.
            
*/
int AnalizzatoreCerchi::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}


