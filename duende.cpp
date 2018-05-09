#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

#define MAX_GRAFO 101
#define BRANCO 0
#define CINZA 1

int cor[MAX_GRAFO];

int grafo[MAX_GRAFO][MAX_GRAFO];

void BFS(int grafo[][MAX_GRAFO], int V,  int fonte)
{
	queue<int> fila;

	int dist[V];     
                      
    bool pi[V]; 
  
     for (int i = 0; i < V; i++)
     {
     	dist[i] = MAX_GRAFO;
     	pi[i] = -1;
     }

     dist[fonte] = 0;

     cor[fonte] = CINZA;

     fila.push(fonte);

    while(!fila.empty())
    {
    	int pos = fila.front();
    	fila.pop();

    	for (int i = 0; i < V; ++i)
    	{

    		if(grafo[pos][i] == 1 && cor[i]==BRANCO){
    			dist[i] = min(dist[i],dist[pos]+1);
    			cor[i]=CINZA;
    			fila.push(i);
    		}
    	}
    }
}

int main(){

	int N, M, v, a;

	int fonte;

	int n = 0;

	cin >> N >> M;

	int matriz[N][M];
	

	for (int i = 0; i < N*M; ++i)
		for (int j = 0; j < N*M; ++j)
			grafo[i][j] = 0;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> matriz[i][j];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cor[i*M+j] = BRANCO;

			if (matriz[i][j] == 3)
				fonte = i*M+j;
			if(matriz[i][j] != 2)
			{
				if(j>0 && matriz[i][j-1] != 2)
				{
					grafo[i*M+j][i*M+j-1]=1;
					grafo[i*M+j-1][i*M+j]=1;
				}

				if(j < M-1 && matriz[i][j+1] != 2)
				{
					grafo[i*M+j][i*M+j+1]=1;
					grafo[i*M+j+1][i*M+j]=1;
				}
				if(i > 0 && matriz[i-1][j] != 2)
				{
					grafo[i*M+j][(i-1)*M+j]=1;
					grafo[(i-1)*M+j][i*M+j]=1;
				}
				if(i < N-1 && matriz[i+1][j] != 2)
				{
					grafo[i*M+j][(i+1)*M+j]=1;
					grafo[(i+1)*M+j][i*M+j]=1;
				}
			}
			
		}
	}

	// for (int i = 0; i < N*M; ++i)
	// {
	// 	for (int j = 0; j < N*M; ++j)
	// 		cout << grafo[i][j] << " ";

	// 	cout << endl;
	// }

	

	BFS(grafo, N*M, fonte);

	cout << "fonte: " << fonte << endl;

	for (int i = 0; i < N*M; ++i)
	{
		cout << cor[i] << " ";
	}
	cout << endl;



	return 0;
}