#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int maxn=123456;

void qsort(int a[],int x,int y)
{
	if(x>=y) return;
	int mid=a[x],i=x,j=y-1;
	while(i<j){
		while(i<j && a[j]>=mid) --j;
		a[i]=a[j];
		while(i<j && a[i]<=mid) ++i;
		a[j]=a[i];
	}
	a[i]=mid;
	qsort(a,x,i-1);
	qsort(a,i+1,y);
}

int main()
{
	srand(time(0));
	int a[maxn],n;
	cin>>n;	
	for(int i=0;i<n;++i) cin>>a[i];
	qsort(a,0,n);
	for(int i=0;i<n;++i) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

