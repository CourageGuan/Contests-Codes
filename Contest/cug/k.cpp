#include<iostream>
using namespace std;
 
typedef unsigned long long ll;
ll n,m;
 
int main()
{
    while(cin>>n>>m){
        if(n==1){
            cout<<6%m<<endl;
            continue;
        }
        if(n==2){
            cout<<18%m<<endl;
            continue;
        }
        n-=1;
		n%=m;
		cout<<(2%m*((n*((n*n)%m+(3*n-1)%m)%m)%m+6)%m)%m<<endl;
    }
    return 0;
}
