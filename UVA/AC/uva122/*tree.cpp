#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct Node{
	bool have_value;
	int v;
	Node *left,*right;
	Node():have_value(false),left(NULL),right(NULL) {};
};

const int maxn=12345;
Node* root;
bool failed;
char s[maxn];

Node* newnode(){return new Node;}

void clear_tree(Node* p)
{
	if(p==NULL) return;
	clear_tree(p->left);
	clear_tree(p->right);
	delete p;
}

void addnode(int v,char* s)
{
	int n=strlen(s);
	node *p=root;
	for(int i=0;i<n;++i){
		char ch=s[i];
		if(ch=='l'){
			if(p->left==null) p->left=newnode();	
			p=p->left;
		}
		if(ch=='r'){
			if(p->right==null) p->right=newnode();	
			p=p->right;
		}
	}
	if(p->have_value) failed=true;
	p->v=v;
	p->have_value=true;	
}

bool read_input()
{
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
	queue<node*> q;
	ans.clear();
	q.push(root);
	while(!q.empty()){
		node* p=q.front();	
		q.pop();
		if(!p->have_value) return false;
		ans.push_back(p->v);
		if(p->left)
			q.push(p->left);
		if(p->right)
			q.push(p->right);
	}
	return true;
}



int main()
{
	//freopen("test","r",stdin);
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
			


