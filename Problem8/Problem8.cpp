#include"MinSpanTree.h"
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << "**" << setw(32) << "电网造价模拟系统" << setw(16) << "**" << endl;
	cout << "==================================================" << endl;
	cout << "**" << setw(32) << "A --- 创建电网顶点  " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "B --- 添加电网的边  " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "C --- 构造最小生成树" << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "D --- 显示最小生成树" << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "E --- 退出程序      " << setw(16) << "**" << endl;
	cout << "==================================================" << endl;
	char order = 'A';				//操作 
	int numVertices = 0;			//顶点个数（不超过50） 
	string nameOfVertices[50]; //顶点名称 
	Graphlnk<string, int> ElecGraph(50);
	MinSpanTree<string, int> MST;
	while (1)
	{
		cout << endl;
		cout << "请选择操作：";
		cin >> order;
		switch (order)
		{
			case 'A':
			{
				cout << "请输入顶点的个数：";
				cin >> numVertices;
				if (numVertices>50 || numVertices<0)
				{
					cout << "请输入50以内的正整数：";
					cin >> numVertices;
				}
				cout << "请依次输入各顶点的名称：";
				for (int i = 0; i<numVertices; i++)
				{
					cin >> nameOfVertices[i];
					ElecGraph.insertVertex(nameOfVertices[i]);
				}
				continue;
			}
			case 'B':
			{
				while (1)
				{
					cout << "请输入两个顶点及边：";
					string u, v;
					int value;
					cin >> u >> v >> value;
					//添加边 
					int v1 = ElecGraph.getVertexPos(u);
					int v2 = ElecGraph.getVertexPos(v);
					//如果出现其他情况则输入结束 
					if (v1 == -1 || v2 == -1)
					{
						break;
					}
					ElecGraph.insertEdge(v1, v2, value);
				}
				continue;
			}
			case 'C':
			{
				cout << "请输入起始顶点：";
				string st;
				cin >> st;
				if (Prim(ElecGraph, st, MST))
				{
					cout << "生成最小生成树！" << endl;
				}
				continue;
			}
			case 'D':
			{
				cout << "最小生成树的顶点及边为：" << endl;
				for (int i = 0; i < numVertices - 1; i++)
				{
					cout << ElecGraph.getValue(MST.getTail(i)) << "-("
						<< MST.getKey(i) << ")->"
						<< ElecGraph.getValue(MST.getHead(i)) << endl;
				}
				continue;
			}
			case 'E':
			{
				return 0;
			}
			default:
			{
				cout << "不合法的操作！" << endl;
				continue;
			}
		}
	}
	return 0;
}
