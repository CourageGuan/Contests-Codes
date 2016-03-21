/*找规律，1 2 3 4 5 6 7 8 9 10 ...
          0 1 1 0 1 1 0 1 1 0  ...*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	/*long long ans,sum;
	ans=sum=0;
	for(long long i=1;i<=n;++i){
		sum+=i;
		if(sum%3==0){
			ans++;
			//printf("%d %d\n",i,ans);
		}
	}*/
	printf("%d\n",(n/3*2+((n%3==2)?1:0)));
	return 0;
}
