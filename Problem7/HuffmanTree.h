#include"Heap.h"

struct HuffmanNode
{
	float data;															//数据值
	HuffmanNode *leftChild,*rightChild,*parent;							//左右子女和父结点指针
	HuffmanNode():leftChild(NULL),rightChild(NULL),parent(NULL){}		//构造函数
	HuffmanNode(float elem,HuffmanNode* left=NULL,
			HuffmanNode* right=NULL,HuffmanNode* pr=NULL)
			:data(elem),leftChild(left),rightChild(right),parent(pr){}	//构造函数
	bool operator<=(HuffmanNode& R){return data<=R.data;}
	bool operator>(HuffmanNode& R){return data>R.data;}
};


class HuffmanTree
{
public:
	HuffmanTree(float w[],int n);					//构造函数
	~HuffmanTree(){delete root;}					//析构函数
	float Show();									//输出霍夫曼树

protected:
	float sum;										//将木头锯成N块的最小花费
	HuffmanNode *root;								//根结点
	void mergeTree(HuffmanNode& ht1,HuffmanNode& ht2,HuffmanNode* &parent);	//合并二叉树
};

//construction
HuffmanTree::HuffmanTree(float w[],int n)		//给出n个权值来构造huffman树 
{
	//使用最小堆来存放
	MinHeap<HuffmanNode> hp;
	HuffmanNode *parent;
	HuffmanNode first,second,work;
	//初始化总花费sum
	sum=0;
	//将各树分别插入到最小堆中
	for(int i=0;i<n;i++)
	{
		work.data=w[i];
		work.leftChild=NULL;
		work.rightChild=NULL;
		work.parent=NULL;
		hp.Insert(work);
	}
	for(int i=0;i<n-1;i++)
	{
		hp.RemoveMin(first);//选择根的权值最小的树
		hp.RemoveMin(second);//选择根的权值次小的树
		mergeTree(first,second,parent);//将他们合并
		hp.Insert(*parent);//重新插入到最小堆中
	}
	root=parent;//建立根节点
}

void HuffmanTree::mergeTree(HuffmanNode& ht1,HuffmanNode& ht2,HuffmanNode* &pr)
{
	//合并ht1和ht2，即pr成为ht1和ht2的父结点
	pr=new HuffmanNode;
	pr->leftChild=&ht1;
	pr->rightChild=&ht2;
	pr->data=ht1.data+ht2.data;
	sum+=pr->data;//刷新总花费
	ht1.parent=ht2.parent=pr;
}

float HuffmanTree::Show()
{
	return sum;
}














