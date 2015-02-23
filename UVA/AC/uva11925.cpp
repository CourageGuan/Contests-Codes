/*好坑，题目描述有误。。。
 * 链表不好写，借鉴了别人的滚动数组
 * 滚动数字改变头位置即可完成操作2*/
#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

const int maxn=300+5;

int a[3*maxn];

int n,head;

bool is_sort()
{
	for(int i=0;i<n;++i)
		if(a[(head+i)%n]!=i+1) return false;
	return true;
}

void move1()
{
	swap(a[head],a[(head+1)%n]);
}

void move2()
{
	head=(head+n-1)%n;
}

int main()
{
	//freopen("test","r",stdin);
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		head=0;
		std::vector<int> ans;
		while(!is_sort()){
			if(a[head]>a[(head+1)%n] && !(a[head]==n && a[(head+1)%n]==1)){
				ans.push_back(1);
				move1();
			}
			else {
				ans.push_back(2);
				move2();
			}
			//for(int i=0;i<n;++i) cout<<a[(head+i)%n];
			//puts("");
		}
		//printf("%d\n",ans.size());
		for(int i=ans.size()-1;i>=0;--i) printf("%d",ans[i]);
		puts("");
	}
	return 0;
}


