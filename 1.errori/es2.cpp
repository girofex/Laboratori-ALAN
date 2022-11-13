#include <iostream>
#include <math.h>
using namespace std;

//funzione fattoriale
float fat(float n){
    float f,j; f=1;
    for(j=1;j<=n;j++)
		f=f*j;
	
    return f;
}

int main(){
	float x;
	cout << "Inserisci valore x :\n";
	cin >> x;
	float N;
	cout << "Inserisci N: \n";
	cin >> N;
    float n = 0;
    float somma = 0;

    //sommatoria(taylor)
	for(n; n<=N; n++){
		float fattoriale = fat(n);
		float potenza = pow(x,n);
		float differenza = potenza/fattoriale;
		somma = somma + differenza;
	}
	
	float FdiX = exp(x);
	cout << FdiX << endl;
    cout << "Errore assoluto = " << somma-FdiX << endl;
    cout << "Errore relativo = " << (somma-FdiX)/FdiX << endl;

	cout << "Una diversa approssimazione di f(-" << x << "), usando il reciproco, e' " << 1/somma << endl;
}
