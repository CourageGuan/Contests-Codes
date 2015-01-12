/*清爽的头文件...就是递归建树，看看样例(代码末)也是醉了*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
const int maxn=1234;

char tree[maxn][maxn];
int n;

void init()
{
	memset(tree,'\0',sizeof(tree));
}

void draw(int line,int pos)
{
	if(line==n) return;
	if (line==0){
		F(i,0,strlen(tree[line])-1){
			char ch=tree[line][i];
			if(ch!=' '){
				printf("%c(",ch);
				pos=i;
				break;
			}
		}
	}
	line++;
	if(tree[line][pos]!='|'){
		printf(")");
		return;
	}
	line++;
	int i=pos;
	while(tree[line][i]=='-') i--;
	while(tree[line][++i]=='-'){
		char ch=tree[line+1][i];
		if(ch!=' ' && ch!='\0'){
			printf("%c(",ch);
			draw(line+1,i);
		}
	}
	printf(")");
}

int main()
{
	int kase;
	//freopen("test","r",stdin);
	//freopen("1","w",stdout);
	cin>>kase;
	getchar();
	while(kase--){
		init();
		int i=0;
		while(scanf("%[^\n]%*c",tree[i])==1){
			//cout<<tree[i]<<endl;
			if(tree[i][0]=='#') break;
			i++;
		}
		n=i;
		cout<<"(";
		draw(0,0);
		cout<<")"<<endl;
	}
	return 0;
}

/*
2
    A
    |
--------
B  C   D
   |   |
 ----- -
 E   F G
#
e
|
----
f g
#


(A(B()C(E()F())D(G())))
(e(f()g()))
*/


