#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1234;
bool failed=false;


struct Node{
	bool have_value;
	int v;
	Node *left,*right;
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
	p->left=p->right=NULL;
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
	clear_tree(p->left);
	clear_tree(p->right);
	delnode(p);
}

	
void addnode(int v,char* s)
{
	int n=strlen(s);
	Node *p=root;

	for(int i=0;i<n;++i){
		char ch=s[i];
		if(ch=='L'){
			if(p->left==NULL) p->left=newnode();	
			p=p->left;
		}
		if(ch=='R'){
			if(p->right==NULL) p->right=newnode();	
			p=p->right;
		}
	}
	if(p->have_value) failed=true;
	p->v=v;
	p->have_value=true;	
}

bool read_input()
{
	char s[1234];
	failed=false;
	clear_tree(root);
	root=newnode();
	for(;;){
		if(scanf("%s",s)!=1) return false;
		if(!strcmp(s,"()")) break;
		int v;
		sscanf(&s[1],"%d",&v);
		addnode(v,strchr(s,',')+1);
	}
	return true;
}

bool bfs(vector<int> &ans)
{
	queue<Node*> que;
	ans.clear();
	que.push(root);
	while(!que.empty()){
		Node* p=que.front();	
		que.pop();
		if(!p->have_value) return false;
		ans.push_back(p->v);
		if(p->left)
			que.push(p->left);
		if(p->right)
			que.push(p->right);
	}
	return true;
}



int main()
{
	//freopen("test","r",stdin);
	init();
	while(read_input()){
		if(failed){
			printf("not complete\n");
			continue;
		}
		vector<int> ans;
		if (bfs(ans)){
			vector<int>::iterator it;
			for(it=ans.begin();it!=ans.end();++it){
				if(it!=ans.begin())	printf(" ");
				printf("%d",*it);
			}
			printf("\n");
		}
		else printf("not complete\n");
	}		
	return 0;
}

