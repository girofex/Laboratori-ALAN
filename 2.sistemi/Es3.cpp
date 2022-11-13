#include <iostream>
#include <cmath>
using namespace std;

/*
	ga1 = grandezza matrice A1
	ga2 = grandezza matrice A2
	gp = grandezza matrice P
	gt = grandezza matrice T
	va1 = vettore termini noti di A1
	va2 = vettore termini noti di A2
	vp = vettore termini noti di P
	vt = vettore termini noti di T
	xa1 = vettore soluzione di A1
	xa2 = vettori soluzione di A2
	xp = vettore soluzione di P
	xt = vettore soluzione di T
	v_pert_a1 = vettore perturbato di a1
	v_pert_a2 = vettore perturbato di a2
	v_pert_p = vettore perturbato di P
	v_pert_t = vettore perturbato di T
*/

void stampa_matrice(float* matrice[], int n1, int n2){
    for(int i = 0; i < n1; i++){
        cout << "{ ";

        for(int j = 0; j < n2; j++){
            if(matrice[i][j] < 0)
                cout << matrice[i][j];

            else
                cout << " " << matrice[i][j];

            if(j + 1 != n1)
                cout << "\t";
        }

        cout << " }\n";
    }

    cout << "\n";
}

float* gauss(float*  matrice[], float* vettore, const int dim){
    float* soluzioni = new float[dim]; // vettore delle soluzioni
    float mat[dim][dim+1]; // matrice composta dalla matrice originale e vettore dei termini noti

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim + 1; j++){
            if(j < dim) 
				mat[i][j] = matrice[i][j];
			else
				mat[i][j] = vettore[i];
        }
    }

    for(int i = 0; i < dim - 1; i++){
        for(int j = i + 1; j < dim; j++){
            float f = mat[j][i] / mat[i][i];
            for(int k = 0; k < dim + 1; k++)
                mat[j][k] = mat[j][k] - f * mat[i][k];
        }
    }
    // scorrimento indietro per trovare la soluzione
    for(int i = dim - 1; i >= 0; i--){
        soluzioni[i] = mat[i][dim];

        for(int j = i + 1; j < dim; j++){
            if (i != j)
                soluzioni[i] = soluzioni[i] - mat[i][j] * soluzioni[j];
        }

        soluzioni[i] = soluzioni[i] / mat[i][i];
    }

    return soluzioni;
}

float* trova_v(float* matrice[], int dim){
    float* v = new float[dim];
    float elem = 0;

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++)
            elem += matrice[i][j];
        
        v[i] = elem;
        elem = 0;
    }

    return v;
}

void vett_trasposto(float vettore[], int dim){
    for(int i = 0; i < dim; i++){
        if(i == 0)
            cout << "[";

        else
            cout << "";

        cout << vettore[i];

        if(i+1 < dim)
            cout << ", ";

        else
            cout << "]\n";
    }
}

float norma_inf_vect(float* vettore, int dim){
    float norma = 0;
    float tmp = 0;

    for(unsigned int i = 0; i < dim; i++){
        tmp = fabs(vettore[i]);

        if(tmp > norma)
            norma = tmp;
    }

    return norma;
}

// Perturba il vettore 
float* perturba_v(float* vettore, int dim){
    float* v_perturbato = vettore;
    float n_inf = norma_inf_vect(vettore, dim);

    for(unsigned int i = 0; i < dim; i++){
        if(i%2 == 0)
            v_perturbato[i] += (n_inf * -0.01);
        
        else
            v_perturbato[i] += (n_inf * 0.01);
    }
    
    return v_perturbato;
}

int main() {
    const int ga1 = 4;
    //MATRICE A1
    float A1[4][4] = {
        { 3, 1, -1, 0 },
        { 0, 7, -3, 0 },
        { 0, -3, 9, -2 },
        { 0, 0, 4, -10 }
    };

    float** a1 = new float* [ga1];
    for(int i = 0; i < ga1; i++){
        a1[i] = new float[ga1];

        for (int j = 0; j < ga1; j++)
            a1[i][j] = A1[i][j];
    }

    //MATRICE A2
    const int ga2 = 4;
    float A2[4][4] = {
        { 2, 4, -2, 0 },
        { 1, 3, 0, 1 },
        { 3, -1, 1, 2 },
        { 0, -1, 2, 1 }
    };

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
				p[i][j] = 1;

			else
				p[i][j] = (p[i][j - 1] + p[i - 1][j]);
        }
    }

    //stampa_matrice(p, gp, gp);

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

    //stampa_matrice(t, gp, gp);

    float* va1 = trova_v(a1, ga1);
    float* va2 = trova_v(a2, ga2);
    float* vp = trova_v(p, gp);
    float* vt = trova_v(t, gt);

	// Matrice A1
    float* v_pert_a1 = perturba_v(va1, ga1);
    cout << "Vettore dei termini noti di A1= ";
    vett_trasposto(v_pert_a1, ga1);

    float* xa1 = gauss(a1, v_pert_a1, ga1);
    cout << "Vettore soluzioni di A1= \t";
    vett_trasposto(xa1, ga1);

    // Matrice A2 
    float* v_pert_a2 = perturba_v(va2, ga2);
    cout << "\nVettore dei termini noti di A2= ";
    vett_trasposto(v_pert_a2, ga2);

    float* xa2 = gauss(a2,v_pert_a2, ga2);
    cout << "Vettore soluzioni di A2= \t";
    vett_trasposto(xa2, ga2);

    // Matrice P
    float* v_pert_p = perturba_v(vp, gp);
    cout << "\nVettore dei termini noti della mat. di Pascal= \n";
    vett_trasposto(v_pert_p, gp);

    float* xp = gauss(p, v_pert_p, gp);
    cout << "Vettore soluzioni di P= \n";
    vett_trasposto(xp, gp);

    // Matrice T
    float* v_pert_t = perturba_v(vt, gt);
    cout << "\nVettore dei termini noti della mat. tridiagonale= \n";
    vett_trasposto(v_pert_t, gt);

    float* xt = gauss(t, v_pert_t, gt);
    cout << "Vettore soluzioni di T= \n";
    vett_trasposto(xt, gt);

}
