
#include "Supermercato.h"

/*
	Restituire il numero di rivenditori (distinti) che vendono solamente prodotti appartenti alle categorie MACELLERIA e PESCHERIA.
	Se non sono presenti prodotti restituire -1.
	Se nessun rivenditore vende soltanto prodotti appartenti alle categorie MACELLERIA e PESCHERIA restituire 0.

	Ad esempio, se la lista di prodotti contenesse:
		("Prod1",MACELLERIA,"riv1",10)
		("Prod2",PESCHERIA,"riv1",20)
		("Prod3",PESCHERIA,"riv2",20)
		("Prod3",PROFUMERIA,"riv3",30)
	in cui per ogni prodotto sono riportati (Descrizione,Categoria,Rivenditore,Costo),
	il metodo restituirebbe 2, poiche' "riv1" e "riv2" vendono soltanto prodotti appartenti alle categorie MACELLERIA e PESCHERIA.
            
*/
int Supermercato::metodo1()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
	Un rivenditore appartiene ad una categoria se vende almeno un prodotto di quella categoria.
	Sia C la categoria con almeno un rivenditore, alla quale appartengono il minor numero di rivenditori (distinti).
	Se due o piu' categorie hanno lo stesso numero minimo di rivenditori (distinti), considerare la prima in ordine alfabetico.
	Si noti, inoltre, che un rivenditore puo' appartenere a diverse categorie.

	Restituire il numero di prodotti che hanno categoria C.
	Se non sono presenti prodotti, restituire -1.

	Ad esempio, se la lista di prodotti contenesse:
		("Prod2",PESCHERIA,"riv1",20)
		("Prod3",PESCHERIA,"riv2",20)
		("Prod1",ALTRO,"riv1",30)
		("Prod1",ALTRO,"riv4",40)
	in cui per ogni prodotto sono riportati (Descrizione,Categoria,Rivenditore,Costo),
	la categoria C sarebbe ALTRO, e il metodo restituirebbe 2.
	
	Infatti, si ottiene che:
		ORTOFRUTTA -> 0 rivenditori
		PESCHERIA  -> 2 rivenditori
		MACELLERIA -> 0 rivenditori
		PROFUMERIA -> 0 rivenditori
		ALTRO      -> 2 rivenditori
	Inoltre, i prodotti con categoria ALTRO sono ("Prod1",ALTRO,"riv1",30) e ("Prod1",ALTRO,"riv4",40).
	Per cui, il numero di prodotti che hanno categoria ALTRO e' 2.
            
*/
int Supermercato::metodo2()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
	Un rivenditore si dice 'poliedrico' se vende almeno un prodotto per ciascuna categoria.
	Restituire l'ultimo rivenditore poliedrico in ordine di apparizione nella lista di prodotti.
	Se non sono presenti prodotti restituire "-1".
	Se non sono presenti rivenditori poliedrici restituire "-2".

	Ad esempio, se la lista di prodotti contenesse:
		("Prod1",MACELLERIA,"riv1",10)
		("Prod2",PESCHERIA,"riv1",20)
		("Prod3",ALTRO,"riv1",20)
		("Prod2",PROFUMERIA,"riv1",30)
		("Prod4",ORTOFRUTTA,"riv1",30)
		("Prod2",ORTOFRUTTA,"riv2",30)
	in cui per ogni prodotto sono riportati (Descrizione,Categoria,Rivenditore,Costo),
	il metodo restituirebbe "riv1", che rappresenta l'unico rivenditore poliedrico 
	e l'ultimo rivenditore poliedrico che compare nella lista.
            
*/
string Supermercato::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    return "-1";
}

/*
	Costruire una lista L di rivenditori (distinti), in cui i rivenditori sono ordinati come segue:
		- in ordine cresente rispetto al costo medio dei prodotti che vendono,
		- a parita' di costo medio in ordine alfabetico inverso (dalla Z alla A).

	Il costo medio dei prodotti venduti da un rivenditore e' pari alla somma dei costi diviso 
	il numero di prodotti che vende.
	Inoltre, si utilizzi una media intera. Per cui se un rivenditore vende 4 prodotti, 
	con costo rispettivamente 1,2,3 e 4, il costo medio e' pari a:
		(1+2+3+4)/4 = 10/4 = 2.5 = 2.

	Restituire il primo rivenditore presente in L.
	Se non sono presenti prodotti restituire "-1".

	Ad esempio, se la lista di prodotti contenesse:
		("Prod2",PESCHERIA,"riv1",20)
		("Prod2",ALTRO,"riv1",10)
		("Prod1",ALTRO,"riv3",20)
		("Prod1",ALTRO,"riv4",15)
	in cui per ogni prodotto sono riportati (Descrizione,Categoria,Rivenditore,Costo),
	il metodo restituirebbe "riv4". 
	
	Infatti, si ottiene che:
		riv1 	-> costo medio 15
		riv3	-> costo medio 20
		riv4 	-> costo medio 15
		
	Quindi, i rivenditori con costo medio piu' basso sono riv1 e riv4, e riv4 e' l'ultimo in ordine alfabetico.
            
*/
string Supermercato::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    return "-1";
}


