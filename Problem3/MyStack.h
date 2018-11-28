#ifndef __STACK_H__
#define __STACK_H__

#include<iostream>
#include<assert.h>

const int Size=50; 
const int stackIncreament=20;					//栈溢出时扩展空间的增量 
using namespace std;

template<class T>
class SeqStack
{ 
public:
	SeqStack(int sz=50);
	~SeqStack(){delete[]elements;}
	void Push(const T& x);
	bool Pop(T& x);					//通过x得到退出的元素的值 
	bool getTop(T& x)const;
	bool IsEmpty()const{return(top==-1)?true:false;}//栈是否为空 
	bool IsFull()const{return(top==maxSize-1)?true:false;}	
	int getSize()const{return top+1;}
	void MakeEmpty(){top=-1;}

private:
	T *elements;						//保存栈内元素的数组
	int top;							//头指针
	int maxSize;						//最大大小
	void overflowProvess();				//栈的溢出处理 
};

//SeqStack的构造函数，新建一个sz大小的数组
template<class T>
SeqStack<T>::SeqStack(int sz)
	:top(-1),maxSize(sz)
{
	elements=new T[maxSize];
	assert(elements!=NULL);
}

//SeqStack的溢出函数，如果溢出，则再次开辟maxsize大小的空间
template<class T>
void SeqStack<T>::overflowProvess()
{
	T * newArray=new T[maxSize+stackIncreament];
	if(newArray=NULL){cerr<<"存储分配失败"<<endl;exit(1);}
	for(int i=0;i<=top;i++)
	{
		newArray[i]=elements[i];
	}
	maxSize+=stackIncreament;
	delete []elements;
	elements=newArray;
}

//值为x的元素入栈，top++
template<class T>
void SeqStack<T>::Push(const T& x)
{
	if(IsFull()){overflowProvess();}
	elements[++top]=x;
}

//出栈，出栈的值保存在x里面
template<class T>
bool SeqStack<T>::Pop(T& x)
{
	if(IsEmpty()){return false;}
	x=elements[top--];
	return true;
}

//得到栈顶元素的值，记录在x里面
template<class T>
bool SeqStack<T>::getTop(T& x)const
{
	if(IsEmpty()){return false;}
	x=elements[top];
	return true;
}


#endif

