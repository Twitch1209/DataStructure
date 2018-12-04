#include"Heap.h"
#include"Graphlnk.h"
#include<iomanip>
#include<string>

using namespace std;
//const float maxValue=FLOAT_MAX;
//最小生成树边结点的定义 
template<class T,class E>
struct MSTEdgeNode
{
	int tail,head;//两顶点 
	E key;//边的权值 
	MSTEdgeNode():tail(-1),head(-1),key(0) {}
	bool operator<=(MSTEdgeNode<T,E>& R){return key<=R.key;}
	bool operator>(MSTEdgeNode<T,E>& R){return key>R.key;}
};

//最小生成树 
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
	int n=G.getNumVertices();						//顶点数 
	int m=G.getNumEdges();							//边数 
	int u=G.getVertexPos(u0);						//求起始顶点号
	MinHeap< MSTEdgeNode<T,E> > H(m);					//最小堆，关键码类型为E
	bool *Vmst=new bool[n];				
	for(i=0;i<n;i++)
	{
		Vmst[i]=false;
	} 
	Vmst[u]=0;
	count=1;										//u加入最小生成树 
	do
	{
		v=G.getFirstNeighbor(u);
		while(v!=-1)								//重复检测u的所有邻接节点 
		{	
			if(Vmst[v]==false)						//若v不在生成树，把（u，v）加入堆 
			{
				ed.tail=u;							//tail在树内，head不在 
				ed.head=v;
				ed.key=G.getWeight(u,v);
				H.Insert(ed);
			}
			v=G.getNextNeighbor(u,v);				//下一个邻接节点 
		}
		while(H.IsEmpty()==false && count<n)
		{
			H.RemoveMin(ed);						//从堆中退出具有最下权值的边ed
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
	cout<<"**"<<setw(32)<<"电网造价模拟系统" <<setw(16)<<"**"<<endl;
	cout<<"=================================================="<<endl;
	cout<<"**"<<setw(32)<<"A --- 创建电网顶点  " <<setw(16)<<"**"<<endl;
	cout<<"**"<<setw(32)<<"B --- 添加电网的边  " <<setw(16)<<"**"<<endl;
	cout<<"**"<<setw(32)<<"C --- 构造最小生成树" <<setw(16)<<"**"<<endl;
	cout<<"**"<<setw(32)<<"D --- 显示最小生成树" <<setw(16)<<"**"<<endl;
	cout<<"**"<<setw(32)<<"E --- 退出程序      " <<setw(16)<<"**"<<endl;
	char order='A';				//操作 
	int numVertices=0;			//顶点个数（不超过50） 
	string nameOfVertices[50]; //顶点名称 
	Graphlnk<string,int> ElecGraph(50);
	MinSpanTree<string,int> MST;
	while(1)
	{
		cout << endl;
		cout<<"请选择操作：";
		cin>>order;
		switch(order)
		{
			case 'A':
			{
				cout<<"请输入顶点的个数：";
				cin>>numVertices;
				if(numVertices>50 ||numVertices<0)
				{
					cout<<"请输入50以内的正整数：";
					cin>>numVertices;	
				} 
				cout<<"请依次输入各顶点的名称：";
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
					cout<<"请输入两个顶点及边：";
					string u,v;
					int value;
					cin>>u>>v>>value;
					//添加边 
					int v1=ElecGraph.getVertexPos(u);
					int v2=ElecGraph.getVertexPos(v);
					//如果出现其他情况则输入结束 
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
				cout<<"请输入起始顶点：";
				string st;
				cin>>st;
				if(Prim(ElecGraph,st,MST))
				{
					cout<<"生成最小生成树！"<<endl;
				}
				continue;
			}
			case 'D':
			{
				cout<<"最小生成树的顶点及边为："<<endl;
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
				cout<<"不合法的操作！"<<endl;
				continue;
			}
		}	
	}
	return 0; 
}






