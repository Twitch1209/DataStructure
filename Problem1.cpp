#include<iostream>
#include"Problem1.h"

using namespace std;

int main()
{
	cout<<"�������Ƚ���������Ϣϵͳ��"<<endl;
	int n;
	cout<<"�����뿼������:";
	cin>>n;
	cout<<"���������뿼���Ŀ��ţ��������Ա����估�������ͣ�"<<endl;
	string number;
	string name;
	string sexing;
	int age;
	string testType;
	List *DataBase;
	
	for(int i=1;i<=n;i++)
	{
		cin>>number>>name>>sexing>>age>>testType;
		DataBase->Insert(i,number,name,sexing,age,testType);
	}
	for(int i=1;i<=n;i++)
	{
		DataBase->Display(i);
	}
	
}
