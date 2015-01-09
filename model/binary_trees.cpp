#include<queue>
#include<cstdio>
using namespace std;

const int maxn=1<<20;
int pre_order[maxn],in_order[maxn],post_order[maxn];

struct Node{
	bool have_value;
	int v,dis;
	Node *lch,*rch;
} node[maxn],*root;

queue<Node*> freenodes;		//free list => memory pool

void init()
{
	for(int i=0;i<maxn;++i)
		freenodes.push(&node[i]);
}

Node *newnode()
{
	Node* p=freenodes.front();
	p->lch=p->rch=NULL;
	p->have_value=false;
	freenodes.pop();
	return p;
}

void delnode(Node* p)
{
	freenodes.push(p);
}

void clear_tree(Node* p)
{
	if(p==NULL) return;
	clear_tree(p->lch);
	clear_tree(p->rch);
	delnode(p);
}

void addnode(int v)
{
	Node *p=root;
	for(;;){
		if(1){
			if(p->lch==NULL) p->lch=newnode();
			p=p->lch;
		}
		else{
			if(p->rch==NULL) p->rch=newnode();
			p=p->rch;
		}
	}
	if(p->have_value) {}
	p->v=v;
	p->have_value=true;
}

void foreach(*Node p)
{
	if(p==NULL) return;
	printf("%d",p->v);
	foreache(p->lch);
	foreach(p->rch);
}

//by in_order[l1..r1] (0..n-1)  post_order[l2..r2] (0..n-1)
Node* create(int dis,int l1,int r1,int l2,int r2)	//n nodes
{
	if(l1>r1) return NULL;
	Node* p=newnode();
	p->v=post_order[r2];
	int cnt=l1;
	while(p->v!=in_order[cnt]) cnt++;
	int num=cnt-l1;			//left nodes
	p->dis=dis+p->v;
	p->lch=create(p->dis,l1,cnt-1,l2,l2+num-1);	//根节点左边[l1,cnt-1] [l2,l2+num-1]  (左子树部分)
	p->rch=create(p->dis,cnt+1,r1,l2+num,r2-1);	//根节点右边[cnt+1,r1] [l2,r2-1]      (右子树部分)
}


int main()
{
	return 0;
}





