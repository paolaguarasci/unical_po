Progettare e implementare la classe Fattura.
La classe deve modellare almeno le seguenti informazioni riguardanti una Fattura:
- il nome dell'azienda che ha emesso la fattura;
- il nome dell'azienda che ha ricevuto la fattura;
- l'importo della fattura (può essere anche negativo);
- il tipo del prodotto venduto (per semplicità si assumano 3 possibili valori: ALIMENTARE, SPORTIVO, CULTURALE).

Implementare inoltre una classe GestoreFatture che contenga una lista di fatture e che implementi i seguenti metodi:
1) Restituire il nome dell'azienda che ha emesso più fatture.
2) Restituire il nome dell'azienda che ha emesso la fattura con l'importo maggiore.
3) Restituire il nome dell'azienda che ha emesso la fattura con l'importo minore.
4) Sia M la media degli importi delle fatture emesse e ricevute da un'azienda. Restituire il nome dell'azienda che ha il valore di M più alto.
5) Restituire il numero di aziende che ha emesso solo fatture per prodotti dello stesso tipo.
6) Restituire la differenza tra il numero di aziende che ha emesso fatture solo per prodotti SPORTIVI e il numero di aziende che ha emesso fatture solo per prodotti CULTURALI.
7) Restituire il numero di aziende che vende solo prodotti ALIMENTARI e compra almeno un prodotto SPORTIVO.
8) Restituire il numero di aziende che non compra prodotti CULTURALI.
9) S(A) la somma degli importi delle fatture emesse da un'azienda A. Siano A1 e A2 due aziende distinte tale per cui S(A1) + S(A2) sia massimo rispetto a tutte le altre coppie di aziende. Restituire il valore di S(A1) + S(A2).
10) Sia A1 l'azienda che ha emesso la fattura per un prodotto ALIMENTARE con l'importo più alto. Sia A2 l'azienda che ha emesso la fattura per un prodotto SPORTIVO con l'importo più basso. Restituire il numero di fatture emesse dall'azienda A1 all'azienda A2.
11) Restituire la stringa con il nome di tutte le aziende che vendono solo prodotti ALIMENTARI separate da una virgola. Esempio di output: A1,A2,A3 (Le aziende devono essere ordinate in ordine lessicografico)
12) Sia A l'azienda che compare di meno nelle fatture (cioè quella che ha emesso e ricevuto meno fatture di tutte le altre). Restituire la stringa con il nome di tutte le aziende che hanno emesso/ricevuto una fattura a/da A separate da una virgola e uno spazio. Esempio di output: A1, A2, A3 (Le aziende devono essere ordinate in ordine lessicografico)

// ricerca ricorsiva
13) Restituire il nome dell'azienda che collabora con più aziende.
14) Restituire la somma degli importi delle fatture emesse dalle aziende che collaborano con la prima azienda in ordine lessicografico.
15) Restituire la stringa con il nome di tutte le aziende che collabora con l'ultima azienda in ordine lessicografico. Esempio di output: A1A2A3 (Le aziende devono essere ordinate in ordine lessicografico)
16) Restituire la somma degli importi delle fatture emesse dall'azienda che ha meno collaborazioni con altre aziende.

Per i metodi dal 13 al 16 si consideri la seguente definizione di collaborazione:
L'azienda A collabora con l'azienda B se:
    - A ha emesso una fattura a favore di B.
    - A collabora con C e C collabora con B.