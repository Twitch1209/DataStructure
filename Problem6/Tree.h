#ifndef _TREE_H__
#define _TREE_H__
#include<iostream>
using namespace std;
template<class T>
struct TreeNode{
	T data;																//结点数据
	TreeNode<T>* firstChild, *nextSibling;								//子女及兄弟节点
	TreeNode(T value = 0,TreeNode<T> *fc = NULL,TreeNode<T> *ns = NULL)
	:data(value),firstChild(fc),nextSibling(ns) {}					//构造函数
};

template<class T>
class Tree {
public:
	Tree() { root = current = NULL; }
	bool IsEmpty() { return root == NULL; }			
	bool FirstChild();								//在树中找到当前节点的长子，并使之成为当前节点
	bool NextSibling();								//在树中找到当前节点的下一个兄弟，并使之成为当前节点
	bool Parent();									//在树中找当前节点的父节点，使之成为当前节点
	bool Find(T target);							//在树中搜索含有target的结点，使之成为当前结点
	void AddChild(T parName, T childName);			//添加左子女结点
	void AddSibling(T childName, T Sibling);		//添加右兄弟结点
	void BuildRoot(T rootVal);						//建立树的根结点,并使之成为树的当前结点
	void showAllChild(T parName);					//展示t结点的所有孩子
	bool RemoveFromPar(T parName);					//删除t结点
	T GetFinalSibling(T parName);					//得到当前结点的最后一个兄弟
	void ChangeName(T nowName, T chName);			//将nowName修改成chName
private:
	TreeNode<T> *root, *current;//指针指向根结点和当前结点
	bool Find(TreeNode<T>*p, T value);//在以p为根的树中搜索value
	void RemovesubTree(TreeNode<T> *p);//删除以p为根的子树
	bool FindParent(TreeNode<T>*t, TreeNode < T >*p);//在以t为根节点的树中搜索p的父节点
};


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
{ 
	//建立树的根结点,并使之成为树的当前结点 
	root= current= new TreeNode<T> (rootVal);
}

template<class T>
void Tree<T>::AddChild(T parName, T childName)
{
	//将当前结点设为parName，将它的子节点设为childName
	if (Find(parName))
	{
		TreeNode<T> *p = new TreeNode<T>(childName);
		current->firstChild = p;
	}
}

template<class T>
void Tree<T>::AddSibling(T childName, T Sibling)
{
	//将当前结点设为childName，将它的右兄弟设为Sibling
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
bool Tree<T>::FindParent(TreeNode<T>* t, TreeNode<T>* p)			//根节点为t的树中找p的父节点，使之成为当前节点
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
bool Tree<T>::FirstChild()					//在树中找到当前节点的长子，并使之成为当前节点
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
	return NULL;
}


template<class T>
bool Tree<T>::RemoveFromPar(T parName)
{
	//找到当前结点并且删除
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
	//如果找到了nowName就更改其名字
	if (Find(nowName))
	{
		current->data = chName;
	}
}
#endif