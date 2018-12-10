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
	cout << endl;
	t->BuildRoot(ancName);
	vector<string> chName;
	while (1)
	{
		cout << endl;
		cout << "������Ҫִ�еĲ�����";
		cin >> order;
		switch (order)
		{
		    case 'A':
			{
				//t�Ƕ�������childNum����Ů������parNameΪ������ͥ����,chName��¼��Ҫ�����ͥ����Ů��
				cout << "������Ҫ������ͥ���˵�������";
				string parName;
				cin >> parName;
				//û�з��������
				if (!t->Find(parName))
				{
					cout << "���޴���" << endl;
					continue;
				}
				cout << "������" << parName << "�Ķ�Ů������";
				int childNum;
				cin >> childNum;
				cout << "����������" << parName << "�Ķ�Ů��������";
				chName.clear();
				//����Ҫ�����ͥ����Ů��
				for (int i = 0; i < childNum; i++)
				{
					string childName;
					cin >> childName;
					chName.push_back(childName);
				}
				//��Ů�Ǽ����ͥ������Ϊ��һ���ӽڵ���ֵ�
				t->AddChild(parName, chName[0]);
				for (int i = 0; i < childNum-1; i++)
				{
					t->AddSibling(chName[i], chName[i + 1]);
				}
				cout << parName << "�ĵ�һ�������ǣ�";
				t->showAllChild(parName);
				cout << endl;
				continue;
			}
			case 'B':
			{
				//t�Ƕ�������parNameΪ������ͥ���ˣ�childName������ӵ���Ů������
				//������ڵ�ԭ��û����Ů��ֱ����ӣ�����������
				cout << "������Ҫ��Ӷ��ӣ���Ů�������˵�������";
				string parName;
				cin >> parName;
				//û�з��������
				if (!t->Find(parName))
				{
					cout << "���޴���" << endl;
					continue;
				}
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
				cout << parName << "�ĵ�һ�������ǣ�";
				t->showAllChild(parName);
				cout << endl;
				continue;
			}
			case 'C':
			{
				cout << "������Ҫ��ɢ��ͥ���˵�������";
				string parName;
				cin >> parName;
				//û�з��������
				if (!t->Find(parName))
				{
					cout << "���޴���" << endl;
					continue;
				}
				cout << "Ҫ��ɢ��ͥ�����ǣ�" << parName <<endl;
				cout << parName << "�ĵ�һ�������ǣ�"; 
				t->showAllChild(parName);
				t->RemoveFromPar(parName);
				cout << endl;
				continue;
			}
			case 'D':
			{
				cout << "������Ҫ�����������˵�Ŀǰ������";
				string nowName;
				cin >> nowName;
				//û�з��������
				if (!t->Find(nowName))
				{
					cout << "���޴���" << endl;
					continue;
				}
				cout << "��������ĺ������:";
				string chName;
				cin >> chName;
				t->ChangeName(nowName, chName);
				if (t->Find(chName))
				{
					cout << nowName << "�Ѿ�����Ϊ" << chName;
				}
				else
				{
					cout << "���޴���" << endl;
					continue;
				}
				cout << endl;
				continue;
			}
			case 'E':
			{
				exit(1);
			}
			//����û��������Ҫ�������ʾ�û���������
			default:
			{
				cout << "��Ǹ������Ҫ���еĲ��������ڣ����������룡" << endl;
				continue;
			}
		}

	}

	return true;
}