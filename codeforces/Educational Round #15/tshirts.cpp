//http://codeforces.com/contest/702/submission/19506886
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

pii a[N];
int ans[N];

bool cmp(pii a, pii b){
	return (a.second == b.second) ? a.first > b.first : a.second < b.second;
}

typedef struct node{
	int value, priority;
	int lazyValue;
	int ans, lazyAns;
	int indx;
	node *left, *right;
}node;

unsigned int GenPriority(){
    unsigned int x = rand();
    unsigned int y = rand();
    return (x << 16) | y;
}

//--------------------- Treap ---------------------//
node* CreateNode(int value, int indx){
	node *temp = new node;

	temp->value = value;
	temp->priority = GenPriority();
	temp->lazyValue = 0;
	temp->ans = temp->lazyAns = 0;
	temp->left = nullptr;
	temp->right = nullptr;
	temp->indx = indx;

	return temp;
}

node* ReAssign(node *n, node *l, node *r){
	n->left = l;
	n->right = r;
	return n;
}

void Apply(node *n, int lazyValue, int lazyAns){
	n->value += lazyValue;
	n->lazyValue += lazyValue;
	n->ans += lazyAns;
	n->lazyAns += lazyAns;
}

void Down(node *n){
	if(n->left)
		Apply(n->left, n->lazyValue, n->lazyAns);
	
	if(n->right)
		Apply(n->right, n->lazyValue, n->lazyAns);
	
	n->lazyValue = 0;
	n->lazyAns = 0;
}

// {<, >=}
pair< node*, node* > Split(node *n, int k){
	if(!n)
		return MP(nullptr, nullptr);

	Down(n);

	node *l, *r;
	
	if(n->value < k){
		tie(l, r) = Split(n->right, k);
		ReAssign(n, n->left, l);
		return MP(n, r);
	}
	else{
		tie(l, r) = Split(n->left, k);
		ReAssign(n, r, n->right);
		return MP(l, n);
	}
}

// all l <= r
node* Merge(node *l, node *r){
	if(!l)
		return r;
	
	if(!r)
		return l;

	Down(l);
	Down(r);
	
	if(l->priority < r->priority)
		return ReAssign(l, l->left, Merge(l->right, r));
	else
		return ReAssign(r, Merge(l, r->left), r->right);
}

node* Insert(node *root, node *n){
	node *l, *r;
	tie(l, r) = Split(root, n->value);
	return Merge(l, Merge(n, r));
}

node* GetLeft(node *n){
	while(n->left){
		Down(n);
		n = n->left;
	}
	
	return n;
}

node* GetRight(node *n){
	while(n->right){
		Down(n);
		n = n->right;
	}

	return n;
}

node* Update(node *root, int c){
	node *l, *r;

	tie(l, r) = Split(root, c);

	if(r)
		Apply(r, -c, 1);

	while(l && r){
		node *lMax, *rMin;

		lMax = GetRight(l);
		rMin = GetLeft(r);

		if(rMin->value <= lMax->value){
			node *tl, *tr;

			tie(tl, tr) = Split(r, rMin->value + 1);
			l = Insert(l, tl);
			r = tr;
		}
		else
			break;
	}

	return Merge(l,r);
}

void Traverse(node *n){
	if(!n)
		return;
	
	Down(n);

	ans[n->indx] = n->ans;
	Traverse(n->left);
	Traverse(n->right);
}
//-------------------- Treap Ends--------------------//

int main(){
	int n, m, q, i, j, k, x, y, z, c, p;
	node *root = nullptr;

	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	scanf("%d", &q);

	for(i = 1; i <= q; i++){
		scanf("%d", &k);
		root = Insert(root, CreateNode(k,i));
	}

	sort(a + 1, a + n + 1, cmp);

	for(i = n; i > 0; i--)
		root = Update(root, a[i].first);
	
	Traverse(root);

	for(i = 1; i <= q; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}