#ifndef __LINKNODE_H__
#define __LINKNODE_H__
#include<iostream>
using namespace std;
//LinkNode
template<class T>
struct LinkNode
{
	T data;//表示数据
	LinkNode<T> *link; //下一个LinkNode的指针域
	LinkNode(LinkNode<T> *next=NULL):link(next){}//构造函数
	LinkNode(const T& d,LinkNode<T> *next=NULL):data(d),link(next){}//具有默认参数的构造函数
};

#endif
