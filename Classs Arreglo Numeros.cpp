#include <iostream>
#include <string.h>
#include <array>

using namespace std;

class ArregloNNP{
public:
	int *arreglo;

	ArregloNNP(int n){
		int a = 0, in = 0, r =0;
		/*while (a<n)
		{
			for (int i = 0; i < n; i++) {
				if ( i%in==0)
					r=r+in;
					in++;

			}
		} */
		for (int i=0; i<n; i++) {
			arreglo[i]=i;
		}
	}
	bool checarNNP(ArregloNNP A, int c) {
		int i = 1; r = 0;

		while(i<arreglo[c]){
			if(arreglo[c]%i==0)
				r=r+i;
			i++;
		}
		if(r==areglo[c])
			return true;
		else
			return false;

	}
};

int main ()
{
	int c = 0, n;
	cout << "Dame el tamaño del arreglo: " ; cin >>n;
	ArregloNNP a(n);

	for (int i=0; i<n; i++)
	{
		if (a.checarNNP(a, c)== true)
			cout<< "Es un numero natural perfecto" <<endl;
		else
			cout<< "no es un numero natural perfecto " <<endl;

		c++;

	}
}