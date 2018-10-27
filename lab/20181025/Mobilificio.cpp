
#include "Mobilificio.h"

/*
Sia X la media dei prezzi di tutti i mobili. Determinare il massimo
prezzo fra quelli che hanno un prezzo minore o uguale a X.

Per il calcolo della media utilizzare la divisione intera.

Se non sono presenti mobili oppure non esiste alcun mobile
con prezzo maggiore di X, restituire -1.

*/
int Mobilificio::metodo1()
{
    if (mobili.size() == 0)
        return -1;

    int somma = 0;
    for (std::list<Mobile>::iterator iter = mobili.begin(); iter != mobili.end(); iter++)
    {
        somma += iter->getPrezzo();
    }

    int prezzoMedio = somma / mobili.size();

    int maxSottoMedia = -1;

    for (std::list<Mobile>::iterator iter = mobili.begin(); iter != mobili.end(); iter++)
    {
        if (iter->getPrezzo() < prezzoMedio && iter->getPrezzo() > maxSottoMedia)
        {
            maxSottoMedia = iter->getPrezzo();
        }
    }
    return maxSottoMedia;
}

/*
Per ogni produttore P sia M(P) il prezzo medio dei mobili prodotti da P.
Un produttore si dice economico se produce solo mobili il cui prezzo e'
minore del prezzo medio M(P) di ogni *altro* produttore.
Attenzione: Il prezzo dei prodotti del produttore economico E non e' mai confrontato
            con la media M(E) (cioe' e' confrontato con tutti tranne che con se stesso).

Il metodo restituisce il numero di mobili prodotti dal *primo* produttore economico
della lista in ordine alfabetico.

Per il calcolo della media utilizzare la divisione intera.

Se non sono presenti mobili oppure se nessun produttore verifica la condizione oppure se c'e' un solo produttore, restituire -1.


*/
int Mobilificio::metodo2()
{
    if (mobili.size() == 0)
        return -1;
    // vector<string> prod = getProduttori();
    // cout << prod.size();
    // cout << prod[0];
    for (std::list<Mobile>::iterator iter = mobili.begin(); iter != mobili.end(); iter++)
        if (economico(iter->getProduttore()))
        {
            cout << iter->getProduttore() << " | num mobili ";
            return contaMobili(iter->getProduttore());
        }
    return -1;
}
/*
Il metodo restituisce la differenza tra il numero di produttori che producono solo TAVOLI e il numero di produttori che producono solo SEDIE.

Nel caso in cui non siano presenti mobili nel mobilificio, restituire -1.

*/
int Mobilificio::metodo3()
{
    if (mobili.size() == 0)
        return -1;
    int nTavoli = 0;
    int nSedie = 0;

    vector<string> produttori = getProduttori();
    // cout << produttori.size();
    for (std::vector<string>::iterator iter_prod = produttori.begin(); iter_prod != produttori.end(); iter_prod++)
    {
        // cout << (*iter_prod) << endl;
        for (std::list<Mobile>::iterator iter_mobili = mobili.begin(); iter_mobili != mobili.end(); iter_mobili++)
        {
            if (iter_mobili->getProduttore() == (*iter_prod) && iter_mobili->getTipo() == Tipo::SEDIA)
            {
                nSedie++;
                cout << "S";
            }
            if (iter_mobili->getProduttore() == (*iter_prod) && iter_mobili->getTipo() == Tipo::TAVOLO)
            {
                nTavoli++;
                cout << "T";
            }
        }
    }

    return nTavoli - nSedie;
}

