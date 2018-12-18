#include<iostream>
#include"Graphlnk.h"

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	Graphlnk<int, int> G(N);
	int v1, v2, cost;
	for (int i = 0; i < N; i++)
	{
		G.insertVertex(i);
	}
	if(TopologicalSort(G, M))
	{
		CriticalPath(G);
	}
	system("pause");
}
