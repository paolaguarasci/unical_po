#include "GestoreContatti.h"

int main(){
	GestoreContatti contatti;

	Contatto c1("mario","rossi","123","mario@gmail.com");
	Contatto c2("luca","bianchi","456","luca@libero.it");
	Contatto c3("giorgio","rossi","678","giorgio@gmail.com");
	Contatto c4("antonio","rossi","456","antonio@gmail.com");

	if(contatti.inserisciContatto(c1))
		cout<<"Contatto c1 inserito"<<endl;
	if(contatti.inserisciContatto(c2))
		cout<<"Contatto c2 inserito"<<endl;
	if(contatti.inserisciContatto(c3))
		cout<<"Contatto c3 inserito"<<endl;
	if(contatti.inserisciContatto(c4))
		cout<<"Contatto c4 inserito"<<endl;

	cout<<"Il gestore contiene: "<<endl;
	contatti.stampaContatti();

	if(contatti.eliminaContattoConRemove(c1))
		cout<<"Contatto c1 eliminato con Remove"<<endl;

	if(contatti.eliminaContattoConErase(c1))
		cout<<"Contatto c1 eliminato con Erase"<<endl;

	contatti.ordina();
	cout<<"Dopo l'ordinamento, il gestore contiene: "<<endl;
	contatti.stampaContatti();

	cout<<"Il cognome piu frequente e': "<<contatti.cognomePiuFrequente()<<endl;

	vector<string> numeri=contatti.trovaNumeri("mario","rossi");

	if(numeri.size()==0){
		cout<<"Non ci sono numeri per mario rossi"<<endl;
	}
	else{
		cout<<"I numeri di mario rossi sono: "<<endl;
		for(unsigned i=0;i<numeri.size();i++){
			cout<<numeri[i]<<endl;
		}
	}

	if(contatti.verificaDueContattiStessoTelefono())
		cout<<"Esistono due contatti con lo stesso numero"<<endl;
	else
		cout<<"NON esistono due contatti con lo stesso numero"<<endl;

	return 0;
}



