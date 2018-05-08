#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MC 51
#define BRANCO 0
#define CINZA 1

int cor[MC];
int dist[MC];


void BFS(int grafo[][MC], int nCidades, int cidadeAtual, int nPedagios)
{
	queue<int> fila;

	cor[cidadeAtual] = CINZA;

	fila.push(cidadeAtual);

	
	while(!fila.empty())
	{
		int cidade = fila.front();
		fila.pop();

		for (int i = 1; i<=nCidades; ++i){
			if(grafo[cidade][i]==1 && cor[i]==BRANCO && nPedagios > dist[cidade])
			{
				dist[i] = dist[cidade]+1;
				fila.push(i);
				cor[i] = CINZA;
			}
		}

	}

	return;
}

int main(){

	int nCidades, nEstradas, cidadeAtual, nPedagios;

	int x, y;

	int n = 0;

	while(true)
	{
		cin >> nCidades >> nEstradas >> cidadeAtual >> nPedagios;

		if ((nCidades + nEstradas + cidadeAtual + nPedagios) == 0)
			break;

		int grafo[MC][MC];

		for (int i = 1; i <= nCidades; ++i)
		{
			cor[i] = BRANCO;
			dist[i] = 0;
			for (int j = 1; j <= nCidades; ++j)
				grafo[i][j] = 0;
		}

		for (int i = 0; i < nEstradas; ++i)
		{
			cin >> x >> y;

			grafo[x][y] = 1;
			grafo[y][x] = 1;
		}

		cout << "Teste " << ++n << endl;
		
		BFS(grafo, nCidades, cidadeAtual, nPedagios);

		cor[cidadeAtual] = 0;

		for (int i = 1; i <= nCidades; ++i)
		{
			if(cor[i] == 1)
			{
				cout << i << " ";
			}
		}
		cout << endl << endl;

	}

	return 0;
}
