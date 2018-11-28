#include"MyStack.h"


const int m=5;
const int p=5;
int Maze[m + 2][p + 2] = {{1,1,1,1,1,1,1},
						  {1,0,1,0,0,0,1},
						  {1,0,1,0,1,1,1},
						  {1,0,0,0,1,0,1},
						  {1,0,1,0,0,0,1},
						  {1,0,1,0,1,0,1},
						  {1,1,1,1,1,1,1}};

int mark[m+2][p+2];
//λ����ֱ�������µ�ƫ�� 
struct offsets{
	int a,b;		//a refer to x,b refer to y
};
//����˸�����
offsets Move[8]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

//���Թ�ĳһλ��[i][j]��ʼ��Ѱ��ͨ�����[m][p]��һ��·��,�ҵ��򷵻�1 
int SeekPath(int x,int y,SeqStack<offsets> &s)
{
	int i,g,h;
	if(x==m&&y==p) return 1;
	for(i=0;i<8;i++)
	{
		g=x+Move[i].a;
		h=y+Move[i].b;
		if(Maze[g][h]==0 &&mark[g][h]==0) //��һλ�ÿ��� 
		{
			mark[g][h]=1;
			if(SeekPath(g,h,s))
			{
				offsets newoff={g,h};
				s.Push(newoff);
				//cout<<"("<<g<<","<<h<<") ---> ";
				return 1;
			}
		}
		
	} 
	if(x==1 &&y==1)cout<<"No path in Maze"<<endl;
	return 0;
}

int main()
{
	int i,j;
	//SeqStack<offsets> *st=new SeqStack<offsets>(50);
    SeqStack<offsets> stk(100);
	/*Ҳ����ͨ�������ͼ�������ͼ
	for(i=0;i<m+2;i++)
	{
		for(j=0;j<p+2;j++)
		{
			cin>>Maze[i][j];
		}
	}*/
	cout << "�Թ���ͼ��"<<endl;
	for (i = 0; i < m + 2; i++)
	{
		for (j = 0; j < p + 2; j++)
		{
			if (Maze[i][j] == 1)
			{
				cout << '#';
			}
			else
			{
				cout << '0';
			}
		}
		cout << endl;
	}
	cout << endl;
	for(i =0;i<m+2;i++)
	{
		for(j=0;j<p+2;j++)
		{
			mark[i][j]=0;//0��ʾû���߹�
		}
	}
	cout << "�Թ�·����" << endl;
	mark[1][1]=1;//�������Ѿ�����
	if(SeekPath(1,1,stk)==1)
	{
		cout<<"("<<1<<","<<1<<")";
	}
	offsets offout;
	while(stk.Pop(offout))
	{
		cout<< " ---> ("<<offout.a<<","<<offout.b << ')';
	}
	system("pause");
	return 0;

}










