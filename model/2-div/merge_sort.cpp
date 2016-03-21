/*归并排序*/
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=123456;

void merge_sort(int a[],int t[],int x,int y) //sort a[]  temp t[]  [x,y)
{
	if(y-x<=1) return;
	int m=x+(y-x)/2;
	merge_sort(a,t,x,m);
	merge_sort(a,t,m,y);
	int p=x,q=m,cnt=x;
	while(p<m || q<y){
		if(p>=m || (q<y && a[p]>=a[q])) t[cnt++]=a[q++];
		else t[cnt++]=a[p++];
	}
	for(int i=x;i<y;++i) a[i]=t[i];
}
		
int main()
{
	int n,a[maxn],t[maxn];
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	merge_sort(a,t,0,n);
	for(int i=0;i<n;++i) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

