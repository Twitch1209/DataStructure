#ifndef _TREE_H__
#define _TREE_H__
#include<iostream>
using namespace std;
template<class T>
struct TreeNode{
	T data;																//�������
	TreeNode<T>* firstChild, *nextSibling;								//��Ů���ֵܽڵ�
	TreeNode(T value = 0,TreeNode<T> *fc = NULL,TreeNode<T> *ns = NULL)
	:data(value),firstChild(fc),nextSibling(ns) {}					//���캯��
};

template<class T>
class Tree {
public:
	Tree() { root = current = NULL; }
	bool Root();									//�����ĸ��ڵ��Ϊ���ĵ�ǰ�ڵ�
	bool IsEmpty() { return root == NULL; }			
	bool FirstChild();
	bool NextSibling();
	bool Parent();									//�������ҵ�ǰ�ڵ�ĸ��ڵ㣬ʹ֮��Ϊ��ǰ�ڵ�
	bool Find(T target);
	void AddChild(T parName, T childName);
	void AddSibling(T childName, T Sibling);
	void BuildRoot(T rootVal);
	void showAllChild(T parName);
	bool RemoveFromPar(T parName);
	T GetFinalSibling(T parName);
	T GetChild(T parName);
	void ChangeName(T nowName, T chName);
private:
	TreeNode<T> *root, *current;
	bool Find(TreeNode<T>*p, T value);
	void RemovesubTree(TreeNode<T> *p);
	bool FindParent(TreeNode<T>*t, TreeNode < T >*p);
};

template<class T>
bool Tree<T>::Root()
{
	if (root == NULL)
	{
		current = NULL;
		return false;
	}
	else
	{
		current = root;
		return true;
	}
}

template<class T>
void Tree<T>::showAllChild(T parName)
{
	if (Find(parName))
	{
		if (current->firstChild == NULL)
		{
			return;
		}
		current = current->firstChild;
		cout << current->data<<' ';
		while (current->nextSibling != NULL)
		{
			cout << current->nextSibling->data<<' ';
			current = current->nextSibling;
		}
	}
}

template <class T> 
void Tree <T> ::BuildRoot(T rootVal) 
{ //�������ĸ����,��ʹ֮��Ϊ���ĵ�ǰ��� 
	root= current= new TreeNode<T> (rootVal);
}

template<class T>
void Tree<T>::AddChild(T parName, T childName)
{
	if (Find(parName))
	{
		TreeNode<T> *p = new TreeNode<T>(childName);
		current->firstChild = p;
	}
}

template<class T>
void Tree<T>::AddSibling(T childName, T Sibling)
{
	if (Find(childName))
	{
		TreeNode<T> *s = new TreeNode<T>(Sibling);
		current->nextSibling = s;
	}
}

template<class T>
bool Tree<T>::Parent()
{
	TreeNode<T>* p = current;
	if (current == NULL || current == root)
	{
		current = root;
		return false;
	}
	return FindParent(root, p);
}

template<class T>
bool Tree<T>::FindParent(TreeNode<T>* t, TreeNode<T>* p)			//���ڵ�Ϊt��������p�ĸ��ڵ㣬ʹ֮��Ϊ��ǰ�ڵ�
{
	TreeNode<T> *q = t->firstChild;
	bool succ;
	while (q != NULL && q != p)
	{
		if (succ = FindParent(q, p))
		{
			return succ;
		}
		q = q->nextSibling;
	}
	if (q != NULL && q == p)
	{
		current = t;
		return true;
	}
	else
	{
		current = NULL;
		return false;
	}
}

template<class T>
bool Tree<T>::FirstChild()					//�������ҵ���ǰ�ڵ�ĳ��ӣ���ʹ֮��Ϊ��ǰ�ڵ�
{
	if (current != NULL && current->firstChild != NULL)
	{
		current = current->firstChild;
		return true;
	}
	current = NULL;
	return false;
}

template<class T>
bool Tree<T>::NextSibling()
{
	if (current != NULL && current->nextSibling != NULL)
	{
		current = current->nextSibling;
		return true;
	}
	current = NULL;
	return false;
}

template<class T>
T Tree<T>::GetFinalSibling(T parName)
{
	if (Find(parName))
	{
		current = current->firstChild;
		while (current != NULL && current->nextSibling != NULL)
		{
			current = current->nextSibling;
		}
		return current->data;
	}
}

template<class T>
T Tree<T>::GetChild(T parName)
{
	if (Find(parName))
	{
		return current->firstChild->data;
	}
}

template<class T>
bool Tree<T>::RemoveFromPar(T parName)
{
	if (Find(parName))
	{
		current->firstChild = NULL;
		current->nextSibling = NULL;
		return true;
	}
	return false;
}
template<class T>
bool Tree<T>::Find(T value)
{
	if (IsEmpty()) return false;
	return Find(root, value);
}

template<class T>
bool Tree<T>::Find(TreeNode<T>*p, T value)
{
	bool result = false;
	if (p->data == value)
	{
		result = true;
		current = p;
	}
	else
	{
		TreeNode<T> *q = p->firstChild;
		while (q != NULL && !(result = Find(q, value)))
		{
			q = q->nextSibling;
		}
	}
	return result;
}

template<class T>
void Tree<T>::RemovesubTree(TreeNode<T> *p)
{
	p->firstChild = NULL;
	p->nextSibling = NULL;
}

template<class T>
void Tree<T>::ChangeName(T nowName, T chName)
{
	if (Find(nowName))
	{
		current->data = chName;
	}
}
#endif