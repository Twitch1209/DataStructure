//����ͳһΪ���� 
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

//ð������ 
void BubbleSort(int a[],int n)
{
	double start,finish;
	start=(double)clock();			//���㿪ʼʱ�� 
	bool exchange=false;			//�ж���û�н��� 
	int i,j;
	long int sortSum=0;				//�������� 
	long int compareSum=0;			//�Ƚϴ��� 
	for(i=0;i<n-1;i++)
	{
		exchange=false;
		for(j=n-1;j>i;j--)
		{
			//���ǰһ���,�򽻻�,��������+1 	
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
	cout<< left <<setw(24)<<"ð����������ʱ�䣺"<<finish-start<<endl;
	cout<< left <<setw(24)<<"ð�����򽻻�������"<<sortSum<<endl;
	cout<< left <<setw(24)<<"ð������Ƚϴ�����"<<compareSum<<endl; 
}

//ѡ������ 
void SelectSort(int a[],int n)
{
	double start,finish;
	start=(double)clock();			//���㿪ʼʱ�� 
	long int sortSum=0;				//�������� 
	long int compareSum=0;			//�Ƚϴ��� 
	int k=0;
	//Ѱ������ 
	for(int i=0;i<n-1;i++)
	{
		k=i;			//��k��¼���ֵ��λ�� 
		for(int j=i+1;j<n;j++)
		{
			//����и��Ӵ�ľͼ�¼λ�� 
			if(a[k]>a[j])
			{
				k=j;
			}
			compareSum++;
		}
		if(k!=i)//���λ�ò�һ���ͽ��� 
		{
			int temp=a[i];
			a[i]=a[k];
			a[k]=temp;
			sortSum++;
		}
		compareSum++;
	}
	finish=(double)clock();	
	cout<< left <<setw(24)<<"ѡ����������ʱ�䣺"<<finish-start<<endl;
	cout<< left <<setw(24)<<"ѡ�����򽻻�������"<<sortSum<<endl;
	cout<< left <<setw(24)<<"ѡ������Ƚϴ�����"<<compareSum<<endl; 	
}

//ֱ�Ӳ������� 
void InsertSort(int a[],int n)
{
	double start,finish;
	start=(double)clock();			//���㿪ʼʱ��
	long int sortSum=0;				//�������� 
	long int compareSum=0;			//�Ƚϴ��� 
	int temp,j;
	for(int i=1;i<n;i++)
	{
		//����δ����������һ��Ԫ�ر�������õ����һ��Ԫ��С��˵��Ҫ���뵽ǰ�� 
		if(a[i]<a[i-1])
		{
			//��¼���ֵ 
			temp=a[i];
			j=i-1;
			//��ͣ��ǰһ��ֵ�Ƚ�,���ǰһ��ֵ���Ӵ�����Ǹ�ֵ����ƶ� 
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
	cout<< left <<setw(24)<<"ֱ�Ӳ�����������ʱ�䣺"<<finish-start<<endl;
	cout<< left <<setw(24)<<"ֱ�Ӳ������򽻻�������"<<sortSum<<endl;
	cout<< left <<setw(24)<<"ֱ�Ӳ�������Ƚϴ�����"<<compareSum<<endl; 
}

//ϣ������
void ShellSort(int a[],int n)
{
	double start,finish;
	start=(double)clock();			//���㿪ʼʱ��
	long int sortSum=0;				//�������� 
	long int compareSum=0;			//�Ƚϴ��� 
	int j;
	int gap=n;
	int temp;
	do{
		gap=gap/3+1;				//����һ��gap 
		for(int i=gap;i<=n;i++)
		{
			if(a[i]<a[i-gap])		//���ǰgap��ֵ���Ӵ�˵��Ҫ���� 
			{
				temp=a[i];
				j=i-gap;
				//���gap�����Ϻ���Ԫ�� 
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
	cout<< left <<setw(24)<<"ϣ����������ʱ�䣺"<<finish-start<<endl;
	cout<< left <<setw(24)<<"ϣ�����򽻻�������"<<sortSum<<endl;
	cout<< left <<setw(24)<<"ϣ������Ƚϴ�����"<<compareSum<<endl; 
} 

//��������
int PartSort(int a[],int l,int r,long int& sortSum,long int &compareSum)
{
	//��׼Ԫ�� 
	int pivotpos=l;
	int pivot=a[l];
	//����������У����л��� 
	for(int i=l+1;i<=r;i++)
	{
		//С�ڻ�׼�Ļ������ 
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
	//����׼Ԫ�ع�λ 
	a[l]=a[pivotpos];
	a[pivotpos]=pivot;
	sortSum++;
	//���ػ�׼Ԫ��λ�� 
	return pivotpos;
}

void myQuickSort(int a[],int left,int right,long int& sortSum,long int& compareSum)
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
	start=(double)clock();			//���㿪ʼʱ��
	long int sortSum=0;				//�������� 
	long int compareSum=0;			//�Ƚϴ��� 
	myQuickSort(a,0,n-1,sortSum,compareSum);
	finish=(double)clock();	
	cout<< left <<setw(24)<<"������������ʱ�䣺"<<finish-start<<endl;
	cout<< left <<setw(24)<<"�������򽻻�������"<<sortSum<<endl;
	cout<< left <<setw(24)<<"��������Ƚϴ�����"<<compareSum<<endl; 
}

//������
void Swap(int& i,int& j)
{
	int temp=i;i=j;j=temp;
}

void siftDown(int a[],int start,int m,long int& sortSum,long int& compareSum)//�ӽڵ�start��m���ϵ��±Ƚϣ������Ů��ֵС��
{										//���ڵ��ֵ����� 
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
	start=(double)clock();			//���㿪ʼʱ��
	long int sortSum=0;				//�������� 
	long int compareSum=0;			//�Ƚϴ��� 		
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
	cout<< left <<setw(24)<<"����������ʱ�䣺"<<finish-start<<endl;
	cout<< left <<setw(24)<<"�����򽻻�������"<<sortSum<<endl;
	cout<< left <<setw(24)<<"������Ƚϴ�����"<<compareSum<<endl; 
}

//�鲢����
void merge(int L1[],int L2[],int left,int mid,int right,long int& sortSum,long int& compareSum)
{
//�Ѵ��鲢Ԫ������L1���Ƶ���������L2�У��ٴ�L2�鲢��L1�� 
	for(int k=left;k<=right;k++)
	{
		L2[k]=L1[k];
	}
	int s1=left;
	int s2=mid+1;			//s1,s2�Ǽ��ָ�� 
	int t=left;				//t�Ǵ��ָ�� 
	//������û�м���� 
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
		compareSum+=3;
	}
	//��һ����û�м���� 
	while(s1<=mid)
	{
		L1[t++]=L2[s1++];
		sortSum++;
		compareSum++;
	}
	//�ڶ�����û�м���� 
	while(s2<=right)
	{
		L1[t++]=L2[s2++];
		sortSum++;
		compareSum++;
	}
}

void mergeSort(int a[],int b[],int left,int right,long int& sortSum,long int& compareSum)
{
	if(left>=right){return;}
	int mid=(left+right)/2;			//����Ϊ���������� 
	mergeSort(a,b,left,mid,sortSum,compareSum);		//����������н������� 
	mergeSort(a,b,mid+1,right,sortSum,compareSum);		//���Ҳ������н������� 
	merge(a,b,left,mid,right,sortSum,compareSum);		//�ϲ� 
}

void MergeSort(int a[],int n)
{
	double start,finish;
	start=(double)clock();			//���㿪ʼʱ��
	long int sortSum=0;				//�������� 
	long int compareSum=0;			//�Ƚϴ��� 	
	int *b=new int[n];
	mergeSort(a,b,0,n-1,sortSum,compareSum);
	delete b;
	finish=(double)clock();	
	cout<< left <<setw(24)<<"�鲢��������ʱ�䣺"<<finish-start<<endl;
	cout<< left <<setw(24)<<"�鲢���򽻻�������"<<sortSum<<endl;
	cout<< left <<setw(24)<<"�鲢����Ƚϴ�����"<<compareSum<<endl; 
}

//�������� 
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

void LSDSort(int a[],int n)
{
	int maxDigit=getMaxDigit(a,n);
	int base=1;
	int *bucket=new int[n];
	while((maxDigit--)>0)
	{
		int counts[10]={0};
		int start[10]={0};
		start[0]=0;
		
		//��numλ��Ԫ�� 
		for(int i=0;i<n;i++)
		{
			int num=(a[i]/base)%10;
			counts[num]++;
		}
		
		for(int i=1;i<10;i++)
		{
			start[i]=start[i-1]+counts[i-1];
		}
		
		for(int i=0;i<n;i++)
		{
			int num=(a[i]/base)%10;
			bucket[start[num]++]=a[i];
		}
		memcpy(a,bucket,sizeof(int)*n);
		base*=10;
	}
	
}

int main()
{
	cout << "**" << setw(32) << "�����㷨�Ƚ�"     	 << setw(16) << "**" << endl;
	cout << "==================================================" << endl;
	cout << "**" << setw(32) << "1 --- ð������    " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "2 --- ѡ������    " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "3 --- ֱ�Ӳ�������" << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "4 --- ϣ������    " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "5 --- ��������    " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "6 --- ������      " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "7 --- �鲢����    " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "8 --- ��������    " << setw(16) << "**" << endl;
	cout << "**" << setw(32) << "9 --- �˳�����    " << setw(16) << "**" << endl;
	cout << "==================================================" << endl;
	srand(int(time(0)));
	int n;
	cout<<"������Ҫ������������ĸ���:";
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		a[i]=rand();
	}
	while(1)
	{
		cout<<endl;
		for(int i=0;i<n;i++) {a[i]=rand();}
		int order;
		cout<< left <<setw(24)<<"��ѡ�������㷨��";
		cin>>order;
		switch(order)
		{
			case 1:{BubbleSort(a,n); continue;}
			case 2:{SelectSort(a,n); continue;}
			case 3:{InsertSort(a,n); continue;}
			case 4:{ShellSort(a,n);continue;}
			case 5:{QuickSort(a,n);continue;}
			case 6:{HeapSort(a,n);continue;}
			case 7:{MergeSort(a,n);continue;}
			case 8:{LSDSort(a,n);continue;}
		}
		 
		
	}
	cout<<endl;
}
