#include<bits/stdc++.h>

const int maxn = 110;
double res[maxn];

int main(){
	double cur = 0.25;
	res[0] = 0; res[1] = 0.25;

	for(int i=2;i<=26;++i) res[i] = res[i-1] + (cur/=2);

	int kase;
	scanf("%d",&kase);

	for(int z = 1;z<=kase;++z){
		double k;
		scanf("%lf",&k);
		if(k == 0.49999999){
			puts("104");
			continue;
		}
		bool flag = false;
		for(int i=0;i<26;++i)
			if(fabs(k - res[i])<1e-10){
				puts("-1");
				flag = true;
				break;
			}
		if(flag) continue;
		int cur = 0;
		for(int i=0;i<26;++i){
			cur += 4;
			if(res[i] < k && k < res[i+1]){
				printf("%d\n",cur);
				break;
			}
		}
	}
	return 0;
}


