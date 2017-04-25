#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const int maxn = 233;
typedef double Matrix[maxn][maxn];
int seq[maxn];
double money[maxn],all_money = 88888;
string name[maxn];
unordered_map<string,int> ID;
int n,pn=8,idx;
double p[maxn],res[maxn];
int passed[10],passedmsk[maxn][10];

struct Node
{
    double tm;
    int uid;
    int pid;
    Node(double tm = 0,int uid = 0,int pid = 0):
        tm(tm),uid(uid),pid(pid) {}
};
vector<Node> nodes;

bool cmp(const int& i,const int& j)
{
    return res[i] > res[j];
}

int dcmp(double x)
{
    if(fabs(x) < eps) return 0;
    else return x > 0 ? 1 : -1;
}

int getID(string name_t)
{
    if(ID.count(name_t)) return ID[name_t];
    idx++;
    name[idx] = name_t;
    return ID[name_t] = idx;
}

int N;
void matrix_mul(Matrix A,Matrix B,Matrix res)
{
    Matrix C;
    memset(C,0,sizeof(C));
    for(int i = 0;i < N;++i)
        for(int j = 0;j < N;++j)
            for(int k = 0;k < N;++k)
                C[i][j] += A[i][k]*B[k][j];
    memcpy(res,C,sizeof(C));
}

void matrix_pow(Matrix A,int n,Matrix res)
{
    Matrix r;
    memset(r,0,sizeof(r));
    for(int i = 0;i < N;++i) r[i][i] = 1;
    Matrix a;
    memcpy(a,A,sizeof(a));

    while(n)
    {
        if(n&1) matrix_mul(r,a,r);
        n >>= 1;
        matrix_mul(a,a,a);
    }
    memcpy(res,r,sizeof(r));
}

double rfac(int num)
{
    double res = 0;

    for(int i = 1;i <= num;++i)
        res += (double)1/i;
    return res;
}

void cal()
{
    int sum = 0;
    double go[maxn][maxn];
    memset(go,0,sizeof(go));
    go[0][0] = 1;
    for(int i = 1;i <= pn;++i)
    {
        go[0][i] = passed[i];
        go[i][0] = rfac(passed[i]);
    }
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= pn;++j)
            if(passedmsk[i][j])
            {
                go[j][i+pn] += (double)1/passed[j];
                go[i+pn][j] += 1;
            }
    }

    double sumout[maxn];
    memset(sumout,0,sizeof(sumout));

    for(int i = 0;i < N;++i)
        for(int j = 0;j < N;++j)
        {
            sumout[i] += go[i][j];
        }

    Matrix exp;
    memset(exp,0,sizeof(exp));
    for(int from = 0;from < N;++from)
        if(dcmp(sumout[from]) != 0)
        {
            for(int to = 0; to < N;++to)
            {
                exp[to][from] =  go[from][to] / sumout[from];
            }
        }

    Matrix A;
    memset(A,0,sizeof(A));
    A[0][0] = 1.0;

    const int T = 10000;
    matrix_pow(exp,T,exp);
    matrix_mul(exp,A,A);

    for(int i = 1;i <= n;++i)
        p[i] = A[i+pn][0];
}

int main()
{
	freopen("./rules_input.txt","r",stdin);
	freopen("./ans.txt","w",stdout);
	idx = 0;
	memset(passed,0,sizeof(passed));
	memset(passedmsk,0,sizeof(passedmsk));

	double tm;
	string namebuf;
	int pid;
	while(scanf("%lf",&tm) == 1)
	{
		cin >> namebuf >> pid;
		int uid = getID(namebuf);
		pid++;
		nodes.push_back(Node(tm,uid,pid));
	}

	n = idx;
	N = 1 + n + pn;

	double prev = 0;
	int sumpass = 0;
	cal();
	int N = nodes.size();

	for(int k = 0;k <= N;++k)
	{
		double now = (k < N)?nodes[k].tm:22*3600;
		for(int i = 1;i <= n;++i)
			res[i] += (now-prev)*p[i]*sumpass;

		if(k < N)
		{
			int nowuid = nodes[k].uid;
			int nowpid = nodes[k].pid;

			if(!passedmsk[nowuid][nowpid])
			{
				passedmsk[nowuid][nowpid] = 1;
				sumpass++;
				passed[nowpid]++;
			}
			cal();
		}
		prev = now;
	}

	for(int i = 1;i <= n;++i) seq[i] = i;
	sort(seq+1,seq+1+n,cmp);

	double tsum = 0;
	for(int i = 1;i <= 32;++i)
		tsum += res[seq[i]];

	double avg = tsum / 32,s=0;
	for(int i = 1;i <= 32;++i)
		s += (avg-res[seq[i]])*(avg-res[seq[i]]);

	s = sqrt(s/32);
	double et[maxn];
	double esum = 0;

	for(int i = 1;i <= 32;++i)
	{
		et[seq[i]] = exp(res[seq[i]]/s);
		esum += et[seq[i]];
	}

	for(int i = 1;i <= 32;++i)
		money[seq[i]] = et[seq[i]]/esum * all_money;

	for(int i = n;i > 32;--i)
		money[seq[i]] = 0;

	for(int i = 1;i <= min(128,n);++i)
	{
		int id = seq[i];
		printf("%d ",i);
		cout << name[id];
		printf(" %.5lf %.5lf\n",res[id],money[id]);
	}
	return 0;
}



