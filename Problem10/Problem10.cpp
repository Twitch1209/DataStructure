//排序统一为升序 
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<iomanip>
#include"MyStack.h"
using namespace std;

void outputall(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<' ';
	} 
}

//冒泡排序 
void BubbleSort(int a[],int n)
{
	double start,finish;
	start=(double)clock();			//计算开始时间 
	bool exchange=false;			//判断有没有交换 
	int i,j;
	long long int sortSum=0;				//交换次数 
	long long int compareSum=0;			//比较次数 
	for(i=0;i<n-1;i++)
	{
		exchange=false;
		for(j=n-1;j>i;j--)
		{
			//如果前一项大,则交换,交换次数+1 	
			if(a[j-1]>a[j])	
			{
				int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				sortSum++;
				exchange=true;
			}
			compareSum++;
		}
		if(exchange==false) break;
	}
	finish=(double)clock();
	cout<< left <<setw(24)<<"冒泡排序所用时间："<<finish-start<<endl;
	cout<< left <<setw(24)<<"冒泡排序交换次数："<<sortSum<<endl;
	cout<< left <<setw(24)<<"冒泡排序比较次数："<<compareSum<<endl; 
}

//选择排序 
void SelectSort(int a[],int n)
{
	double start,finish;
	start=(double)clock();			//计算开始时间 
	long long int sortSum=0;				//交换次数 
	long long int compareSum=0;			//比较次数 
	int k=0;
	//寻找最大的 
	for(int i=0;i<n-1;i++)
	{
		k=i;			//用k记录最大值的位置 
		for(int j=i+1;j<n;j++)
		{
			//如果有更加大的就记录位置 
			if(a[k]>a[j])
			{
				k=j;
			}
			compareSum++;
		}
		if(k!=i)//如果位置不一样就交换 
		{
			int temp=a[i];
			a[i]=a[k];
			a[k]=temp;
			sortSum++;
		}
		compareSum++;
	}
	finish=(double)clock();	
	cout<< left <<setw(24)<<"选择排序所用时间："<<finish-start<<endl;
	cout<< left <<setw(24)<<"选择排序交换次数："<<sortSum<<endl;
	cout<< left <<setw(24)<<"选择排序比较次数："<<compareSum<<endl; 	
}

//直接插入排序 
void InsertSort(int a[],int n)
{
	double start,finish;
	start=(double)clock();			//计算开始时间
	long long int sortSum=0;				//交换次数 
	long long int compareSum=0;			//比较次数 
	int temp,j;
	for(int i=1;i<n;i++)
	{
		//发现未排序好区域第一个元素比已排序好的最后一个元素小，说明要加入到前面 
		if(a[i]<a[i-1])
		{
			//记录这个值 
			temp=a[i];
			j=i-1;
			//不停和前一个值比较,如果前一个值更加大就让那个值向后移动 
			while(j>=0 && temp<a[j])
			{
				a[j+1]=a[j];
				sortSum++; 
				compareSum++;
				if(j!=0) j--;
				else break;
			}
			a[j]=temp;
		}
		compareSum++;
	}
	finish=(double)clock();	
	cout<< left <<setw(24)<<"直接插入排序所用时间："<<finish-start<<endl;
	cout<< left <<setw(24)<<"直接插入排序交换次数："<<sortSum<<endl;
	cout<< left <<setw(24)<<"直接插入排序比较次数："<<compareSum<<endl; 
}

//希尔排序
void ShellSort(int a[],int n)
{
	double start,finish;
	start=(double)clock();			//计算开始时间
	long long int sortSum=0;				//交换次数 
	long long int compareSum=0;			//比较次数 
	int j;
	int gap=n;
	int temp;
	do{
		gap=gap/3+1;				//求下一个gap 
		for(int i=gap;i<=n;i++)
		{
			if(a[i]<a[i-gap])		//如果前gap的值更加大，说明要排序 
			{
				temp=a[i];
				j=i-gap;
				//相隔gap来不断后移元素 
				do{
					a[j+gap]=a[j];
					j=j-gap;
					sortSum++;
					compareSum++;
				}while(j>=0 && temp<a[j]);
				a[j+gap]=temp;
			}
			compareSum++;
		}
	}while(gap>1);
	finish=(double)clock();	
	cout<< left <<setw(24)<<"希尔排序所用时间："<<finish-start<<endl;
	cout<< left <<setw(24)<<"希尔排序交换次数："<<sortSum<<endl;
	cout<< left <<setw(24)<<"希尔排序比较次数："<<compareSum<<endl; 
} 

