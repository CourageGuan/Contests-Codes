#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include <algorithm>
using namespace std;


int main()
{
    //freopen("test","r",stdin);
    //freopen("1","w",stdout);
    string s;
    int a=0;
    while(getline(cin,s))
    {
        if(a++) cout<<endl;
        string ss=s;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        while(s.find("marshtomp")!=-1)
        {
            int pos=s.find("marshtomp");
            //cout<<pos<<endl;
            ss.replace(pos,9,"fjxmlhx");
            s.replace(pos,9,"fjxmlhx");
        }
        cout<<ss;
    }
    return 0;
}
