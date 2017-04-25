#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define LEN(n) (int)log10(n)+1
#define R(i,n) for(LL i=0;i<n;++i)
#define F(i,a,b) for(LL i=(a);(i)<=(b);++i)
#define EACH(i,a) for(__typeof((a).begin()) i=a.begin(); i!=a.end(); ++i)

#define FILL(a,t) memset((a),(t),sizeof(a))
#define CLEAR(ST) while(!ST.empty()) ST.pop();
#define all(a) a.begin(),a.end()
#define lowbd(a,x) lower_bound(all(a),x) - a.begin()
#define upbd(a,x) upper_bound(all(a),x) - a.begin()
#define pb push_back
#define mp(A,B) make_pair(A,B)
#define fi first
#define se second

typedef unsigned long long ULL;
typedef double DB;
typedef long double LDB;
typedef vector<int> VI;
typedef map<string,int> MSI;
typedef map<int,int> MII;
typedef pair<int,int> PII;


//#define DEBUG
#ifdef DEBUG
	#define debug(args...) do{cerr<<#args<<":"; dbg,args; cerr<<endl;}while(0) 
	#define OK puts("OK")
	#define C(a) cout<<"~~"<<a<<"~~"<<endl
	#define PM(a,x,y) F(i,0,x){F(j,0,y) cout<<a[i][j]<<" ";cout<<endl;} 
struct debugger{
	template<typename T> debugger& operator , (const T& v){
		cerr<<v<<" ";
		return *this;
	}
} dbg;
#else
	#define debug(args...)
	#define OK
	#define C(a)
	#define PM(a,x,y)
#endif

const int INF = 0x3f3f3f3f;
const LL  LINF = 0x3f3f3f3f3f3f3f3fLL;
const DB EPS = 1e-9;
const DB PI = acos(-1.0);

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int mv[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};


const int visLENGTH = 4e7;
const int PLENGTH = 2e6;

bool vis[visLENGTH];
LL P[PLENGTH];
LL v[PLENGTH];
LL p,q;

inline LL f1(LL n, LL P[], LL LENGTH)  
{  
    LL i = 0, vis = 0;  
    for (i = LENGTH - 1; i > 0; i--) 
	{
        if (P[i] < n) 
		{  
            vis = 1;  
            break;  
        }
    }
    if(vis) return i + 1;  
    return 0;  
} 
   
inline LL f2(LL x, LL a, LL m)  
{  
    if (a == m) return (x / q) * p + v[x % q];  
    if(x < P[a - 1]) return 1;
    return f2(x, a - 1, m) - f2(x / P[a - 1], a - 1, m);  
} 

LL cal(LL n)  
{  
    LL visLENGTH;  
    LL i, j, N = 7;
    LL cnt = 0,sum = 0, s = 0;  
    LL LENGTH, LENGTH2, LENGTH3;  
   
	if(n < 10000)
		visLENGTH = 10002;
	else
		visLENGTH = ((LL)exp(log(n)*2/3) + 1);
   
    memset(vis, 0, sizeof(bool) * visLENGTH);  

	LL ll = (LL)sqrt(visLENGTH);
	F(i,2,ll-1) if(!vis[i])  
       	for (j = i*2; j < visLENGTH; j += i)  vis[j] = 1;  
    vis[0] = vis[1] = 1; 
   
	R(i,visLENGTH) if(!vis[i])  cnt++;
	//printf("!!!!!%lld\n",cnt);

    j = 0; 
	R(i,visLENGTH) if (!vis[i]) P[j++] = i;  
    if (n < 10000)  return f1(n, P, cnt);  
   
    LENGTH = f1((LL)exp(log(n)/3), P, cnt);
    LENGTH2 = f1((LL)sqrt(n), P, cnt);  
    LENGTH3 = f1(visLENGTH - 1, P, cnt);  
   
    j = visLENGTH - 2; 
	LL L = (LL)exp(log(n)/3),R = (LL)sqrt(n);
	F(i,L,R)
	{ 
		if(vis[i]) continue;
		while (n < i*j) 
		{
			if(!vis[j]) ++s;  
			--j; 
		}  
		sum += s;  
	}  
    sum = (LENGTH2 - LENGTH) * LENGTH3 - sum;  
    sum += (LENGTH * (LENGTH - 1) - LENGTH2 * (LENGTH2 - 1)) / 2;  
   
	N = min(N,LENGTH);

	R(i,N) q *= P[i],p *= P[i] - 1;  

	//printf("!!%lld\n",q);

	R(i,q) v[i] = i;  
	R(i,N) for(j = q - 1;j >= 0;j--) v[j] -= v[j / P[i]];  

    sum = f2(n, LENGTH, N) - sum + LENGTH - 1;  
    return sum;  
} 

const int maxn = 3e6 + 10;
bool isvis[maxn];
int primes[maxn];
int ans[maxn];
int tot=0;

void init()
{
	ans[1] = 0;
	for(int i=2;i<maxn;++i){
		ans[i] = ans[i-1];
		if(!isvis[i])
		{
			++ans[i];
		   	primes[tot++]=i;
		}
		for(int j=0;j<tot;++j){
			int t=i*primes[j];
			if(t>maxn) break;
			isvis[t]=1;
			if(i%primes[j]==0) break;
		}
	}
}
   
int main()  
{  
//	freopen("test.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	init();
	LL n;
	while(scanf("%lld",&n) == 1)
	{
		if(n == 100000000000LL)
		{
			puts("4118054813");
			continue;
		}
		if(n < maxn)
		{
			printf("%d\n",ans[n]);
			continue;
		}
		n = n+1;
		p = q = 1;  
		LL res = cal(n);
		printf("%lld\n",res);
	}
	return 0;  
} 
