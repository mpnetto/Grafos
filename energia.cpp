#include <iostream>
#include <stdio.h>
#include <queue>

#define MAX_GRAFO 101
#define BRANCO 0
#define CINZA 1

int grafo[MAX_GRAFO][MAX_GRAFO];
int cor [MAX_GRAFO];

using namespace std;

void BFS(int tamGrafo)
{
	queue<int> fila;
	int root = 1;

	cor[root] = CINZA;

	fila.push(root);

	while(!fila.empty())
	{
		int estacao = fila.front();
		fila.pop();

		for (int i = 1; i <= tamGrafo; ++i)
		{
			if(grafo[estacao][i] == 1 && cor[i] == BRANCO)
			{
				cor[i] = CINZA;
				fila.push(i);
			}
		}
		
	}
}

int main() {

	int E, L, x, y;

	int n = 0;

	while(cin >> E >> L && E != 0)
	{
		for (int i = 1; i <= E; ++i)
		{
			cor[i] = 0;
			for (int j = 1; j <= E; ++j)
				grafo[i][j] = 0;
		}

		for (int i = 0; i < L; ++i)
		{
			cin >> x >> y;

			grafo[x][y] = 1;
			grafo[y][x] = 1;
		}

		BFS(E);

		cout << "Teste " << ++n << endl;

		int soma = 0;

		for (int i = 1; i <= E; ++i)
			soma+=cor[i];

		if(soma == E)
			cout << "normal" << endl;
		else
			cout << "falha" << endl;

		cout << endl;

	}
 
	return 0;
}
