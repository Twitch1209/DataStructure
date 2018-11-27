#include<iostream>
//#include<string>
#include<assert.h>

using namespace std;

template<class T>
struct LinkNode
{
	T data;															//节点值的值
	LinkNode<T> *link;												//下一个节点的地址
	LinkNode(LinkNode<T> *next=NULL):link(next){}					//构造函数
	LinkNode(const T& d,LinkNode<T> *next=NULL):data(d),link(next){}//构造函数
};

template<class T>
class List
{
public:
	List(){first=new LinkNode<T>;}
	List(const T& x){first=new LinkNode<T>(x);}
	List(List<T>& L);						//copy
	~List(){makeEmpty();}					//list的析构函数，通过调用makeEmpty()实现对内存的回收
	void makeEmpty();						//收回链表所占的内存，防止内存泄漏
	int Length()const;						//得到List的长度
	LinkNode<T> *getHead()const {return first;}			//get head
	LinkNode<T> *Search(T x);
	LinkNode<T> *Locate(int i)const;				//search no.i
	bool Insert(int i,T& x);			
	bool IsEmpty(){return first->link==NULL?true:false;}
	bool IsFull()const {return false;}
	void output();
private:
	LinkNode<T> *first;									//链表的头节点
};

template<class T>
List<T>::List(List<T>& L)
{
	T value;
	LinkNode<T> *srcptr = L.getHead();
	LinkNode<T> *destptr = first = new LinkNode<T>;
	while (srcptr->link != NULL)
	{
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		destptr = srcptr->link;
	}
	destptr->link = NULL;
}

template<class T>
void List<T>::makeEmpty()
{
	LinkNode<T> *q;
	while (first->link != NULL)
	{
		q = first->link;
		first->link = q->link;
		delete q;
	}
	delete first;
}

template<class T>
int List<T>::Length()const
{
	LinkNode<T> *p = first->link;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->link;
	}
	return count;
}

template<class T>
LinkNode<T> *List<T>::Search(T x)
{
	LinkNode<T> *current = first->link;
	while (current != NULL)
	{
		if (current->data == x)
		{
			break;
		}
		else
		{
			current = current->link;
		}
	}
	return current;
}

template<class T>
LinkNode<T>* List<T>::Locate(int i)const
{
	if (i < 0) return NULL;
	LinkNode<T> *current = first;
	int k = 1;
	while (current != NULL && k < i)
	{
		current = current->link;
		k++;
	}
	return current;
}


template<class T>
bool List<T>::Insert(int i, T& x)
//前一个参数i是为辨别此节点是否第一个元素
{
	LinkNode<T> *current = Locate(i);//找到要插入的位置
	LinkNode<T> *newNode = new LinkNode<T>(x);
	//创建节点失败
	if (newNode == NULL) { cerr << "储存分配错误！！！" << endl; exit(1); }
	//插入
	if (i == 1)
	{
		first->link = newNode;
	}
	else
	{
		newNode->link=current->link;
		current->link=newNode;
	}

	return true;
}

template<class T>
void List<T>::output()
{
	LinkNode<T>* current=first->link;
	if (current == NULL) { cout << "NULL"; }
	while(current!=NULL)
	{
		cout<<current->data<<" ";
		current=current->link;
	}
}
