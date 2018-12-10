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
	cout << endl;
	t->BuildRoot(ancName);
	vector<string> chName;
	while (1)
	{
		cout << endl;
		cout << "请输入要执行的操作：";
		cin >> order;
		switch (order)
		{
		    case 'A':
			{
				//t是二叉树，childNum是子女数量，parName为建立家庭的人,chName记录了要加入家庭的子女名
				cout << "请输入要建立家庭的人的姓名：";
				string parName;
				cin >> parName;
				//没有发现这个人
				if (!t->Find(parName))
				{
					cout << "查无此人" << endl;
					continue;
				}
				cout << "请输入" << parName << "的儿女人数：";
				int childNum;
				cin >> childNum;
				cout << "请依次输入" << parName << "的儿女的姓名：";
				chName.clear();
				//输入要加入家庭的子女们
				for (int i = 0; i < childNum; i++)
				{
					string childName;
					cin >> childName;
					chName.push_back(childName);
				}
				//子女们加入家庭，都成为第一个子节点的兄弟
				t->AddChild(parName, chName[0]);
				for (int i = 0; i < childNum-1; i++)
				{
					t->AddSibling(chName[i], chName[i + 1]);
				}
				cout << parName << "的第一代子孙是：";
				t->showAllChild(parName);
				cout << endl;
				continue;
			}
			case 'B':
			{
				//t是二叉树，parName为建立家庭的人，childName是新添加的子女的姓名
				//如果父节点原来没有子女，直接添加，否则加在最后
				cout << "请输入要添加儿子（或女儿）的人的姓名：";
				string parName;
				cin >> parName;
				//没有发现这个人
				if (!t->Find(parName))
				{
					cout << "查无此人" << endl;
					continue;
				}
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
				cout << parName << "的第一代子孙是：";
				t->showAllChild(parName);
				cout << endl;
				continue;
			}
			case 'C':
			{
				cout << "请输入要解散家庭的人的姓名：";
				string parName;
				cin >> parName;
				//没有发现这个人
				if (!t->Find(parName))
				{
					cout << "查无此人" << endl;
					continue;
				}
				cout << "要解散家庭的人是：" << parName <<endl;
				cout << parName << "的第一代子孙是："; 
				t->showAllChild(parName);
				t->RemoveFromPar(parName);
				cout << endl;
				continue;
			}
			case 'D':
			{
				cout << "请输入要更改姓名的人的目前姓名：";
				string nowName;
				cin >> nowName;
				//没有发现这个人
				if (!t->Find(nowName))
				{
					cout << "查无此人" << endl;
					continue;
				}
				cout << "请输入更改后的姓名:";
				string chName;
				cin >> chName;
				t->ChangeName(nowName, chName);
				if (t->Find(chName))
				{
					cout << nowName << "已经更名为" << chName;
				}
				else
				{
					cout << "查无此人" << endl;
					continue;
				}
				cout << endl;
				continue;
			}
			case 'E':
			{
				exit(1);
			}
			//如果用户输入操作要求错误，提示用户重新输入
			default:
			{
				cout << "抱歉，您想要进行的操作不存在，请重新输入！" << endl;
				continue;
			}
		}

	}

	return true;
}