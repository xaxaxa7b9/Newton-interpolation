#include <iostream>

using namespace std;

float iloraz_1(int* tab_x, int* tab_y, int i)
{
  return (tab_y[i+1]-tab_y[i])/(tab_x[i+1]-tab_x[i]);
}

float Newton(int* tab_x,int* tab_y,int n, int i)
{
	if (n==0)return 1;
	if (n==1)return iloraz_1(tab_x, tab_y, i);	
	return	(Newton(tab_x, tab_y, n - 1, i + 1) - Newton(tab_x, tab_y, n - 1, i)) / (tab_x[i+n] - tab_x[i]);
}

int main(){


  FILE *data;
  data = fopen("data.txt", "r");
 int tab_x[5];
    int tab_y[5];  
    int i=0;

    for(i=0; i<5; i++) 
            fscanf(data, "%d,", &tab_x[i]);

    for(i=0; i<5; i++) 
            fscanf(data, "%d,", &tab_y[i]);

fclose(data);
  
int liczba_punktow=5;
double x = 0;
float wynik=tab_y[0];
double tmp=0;



  
cout << "podaj szukany x: ";
cin >> x;
  
	for (int i=0; i<liczba_punktow; i++)
	{
		tmp = 0;
		for (int j=0; j<i; j++)
    {
			if (j==0)tmp = x-tab_x[0];
			else tmp *= x-tab_x[j];
		}
		wynik += tmp*Newton(tab_x,tab_y,i,0);
	}
  
cout << "licze wartosc dla puntku: " << x <<endl;
cout <<"Wartosc wielomianu Newtona w danym punkcie: " << wynik;

return 0;
}
