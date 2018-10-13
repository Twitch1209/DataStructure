#include<iostream>
#include"Problem1.h"

using namespace std;

int main()
{
	cout<<"首先请先建立考生信息系统！"<<endl;
	int n;
	cout<<"请输入考生人数:";
	cin>>n;
	cout<<"请依次输入考生的考号，姓名，性别，年龄及报考类型："<<endl;
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
