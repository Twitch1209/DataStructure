#ifndef __STACK_H__
#define __STACK_H__

#include<iostream>
#include<assert.h>

const int Size=50; 
const int stackIncreament=20;					//ջ���ʱ��չ�ռ������ 
using namespace std;

template<class T>
class SeqStack
{ 
public:
	SeqStack(int sz=50);
	~SeqStack(){delete[]elements;}
	void Push(const T& x);
	bool Pop(T& x);					//ͨ��x�õ��˳���Ԫ�ص�ֵ 
	bool getTop(T& x)const;
	bool IsEmpty()const{return(top==-1)?true:false;}//ջ�Ƿ�Ϊ�� 
	bool IsFull()const{return(top==maxSize-1)?true:false;}	
	int getSize()const{return top+1;}
	void MakeEmpty(){top=-1;}

private:
	T *elements;						//����ջ��Ԫ�ص�����
	int top;							//ͷָ��
	int maxSize;						//����С
	void overflowProvess();				//ջ��������� 
};

//SeqStack�Ĺ��캯�����½�һ��sz��С������
template<class T>
SeqStack<T>::SeqStack(int sz)
	:top(-1),maxSize(sz)
{
	elements=new T[maxSize];
	assert(elements!=NULL);
}

//SeqStack����������������������ٴο���maxsize��С�Ŀռ�
template<class T>
void SeqStack<T>::overflowProvess()
{
	T * newArray=new T[maxSize+stackIncreament];
	if(newArray=NULL){cerr<<"�洢����ʧ��"<<endl;exit(1);}
	for(int i=0;i<=top;i++)
	{
		newArray[i]=elements[i];
	}
	maxSize+=stackIncreament;
	delete []elements;
	elements=newArray;
}

//ֵΪx��Ԫ����ջ��top++
template<class T>
void SeqStack<T>::Push(const T& x)
{
	if(IsFull()){overflowProvess();}
	elements[++top]=x;
}

//��ջ����ջ��ֵ������x����
template<class T>
bool SeqStack<T>::Pop(T& x)
{
	if(IsEmpty()){return false;}
	x=elements[top--];
	return true;
}

//�õ�ջ��Ԫ�ص�ֵ����¼��x����
template<class T>
bool SeqStack<T>::getTop(T& x)const
{
	if(IsEmpty()){return false;}
	x=elements[top];
	return true;
}


#endif

