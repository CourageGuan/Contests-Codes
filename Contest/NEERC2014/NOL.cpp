#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;

map<string,int> Q;
void init()
{
    Q["Alice"] = 0;
    Q["Ariel"] = 0;
    Q["Aurora"] = 0;
    Q["Phil"] = 0;
    Q["Pctcr"] = 0;
    Q["Olaf"] = 0;
    Q["Phocbus"] = 0;
    Q["Ralph"] = 0;
    Q["Robin"] = 0;

    Q["Bambi"] = 1;
    Q["Belle"] = 1;
    Q["Bolt"] = 1;
    Q["Mulan"] = 1;
    Q["Mowgli"] = 1;
    Q["Mickey"] = 1;
    Q["Silver"] = 1;
    Q["Simba"] = 1;
    Q["Stitch"] = 1;

    Q["Dumbo"] = 2;
    Q["Genie"] = 2;
    Q["Jiminy"] = 2;
    Q["Kuzko"] = 2;
    Q["Kida"] = 2;
    Q["Kenai"] = 2;
    Q["Tarzan"] = 2;
    Q["Tiana"] = 2;
    Q["Winnic"] = 2;
}

int main()
{
 //   freopen("./test.txt","r",stdin);
    init();
    int n;
    cin >> n;
    string t;
    int res = 0,cur = 0;
    for(int i = 0;i < n;++i)
    {
        cin >> t;
        res += abs(cur-Q[t]);
        cur = Q[t];
    }
    cout << res << endl;
    return 0;
}

































