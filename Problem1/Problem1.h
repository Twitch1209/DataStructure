#include<string>
#include<iostream>
#include<iomanip>
using namespace std;

struct LinkNode{
	string number;
	string name;
	string sexing;
	int age;
	string testType;
	LinkNode *link;
	LinkNode(LinkNode *ptr=NULL){link=ptr;}
	LinkNode(const string& nNumber,const string& nName,const string &nSexing,
	const int& nAge,const string& nTestType,LinkNode*ptr=NULL)
	{
		number=nNumber;
		name=nName;
		sexing=nSexing;
		age=nAge;
		testType=nTestType;
		link=ptr;
	}
};

class List{
public:
	List(){first=new LinkNode;length=0;}									//List�Ĺ��캯�����ڶ��ڴ濪��һ������ͷ��㲢ʹfirstָ�򸽼�ͷ��㣬����length=0
	List(const string& nNumber,const string& nName,const string &nSexing,
	    const int& nAge,const string& nTestType)
	    {first=new LinkNode(nNumber,nName,nSexing,nAge,nTestType);length=0;}//��ͷ�����г�ʼ���Ĺ��캯�� 
	//List(List& L);
	~List(){makeEmpty();}													//List������������ͨ������MakeEmpty()ʵ�ֶ��ڴ�Ļ���
	void makeEmpty();
	bool Insert(int i,string& nNumber,string& nName,string &nSexing,
    	int& nAge,string& nTestType);										//�������в���һ�����
    bool Remove(string& nNumber);											//��������ɾ��һ����㣨���ΪnNumber�ĳ�Ա��
    bool Find(string& nNumber);												//�������в���һ����㣨���ΪnNumber�ĳ�Ա��
    bool Change(string& nNumber,string& nName,string &nSexing,
    	int& nAge,string& nTestType);										//���������޸�һ�����
	bool isEmpty() const{return first->link==NULL?true:false;}
	void Display(int pos);													//���λ��Ϊpos����Ϣ 
	void showTitle();														//��ʾ���⿼�ŵ���Ϣ
	void help();															//��ʾ��ʾ
private:
	LinkNode* first;														//�����ͷָ��
	int length;																//����ĳ���
};

//make the list an empty list
void List::makeEmpty()
{
	LinkNode *q;
	while(first->link!=NULL)
	{
		length = 0;
		q=first->link;
		first->link=q->link;
		delete q;
	}
}

//Find
bool List::Find(string& nNumber)
{
	LinkNode* current=first->link;//��ǰѰ�ҵĽڵ�
	while(current!=NULL)
	{
		//�ҵ��������������Ϣ
		if(current->number==nNumber)
		{
			this->showTitle();
			cout << left << setw(8) << current->number
				<< left << setw(8) << current->name
				<< left << setw(8) << current->sexing
				<< left << setw(8) << current->age
				<< left << setw(8) << current->testType << endl;
			return true;
		}
		else{current=current->link;}
	}
	cout << "�Ҳ�������ѧ����"<<endl;
	return false;
}

bool List::Insert(int i,string& nNumber,string& nName,string &nSexing,
    	int& nAge,string& nTestType)
{
	//��������λ�ô���1000���涨������������С��0�ᱨ�����λ�ò��Ϸ������������룡
	if(i>1000 || i<0)
	{
		cout<<"���λ�ò��Ϸ������������룡"<<endl;
		return false;
	}
	//��ʼ��
	else if (length==0)
	{
		LinkNode* q=new LinkNode(nNumber, nName, nSexing, nAge, nTestType);
		//q = new LinkNode(nNumber, nName, nSexing, nAge, nTestType);
		first->link = q;
		length++;
		return true;
	}
	//���в���
   	int nowpos=0;
	length++;
   	LinkNode* p=first->link;
   	while(nowpos<i-2)
   	{
	    nowpos++;
   		p=p->link;
	}
	LinkNode* q1=new LinkNode(nNumber, nName, nSexing, nAge, nTestType);
	q1->link=p->link;
	p->link=q1;
	return true;
}

bool List::Remove(string& nNumber)
{
	LinkNode* p=first;
	//Ѱ��Ҫɾ���Ľڵ��λ��
	while(p->link!=NULL)
	{
		if(p->link->number==nNumber)
		{
			break;
		}
		p=p->link;
	}
	if(p->link==NULL)
	{
		cout<<"��Ҫɾ����ѧ�Ų����ڣ�"<<endl;
		return false;
	}
//����ɾ������
	length--;
	LinkNode* q=p->link;
	cout << "��ɾ���Ŀ�����Ϣ�ǣ�";
	cout << left << setw(8) << q->number
		<< left << setw(8) << q->name
		<< left << setw(8) << q->sexing
		<< left << setw(8) << q->age
		<< left << setw(8) << q->testType << endl;
	p->link=q->link;
	delete q;
	return true;
}

bool List::Change(string& nNumber, string& nName, string &nSexing,
	int& nAge, string& nTestType)
{
	LinkNode* p = first;
	while (p->link != NULL)
	{
		if (p->link->number == nNumber)
		{
			break;
		}
		p = p->link;
	}
	if (p->link == NULL)
	{
		cout << "���λ�ò��Ϸ������������룡" << endl;
		return false;
	}
	LinkNode* q = p->link;
	q->name = nName;
	q->sexing = nSexing;
	q->age = nAge;
	q->testType = nTestType;
	return true;
}


void List::Display(int pos)
{
	int i=1;
	LinkNode* p=first->link;
	while(i<pos)
	{
		i++;
		p=p->link;
	}
	cout<< left << setw(8) <<p->number
		<< left << setw(8) <<p->name
		<< left << setw(8) <<p->sexing
		<< left << setw(8) <<p->age
		<< left << setw(8) <<p->testType<<endl;
	
}

void List::showTitle()
{
	cout << left << setw(8) << "����"
		<< left << setw(8) << "����"
		<< left << setw(8) << "�Ա�"
		<< left << setw(8) << "����"
		<< left << setw(8) << "��������" << endl;
}

void List::help()
{
	cout << "��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ����"
		<< endl;
	cout << "��ѡ����Ҫ���еĲ�����";
}
