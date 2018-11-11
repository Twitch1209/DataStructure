#include<iostream>
#include<string>
#include"Tree.h"
#include<vector>

using namespace std;

int main()
{   
	string ancName;
	char order;
	cout << "**              家谱管理系统              **" << endl;
	cout << "============================================" << endl;    
	cout << "**           请选择要执行的操作           **" << endl;
	cout << "**             A ---完善家谱              **" << endl;    
	cout << "**             B ---添加家庭成员          **" << endl;
	cout << "**             C ---解散局部家庭          **" << endl;
	cout << "**             D ---更改家庭成员姓名      **" << endl;
	cout << "**             E ---退出程序              **" << endl;
	cout << "============================================" << endl;

	Tree<string> *t = new Tree<string>();
	cout << "首先建立一个家庭！"<< endl;
	cout << "请输入祖先的姓名：";
	cin >> ancName;
	cout << "此家庭的祖先是：" << ancName;
	cout << endl << endl;;
	t->BuildRoot(ancName);
	vector<string> chName;
	while (1)
	{
		cout << "请输入要执行的操作：";
		cin >> order;
		cout << endl;
		switch (order)
		{
		    case 'A':
			{
				cout << "请输入要建立家庭的人的姓名：";
				string parName;
				cin >> parName;
				cout << "请输入" << parName << "的儿女人数：";
				int childNum;
				cin >> childNum;
				cout << "请依次输入" << parName << "的儿女的姓名：";
				for (int i = 0; i < childNum; i++)
				{
					string childName;
					cin >> childName;
					chName.push_back(childName);
				}
				t->AddChild(parName, chName[0]);
				for (int i = 0; i < childNum; i++)
				{
					if (i != childNum - 1)
					{
						t->AddSibling(chName[i], chName[i + 1]);
					}
				}
				cout << parName << "的第一代子孙是：";
				t->showAllChild(parName);
				cout << endl;
				continue;
			}
			case 'B':
			{
				cout << "请输入要添加儿子（或女儿）的人的姓名：";
				string parName;
				cin >> parName;
				cout << "请输入" << parName << "新添加的儿子（或女儿）的姓名：";
				string childName;
				cin >> childName;
				if (!t->FirstChild())
				{
					t->AddChild(parName, childName);
				}
				else
				{
					string finalSibling = t->GetFinalSibling(parName);
					t->AddSibling(finalSibling, childName);
				}
				cout << t->GetChild(parName);
				continue;
			}
			case 'C':
			{
				cout << "请输入要解散家庭的人的姓名：";
				string parName;
				cin >> parName;
				if (!t->Find(parName))
				{
					cout << "查无此人" << endl;
				}
				cout << "要解散家庭的人是：" << parName;
				t->RemoveFromPar(parName);
				cout << t->GetChild(parName);
				continue;
			}
			case 'D':
			{
				cout << "请输入要更改姓名的人的目前姓名：";
				string nowName;
				cin >> nowName;
				cout << "请输入更改后的姓名";
				string chName;
				cin >> chName;
				t->ChangeName(nowName, chName);
				if (t->Find(chName))
				{
					cout << nowName << "已经更名为" << chName;
				}
				continue;
			}
			case 'E':
			{
				exit(1);
			}
		}

	}

	return true;
}