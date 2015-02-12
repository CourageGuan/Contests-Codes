/*BFS,300+,汝佳说代码太长写的IDA*解法...*/
#include<bits/stdc++.h>
using namespace std;

const int maxn=24;
typedef int State[maxn];
typedef long long LL;
State a,b,c;	//case 1  2  3
const LL goal=0x0399c0;

/*
 
    00  01
	02  03
04050607080910
    11  12
13141516171819
    20  21
    22  23	
 
*/

void init()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
}

LL id(int a[])
{
	LL res=0;
	for(int i=0;i<24;++i) res+=a[i]<<i;
	return res;
}

LL mv(int i,LL a)
{
	LL res=0;
	switch(i){
		case 0:
			for(int i=0;i<24;++i)
				switch(i){
					case 0:res+=(a>>2&1)<<i;break; 
					case 2:res+=(a>>6&1)<<i;break;
					case 6:res+=(a>>11&1)<<i;break;
					case 11:res+=(a>>15&1)<<i;break;
					case 15:res+=(a>>20&1)<<i;break;
					case 20:res+=(a>>22&1)<<i;break;
					case 22:res+=(a&1)<<i;break;
					default:res+=(a>>i&1)<<i;break;
				}
			break;
		case 1:
			for(int i=0;i<24;++i)
				switch(i){
					case 1:res+=(a>>3&1)<<i;break; 
					case 3:res+=(a>>8&1)<<i;break;
					case 8:res+=(a>>12&1)<<i;break;
					case 12:res+=(a>>17&1)<<i;break;
					case 17:res+=(a>>21&1)<<i;break;
					case 21:res+=(a>>23&1)<<i;break;
					case 23:res+=(a>>1&1)<<i;break;
					default:res+=(a>>i&1)<<i;break;
				}
			break;
		case 2:
			for(int i=0;i<24;++i)
				switch(i){
					case 10:res+=(a>>9&1)<<i;break; 
					case 9:res+=(a>>8&1)<<i;break;
					case 8:res+=(a>>7&1)<<i;break;
					case 7:res+=(a>>6&1)<<i;break;
					case 6:res+=(a>>5&1)<<i;break;
					case 5:res+=(a>>4&1)<<i;break;
					case 4:res+=(a>>10&1)<<i;break;
					default:res+=(a>>i&1)<<i;break;
				}
			break;
		case 3:
			for(int i=0;i<24;++i)
				switch(i){
					case 19:res+=(a>>18&1)<<i;break; 
					case 18:res+=(a>>17&1)<<i;break;
					case 17:res+=(a>>16&1)<<i;break;
					case 16:res+=(a>>15&1)<<i;break;
					case 15:res+=(a>>14&1)<<i;break;
					case 14:res+=(a>>13&1)<<i;break;
					case 13:res+=(a>>19&1)<<i;break;
					default:res+=(a>>i&1)<<i;break;
				}
			break;
		case 4:
			for(int i=0;i<24;++i)
				switch(i){
					case 23:res+=(a>>21&1)<<i;break; 
					case 21:res+=(a>>17&1)<<i;break;
					case 17:res+=(a>>12&1)<<i;break;
					case 12:res+=(a>>8&1)<<i;break;
					case 8:res+=(a>>3&1)<<i;break;
					case 3:res+=(a>>1&1)<<i;break;
					case 1:res+=(a>>23&1)<<i;break;
					default:res+=(a>>i&1)<<i;break;
				}
			break;
		case 5:
			for(int i=0;i<24;++i)
				switch(i){
					case 22:res+=(a>>20&1)<<i;break; 
					case 20:res+=(a>>15&1)<<i;break;
					case 15:res+=(a>>11&1)<<i;break;
					case 11:res+=(a>>6&1)<<i;break;
					case 6:res+=(a>>2&1)<<i;break;
					case 2:res+=(a&1)<<i;break;
					case 0:res+=(a>>22&1)<<i;break;
					default:res+=(a>>i&1)<<i;break;
				}
			break;
		case 6:
			for(int i=0;i<24;++i)
				switch(i){
					case 13:res+=(a>>14&1)<<i;break; 
					case 14:res+=(a>>15&1)<<i;break;
					case 15:res+=(a>>16&1)<<i;break;
					case 16:res+=(a>>17&1)<<i;break;
					case 17:res+=(a>>18&1)<<i;break;
					case 18:res+=(a>>19&1)<<i;break;
					case 19:res+=(a>>13&1)<<i;break;
					default:res+=(a>>i&1)<<i;break;
				}
			break;
		case 7:
			for(int i=0;i<24;++i)
				switch(i){
					case 4:res+=(a>>5&1)<<i;break; 
					case 5:res+=(a>>6&1)<<i;break;
					case 6:res+=(a>>7&1)<<i;break;
					case 7:res+=(a>>8&1)<<i;break;
					case 8:res+=(a>>9&1)<<i;break;
					case 9:res+=(a>>10&1)<<i;break;
					case 10:res+=(a>>4&1)<<i;break;
					default:res+=(a>>i&1)<<i;break;
				}
			break;
	}
	return res;
}

