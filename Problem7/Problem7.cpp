#include"HuffmanTree.h"

int main()
{
	int n;
	cin>>n;
	float a[10000];
	//����ÿ��ľͷ�ĳ���
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	HuffmanTree ht(a,n);
	//�õ���С����
	cout<<ht.Show()<<endl;
	return 0;
}
