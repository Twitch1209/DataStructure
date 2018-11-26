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
	List(){first=new LinkNode;length=0;}									//List的构造函数，在堆内存开辟一个附加头结点并使first指向附加头结点，长度length=0
	List(const string& nNumber,const string& nName,const string &nSexing,
	    const int& nAge,const string& nTestType)
	    {first=new LinkNode(nNumber,nName,nSexing,nAge,nTestType);length=0;}//对头结点进行初始化的构造函数 
	//List(List& L);
	~List(){makeEmpty();}													//List的析构函数，通过调用MakeEmpty()实现对内存的回收
	void makeEmpty();
	bool Insert(int i,string& nNumber,string& nName,string &nSexing,
    	int& nAge,string& nTestType);										//在链表中插入一个结点
    bool Remove(string& nNumber);											//在链表中删除一个结点（编号为nNumber的成员）
    bool Find(string& nNumber);												//在链表中查找一个结点（编号为nNumber的成员）
    bool Change(string& nNumber,string& nName,string &nSexing,
    	int& nAge,string& nTestType);										//在链表中修改一个结点
	bool isEmpty() const{return first->link==NULL?true:false;}
	void Display(int pos);													//输出位置为pos的信息 
	void showTitle();														//显示标题考号等信息
	void help();															//显示提示
private:
	LinkNode* first;														//链表的头指针
	int length;																//链表的长度
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
	LinkNode* current=first->link;//当前寻找的节点
	while(current!=NULL)
	{
		//找到并且输出该条信息
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
	cout << "找不到该名学生！"<<endl;
	return false;
}

bool List::Insert(int i,string& nNumber,string& nName,string &nSexing,
    	int& nAge,string& nTestType)
{
	//如果输入的位置大于1000（规定总人数）或者小于0会报错：这个位置不合法，请重新输入！
	if(i>1000 || i<0)
	{
		cout<<"这个位置不合法，请重新输入！"<<endl;
		return false;
	}
	//初始化
	else if (length==0)
	{
		LinkNode* q=new LinkNode(nNumber, nName, nSexing, nAge, nTestType);
		//q = new LinkNode(nNumber, nName, nSexing, nAge, nTestType);
		first->link = q;
		length++;
		return true;
	}
	//进行插入
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
	//寻找要删除的节点的位置
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
		cout<<"您要删除的学号不存在！"<<endl;
		return false;
	}
//进行删除操作
	length--;
	LinkNode* q=p->link;
	cout << "你删除的考生信息是：";
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
		cout << "这个位置不合法，请重新输入！" << endl;
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
	cout << left << setw(8) << "考号"
		<< left << setw(8) << "姓名"
		<< left << setw(8) << "性别"
		<< left << setw(8) << "年龄"
		<< left << setw(8) << "报考类型" << endl;
}

void List::help()
{
	cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消。"
		<< endl;
	cout << "请选择您要进行的操作：";
}
