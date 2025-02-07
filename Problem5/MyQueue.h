#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#include<iostream>
#include"LinkNode.h"

using namespace std;
const int maxSize=50;

template<class T>
class LinkedQueue
{
public:
	LinkedQueue():rear(NULL),front(NULL){}
	~LinkedQueue(){makeEmpty();}
	bool EnQueue(const T& x);
	bool DeQueue(T& x);
	bool getFront(T& x);
	void makeEmpty();
	bool IsEmpty()const{return (front==NULL)?true:false;}
	int getSize()const;
	void show();
//	friend ostream& operator<<(ostream& os,LinkedQueue<T>& Q);
private:
	LinkNode<T> *front,*rear;
	
};

//graduately delete node in the queue
template<class T>
void LinkedQueue<T>::makeEmpty()
{
	LinkNode<T> *p;
	while(front!=NULL)
	{
		p=front;
		front=front->link;
		delete p;
	}
}

//enter the queue(after the queue)
template<class T>
bool LinkedQueue<T>::EnQueue(const T& x)
{
	if(front==NULL)
	{
		front=rear=new LinkNode<T>(x);
		if(front==NULL) return false;
	}
	else
	{
		rear->link=new LinkNode<T>(x);
		if(rear->link==NULL) return false;
		rear=rear->link;
	}
	return true;
}

//delete from the queue,put the value to the x
template<class T>
bool LinkedQueue<T>::DeQueue(T& x)
{
	if(IsEmpty()==true) return false;
	LinkNode<T>* p=front;
	x=front->data;
	front=front->link;
	delete p;
	return true;
}

//get the front of the queue
template<class T>
bool LinkedQueue<T>::getFront(T& x)
{
	if(IsEmpty()==true) return false;
	x=front->data;
	return true;
}

//get the size of the queue
template<class T>
int LinkedQueue<T>::getSize()const
{
	LinkNode<T> *p=front;
	int k=0;
	while(p!=NULL)
	{
		p=p->link;
		k++;
	}
	return k;
}

template<class T>
void LinkedQueue<T>::show()
{
	LinkNode<T> *p=this->front;
	int i=0;
	while(p!=NULL)
	{
		cout<<p->data<<' ';
		p=p->link;
	}
}
#endif

