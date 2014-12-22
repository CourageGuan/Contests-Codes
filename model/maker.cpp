#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>

using namespace std;

void print()
{
	int r=rand()%rand;
	string s;
	switch(r)
	{
	}

}

int main()
{
	srand (time(0));
	freopen("test","w",stdout);
	int t;
	cin>>t;
	cout<<t<<endl;
	while(t--){
		int n;
		cin>>n;
		cout<<n<<endl;
		while(n--) print();
	}
	return 0;
}
