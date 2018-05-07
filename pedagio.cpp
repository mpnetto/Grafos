#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define MC 50

vector<int> vec;
vector<int>::iterator it;

void contaCidades(int grafo[][MC], int nCidades, int cidadeAtual, int nPedagios)
{
   if (nPedagios == 0){ 
   	vec.push_back(cidadeAtual); 
   	return;
   } 
 
   for (int i = 0; i < nCidades; i++)
       if (grafo[cidadeAtual][i] == 1)  
           contaCidades(grafo,nCidades, i, nPedagios-1);
 	
   return;
}

void imprimecidades()
{
	for (it = vec.begin(); it != vec.end()-1; ++it)
	{
		cout << *it << endl;
	}
}

int main(){
	

	int nCidades, nEstradas, cidadeAtual, nPedagios;

	int x, y;

	int n = 0;

	
	while(true)
	{
		cin >> nCidades >> nEstradas >> cidadeAtual >> nPedagios;

		int grafo[MC][MC];

		vec.clear();

		for (int i = 0; i < nCidades; ++i)
			for (int j = 0; j < nCidades; ++j)
				grafo[i][j] = 0;

	
		for (int i = 0; i < nEstradas; ++i)
		{
			cin >> x >> y;

			grafo[x][y] = 1;
			grafo[y][x] = 1;
		}

		cout << "Teste " << ++n << endl;
		
		contaCidades(grafo, nCidades, cidadeAtual, nPedagios);

		imprimecidades();

		if (nCidades== nEstradas == cidadeAtual == nPedagios==0)
			break;

	}

	return 0;
}