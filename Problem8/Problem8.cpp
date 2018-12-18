#include"MinSpanTree.h"
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << "**" << setw(32) << "�������ģ��ϵͳ" << setw(16) << "**" << endl;
	cout << "==================================================" << endl;
	cout << "**" << setw(32) << "A --- ������������  " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "B --- ��ӵ����ı�  " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "C --- ������С������" << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "D --- ��ʾ��С������" << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "E --- �˳�����      " << setw(16) << "**" << endl;
	cout << "==================================================" << endl;
	char order = 'A';				//���� 
	int numVertices = 0;			//���������������50�� 
	string nameOfVertices[50]; //�������� 
	Graphlnk<string, int> ElecGraph(50);
	MinSpanTree<string, int> MST;
	while (1)
	{
		cout << endl;
		cout << "��ѡ�������";
		cin >> order;
		switch (order)
		{
			case 'A':
			{
				cout << "�����붥��ĸ�����";
				cin >> numVertices;
				if (numVertices>50 || numVertices<0)
				{
					cout << "������50���ڵ���������";
					cin >> numVertices;
				}
				cout << "�������������������ƣ�";
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
					cout << "�������������㼰�ߣ�";
					string u, v;
					int value;
					cin >> u >> v >> value;
					//��ӱ� 
					int v1 = ElecGraph.getVertexPos(u);
					int v2 = ElecGraph.getVertexPos(v);
					//����������������������� 
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
				cout << "��������ʼ���㣺";
				string st;
				cin >> st;
				if (Prim(ElecGraph, st, MST))
				{
					cout << "������С��������" << endl;
				}
				continue;
			}
			case 'D':
			{
				cout << "��С�������Ķ��㼰��Ϊ��" << endl;
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
				cout << "���Ϸ��Ĳ�����" << endl;
				continue;
			}
		}
	}
	return 0;
}
