
#include "Cinema.h"

/*
Restituire il genere di film che ha incassato di piu' tra quelli presenti nella lista (escludendo i film per cui il genere e' NONDEFINITO). 
Se due generi diversi hanno incassato lo stesso importo massimo restituire il primo in ordine alfabetico (esempio, ANIMAZIONE precede COMICO)
Se non sono presenti film o se tutti i film hanno il genere NONDEFINITO, restituire NONDEFINITO.
            
*/
Genere Cinema::metodo1()
{
    /* IMPLEMENTARE QUESTO METODO */
    return NONDEFINITO;
}

/*
Sia A l'anno piu' recente di un film nella lista.
Determinare il regista che ha diretto meno film nell'anno A.
Se due o piu' registi hanno diretto lo stesso numero minimo di film nell'anno A, restituire il primo in ordine alfabetico.
Se non sono presenti film, restituire "-1".
            
*/
string Cinema::metodo2()
{
    /* IMPLEMENTARE QUESTO METODO */
    return "-1";
}

/*
Un regista e' detto settoriale se almeno il 70% dei suoi film sono dello stesso genere (includendo il genere NONDEFINITO).
Restituire il numero di registi settoriali.
Se non sono presenti film, restituire -1.

Esempio:
Un regista che ha diretto due film di ANIMAZIONE e un film COMICO NON E' settoriale (67% dei film di ANIMAZIONE e 33% COMICO).
Un regista che ha diretto tre film di COMICO e un film COMMEDIA E' settoriale (75% dei film di COMICO e 25% COMMEDIA).

            
*/
int Cinema::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
Data una qualsiasi coppia di film F1, F2 la differenza di incasso tra i due film e' l'incasso di F1 - l'incasso di F2.
Restituire la differenza di incasso piu' alta tra i film presenti nella lista.
Se sono presenti meno di 2 film nella lista, restituire -1.
            
*/
int Cinema::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}


