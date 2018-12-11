#include"Heap.h"

struct HuffmanNode
{
	float data;															//����ֵ
	HuffmanNode *leftChild,*rightChild,*parent;							//������Ů�͸����ָ��
	HuffmanNode():leftChild(NULL),rightChild(NULL),parent(NULL){}		//���캯��
	HuffmanNode(float elem,HuffmanNode* left=NULL,
			HuffmanNode* right=NULL,HuffmanNode* pr=NULL)
			:data(elem),leftChild(left),rightChild(right),parent(pr){}	//���캯��
	bool operator<=(HuffmanNode& R){return data<=R.data;}
	bool operator>(HuffmanNode& R){return data>R.data;}
};


class HuffmanTree
{
public:
	HuffmanTree(float w[],int n);					//���캯��
	~HuffmanTree(){delete root;}					//��������
	float Show();									//�����������

protected:
	float sum;										//��ľͷ���N�����С����
	HuffmanNode *root;								//�����
	void mergeTree(HuffmanNode& ht1,HuffmanNode& ht2,HuffmanNode* &parent);	//�ϲ�������
};

//construction
HuffmanTree::HuffmanTree(float w[],int n)		//����n��Ȩֵ������huffman�� 
{
	//ʹ����С�������
	MinHeap<HuffmanNode> hp;
	HuffmanNode *parent;
	HuffmanNode first,second,work;
	//��ʼ���ܻ���sum
	sum=0;
	//�������ֱ���뵽��С����
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
		hp.RemoveMin(first);//ѡ�����Ȩֵ��С����
		hp.RemoveMin(second);//ѡ�����Ȩֵ��С����
		mergeTree(first,second,parent);//�����Ǻϲ�
		hp.Insert(*parent);//���²��뵽��С����
	}
	root=parent;//�������ڵ�
}

void HuffmanTree::mergeTree(HuffmanNode& ht1,HuffmanNode& ht2,HuffmanNode* &pr)
{
	//�ϲ�ht1��ht2����pr��Ϊht1��ht2�ĸ����
	pr=new HuffmanNode;
	pr->leftChild=&ht1;
	pr->rightChild=&ht2;
	pr->data=ht1.data+ht2.data;
	sum+=pr->data;//ˢ���ܻ���
	ht1.parent=ht2.parent=pr;
}

float HuffmanTree::Show()
{
	return sum;
}














