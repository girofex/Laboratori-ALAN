#include <iostream>
#include <cmath>
using namespace std;

/*
	ga1 = grandezza matrice A1
	ga2 = grandezza matrice A2
	gp = grandezza matrice P
	gt = grandezza matrice T
*/

void stampa_mat(float* matrice[], int n1, int n2){
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++)
            cout << matrice[i][j] << "\t";
        
        cout << "\n";
    }
}

int main(){
    //MATRICE A1
    float A1[4][4] = {
		{ 3, 1, -1, 0 }, 
		{ 0, 7, -3, 0 }, 
		{ 0, -3, 9, -2 }, 
		{ 0, 0, 4, -10 }
	};

	const int ga1 = 4;
    float** a1 = new float*[ga1];

    for(int i = 0; i < ga1; i++){
        a1[i] = new float[ga1];

        for (int j = 0; j < ga1; j++)
            a1[i][j] = A1[i][j];
    }

    //MATRICE A2
    float A2[4][4] = {
        { 2, 4, -2, 0 },
        { 1, 3, 0, 1 },
        { 3, -1, 1, 2 },
        { 0, -1, 2, 1 }
    };

    const int ga2 = 4;
    float** a2 = new float* [ga2];

    for(int i = 0; i < ga2; i++){
        a2[i] = new float[ga2];

        for(int j = 0; j < ga2; j++)
            a2[i][j] = A2[i][j];
    }
    
    //MATRICE P
    const int gp = 10;
    float** p = new float* [gp];

    for(int i = 0; i < gp; i++){
        p[i] = new float[gp];

        for(int j = 0; j < gp; j++){
            if(i == 0 || j == 0) 
				p[i][j] = 1 ;
			else
				p[i][j] = (p[i][j - 1] + p[i - 1][j]);
        }
    }
    
    //MATRICE T
    //Abbiamo usato la matricola di Josen Hans Chellakkudam: 4979416
    const int d0 = 6; // ultima cifra matricola
    const int d1 = 1; // penultima cifra matricola
    const int gt = 10 * (d1 + 1) + d0;

    float** t = new float* [gt];

    for(int i = 0; i < gt; i++){
        t[i] = new float[gt];

        for(int j = 0; j < gt; j++){
            if(i == j)
                t[i][j] = 2;

            else if(fabs(i - j) == 1)
                t[i][j] = -1;

            else t[i][j] = 0;
        }
    }


    //variabili per registrare le somme
    double sum_A1 = 0.0;
    double sum_A2 = 0.0;
    double sum_p = 0.0;
    double sum_t= 0.0;

    //variabili per registrare i massimi
    double max_A1 = 0.0; //tutte le somme sono >= 0
    double max_A2 = 0.0;
    double max_p = 0.0;
    double max_t = 0.0;

    //scorro e sommo il valore assoluto della casella corrente. se il valore � maggiore del massimo corrente, aggiorno il massimo
    for(int i = 0; i < 4; ++i){
        sum_A1 = 0.0;

        for(int j = 0; j < 4; ++j)
            sum_A1 += fabs(a1[i][j]);

        if(sum_A1 > max_A1)
            max_A1 = sum_A1;
    }
    
    //stampa_mat(a1,4,4);
    cout << "Norma infinito di A1: " << max_A1 << endl;
    
    cout << endl;

    //stessa cosa per matrice B
    for(int i = 0; i < 4; ++i){
        sum_A2 = 0.0;

        for(int j = 0; j < 4; ++j)
            sum_A2 += fabs(a2[i][j]);

        if(sum_A2 > max_A2)
            max_A2 = sum_A2;
    }
    
    //stampa_mat(a2,4,4);
    cout << "Norma infinito di A2: " << max_A2 << endl;
    
    cout << endl;
    
    for(int i=1; i<4; ++i){
        sum_p = 0.0;

        for(int j=1; j<4; ++j) 
            sum_p += fabs(p[i][j]);
        
        if(sum_p > max_p)
            max_p = sum_p;
    }

	//stampa_mat(p,gp,gp);
	cout << "Norma infinito di A=P: " << max_p << endl;
	
	cout << endl;
	
	for(int i=0; i<4; ++i){
        sum_t = 0.0;

        for(int j=0; j<4; ++j)
            sum_t += fabs(t[i][j]);

        if(sum_t > max_t)
            max_t = sum_t;
    }
    
    //stampa_mat(t,gt,gt);
    cout << "Norma infinito di A=T: " << max_t << endl;
    

}
