#include<iostream>
#include"Graphlnk.h"

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	Graphlnk<int, int> G(N);
//	int v1, v2, cost;
	for (int i = 1; i <= N; i++)
	{
		G.insertVertex(i);
	}
//ÊäÈëÒ»Ìõ±ß£¨i£¬j£©
	//for(int i=0;i<M;i++)
	//{
	//	cin >> v1 >> v2 >> cost;
	//	G.insertEdge(v1, v2, cost);
	//}
	TopologicalSort(G, M);
	CriticalPath(G);
	system("pause");
}