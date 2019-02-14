#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define LOGN 17

typedef struct node
{
	int leftEnd;
	int rightEnd;
	int count;
	node* leftChild;
	node* rightChild;
}node;

vector< vector<int> > adj(N), c(N);
int parent[N];
bool visited[N];
queue<int> ans;

//------------------------------------- LCA -------------------------------------//
int start[N], t_time[N], indx[N], ind = 1, timer = 1, T[LOGN + 1][2*N], lg[2*N];

void BuildLCASparseTable(int n){
	int m, i, j, k;
	n = 2*n - 1;

	for(i = 2; i <= n; i++)
		lg[i] = 1 + lg[i/2];

	for(k = 1; (1 << k) <= n; k++)
		for(i = 1, j = 1 + (1 << (k - 1)), m = n - (1 << k) + 1; i <= m; i++, j++)
			T[k][i] = min(T[k - 1][i], T[k - 1][j]);
}

int Lca(int x, int y){
	x = indx[x], y = indx[y];

	if(x > y) swap(x,y);
	
	int k = lg[y - x + 1];
	k = min(T[k][x], T[k][y - (1 << k) + 1]);
	return t_time[k];
}
//----------------------------------- LCA Ends -----------------------------------//

//----------------------------------------- Persistent Segment Tree -----------------------------------------//
node *root[N];

node* CreateNode(int leftEnd, int rightEnd, int count){
	node *temp = new node;
	
	temp->leftEnd = leftEnd;
	temp->rightEnd = rightEnd;
	temp->count = count;

	return temp;
}

node* BuildSegmentTree(int leftEnd, int rightEnd){
	node *temp = CreateNode(leftEnd, rightEnd, 0);

	if(leftEnd != rightEnd){
		int mid = (leftEnd + rightEnd) / 2;
		temp->leftChild = BuildSegmentTree(leftEnd, mid);
		temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
	}
	else
		temp->leftChild = temp->rightChild = NULL;

	return temp;
}

void TraverseSegmentTree(node* root){
	if(root != NULL){
		TraverseSegmentTree(root->leftChild);
		TraverseSegmentTree(root->rightChild);
		printf("%d %d\n", root->leftEnd, root->rightEnd);
	}
}

node* Insert(node *parentNode, int i){
	node *newNode;

	if(parentNode->leftEnd <= i && i <= parentNode->rightEnd){
		newNode = CreateNode(parentNode->leftEnd, parentNode->rightEnd, parentNode->count);
		
		if(parentNode->leftEnd != parentNode->rightEnd){
			newNode->leftChild = Insert(parentNode->leftChild, i);
			newNode->rightChild = Insert(parentNode->rightChild, i);
		}
		else
			newNode->leftChild = newNode->rightChild = NULL;
	}
	else
		newNode = parentNode;

	return newNode;
}

void UpdateNode(node *currentNode, int i, int x){
	if(i < currentNode->leftEnd || currentNode->rightEnd < i){
		return;
	}
	else{
		if(i == currentNode->leftEnd && i == currentNode->rightEnd)
			currentNode->count += x;
		else{
			UpdateNode(currentNode->leftChild, i, x);
			UpdateNode(currentNode->rightChild, i, x);
			currentNode->count = (currentNode->leftChild)->count + (currentNode->rightChild)->count;
		}
	}
}

void Query(node *u, node *v, node *w, node *x, int k){
	int count = u->count + v->count - w->count - x->count;

	k = min(k, count);

	if(k != 0){
		if(u->leftEnd == u->rightEnd){
			while(k--)
				ans.push(u->leftEnd);
		}
		else{
			count = u->leftChild->count + v->leftChild->count - w->leftChild->count - x->leftChild->count;

			if(count >= k)
				Query(u->leftChild, v->leftChild, w->leftChild, x->leftChild, k);
			else{
				Query(u->leftChild, v->leftChild, w->leftChild, x->leftChild, count);
				Query(u->rightChild, v->rightChild, w->rightChild, x->rightChild, k - count);
			}
		}
	}
}
//-------------------------------------- Persistent Segment Tree Ends --------------------------------------//

void Dfs(int i){
	visited[i] = 1;
	
	start[i] = timer;
	t_time[timer++] = i;
	indx[i] = ind;
	T[0][ind++] = start[i];
	
	root[i] = root[parent[i]];
	for(int j = 0; j < c[i].size(); j++){
		int k = c[i][j];
		root[i] = Insert(root[i], k);
		UpdateNode(root[i], k, 1);
	}

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 0){
			parent[k] = i;
			Dfs(k);			
			T[0][ind++] = start[i];						
		}
	}
}

int main(){
	int n, m, q, i, j, k, u, v, w, x;

	scanf("%d%d%d", &n, &m, &q);

	for(x = 1; x < n; x++){
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
	}

	for(i = 1; i <= m; i++){
		scanf("%d", &j);
		c[j].PB(i);
	}

	root[0] = BuildSegmentTree(1, m);
	Dfs(1);

	BuildLCASparseTable(n);

	while(q--){
		scanf("%d%d%d", &u, &v, &k);

		w = Lca(u,v);
		x = parent[w];

		Query(root[u], root[v], root[w], root[x], k);

		printf("%d ", (int)ans.size());

		while(!ans.empty()){
			printf("%d ", ans.front());
			ans.pop();
		}

		printf("\n");
	}

	return 0;
}
