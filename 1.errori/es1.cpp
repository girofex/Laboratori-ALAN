#include <iostream>
#include <math.h>
using namespace std;

const int N = 7;

int main(){
	//Abbiamo usato la matricola: 5029301
  double d0=0;
  double d1=1;
  double i[N]={0,1,2,3,4,5,6};
  double a;
  double b=(d1+1) * pow(10, 20);
  double c=-b;
  double ris1[7];
  double ris2[7];
  
  for(int j=0; j<N; j++){
    	a = (d0 + 1) * pow(10, i[j]);
    	
  		ris1[j] = (a+b)+c;
    	ris2[j] = a+(b+c);
    	cout << "(" << ris1[j] << "-" << ris2[j] << ")" << endl;
  }
}
