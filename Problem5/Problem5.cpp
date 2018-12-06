 #include"MyQueue.h"
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin>>N;
	int cus=0;
	bool flag=true;
	LinkedQueue<int> *q1,*q2;
	q1 = new LinkedQueue<int>();
	q2 = new LinkedQueue<int>();
	for(int i=0;i<N;i++)
	{
		cin>>cus;
		//顾客的编号为偶数
		if(cus%2==0)
		{
			flag=q2->EnQueue(cus);
		}
		//顾客的编号为奇数
		else
		{
			q1->EnQueue(cus);
		}
	}
	//q1为空
	if(q1->getSize()==0)
	{
		q2->show();
		system("pause");
		return 0;
	}
	//q2为空
	else if(q2->getSize()==0)
	{
		q1->show();
		system("pause");
		return 0;
	}
	int count=1;
	int deque=0;
	int Maxcus = max(q1->getSize(), q2->getSize() * 2);//最多办理业务时间
	while(count<=Maxcus)
	{
		if (q1->DeQueue(deque))
		{
			cout << deque << ' ';
		}
		if(count%2==0)
		{
			if(q2->DeQueue(deque))
			{
				cout<<deque<<' ';
			}
		}
		count++;
	}
	system("pause");
	return 0;
}
