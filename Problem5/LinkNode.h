#ifndef __LINKNODE_H__
#define __LINKNODE_H__
#include<iostream>
using namespace std;
//LinkNode
template<class T>
struct LinkNode
{
	T data;//��ʾ����
	LinkNode<T> *link; //��һ��LinkNode��ָ����
	LinkNode(LinkNode<T> *next=NULL):link(next){}//���캯��
	LinkNode(const T& d,LinkNode<T> *next=NULL):data(d),link(next){}//����Ĭ�ϲ����Ĺ��캯��
};

#endif
