#include <iostream>
#include <math.h>
using namespace std;

float prec_sing(){
    float p = 0;
    float eps = 1;
    for (int d = 0; 1 + eps > 1; d++) {
        eps = pow(2, -d);
        if (1 + eps == 1) 
            p = d--;
    }
    return p;
}

double prec_doppia(){
    double p = 0;
    double eps = 1;
    for (int d = 0; 1 + eps > 1; d++) {
        eps = pow(2, -d);
        if (1 + eps == 1) 
            p = d--;
    }
    return p;
}
        
int main(){
    float sing = prec_sing();
    float dopp = prec_doppia();

    cout << "Singola precisione: eps = 2^-" << sing << " = " << pow(2, -sing) << endl;
    cout << "Doppia precisione:  eps = 2^-" << dopp << " = " << pow(2, -dopp) << endl;
}
