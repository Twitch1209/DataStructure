#include<iostream>
#include"stack.h"

using namespace std;

const int m=5;
const int p=5;
int Maze[m+2][p+2];
int mark[m+2][p+2];

//位置在直角坐标下的偏移 
//struct offsets{
//	int a,b;		
//};
int Move[8][2] = { { -1,0 },{ -1,1 },{ 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 } };

//从迷宫某一位置[i][j]开始，寻找通向出口[m][p]的一条路径,找到则返回1 
int SeekPath(int x,int y)
{
	int i,g,h;
	if(x==m&&y==p) return 1;
	for(i=0;i<8;i++)
	{
		g=x+Move[i][0];
		h=y+Move[i][1];
		if(Maze[g][h]==0 &&mark[g][h]==0) //下一位置可以 
		{
			mark[g][h]=1;
			if(SeekPath(g,h)==1)
			{
				cout<<"("<<g<<","<<h<<") ---> ";
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
	for(i=0;i<m+2;i++)
	{
		for(j=0;j<p+2;j++)
		{
			cin>>Maze[i][j];
		}
	}
	for(i =0;i<m+2;i++)
	{
		for(j=0;j<p+2;j++)
		{
			mark[i][j]=0;
		}
	}
	mark[1][1]=1;
	if(SeekPath(1,1)==1)
	{
		cout<<"("<<1<<","<<1<<") ";
	}
	system("pause");
	return 0;

}









