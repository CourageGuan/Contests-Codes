/*输出太恶心,精度四舍五入存在问题,排序存在问题*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2014年12月29日 星期一 15时34分38秒
 & File Name: uva207.cpp
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sstream>

#include <algorithm>
#include <list>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <string>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef map<string,int> MSI;
typedef map<int,int> MII;
typedef pair<int,int> PII;

#define F(i,a,b) for(int i=a;i<=b;i++)
#define Fd(i,a,b) for(int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define SET(a,t) memset(a,t,sizeof(a))
#define SETS(ST) while(!ST.empty()) ST.pop();
#define DEBUG puts("OK")
#define C(a) cout<<"~~"<<a<<"~~"<<endl
#define PM(a,x,y) F(i,0,x){F(j,0,y) cout<<a[i][j]<<" ";cout<<endl;}

#define FRER freopen("test","r",stdin)
#define FREW freopen("1","w",stdout)

const int inf = 0x7fffffff;
const int _inf= 0x8fffffff;
const LL  INF = 1e18;
const double EPS = 1e-8;
const double pi = acos(-1.0);

double ROUNDF(double x,int n){
	double t1,t2=modf(x,&t1);
	double t3=pow(10,n);
	long t4=long(t2*t3+0.5);
	x=t1+t4/t3;
	return x;
}

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

/*-----  on ne voit bien qu avec le coeur.l essentiel est invisible pour les yeux  -----*/

/*吐血模拟,希望写完还健在~~~~(>_<)~~~~ */

class player{
public:
   	string name;
	bool is_profel,is_won,is_tied,is_foul;		//专业选手？  获得奖金？  并列？  foul?
	int RD[5],total,sum2,rd,place;
	double won;

	bool operator< (const player& p)const {		//重载<，用于比较前两轮。
		return this->sum2 < p.sum2;
	}

	player(){		//init
		is_won=is_profel=true;
		rd=total=sum2=0;
		SET(RD,-1);
		won=0.0;
		is_foul=is_tied=false;
	}

	void get(){			//read data
		string s;
		getline(cin,s);
		name=s.substr(0,21);
		if(name.find('*')<21) is_won=is_profel=false;
		string s1=s.substr(21),s2;
		stringstream inp(s1);
		rd=0;
		while(inp>>s2){
			if(s2[0]!='D'){
				RD[++rd]=atoi(s2.c_str());
				total+=RD[rd];
			}
			else{
				if(++rd<3) {sum2=inf;total=-1;}		//foul => total=-1
				else total=-1;
				is_foul=true;
				is_won=false;
				break;
			}
		}
		sum2=(sum2==inf)?inf:RD[1]+RD[2];			//case the rounds
		Fd(i,4,1) if(RD[i]!=-1){rd=i;break;}
		//cout<<RD[1]<<" "<<RD[2]<<" "<<RD[3]<<" "<<RD[4]<<endl;
	}

	void put(){		//得分  上一个人得分  下一个人得分  名次
		//printf("%-21s%-10s%-5d%-5d%-5d%-5d%-10d$%10.2f\n",);
		cout<<name;
		if(!is_foul)
			if(is_tied){
				if(place<10) printf("%dT        ",place);
				if(place>=10 && place<100) printf("%dT       ",place);
				if(place>=100) printf("%dT      ",place);
			}
			else
				printf("%-10d",place);
		else
			printf("          ");
		F(i,1,4)
			if(RD[i]!=-1) printf("%-5d",RD[i]);
			else printf("     ");
		if(is_foul) printf("DQ\n");
		else
			if(is_won){
				printf("%-10d",total);
				printf("$%9.2lf\n",won);
			}
			else printf("%d\n",total);
	}

};	//感觉这个class写的好烂...

class playersort{
public:
	bool operator()(const player& p1,const player& p2){		//重载仿函数，用于比较总得分
		int total1=p1.RD[1]+p1.RD[2]+p1.RD[3]+p1.RD[4],total2=p2.RD[1]+p2.RD[2]+p2.RD[3]+p2.RD[4];
		if(p1.rd!=p2.rd) return p1.rd>p2.rd;
		else if(total1!=total2) return total1<total2;
			else return p1.name<p2.name; 
	}
};

const int N=180;
double mon[N];
vector<player> pl;

void init()
{
	SET(mon,0.0);
	pl.clear();
}

void print()
{
	printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n");
	printf("-----------------------------------------------------------------------\n");
}

void read()
{
	double money;
	getchar();
	scanf("%lf",&money);
	F(i,1,70)
	{
		scanf("%lf",&mon[i]);
		mon[i]=(money*mon[i])/100.0;
	}
	int n;
	scanf("%d",&n);
	getchar();
    F(i,1,n)
	{
		player p;
		p.get();
		pl.push_back(p);
	}
}

void solve()
{
	int kase;
	scanf("%d",&kase);
	while(kase--){
		init();
		read();
		print();
		sort(pl.begin(),pl.end());
		int l=pl.size()-1;
		while (pl[l--].sum2==inf) pl.pop_back();
		if(pl.size()>=70){
			int j=69;
			while(pl[j].total==pl[j+1].total) j++;
			pl.resize(j+1);
			sort(pl.begin(),pl.end(),playersort());
		}
		sort(pl.begin(),pl.end(),playersort());
		int i=1,j=0;
		while(i<70 && j<pl.size()){
			if(pl[j].is_profel){
				pl[j].won=mon[i];
				i++;
			}
			j++;
		}
		F(i,0,pl.size()-1) pl[i].place=i+1;		
		i=0;
		while(i<pl.size()){
			int j=i+1;
			int num=(pl[i].is_profel)?1:0;
			double money=pl[i].won;
			while(pl[j].total==pl[i].total){
				pl[j].place=pl[i].place;
				if(pl[j].is_profel){
					num++;
					money+=pl[j].won;
				}
				j++;
			}
			money=money/(double)num;
			F(k,i,j-1) {
				pl[k].won=money; 
			    if(num>=2 && pl[k].is_profel) pl[k].is_tied=true;
			}
			i=j;
		}		
		
		F(i,0,pl.size()-1) pl[i].put();		

		/*int t=1;
		  int i=0;
		  int p=1;
		  while(i<pl.size())
		  {
		  if(pl[i].is_foul){
		  pl[i++].put();
		  continue;
		  }

		  double sum=0.0;
		  int T=0,num=0;
		  if(t<=70){
		  int j=i+1;
		  while(pl[i].total==pl[j].total){
l
		  if(pl[j].is_foul) break;
		  if(pl[j].is_profel) T++;
		  sum+=mon[t++];
		  num++;
		  j++;
		  }
		  F(k,i,i+num){
		  pl[k].place=i+1;
		  pl[k].won=sum/num*1.0;
		  pl[k].is_won=true;
		  if(T>=2 && pl[k].is_profel) pl[k].is_tied=true;
		//pl[k].put();
		i+=num;
		}

		}else
		{
		pl[i].is_won=false;
		pl[i].place=i+1;
		pl[i].put();
		}
		i++;
		}*/
		printf("\n");
	}
}


int main()
{
	FRER;
	FREW;
	solve();
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