//快速排序
int PartSort(int a[],int l,int r,long long int& sortSum,long long int &compareSum)
{
	//基准元素 
	int pivotpos=l;
	int pivot=a[l];
	//检查整个序列，进行划分 
	for(int i=l+1;i<=r;i++)
	{
		//小于基准的划到左边 
		if(a[i]<pivot)
		{
			pivotpos++;
			if(pivotpos!=i)
			{
				int temp=a[pivotpos];
				a[pivotpos]=a[i];
				a[i]=temp;
				sortSum++;
			}
		}
		compareSum++;
	}
	//将基准元素归位 
	a[l]=a[pivotpos];
	a[pivotpos]=pivot;
	sortSum++;
	//返回基准元素位置 
	return pivotpos;
}

void myQuickSort(int a[],int left,int right,long long int& sortSum,long long int& compareSum)
{
	if(left<right)
	{
		int pivotpos=PartSort(a,left,right,sortSum,compareSum);
		myQuickSort(a,left,pivotpos-1,sortSum,compareSum);
		myQuickSort(a,pivotpos+1,right,sortSum,compareSum);
	}
	compareSum++;
}

void QuickSort(int a[],int n)
{
	double start,finish;
	start=(double)clock();			//计算开始时间
	long long int sortSum=0;				//交换次数 
	long long int compareSum=0;			//比较次数 
	myQuickSort(a,0,n-1,sortSum,compareSum);
	finish=(double)clock();	
	cout<< left <<setw(24)<<"快速排序所用时间："<<finish-start<<endl;
	cout<< left <<setw(24)<<"快速排序交换次数："<<sortSum<<endl;
	cout<< left <<setw(24)<<"快速排序比较次数："<<compareSum<<endl; 
}

//堆排序
void Swap(int& i,int& j)
{
	int temp=i;i=j;j=temp;
}

void siftDown(int a[],int start,int m,long long int& sortSum,long long int& compareSum)//从节点start到m从上到下比较，如果子女的值小于
{										//父节点的值则调整 
	int i=start;
	int j=2*i+1;
	int temp=a[i];
	while(j<=m)
	{
		if(j<m && a[j]<a[j+1])j++;			//j->min(heap[j],heap[j+1])
		else if(temp>=a[j])break;
		//the max of child up
		else
		{
			a[i]=a[j];
			i=j;
			j=2*j+1;
			sortSum++;
		}
		compareSum+=3;
	}
	a[i]=temp;
}

void HeapSort(int a[],int n)
{
	double start,finish;
	start=(double)clock();			//计算开始时间
	long long int sortSum=0;				//交换次数 
	long long int compareSum=0;			//比较次数 		
	for(int i=(n-2)/2;i>=0;i--)
	{
		siftDown(a,i,n-1,sortSum,compareSum);
	}
	for(int i=n-1;i>=0;i--)
	{
		Swap(a[0],a[i]);
		sortSum++;
		siftDown(a,0,i-1,sortSum,compareSum);
	}
	finish=(double)clock();	
	cout<< left <<setw(24)<<"堆排序所用时间："<<finish-start<<endl;
	cout<< left <<setw(24)<<"堆排序交换次数："<<sortSum<<endl;
	cout<< left <<setw(24)<<"堆排序比较次数："<<compareSum<<endl; 
}

//归并排序
void merge(int L1[],int L2[],int left,int mid,int right,long long int& sortSum,long long int& compareSum)
{
//把待归并元素序列L1复制到辅助数组L2中，再从L2归并到L1中 
	for(int k=left;k<=right;k++)
	{
		L2[k]=L1[k];
	}
	int s1=left;
	int s2=mid+1;			//s1,s2是检测指针 
	int t=left;				//t是存放指针 
	//两个表都没有检测完 
	while(s1<=mid&& s2<=right)
	{
		if(L2[s1]<=L2[s2]) 
		{
			L1[t++]=L2[s1++];
			sortSum++;
		}
		else
		{
			L1[t++]=L2[s2++];
			sortSum++;
		}
		compareSum+=2;
	}
	//第一个表没有检测完 
	while(s1<=mid)
	{
		L1[t++]=L2[s1++];
		sortSum++;
	}
	//第二个表没有检测完 
	while(s2<=right)
	{
		L1[t++]=L2[s2++];
		sortSum++;
	}
}

