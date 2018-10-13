#include<string>
#include<iostream>

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
			cout<<current->number
			    <<current->name
			    <<current->sexing
			    <<current->age
			    <<current->testType;
			return true;
		}
		else{current=current->link;}
	}
	return false;
}

//写到了这里 
bool List::Insert(int i,string& nNumber,string& nName,string &nSexing,
    	int& nAge,string& nTestType)
{
	if(i>length+1 ||i<-1)
	{
		cout<<"This postion is not allowed!"<<endl;
		return false;
	}
   	int nowpos=0;
   	LinkNode* p=first->link;
   	while(nowpos<i-1)
   	{
	    nowpos++;
   		p=p->link;
	}
	LinkNode* q;
	q-> number=nNumber;
	q-> name=nName;
	q->sexing=nSexing;
	q->age=nAge;
	q->testType=nTestType;
	q->link=NULL;
	p->link=q;
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
	LinkNode* q=p->link;
	p->link=q->link;
	delete q;
	return true;
}

void List::Display(int pos)
{
	int i=1;
	LinkNode* p=first->link;
	while(i<=pos)
	{
		i++;
		p=p->link;
	}
	cout<<p->number
		<<p->name
		<<p->sexing
		<<p->age
		<<p->testType<<endl;
	
}
