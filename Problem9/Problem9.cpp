#include<iostream>
#include"Graphlnk.h"

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	Graphlnk<int, int> G(N);
	for (int i = 0; i < N; i++)
	{
		G.insertVertex(i);
	}
	//int v1, v2, cost;
	//for (int i = 0; i<M; i++)
	//{
	//	cin >> v1 >> v2 >> cost;
	//	v1--;
	//	v2--;
	//	G.insertEdge(v1, v2, cost);
	//}
	if (TopologicalSort(G, M))
	{
		CriticalPath(G);
	}

	system("pause");
}
