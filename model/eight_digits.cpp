#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;


typedef int State[9];
const int maxn=1234567;
const int mv4[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
State st[maxn],goal;
int dis[maxn],father[maxn];

void init()
{
	memset(st,0,sizeof(st));
	memset(dis,0,sizeof(dis));
}

bool inside(int x,int y)
{
	return x>=0 && y>=0 && x<3 && y<3;
}

const int hashsize=1000003;
int head[hashsize],next[hashsize];	//hash list

void init_lookup_table() {memset(head,0,sizeof(head));}

int hash(State &s){		//hash faction
	int v=0;
	for(int i=0;i<9;++i) v=v*10+s[i];
	return v%hashsize;
}

bool try_to_insert(int s)
{
	int h=hash(st[s]);
	int u=head[h];
	while(u){
		if(memcmp(st[u],st[s],sizeof(st[s]))==0) return 0;
		u=next[u];
	}
	next[s]=head[h];	//insert head
	head[h]=s;
	return 1;
}

int bfs()
{
	//init();
	init_lookup_table();
	int front=1,rear=2;
	father[1]=0;
	while(front<rear){
		State &s=st[front];
		if(memcmp(goal,s,sizeof(s))==0) return front;	//find it
		int z;
		for(z=0;z<9;++z) if(!s[z]) break;	//0 's pos
		int x=z/3,y=z%3;	//row col
		for(int d=0;d<4;++d){
			int newx=x+mv4[d][0],newy=y+mv4[d][1];
			int newz=newx*3+newy;
			if(inside(newx,newy)){
				State &t=st[rear];
				memcpy(&t,&s,sizeof(s));
				t[newz]=s[z];	//exchange 0 whith num
				t[z]=s[newz];
				dis[rear]=dis[front]+1;
				father[rear]=front;
				if(try_to_insert(rear)) rear++;	//repeat judge
			}
		}
		front++;
	}
	return 0;
}

int main()
{
	//freopen("test","r",stdin);
	for(int i=0;i<9;++i){
		scanf("%d",&st[1][i]);
		//cout<<st[1][i]<<" ";
	}
	//cout<<endl;
	for(int i=0;i<9;++i){
		scanf("%d",&goal[i]);
		//cout<<goal[i]<<" ";
	}
	//cout<<endl;
	//cout<<memcmp(goal,st[1],sizeof(st[1]))<<endl;
	int ans=bfs();
	dis[0]=-1;
	for(int i=ans;i;i=father[i]){	//reverse print
		for(int j=0;j<9;++j)
			printf("%d ",st[i][j]);
		printf("\n");
	}
	printf("%d\n",dis[ans]);
	return 0;
}




