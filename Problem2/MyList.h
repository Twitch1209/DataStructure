#include<iostream>
//#include<string>
#include<assert.h>

using namespace std;

template<class T>
struct LinkNode
{
	T data;															//�ڵ�ֵ��ֵ
	LinkNode<T> *link;												//��һ���ڵ�ĵ�ַ
	LinkNode(LinkNode<T> *next=NULL):link(next){}					//���캯��
	LinkNode(const T& d,LinkNode<T> *next=NULL):data(d),link(next){}//���캯��
};

template<class T>
class List
{
public:
	List(){first=new LinkNode<T>;}
	List(const T& x){first=new LinkNode<T>(x);}
	List(List<T>& L);						//copy
	~List(){makeEmpty();}					//list������������ͨ������makeEmpty()ʵ�ֶ��ڴ�Ļ���
	void makeEmpty();						//�ջ�������ռ���ڴ棬��ֹ�ڴ�й©
	int Length()const;						//�õ�List�ĳ���
	LinkNode<T> *getHead()const {return first;}			//get head
	LinkNode<T> *Search(T x);
	LinkNode<T> *Locate(int i)const;				//search no.i
	bool Insert(int i,T& x);			
	bool IsEmpty(){return first->link==NULL?true:false;}
	bool IsFull()const {return false;}
	void output();
private:
	LinkNode<T> *first;									//�����ͷ�ڵ�
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
//ǰһ������i��Ϊ���˽ڵ��Ƿ��һ��Ԫ��
{
	LinkNode<T> *current = Locate(i);//�ҵ�Ҫ�����λ��
	LinkNode<T> *newNode = new LinkNode<T>(x);
	//�����ڵ�ʧ��
	if (newNode == NULL) { cerr << "���������󣡣���" << endl; exit(1); }
	//����
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
