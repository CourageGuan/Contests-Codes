#include<cstdio>
#include<cstring>
#define N 100010
typedef long long ll;
int n,i,x,y,z,g[N],nxt[N<<1],v[N<<1],w[N<<1],ok[N<<1],ed=1,son[N],f[N],size,now,fa[N];
int q[N],anc[N],t,ta,p;
ll ans[N],d[N];
inline void add(int x,int y,int z){v[++ed]=y,w[ed]=z,nxt[ed]=g[x],ok[ed]=1,g[x]=ed;}
inline void up(ll&x,ll y){if(x>y)x=y;}
inline double pos(int x,int y){return (double)(ans[y]-ans[x]+d[y]*d[y]-d[x]*d[x])/(double)(d[y]-d[x]);}
void findroot(int x,int pre){
  son[x]=1;f[x]=0;
  for(int i=g[x];i;i=nxt[i])if(ok[i]&&v[i]!=pre){
    findroot(v[i],x),son[x]+=son[v[i]];
    if(son[v[i]]>f[x])f[x]=son[v[i]];
  }
  if(size-son[x]>f[x])f[x]=size-son[x];
  if(f[x]<f[now])now=x;
}
inline void deal(int x){
	int l=1,r=t-1,fin=t,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if((double)2*d[x]<=pos(q[mid],q[mid+1]))r=(fin=mid)-1;else l=mid+1;
	}
	up(ans[x],ans[q[fin]]+(d[x]-d[q[fin]])*(d[x]-d[q[fin]])+p);
	//printf("%d %lld\n",x,ans[x]);
}
void dfs(int x){
	for(int i=g[x];i;i=nxt[i])if(v[i]!=fa[x]) d[v[i]]=d[fa[v[i]]=x]+w[i],dfs(v[i]);
}
void cal(int x,int pre){
  deal(x);
  for(int i=g[x];i;i=nxt[i])if(ok[i]&&v[i]!=pre)cal(v[i],x);
}
void cal2(int x,int y){
  up(ans[x],ans[y]+(d[x]-d[y])*(d[x]-d[y])+p);
  for(int i=g[x];i;i=nxt[i])if(ok[i]&&v[i]!=fa[x])cal2(v[i],y);
}
void solve(int x){
	f[0]=size=son[x],findroot(x,now=0);
	int rt=now,i;
	//printf("..%d %d\n",x,rt);
	if(rt!=x){
		for(i=g[rt];i;i=nxt[i])if(v[i]==fa[rt]){ok[i]=ok[i^1]=0,solve(x);break;}
		for(ta=0,i=fa[rt];;i=fa[i]){
			anc[++ta]=i;
			if(i==x)break;
		}
		for(t=0;ta;q[++t]=anc[ta--])while(t>1&&pos(anc[ta],q[t])<pos(q[t],q[t-1]))t--;
		if(rt>1)deal(rt);
		while(t>1&&pos(rt,q[t])<pos(q[t],q[t-1]))t--;
		q[++t]=rt;
		for(i=g[rt];i;i=nxt[i])if(ok[i])cal(v[i],rt);
		for(i=g[rt];i;i=nxt[i])if(ok[i])ok[i^1]=0,solve(v[i]);
	}else for(i=g[x];i;i=nxt[i])if(ok[i])ok[i^1]=0,cal2(v[i],x),solve(v[i]);
}

const int BUF=40000000;
char Buf[BUF],*buf=Buf;
inline void read(int&a){for(a=0;*buf<48;buf++);while(*buf>47)a=a*10+*buf++-48;}


int main(){
	//freopen("input.txt","r",stdin);
	fread(buf,1,BUF,stdin);
	int T;
	read(T);
	for(int kase=1;kase<=T;++kase)
	{
		read(n); read(p);
		if(n == 1)
		{
			puts("0");
			continue;
		}
		memset(g,0,sizeof g);
		ans[1] = 0;
		d[1] = 0;
		ed = 1;
		for(i=1;i<n;i++)read(x),read(y),read(z),add(x,y,z),add(y,x,z);
		for(i=2;i<=n;i++) ans[i]=1LL<<60;
		son[1]=n;
		dfs(1);
		solve(1);
		ll res = 0;
		for(i=2;i<=n;i++)
		{
			//printf("..%lld\n",ans[i]);
		   	if(res < ans[i]) res = ans[i];
		}
		printf("%lld\n",res-p);
	}
	return 0;
}
