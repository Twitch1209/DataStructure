#include"Heap.h"
#include"Graphlnk.h"
#include<iomanip>
#include<string>

using namespace std;
//const float maxValue=FLOAT_MAX;
//��С�������߽��Ķ��� 
template<class T,class E>
struct MSTEdgeNode
{
	int tail,head;//������ 
	E key;//�ߵ�Ȩֵ 
	MSTEdgeNode():tail(-1),head(-1),key(0) {}
	bool operator<=(MSTEdgeNode<T,E>& R){return key<=R.key;}
	bool operator>(MSTEdgeNode<T,E>& R){return key>R.key;}
};

//��С������ 
template<class T,class E>
class MinSpanTree
{
public:	
	MinSpanTree(int sz=DefaultSize-1):maxSize(sz),n(0)
	{
		edgevalue=new MSTEdgeNode<T,E>[sz];
	}
	void Insert(MSTEdgeNode<T,E> &item);
	bool isEmpty(){return (n==0)?true:false;}
	void show()
	{
		for(int i=0;i<n;i++)
		{
			cout<<edgevalue[i].tail<<"-("
				<<edgevalue[i].key<<")->"
				<<edgevalue[i].head<<endl;
		}
	}
	int getTail(int i) { return edgevalue[i].tail; }
	int getKey(int i) { return edgevalue[i].key; }
	int getHead(int i) { return edgevalue[i].head; }
protected:
	MSTEdgeNode<T,E> *edgevalue;
	int maxSize,n;
};

template<class T,class E>
void MinSpanTree<T,E>::Insert(MSTEdgeNode<T,E> &item)
{
	edgevalue[n]=item;
	n++;
}

template<class T,class E>
bool Prim(Graphlnk<T,E>& G,const T u0,MinSpanTree<T,E>& MST)
{
	MSTEdgeNode<T,E> ed;
	int i,v,count;
	int n=G.getNumVertices();						//������ 
	int m=G.getNumEdges();							//���� 
	int u=G.getVertexPos(u0);						//����ʼ�����
	MinHeap< MSTEdgeNode<T,E> > H(m);					//��С�ѣ��ؼ�������ΪE
	bool *Vmst=new bool[n];				
	for(i=0;i<n;i++)
	{
		Vmst[i]=false;
	} 
	Vmst[u]=0;
	count=1;										//u������С������ 
	do
	{
		v=G.getFirstNeighbor(u);
		while(v!=-1)								//�ظ����u�������ڽӽڵ� 
		{	
			if(Vmst[v]==false)						//��v�������������ѣ�u��v������� 
			{
				ed.tail=u;							//tail�����ڣ�head���� 
				ed.head=v;
				ed.key=G.getWeight(u,v);
				H.Insert(ed);
			}
			v=G.getNextNeighbor(u,v);				//��һ���ڽӽڵ� 
		}
		while(H.IsEmpty()==false && count<n)
		{
			H.RemoveMin(ed);						//�Ӷ����˳���������Ȩֵ�ı�ed
			if(Vmst[ed.head]==false)
			{
				MST.Insert(ed);
				u=ed.head;
				Vmst[u]=true;
				count++;
				break;
			 } 
		}
	}while(count<n);
	if(MST.isEmpty())
	{
		return false;
	}
	return true;
}

int main()
{
	cout<<"**"<<setw(32)<<"�������ģ��ϵͳ" <<setw(16)<<"**"<<endl;
	cout<<"=================================================="<<endl;
	cout<<"**"<<setw(32)<<"A --- ������������  " <<setw(16)<<"**"<<endl;
	cout<<"**"<<setw(32)<<"B --- ��ӵ����ı�  " <<setw(16)<<"**"<<endl;
	cout<<"**"<<setw(32)<<"C --- ������С������" <<setw(16)<<"**"<<endl;
	cout<<"**"<<setw(32)<<"D --- ��ʾ��С������" <<setw(16)<<"**"<<endl;
	cout<<"**"<<setw(32)<<"E --- �˳�����      " <<setw(16)<<"**"<<endl;
	char order='A';				//���� 
	int numVertices=0;			//���������������50�� 
	string nameOfVertices[50]; //�������� 
	Graphlnk<string,int> ElecGraph(50);
	MinSpanTree<string,int> MST;
	while(1)
	{
		cout << endl;
		cout<<"��ѡ�������";
		cin>>order;
		switch(order)
		{
			case 'A':
			{
				cout<<"�����붥��ĸ�����";
				cin>>numVertices;
				if(numVertices>50 ||numVertices<0)
				{
					cout<<"������50���ڵ���������";
					cin>>numVertices;	
				} 
				cout<<"�������������������ƣ�";
				for(int i=0;i<numVertices;i++)
				{
					cin>>nameOfVertices[i];
					ElecGraph.insertVertex(nameOfVertices[i]);
				}
				continue;
			}
			case 'B':
			{
				while(1)
				{
					cout<<"�������������㼰�ߣ�";
					string u,v;
					int value;
					cin>>u>>v>>value;
					//��ӱ� 
					int v1=ElecGraph.getVertexPos(u);
					int v2=ElecGraph.getVertexPos(v);
					//����������������������� 
					if(v1==-1 ||v2==-1)
					{
						break;
					}
					ElecGraph.insertEdge(v1,v2,value);
				}
				continue;	
			}
			case 'C':
			{
				cout<<"��������ʼ���㣺";
				string st;
				cin>>st;
				if(Prim(ElecGraph,st,MST))
				{
					cout<<"������С��������"<<endl;
				}
				continue;
			}
			case 'D':
			{
				cout<<"��С�������Ķ��㼰��Ϊ��"<<endl;
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
				cout<<"���Ϸ��Ĳ�����"<<endl;
				continue;
			}
		}	
	}
	return 0; 
}






