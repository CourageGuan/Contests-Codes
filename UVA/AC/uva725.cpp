/*果然是行末空格惹的祸，uva的文本对比啊啊啊...
 　枚举被除数即可*/
#include<cstdio>
#include<cstring>

const int maxn=49382;

bool yes(int i ,int j)
{
	if (j>99999) return false;
	bool flag[10];
	memset(flag,0,sizeof(flag));
	for(int k=0;k<5;++k){
		if(flag[j%10]) return false;
		else flag[j%10]=1;
		j/=10;
		if(flag[i%10]) return false;
		else flag[i%10]=1;
		i/=10;
	}
	return true;
}

bool solve(int n)
{
	bool flag=false;
	for(int i=1234;i<=maxn;++i){
		int j=i*n;
		if(yes(i,j)){
		   	printf("%05d / %05d = %d\n",j,i,n);
			flag=true;
		}
	}
	return flag;
}	

		
int main()
{
	//freopen("725.in","r",stdin);
	//freopen("1","w",stdout);
	int n,kase=0;
	while(scanf("%d",&n)==1 && n){
		if(kase++) printf("\n");
		if(!solve(n)) printf("There are no solutions for %d.\n",n);
	}
	return 0;
}
