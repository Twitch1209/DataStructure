#include<iostream>
#include"MyStack.h"

using namespace std;

//判断是否是运算符 
bool isdigit(char ch)
{
	if(ch=='+' ||ch=='-' ||ch=='*'||ch=='/'){return false;}
	if(ch=='(' ||ch==')'){return false;}
	return true;
}

//栈内优先数 
int isp(char ch)
{
	if(ch=='#'){return 0;}
	if(ch=='('){return 1;}
	if(ch=='+' || ch=='-' ){return 3;}
	if(ch=='*' || ch=='/' || ch== '%'){return 5;}
	if(ch==')'){return 6;}
}

//栈外优先数 
int icp(char ch)
{
	if(ch=='#'){return 0;}
	if(ch=='('){return 6;}
	if(ch=='+' || ch=='-' ){return 2;}
	if(ch=='*' || ch=='/' || ch== '%'){return 4;}
	if(ch==')'){return 1;}
}

//具体实现 
int main()
{
	//将栈底标志#先放入栈中
	SeqStack<char> s;
	char ch='#',ch1,op;
	s.Push(ch);
	cin>>ch;
	if(ch=='-')
	{
		cout<<'-';
		cin>>ch;
	}
	char a;
	while(s.IsEmpty()==false)
	{
		 //如果输入结束，则将栈内的元素逐个退出
		if(ch=='\n')
		{
			cout<<' ';
			while(s.getTop(a) &&a!='#')
			{
				s.Pop(a);
				cout<<a<<' ';
			}	
		}
		//如果是操作数，输出它 
		if(isdigit(ch))
		{
			cout<<ch;
			cin.get(ch);
		}
		else
		{
			s.getTop(ch1);
			//新输入操作符ch的优先级较高，进栈，读入下一个字符 
			if(isp(ch1)<icp(ch))
			{
				s.Push(ch);
				cin>>ch;
			}
			//新输入操作符ch的优先级较低，出栈 
			else if(isp(ch1)>icp(ch))
			{
				s.Pop(op);
				cout<<op<<' ';
			}
			//新输入操作符ch的优先级等于栈顶优先级 
			else
			{
				s.Pop(op);
				if(op=='('){cin>>ch;}
			}
		}
	}
	return 0;
	
}
