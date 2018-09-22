
#include "Museo.h"
#include <cmath>
/*
Restituire il numero di quadri dove la coordinata x < 10 e la coordinata y < 11.

Se non sono presenti opere restituire -1.
Se non sono presenti quadri restituire -2.
            
*/
int Museo::metodo1()
{
    if(opere.empty())
	    return -1;

	int cont=0;
	int cont1=0;

	for(list<Opera>::iterator it=opere.begin(); it!=opere.end(); it++)
		{
		if(it->getTipo()==QUADRO)
			cont1++;
		}

	if(cont1!=0)
	{
	for(list<Opera>::iterator it=opere.begin(); it!=opere.end(); it++)
	{
		if(it->getTipo()==QUADRO && it->getX()<10 && it->getY()<11)
			cont++;
	}
	return cont;
	}
	return -2;
}

/*
Calcolare la distanza massima tra due opere d'arte distinte.
Date due opere d'arte O1 e O2, la distanza e` calcolata come la radice quadrata di ((x2-x1)^2 + (y2-y1)^2); dove x1,y1 sono le coordinate di O1 e x2,y2 sono le coordinate di O2.
Utilizzare un intero per la distanza.

Se non sono presenti opere restituire -1.
Se e` presente solo un'opera d'arte restituire 0.
            
*/
int Museo::metodo2()
{
    if(opere.empty())
		return -1;

	if(opere.size()==1)
		return 0;

	vector<Opera> v;
	int n=0;
	int m=0;
	int q=0;

	for(list<Opera>::iterator it=opere.begin(); it!=opere.end(); it++)
	{
		v.push_back(*it);
	}

    for(int i=0; i<v.size(); i++)
        	for(int j=0; j<v.size(); j++)
            if(i!=j)
	        {
		        n=pow((v[j].getX()) - (v[i].getX()),2);// * (v[i+1].getX() - v[i].getX()));
		        m=pow((v[j].getY()) - (v[i].getY()),2); //* (v[i+1].getY() - v[i].getY()));
                if(q<sqrt(n+m))
        		        q=sqrt(n+m);
	        }

	return q;
}

/*
Restituire il numero di artisti che hanno realizzato almeno un quadro ma non hanno realizzato edifici.

Se non sono presenti opere restituire -1;
            
*/
int Museo::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(opere.empty())
        return -1;
    
    list<string> artisti;
    for(list<Opera>::iterator it=opere.begin(); it!=opere.end(); it++)
	{
        if(it->getTipo()==QUADRO)
            artisti.push_back(it->getArtista());
    }

    artisti.sort();
    artisti.unique();

    int count = 0;
    for(list<string>::iterator it2 = artisti.begin(); it2 != artisti.end(); it2++)
    {

        bool considera = true;
        for(list<Opera>::iterator it=opere.begin(); it!=opere.end(); it++)
	    {
            if(it->getArtista() == *it2 && it->getTipo() == EDIFICIO)
                considera = false;
        }
        if(considera)
            count++;
    }
    return count;
}

/*
Sia TMP una lista temporanea di opere d'arte contenenti tutte le opere d'arte del museo.
Ordinare TMP in accordo al seguente schema:
1) prima tutti i quadri in ordine alfabetico sul titolo.
2) poi tutte le statue in ordine alfabetico sul titolo.
3) poi tutti gli edifici in ordine alfabetico sul titolo.

Restituire il titolo dell'opera che si trova in ultima posizione di tmp.
Se non sono presenti opere restituire la stringa "-1";
            
*/
string Museo::metodo4()
{
   if(opere.empty())
	return "-1";

	list<string> q;
	list<string> e;
	list<string> s;
	list<string> tmp;

	for(list<Opera>::iterator it=opere.begin(); it!=opere.end(); it++)
	{
		if(it->getTipo()==QUADRO)
		q.push_back(it->getTitolo());

		if(it->getTipo()==EDIFICIO)
		e.push_back(it->getTitolo());

		if(it->getTipo()==STATUA)
		s.push_back(it->getTitolo());
	}

	q.sort();
	e.sort();
	s.sort();

	for(list<string>::iterator it=q.begin(); it!=q.end(); it++)
		{
		tmp.push_back(*it);
		}

	for(list<string>::iterator it=s.begin(); it!=s.end(); it++)
		{
		tmp.push_back(*it);
		}

	for(list<string>::iterator it=e.begin(); it!=e.end(); it++)
		{
		tmp.push_back(*it);
		}
	string n = tmp.back();
	return n;
}


