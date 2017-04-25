#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

int dcmp(double x)
{
    if(fabs(x) < eps) return 0;
    else return x > 0 ? 1 : -1;
}

const int maxn = 200;

typedef double Matrix[maxn][maxn];

int sz;
void matrix_mul(Matrix A,Matrix B,Matrix res)
{
    Matrix C;
    memset(C,0,sizeof(C));
    for(int i = 0;i < sz;++i)
        for(int j = 0;j < sz;++j)
            for(int k = 0;k < sz;++k)
                C[i][j] += A[i][k]*B[k][j];
    memcpy(res,C,sizeof(C));
}


void matrix_pow(Matrix A,int n,Matrix res)
{
    Matrix r;
    memset(r,0,sizeof(r));
    for(int i = 0;i < sz;++i) r[i][i] = 1;
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


string savename[maxn];
map<string,int> ID;
int idx;
int getID(string name)
{
    if(ID.count(name))
        return ID[name];
    idx++;
    savename[idx] = name;
    return ID[name] = idx;
}


int cntu;
int cntp = 8;
struct Node
{
    double tm;
    int uid;
    int pid;
    Node(double tm = 0,int uid = 0,int pid = 0):
        tm(tm),uid(uid),pid(pid) {}

};

vector<Node> savenode;


double p[maxn];
int cntpass[10];
int userpassmask[maxn][10];



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
    for(int i = 1;i <= cntp;++i)
    {
        go[0][i] = cntpass[i];
        go[i][0] = rfac(cntpass[i]);
    }
    for(int i = 1;i <= cntu;++i)
    {
        for(int j = 1;j <= cntp;++j)
            if(userpassmask[i][j])
            {
                go[j][i+cntp] += (double)1/cntpass[j];
                go[i+cntp][j] += 1;
            }
    }

    double sumout[maxn];
    memset(sumout,0,sizeof(sumout));

    for(int i = 0;i < sz;++i)
        for(int j = 0;j < sz;++j)
        {
            sumout[i] += go[i][j];
        }

    Matrix exp;
    memset(exp,0,sizeof(exp));
    for(int from = 0;from < sz;++from)
        if(dcmp(sumout[from]) != 0)
        {
            for(int to = 0; to < sz;++to)
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

    for(int i = 1;i <= cntu;++i)
        p[i] = A[i+cntp][0];

}


void test()
{
    cntpass[1] = 2;
    cntpass[2] = 1;
    cntpass[3] = 1;
    userpassmask[1][1] = 1;
    userpassmask[2][1] = 1;
    userpassmask[2][2] = 1;
    userpassmask[3][3] = 1;
    cal();
    for(int i = 1;i <= cntu;++i)
        printf("%lf\n",p[i]*4);
}

double res[maxn];
bool cmp(int a,int b)
{
    return res[a] > res[b];
}


int main()
{
    //freopen("./test.txt","r",stdin);
    freopen("./rules_input.txt","r",stdin);
    freopen("./ans.txt","w",stdout);
    idx = 0;
    memset(cntpass,0,sizeof(cntpass));
    memset(userpassmask,0,sizeof(userpassmask));
    {
        double tm;
        string namebuf;
        int pid;
        while(scanf("%lf",&tm) == 1)
        {
            cin >> namebuf >> pid;
            int uid = getID(namebuf);
            pid++;
            savenode.push_back(Node(tm,uid,pid));
        }
    }

    cntu = idx;
    sz = 1 + cntu + cntp;
//
//    test();
//    return 0;


    double prv = 0;
    int sumpass = 0;
    cal();
    int sz = savenode.size();



    for(int k = 0;k <= sz;++k)
    {
        fprintf(stderr,"%d\n",k);
        double now = (k < sz)?savenode[k].tm:22*3600;
        for(int i = 1;i <= cntu;++i)
            res[i] += (now-prv)*p[i]*sumpass;

        if(k < sz)
        {
            int nowuid = savenode[k].uid;
            int nowpid = savenode[k].pid;

            if(!userpassmask[nowuid][nowpid])
            {
                userpassmask[nowuid][nowpid] = 1;
                sumpass++;
                cntpass[nowpid]++;
            }
            cal();
        }

        prv = now;
    }
    int seq[maxn];
    for(int i = 1;i <= cntu;++i)
        seq[i] = i;
    sort(seq+1,seq+1+cntu,cmp);

    double tsum = 0;
    for(int i = 1;i <= 32;++i)
        tsum += res[seq[i]];

    double avg = tsum / 32;
    double s = 0;

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

    double money[maxn];
    double tot = 88888;

    for(int i = 1;i <= 32;++i)
        money[seq[i]] = et[seq[i]]/esum * tot;

    for(int i = cntu;i > 32;--i)
        money[seq[i]] = 0;

    for(int i = 1;i <= min(128,cntu);++i)
    {
        int id = seq[i];
        printf("%d ",i);
        cout << savename[id];
        printf(" %.5f %.5f\n",res[id],money[id]);
    }
    return 0;
}
