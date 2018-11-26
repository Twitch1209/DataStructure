#include<iostream>
#include"Problem1.h"
#include<iomanip>

using namespace std;

int main()
{
	cout<<"首先请先建立考生信息系统！"<<endl;
	int n;
	cout<<"请输入考生人数:";
	cin>>n;
	if(n<0)
	{
		cout<<"请输入一个自然数！"<<endl; 
		cout<<"请输入考生人数:";
		cin>>n;
	}
	cout<<"请依次输入考生的考号，姓名，性别，年龄及报考类型："<<endl;
	string number;
	string name;
	string sexing;
	int age;
	string testType;
	List DataBase;
	bool flag;
	int order = 10;

	for(int i=1;i<=n;i++)
	{
		cin>>number>>name>>sexing>>age>>testType;
		flag=DataBase.Insert(i,number,name,sexing,age,testType);
	}
	cout << endl;
	DataBase.showTitle();
	for(int i=1;i<=n;i++)
	{
		DataBase.Display(i);
	}
	while (order != 0)
	{
		DataBase.help();
		cin >> order;
		if (order == 1)
		{
			cout << "请输入你要插入的考生的位置：";
			int ipos;
			cin >> ipos;
			cout << "请输入要插入考生的考号，姓名，性别，年龄及报考类型：" << endl;
			cin >> number >> name >> sexing >> age >> testType;
			flag = DataBase.Insert(ipos, number, name, sexing, age, testType);
			if(flag)
			{
				n++;
			}
			cout << endl;
			DataBase.showTitle();
			for (int i = 1; i <= n; i++)
			{
				DataBase.Display(i);
			}
			continue;
		}
		else if (order == 2)
		{
			cout << "请输入你要删除的考生考号：";
			string dNumber;
			cin >> dNumber;
			if(DataBase.Remove(dNumber))
			{
				n--;
			}
			cout << endl;
			DataBase.showTitle();
			for (int i = 1; i <= n; i++)
			{
				DataBase.Display(i);
			}
			continue;
		}
		else if (order == 3)
		{
			cout << "请输入你要查找的考生考号：";
			string dNumber;
			cin >> dNumber;
			flag = DataBase.Find(dNumber);
			continue;
		}
		else if (order == 4)
		{
			cout << "请输入你要修改的考生考号：";
			string dNumber;
			cin >> dNumber;
			cin >> number >> name >> sexing >> age >> testType;
			DataBase.Change(number, name, sexing, age, testType);
			cout << endl;
			DataBase.showTitle();
			for (int i = 1; i <= n; i++)
			{
				DataBase.Display(i);
			}
			continue;
		}
		else if (order == 5)
		{
			cout << endl;
			DataBase.showTitle();
			for (int i = 1; i <= n; i++)
			{
				DataBase.Display(i);
			}
			continue;
		}
		else if (order == 0)
		{
			return 0;
		}
		else
		{
			cout<<"抱歉您想进行的操作不存在，请重新输入"<<endl; 
			continue;
		}
	}
	return 0;
}
