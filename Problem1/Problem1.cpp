#include<iostream>
#include"Problem1.h"
#include<iomanip>

using namespace std;

int main()
{
	cout<<"�������Ƚ���������Ϣϵͳ��"<<endl;
	int n;
	cout<<"�����뿼������:";
	cin>>n;
	if(n<0)
	{
		cout<<"������һ����Ȼ����"<<endl; 
		cout<<"�����뿼������:";
		cin>>n;
	}
	cout<<"���������뿼���Ŀ��ţ��������Ա����估�������ͣ�"<<endl;
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
			cout << "��������Ҫ����Ŀ�����λ�ã�";
			int ipos;
			cin >> ipos;
			cout << "������Ҫ���뿼���Ŀ��ţ��������Ա����估�������ͣ�" << endl;
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
			cout << "��������Ҫɾ���Ŀ������ţ�";
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
			cout << "��������Ҫ���ҵĿ������ţ�";
			string dNumber;
			cin >> dNumber;
			flag = DataBase.Find(dNumber);
			continue;
		}
		else if (order == 4)
		{
			cout << "��������Ҫ�޸ĵĿ������ţ�";
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
			cout<<"��Ǹ������еĲ��������ڣ�����������"<<endl; 
			continue;
		}
	}
	return 0;
}