struct status{
	int id;
	string s;
	bool operator<(status const b) const {
		if(s.size()==b.s.size()) return s<b.s;
		else return s.size()<b.s.size();
	}

	status operator=(status b){
		id=b.id;
		s=b.s;
		return *this;
	}
};

set<LL> vis1,vis2,vis3;
int father1[1000000],rec1[1000000],father2[1000000],rec2[1000000],father3[1000000],rec3[1000000];

status bfs(LL a,LL b,LL c)
{
	memset(father1,0,sizeof(father1));
	memset(rec1,-1,sizeof(rec1));
	memset(father2,0,sizeof(father2));
	memset(rec2,-1,sizeof(rec2));
	memset(father3,0,sizeof(father3));
	memset(rec3,-1,sizeof(rec3));
	int cnt1=0,cnt2=0,cnt3=0,front=0,code=0;
	vis1.clear();
	vis2.clear();
	vis3.clear();
	//memset(stu,0,sizeof(stu));
	//int front=1,rear=2;
	//memcpy(stu[0],a,sizeof(a));
	queue<LL> q1,q2,q3;
	q1.push(a);q2.push(b);q3.push(c);
	vis1.insert(a);
	vis2.insert(b);
	vis3.insert(c);
	father1[cnt1++]=0;
	father2[cnt2++]=0;
	father3[cnt3++]=0;
	while(!q1.empty() || !q2.empty() || !q3.empty()){
		LL u1=q1.front();q1.pop();
		LL u2=q2.front();q2.pop();
		LL u3=q3.front();q3.pop();
		//for(int j=0;j<24;++j) cout<<((u>>j)&1)<<" ";
		//cout<<endl;
		//cout<<u<<endl;
		bool yes=false;
		if (u1==goal){code+=1;yes=1;}
		if (u2==goal){code+=10;yes=1;}
		if (u3==goal){code+=100;yes=1;}
		if(yes) break;
		for(int i=0;i<8;++i){
			LL v1=mv(i,u1);
			LL v2=mv(i,u2);
			LL v3=mv(i,u3);
			if(!vis1.count(v1)){
				rec1[cnt1]=i;
				father1[cnt1++]=front;
				q1.push(v1);
				vis1.insert(v1);
			}
			if(!vis2.count(v2)){
				rec2[cnt2]=i;
				father2[cnt2++]=front;
				q2.push(v2);
				vis2.insert(v2);
			}
			if(!vis3.count(v3)){
				rec3[cnt3]=i;
				father3[cnt3++]=front;
				q3.push(v3);
				vis3.insert(v3);
			}
		}
		front++;
		if(front>740000) break;
	}
	//cout<<front<<"!"<<endl;
	stack<int> an1,an2,an3;
	status ans1,ans2,ans3;
	ans1.id=1;ans2.id=2;ans3.id=3;
	for(int i=front;rec1[i]!=-1;i=father1[i]) an1.push(rec1[i]);
	while(!an1.empty()){
		int i=an1.top();an1.pop();
		ans1.s.push_back('A'+i);
	}
	for(int i=front;rec2[i]!=-1;i=father2[i]) an2.push(rec2[i]);
	while(!an2.empty()){
		int i=an2.top();an2.pop();
		ans2.s.push_back('A'+i);
	}
	for(int i=front;rec3[i]!=-1;i=father3[i]) an3.push(rec3[i]);
	while(!an3.empty()){
		int i=an3.top();an3.pop();
		ans3.s.push_back('A'+i);
	}
	status ans;
	switch(code){
		case 1:ans=ans1;break;
		case 10:ans=ans2;break;
		case 100:ans=ans3;break;
		case 11:ans=min(ans1,ans2);break;
		case 101:ans=min(ans1,ans3);break;
		case 110:ans=min(ans2,ans3);break;
		case 111:ans=min(min(ans1,ans2),ans3);break;
	}
	return ans;
}

//const int op[]={2,4,4,5,6,4,2,5};

int main()
{
	//freopen("input","r",stdin);
	//freopen("1","w",stdout);
	int	t,cnt=0;
	while(scanf("%d",&t)==1 && t){
		if(t==1) a[cnt++]=1;
		if(t==2) b[cnt++]=1;
		if(t==3) c[cnt++]=1;
		if(cnt>=24){
			cnt=0;
			/*int m=id(a);
			cout<<endl;
			for(int i=0;i<8;++i){
				m=mv(op[i],m);
				cout<<m<<endl;
				if(m==goal) puts("get");
				for(int j=0;j<24;++j) cout<<((m>>j)&1)<<" ";
				cout<<endl;
			}
			continue;*/
			if(id(a)==goal){
				cout<<"No moves needed"<<endl;
				cout<<1<<endl;
				continue;
			}
			if(id(b)==goal){
				cout<<"No moves needed"<<endl;
				cout<<2<<endl;
				continue;
			}
			if(id(c)==goal){
				cout<<"No moves needed"<<endl;
				cout<<3<<endl;
				continue;
			}
			status s=bfs(id(a),id(b),id(c));
			cout<<s.s<<endl;
			cout<<s.id<<endl;
			init();
		}
	}
	return 0;
}