void mergeSort(int a[],int b[],int left,int right,long long int& sortSum,long long int& compareSum)
{
	if(left>=right){return;}
	int mid=(left+right)/2;			//花费为两个子序列 
	mergeSort(a,b,left,mid,sortSum,compareSum);		//对左侧子序列进行排序 
	mergeSort(a,b,mid+1,right,sortSum,compareSum);		//对右侧子序列进行排序 
	merge(a,b,left,mid,right,sortSum,compareSum);		//合并 
}

void MergeSort(int a[],int n)
{
	double start,finish;
	start=(double)clock();			//计算开始时间
	long long int sortSum=0;				//交换次数 
	long long int compareSum=0;			//比较次数 	
	int *b=new int[n];
	mergeSort(a,b,0,n-1,sortSum,compareSum);
	delete b;
	finish=(double)clock();	
	cout<< left <<setw(24)<<"归并排序所用时间："<<finish-start<<endl;
	cout<< left <<setw(24)<<"归并排序交换次数："<<sortSum<<endl;
	cout<< left <<setw(24)<<"归并排序比较次数："<<compareSum<<endl; 
}

//基数排序 
int getMaxDigit(int a[],int n)
{
	int digit=1;
	int base=10;
	for(int i=0;i<n;i++)
	{
		while(a[i]>=base)
		{
			base*=10;
			digit++;	
		}	
	}
	return digit;	
} 

void LSDSort(int a[],int n,long long int& sortSum,long long int& compareSum)
{
	int maxDigit=getMaxDigit(a,n);
	int count[10];
	int *tmp=new int[n];
	int radix = 1;
	int i, j, k;
	for (i = 1; i <= maxDigit; i++)//进行maxdiDigit次排序
	{
		//每次分配前清空计数器
		for (j = 0; j < 10; j++)
		{
			count[j] = 0;
		}
		for (j = 0; j < n; j++)
		{
			k = (a[j] / radix) % 10;//统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
		{
			count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
		}
		//将所有桶中记录依次收集到tmp中
		for (j = n - 1; j >= 0; j--)
		{
			k = (a[j] / radix) % 10;
			tmp[count[k] - 1] = a[j];
			count[k]--;
		}
		//将临时数组的内容复制到data中
		for (j = 0; j < n; j++)
		{
			a[j] = tmp[j];
		}
		radix = radix * 10;
	}
	delete[] tmp;
}

void RadixSort(int a[], int n)
{
	double start, finish;
	start = (double)clock();			//计算开始时间
	long long int sortSum = 0;				//交换次数 
	long long int compareSum = 0;			//比较次数 	
	LSDSort(a, n, sortSum, compareSum);
	finish = (double)clock();
	cout << left << setw(24) << "基数排序所用时间：" << finish - start << endl;
	cout << left << setw(24) << "基数排序交换次数：" << sortSum << endl;
	cout << left << setw(24) << "基数排序比较次数：" << compareSum << endl;
}

int main()
{
	cout << "**" << setw(32) << "排序算法比较"     	 << setw(16) << "**" << endl;
	cout << "==================================================" << endl;
	cout << "**" << setw(32) << "1 --- 冒泡排序    " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "2 --- 选择排序    " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "3 --- 直接插入排序" << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "4 --- 希尔排序    " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "5 --- 快速排序    " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "6 --- 堆排序      " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "7 --- 归并排序    " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "8 --- 基数排序    " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "9 --- 退出程序    " << setw(16) << "**" << endl;
	cout << "==================================================" << endl;

	while(1)
	{
		cout << endl;
		srand(int(time(0)));
		int n;
		cout << "请输入要产生的随机数的个数:";
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i<n; i++)
		{
			a[i] = rand();
		}

		cout<<endl;
		for(int i=0;i<n;i++) {a[i]=rand();}
		int order;
		cout<< left <<setw(24)<<"请选择排序算法：";
		cin>>order;
		switch(order)
		{
			case 1:{BubbleSort(a,n); break;}
			case 2:{SelectSort(a,n); break;}
			case 3:{InsertSort(a,n); break;}
			case 4:{ShellSort(a,n); break;}
			case 5:{QuickSort(a,n); break;}
			case 6:{HeapSort(a,n); break;}
			case 7:{MergeSort(a,n); break;}
			case 8:{RadixSort(a,n); break;}
			case 9: {return 0; }
			default:{
				cout << "没有匹配的操作！请重新输入" << endl;
				break;
			}
		}
	}
	return 0;
}