/*
Data la seguente definizione:
Un produttore P1 collabora con un produttore P2 se:
- P1 produce un mobile in collaborazione con P2, oppure
- P1 produce un mobile in collaborazione con P3 e P3 collabora con P2.

Inoltre ogni produttore collabora con se stesso.

Il metodo deve restituire il numero di produttori che collabora con l'ultimo
produttore presente nella lista.

Nel caso in cui non ci siano mobili restituisce -1.

Esempio di collaborazione.

Supponiamo che:
- P1 realizza il mobile S con la collaborazione di P2.
- P2 realizza il mobile S1 con la collaborazione di P3.
- P3 realizza il mobile S2 con la collaborazione di P4.

P1 collabora con P1 (se' stesso), P2, con P3 e con P4.
P2 collabora con P2 (se' stesso), P3 e con P4.
P3 collabora con P3 (se' stesso), P4.
P4 collabora con P4 (se' stesso).

Se P1 fosse l'ultimo produttore della lista il metodo restituirebbe 4.
Se P4 fosse l'ultimo produttore della lista il metodo restituirebbe 1.

*/
int Mobilificio::metodo4()
{

    string ultimoProduttore = mobili.back().getProduttore();
    // cout << "Ultimo produttore: " << ultimoProduttore << endl;
    vector<string> collaborazioniUltimoL1 = getCollaborazioni(ultimoProduttore);
    vector<string> collaborazioniUltimoL2;
    for (int i = 1; i < collaborazioniUltimoL1.size(); i++)
    {
        vector<string> tmp = getCollaborazioni(collaborazioniUltimoL1[i]);
        for (int j = 1; j < tmp.size(); j++)
        {
            if (find(collaborazioniUltimoL2.begin(), collaborazioniUltimoL2.end(), tmp[i]) == collaborazioniUltimoL2.end())
            {
                collaborazioniUltimoL2.push_back(tmp[i]);
            }
        }
    }
    return collaborazioniUltimoL2.size() + 1;
}
// calcolo media prezzi escluso il produttore passato come parametro.
// vector<int> Mobilificio::mediaPrezziPerProduttore(vector<string> produttori)
// {
//     int somma = 0;
//     for ()
//         for (std::list<Mobile>::iterator iter = mobili.begin(); iter != mobili.end(); iter++)
//         {
//             if (iter->getPrezzo() < prezzoMedio && iter->getProduttore() != produttore)
//             {
//                 somma = iter->getPrezzo();
//             }
//         }
//     return maxSottoMedia;
// }
int Mobilificio::mediaProd(string prod)
{
    int somma = 0;
    int k = 0;
    for (std::list<Mobile>::iterator iter = mobili.begin(); iter != mobili.end(); iter++)
    {
        if (iter->getProduttore() == prod)
        {
            somma = iter->getPrezzo();
            k++;
        }
    }
    return somma / k;
}

int Mobilificio::prezzoMaxProduttore(string prod)
{
    if (mobili.size() == 0)
        return -1;
    int max = 0;
    for (std::list<Mobile>::iterator iter = mobili.begin(); iter != mobili.end(); iter++)
    {
        if (iter->getProduttore() == prod && iter->getPrezzo() > max)
        {
            max = iter->getPrezzo();
        }
    }

    return max;
}

bool Mobilificio::economico(string prod)
{
    if (mobili.size() == 0)
        return -1;
    int prezzoMax = prezzoMaxProduttore(prod);
    for (std::list<Mobile>::iterator iter = mobili.begin(); iter != mobili.end(); iter++)
    {
        if (iter->getProduttore() != prod && mediaProd(iter->getProduttore()) < prezzoMax)
        {
            return false;
        }
    }

    return true;
}
int Mobilificio::contaMobili(string prod)
{
    if (mobili.size() == 0)
        return -1;
    int k = 0;
    for (std::list<Mobile>::iterator iter = mobili.begin(); iter != mobili.end(); iter++)
    {
        if (iter->getProduttore() == prod)
        {
            k++;
        }
    }

    return k;
}

vector<string> Mobilificio::getProduttori()
{
    vector<string> produttori;
    int k = 0;
    for (std::list<Mobile>::iterator iter = mobili.begin(); iter != mobili.end(); iter++)
    {
        if (find(produttori.begin(), produttori.end(), iter->getProduttore()) == produttori.end())
        {
            produttori.push_back(iter->getProduttore());
        }
    }
    // cout << "Primo produttore " << produttori[0];
    return produttori;
}

vector<string> Mobilificio::getCollaborazioni(string produttore)
{
    vector<string> collaborazioni;
    collaborazioni.push_back(produttore);
    for (std::list<Mobile>::iterator iter = mobili.begin(); iter != mobili.end(); iter++)
    {
        if ((iter->getProduttore() == produttore) && (find(collaborazioni.begin(), collaborazioni.end(), iter->getCollaboratore()) == collaborazioni.end()))
        {
            collaborazioni.push_back(iter->getCollaboratore());
            // cout << iter->getCollaboratore() << endl;
        }
    }
    return collaborazioni;
}