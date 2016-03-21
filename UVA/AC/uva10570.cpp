/*枚举起点，依次将i交换至第i位，取最小的交换次数*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn=500+5;

int a[maxn],b[maxn],p[maxn],q[maxn],hd,n;

/*bool is_sort(int hd,int r)
{
	for(int i=0;r*i<n;i+=r)
		if(a[(i+hd+n)%n]!=r*i+1) return false;
	return true;
}*/

int main()
{
	//freopen("test","r",stdin);
	while(scanf("%d",&n)==1 && n){
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			b[i]=a[i];
			p[a[i]]=i;
			q[a[i]]=i;
		}
		/*while(1){
			if(r>2*n) break;
			if (a[(r+1)%n]==a[r%n]+1) ++r;
			else{ 
				if(r-l+1>len){ 
					pos=l;
					len=r-l+1;
				}
				++r;l=r;
			}
		}
		l=r=0;
		while(1){
			if(r>2*n) break;
			if (a[(r+1)%n]==a[r%n]-1) ++r;
			else{
				if(r-l+1>len){ 
					pos=l;
					len=r-l+1;
					r=l=r+1;
					rev=-1;
				}
				++r;l=r;
			}
		}
		if(len==n){
			printf("0\n");
			continue;
		}*/
		/*while(!is_sort(rev)){
			if(rev==1){
				int cur=(a[pos]==1)?n:a[pos]-1,pos=(pos-1+n)%n;
				int i;
				for(i=0;i<n;++i) if(a[i]==cur) break;
				if(i!=pos){
					if(cur==1) hd=pos;
					swap(a[i],a[pos]); 
					++cnt;
				}
			}
			else{
				int cur=(a[pos]==n)?1:a[pos]+1,pos=(pos-1+n)%n;
				int i;
				for(i=0;i<n;++i) if(a[i]==cur) break;
				if(i!=pos){
					if(cur==1) hd=pos;
					if(a[pos]==1) hd=i;
					swap(a[i],a[pos]); 
					++cnt;
				}
			}
		}*/
		//for(int j=0;j<n;++j) cout<<a[j]<<" ";
		//puts("");
		int cnt,ans=0x3f3f3f3f;
		for(int i=0;i<n;++i){
			memcpy(a,b,sizeof(a));
			memcpy(p,q,sizeof(p));
			cnt=0;
			for(int j=0;j<n;++j){
				int k=(i+j)%n;
				//while(!is_sort(i,1))
					if(k!=p[j+1]){
						p[a[k]]=p[j+1];
						swap(a[k],a[p[j+1]]);
						cnt++;
					}
			}
			ans=min(cnt,ans);
		}
		for(int i=0;i<n;++i){
			memcpy(a,b,sizeof(a));
			memcpy(p,q,sizeof(p));
			cnt=0;
			for(int j=0;j<n;++j){
				int k=(i-j+n)%n;
				//while(!is_sort(i,-1))
					if(k!=p[j+1]){
						p[a[k]]=p[j+1];
						swap(a[k],a[p[j+1]]);
						cnt++;
					}
			}
			ans=min(ans,cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}

