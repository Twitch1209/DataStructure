#include<iostream>
#include"MyStack.h"

using namespace std;

bool isdigit(char ch)
{
	if(ch=='+' ||ch=='-' ||ch=='*'||ch=='/'){return false;}
	if(ch=='(' ||ch==')'){return false;}
	return true;
}

int isp(char ch)
{
	if(ch=='#'){return 0;}
	if(ch=='('){return 1;}
	if(ch=='+' || ch=='-' ){return 3;}
	if(ch=='*' || ch=='/' || ch== '%'){return 5;}
	if(ch==')'){return 6;}
}

int icp(char ch)
{
	if(ch=='#'){return 0;}
	if(ch=='('){return 6;}
	if(ch=='+' || ch=='-' ){return 2;}
	if(ch=='*' || ch=='/' || ch== '%'){return 4;}
	if(ch==')'){return 1;}
}


int main()
{
	SeqStack<char> s;
	char ch='#',ch1,op;
	s.Push(ch);
	cin>>ch;
	char a;
	while(s.IsEmpty()==false &&ch!='#')
	{
		if(ch=='\n')
		{
			while(s.getTop(a) &&a!='#')
			{
				s.Pop(a);cout<<a;
			}	
		}
		if(isdigit(ch))
		{
			cout<<ch;
			cin.get(ch);
		}
		else
		{
			s.getTop(ch1);
			if(isp(ch1)<icp(ch))
			{
				s.Push(ch);cin>>ch;
			}
			else if(isp(ch1)>icp(ch))
			{
				s.Pop(op);cout<<op;
			}
			else
			{
				s.Pop(op);
				if(op=='('){cin>>ch;}
			}
		}
	}
	return 0;
	
}
