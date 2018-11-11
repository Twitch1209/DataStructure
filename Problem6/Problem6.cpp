#include<iostream>
#include<string>
#include"Tree.h"
#include<vector>

using namespace std;

int main()
{   
	string ancName;
	char order;
	cout << "**              ���׹���ϵͳ              **" << endl;
	cout << "============================================" << endl;    
	cout << "**           ��ѡ��Ҫִ�еĲ���           **" << endl;
	cout << "**             A ---���Ƽ���              **" << endl;    
	cout << "**             B ---��Ӽ�ͥ��Ա          **" << endl;
	cout << "**             C ---��ɢ�ֲ���ͥ          **" << endl;
	cout << "**             D ---���ļ�ͥ��Ա����      **" << endl;
	cout << "**             E ---�˳�����              **" << endl;
	cout << "============================================" << endl;

	Tree<string> *t = new Tree<string>();
	cout << "���Ƚ���һ����ͥ��"<< endl;
	cout << "���������ȵ�������";
	cin >> ancName;
	cout << "�˼�ͥ�������ǣ�" << ancName;
	cout << endl << endl;;
	t->BuildRoot(ancName);
	vector<string> chName;
	while (1)
	{
		cout << "������Ҫִ�еĲ�����";
		cin >> order;
		cout << endl;
		switch (order)
		{
		    case 'A':
			{
				cout << "������Ҫ������ͥ���˵�������";
				string parName;
				cin >> parName;
				cout << "������" << parName << "�Ķ�Ů������";
				int childNum;
				cin >> childNum;
				cout << "����������" << parName << "�Ķ�Ů��������";
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
				cout << parName << "�ĵ�һ�������ǣ�";
				t->showAllChild(parName);
				cout << endl;
				continue;
			}
			case 'B':
			{
				cout << "������Ҫ��Ӷ��ӣ���Ů�������˵�������";
				string parName;
				cin >> parName;
				cout << "������" << parName << "����ӵĶ��ӣ���Ů������������";
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
				cout << "������Ҫ��ɢ��ͥ���˵�������";
				string parName;
				cin >> parName;
				if (!t->Find(parName))
				{
					cout << "���޴���" << endl;
				}
				cout << "Ҫ��ɢ��ͥ�����ǣ�" << parName;
				t->RemoveFromPar(parName);
				cout << t->GetChild(parName);
				continue;
			}
			case 'D':
			{
				cout << "������Ҫ�����������˵�Ŀǰ������";
				string nowName;
				cin >> nowName;
				cout << "��������ĺ������";
				string chName;
				cin >> chName;
				t->ChangeName(nowName, chName);
				if (t->Find(chName))
				{
					cout << nowName << "�Ѿ�����Ϊ" << chName;
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