#include<iostream>
#include"MyList.h"

using namespace std;

bool createNew(List<int>& s1,List<int>& s2,List<int> &s3)
{
	//assert(s3.getHead() != NULL);
	LinkNode<int>* p = s1.getHead()->link;//得到s1的第一个元素
	LinkNode<int>* q = s2.getHead()->link;//得到s2的第一个元素
	int count = 0;//记录s3的元素个数
	const int x = -1;//结束标志
	//结束
	if (p->data == x || q->data == x)
	{
		return 0;
	}
	//求交集
	while (p->link->data != x || q->link->data != x)
	{
		//如果两个元素相等，则把这个元素加入到s3里面
		if (p->data == q->data)
		{
			count++;
			s3.Insert(count, p->data);
			if (p->link->data != x)
			{
				p = p->link;
			}
			if (q->link->data != x)
			{
				q = q->link;
			}
		}
		//如果q大，且p没有到达最后，则p后移；如果p已经是最后一个元素了则q后移。p大，同理。
		else if (p->data < q->data)
		{
			if (p->link->data != x)
			{
				p = p->link;
			}
			else if(q->link->data != x)
			{
				q = q->link;
			}
		}
		else if (p->data > q->data)
		{
			if (q->link->data != x)
			{
				q = q->link;
			}
			else if(p->link->data != x)
			{
				p = p->link;
			}
		}
	}
	//比较最后一个元素
	if (p->data == q->data)
	{
		count++;
		s3.Insert(count, p->data);
	}
	return true;
}

int main()
{
	List<int> s1,s2,s3;
	//init s1
	bool flag1 = false;
	int InputNum=0;
	int count = 0;
	while (InputNum>=0)
	{
		cin >> InputNum;
		count++;
		flag1=s1.Insert(count, InputNum);
	}
	s1.Insert(count, InputNum);
	//init s2
	InputNum = 0;
	count = 0;
	while (InputNum >= 0)
	{
		cin >> InputNum;
		count++;
		flag1=s2.Insert(count, InputNum);
	}
	s2.Insert(count, InputNum);

	bool flag = createNew(s1, s2, s3);
	s3.output();
	system("pause");
	return 0;
}