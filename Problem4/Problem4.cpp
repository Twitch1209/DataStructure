#include<iostream>
#include"MyStack.h"

using namespace std;

//�ж��Ƿ�������� 
bool isdigit(char ch)
{
	if(ch=='+' ||ch=='-' ||ch=='*'||ch=='/'){return false;}
	if(ch=='(' ||ch==')'){return false;}
	return true;
}

//ջ�������� 
int isp(char ch)
{
	if(ch=='#'){return 0;}
	if(ch=='('){return 1;}
	if(ch=='+' || ch=='-' ){return 3;}
	if(ch=='*' || ch=='/' || ch== '%'){return 5;}
	if(ch==')'){return 6;}
}

//ջ�������� 
int icp(char ch)
{
	if(ch=='#'){return 0;}
	if(ch=='('){return 6;}
	if(ch=='+' || ch=='-' ){return 2;}
	if(ch=='*' || ch=='/' || ch== '%'){return 4;}
	if(ch==')'){return 1;}
}

//����ʵ�� 
int main()
{
	//��ջ�ױ�־#�ȷ���ջ��
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
		 //��������������ջ�ڵ�Ԫ������˳�
		if(ch=='\n')
		{
			cout<<' ';
			while(s.getTop(a) &&a!='#')
			{
				s.Pop(a);
				cout<<a<<' ';
			}	
		}
		//����ǲ������������ 
		if(isdigit(ch))
		{
			cout<<ch;
			cin.get(ch);
		}
		else
		{
			s.getTop(ch1);
			//�����������ch�����ȼ��ϸߣ���ջ��������һ���ַ� 
			if(isp(ch1)<icp(ch))
			{
				s.Push(ch);
				cin>>ch;
			}
			//�����������ch�����ȼ��ϵͣ���ջ 
			else if(isp(ch1)>icp(ch))
			{
				s.Pop(op);
				cout<<op<<' ';
			}
			//�����������ch�����ȼ�����ջ�����ȼ� 
			else
			{
				s.Pop(op);
				if(op=='('){cin>>ch;}
			}
		}
	}
	return 0;
	
}
