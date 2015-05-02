#include<bits/stdc++.h>
using namespace std;


const char Month[13][20]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

inline bool yes(int year){
	return (!(year%4) && year%100 ) || !(year%400);
}

int main()
{
	freopen("test.txt","r",stdin);
	int T,kase=0;
	scanf("%d",&T);
	while(T--){
		char month[20];
		int mon[2],day[2],year[2],tem[2];
		for(int i=0;i<2;++i){
		scanf("%s",month);
		scanf("%d, %d",day+i,year+i);
		for(int j=1;j<=12;++j) if(Month[j][0]==month[0] && Month[j][1]==month[1] && Month[j][2]==month[2]){
				mon[i]=j;break;
		}
		tem[i]=year[i];
		if(year[i]%4){
			while(year[i]%4) ++year[i];
			day[i]=mon[i]=0;
		}
		else 
			if(!i){
				if(mon[i]>2) year[i]+=4;
			}
			else{
				if(mon[i]>2 || (mon[i]==2 && day[i]>=29)) year[i]+=4;
			}
		}
		int ans=(year[1]-year[0])/4;
		if(ans==0)
			printf("Case #%d: %d\n",++kase,0);
		else{
			year[0]-=4;year[0]/=100;
			year[1]-=4;year[1]/=100;
			//cout<<year[0]<<" "<<year[1]<<endl;
			ans-=(year[1]-year[0]);
			++year[0],++year[1];
			while(year[0]%4) ++year[0];
			while(year[1]%4) ++year[1];
			//cout<<year[0]<<" "<<year[1]<<endl;
			ans+=(year[1]-year[0])/4;
			printf("Case #%d: %d\n",++kase,ans);
		}
	}
	return 0;
}

