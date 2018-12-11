#include"HuffmanTree.h"

int main()
{
	int n;
	cin>>n;
	float a[10000];
	//输入每块木头的长度
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	HuffmanTree ht(a,n);
	//得到最小花费
	cout<<ht.Show()<<endl;
	return 0;
}
