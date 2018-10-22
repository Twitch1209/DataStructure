#include<iostream>
#include"LinkNode&&List.h"

using namespace std;

bool createNew(List<int>& s1,List<int>& s2,List<int> &s3)
{
	//assert(s3.getHead() != NULL);
	LinkNode<int>* p = s1.getHead()->link;
	LinkNode<int>* q = s2.getHead()->link;
	int count = 0;
	const int x = -1;
	if (p->data == x || q->data == x)
	{
		return 0;
	}
	//no.5
	while (p->link->data != x || q->link->data != x)
	{
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