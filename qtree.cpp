#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define LOGN 17
#define inf 1000000007

typedef struct node
{
	int leftEnd;
	int rightEnd;
	int ans;
	node* leftChild;
	node* rightChild;
}node;

vector< vector<int> > adj(N), w(N), edgeNo(N);
int parent[N], subtreeSize[N], edgeChild[N];
bool visited[N];

//------------------------------------------------ HLD ------------------------------------------------//
int totalChains = 1, chainSize[N], chainHead[N], chainNo[N], chainPosition[N];
node *root[N];

void HLD(int i){ //initialize first vertex with chainNo[i] = chainPosition[i] = 1, chainHead[1] = i;
	chainSize[chainNo[i]]++;
	int heavyChild = 0;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(parent[k] == i && subtreeSize[k] > subtreeSize[heavyChild])
			heavyChild = k;
	}

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(parent[k] == i){
			if(k == heavyChild){
				chainNo[k] = chainNo[i];
				chainPosition[k] = chainPosition[i] + 1;
			}
			else{
				chainNo[k] = ++totalChains;
				chainPosition[k] = 1;
				chainHead[totalChains] = k;
			}
			HLD(k);
		}
	}
}

node* CreateNode(int leftEnd, int rightEnd, int ans){
	node *temp = new node;
	
	temp->leftEnd = leftEnd;
	temp->rightEnd = rightEnd;
	temp->ans = ans;

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

void UpdateNode(node *currentNode, int i, int x){
	if(i < currentNode->leftEnd || currentNode->rightEnd < i){
		return;
	}
	else{
		if(i == currentNode->leftEnd && i == currentNode->rightEnd)
			currentNode->ans = x;
		else{
			UpdateNode(currentNode->leftChild, i, x);
			UpdateNode(currentNode->rightChild, i, x);
			currentNode->ans = max(currentNode->leftChild->ans, currentNode->rightChild->ans);
		}
	}
}

int QueryNode(node *currentNode, int l, int r){
	if(r < currentNode->leftEnd || currentNode->rightEnd < l){
		return -inf;
	}
	else{
		l = max(l, currentNode->leftEnd);
		r = min(r, currentNode->rightEnd);

		if(l == currentNode->leftEnd && r == currentNode->rightEnd)
			return currentNode->ans;
		else
			return max(QueryNode(currentNode->leftChild, l, r), QueryNode(currentNode->rightChild, l, r));
	}
}

void BuildSegmentTrees(int n){
	for(int chain = 1; chain <= totalChains; chain++)
		root[chain] = BuildSegmentTree(1, chainSize[chain]);

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < adj[i].size(); j++){
			int k = adj[i][j];

			if(parent[k] == i)
				UpdateNode(root[chainNo[k]], chainPosition[k], w[i][j]);
		}
	}
}
//----------------------------------------------- HLD Ends -----------------------------------------------//

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

int LCA(int x, int y){
	x = indx[x], y = indx[y];

	if(x > y) swap(x,y);
	
	int k = lg[y - x + 1];
	k = min(T[k][x], T[k][y - (1 << k) + 1]);
	return t_time[k];
}
//----------------------------------- LCA Ends -----------------------------------//

void DFS(int i){
	visited[i] = 1;
	
	start[i] = timer;
	t_time[timer++] = i;
	indx[i] = ind;
	T[0][ind++] = start[i];

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 0){
			parent[k] = i;
			edgeChild[edgeNo[i][j]] = k;
			DFS(k);
			subtreeSize[i] += subtreeSize[k];
			T[0][ind++] = start[i];
		}
	}

	subtreeSize[i]++;
}

void Update(int i, int k){
	i = edgeChild[i];

	UpdateNode(root[chainNo[i]], chainPosition[i], k);
}

int Query(int v, int u){
	int ans = -inf;

	while(chainNo[v] != chainNo[u]){
		ans = max(ans, QueryNode(root[chainNo[v]], 1, chainPosition[v]));
		v = parent[chainHead[chainNo[v]]];
	}

	if(u != v)
		ans = max(ans, QueryNode(root[chainNo[u]], chainPosition[u] + 1, chainPosition[v]));

	return ans;
}

int main(){
	int t, n, m, i, j, k, ans, x;
	char s[10];

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		totalChains = ind = timer = 1;

		for(i = 1; i <= n; i++){
			visited[i] = 0;
			subtreeSize[i] = 0;
			adj[i].clear();
			w[i].clear();
			edgeNo[i].clear();
			chainSize[i] = 1;
		}

		m = n - 1;

		for(x = 1; x < n; x++){
			scanf("%d%d%d", &i, &j, &k);

			adj[i].PB(j);
			w[i].PB(k);
			edgeNo[i].PB(x);

			adj[j].PB(i);
			w[j].PB(k);
			edgeNo[j].PB(x);
		}

		DFS(1);
		// cout << "DFS done\n";
		BuildLCASparseTable(n);
		// cout << "LCASparseTable built\n"; 

		chainNo[1] = chainPosition[1] = 1;
		chainHead[1] = 1;
		HLD(1);
		// cout << "HLD done\n";
		BuildSegmentTrees(n);
		// cout << "Segment Trees built\n";

		while(1){
			scanf("%s", s);

			if(s[0] == 'D')
				break;

			if(s[0] == 'C'){
				scanf("%d%d", &i, &k);
				Update(i, k);
			}
			else{
				scanf("%d%d", &i, &j);
				
				k = LCA(i,j);
				ans = max(Query(i, k), Query(j, k));

				printf("%d\n", ans);
			}
		}
	}
}