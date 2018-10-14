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
	List(){first=new LinkNode;length=0;}
	List(const string& nNumber,const string& nName,const string &nSexing,
	    const int& nAge,const string& nTestType)
	    {first=new LinkNode(nNumber,nName,nSexing,nAge,nTestType);length=0;}
	//List(List& L);
	~List(){makeEmpty();}
	void makeEmpty();
	int getLength()const{return length;}
	void setLength(int n){length=n;}
	bool Insert(int i,string& nNumber,string& nName,string &nSexing,
    	int& nAge,string& nTestType);
    bool Remove(string& nNumber);
    bool Find(string& nNumber);
    bool Change(string& nNumber,string& nName,string &nSexing,
    	int& nAge,string& nTestType);
	bool isEmpty() const{return first->link==NULL?true:false;}
	void Display(int pos);
	void showTitle();
	void help();
private:
	LinkNode* first;
	int length;
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
	LinkNode* current=first->link;
	while(current!=NULL)
	{
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

//写到了这里 
bool List::Insert(int i,string& nNumber,string& nName,string &nSexing,
    	int& nAge,string& nTestType)
{
	if(i>100 || i<-1)
	{
		cout<<"This postion is not allowed!"<<endl;
		return false;
	}
	else if (length==0)
	{
		LinkNode* q;
		q = new LinkNode(nNumber, nName, nSexing, nAge, nTestType);
		first->link = q;
		length++;
		return true;
	}
   	int nowpos=0;
	length++;
   	LinkNode* p=first->link;
   	while(nowpos<i-2)
   	{
	    nowpos++;
   		p=p->link;
	}
	LinkNode* q1;
	q1=new LinkNode(nNumber, nName, nSexing, nAge, nTestType);
	//q->number=nNumber;
	//q->name=nName;
	//q->sexing=nSexing;
	//q->age=nAge;
	//q->testType=nTestType;
	//q->link=NULL;
	p->link=q1;
	return true;
}

bool List::Remove(string& nNumber)
{
	LinkNode* p=first;
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
		cout<<"Sorry,we can't find the number."<<endl;
		return false;
	}
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
		cout << "Sorry,we can't find the number." << endl;
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