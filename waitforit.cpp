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
	ll ans;
	ll lazyvalue;
	ll girlIndex;
	node* leftChild;
	node* rightChild;
}node;

vector< vector<int> > adj(N);
vector< vector<ll> > girls(N);
int parent[N], subtreeSize[N], nextGirl[N], junctionNo[N];
ll lazyValuesForSegmentTrees[N], inf = 1E18;
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

node* CreateNode(int leftEnd, int rightEnd){
	node *temp = new node;
	
	temp->leftEnd = leftEnd;
	temp->rightEnd = rightEnd;
	temp->ans = 0;
	temp->lazyvalue = 0;
	temp->girlIndex = 0;

	return temp;
}

node* BuildSegmentTree(int leftEnd, int rightEnd){
	node *temp = CreateNode(leftEnd, rightEnd);

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

void UpdateNode(node *currentNode, int l, int r, ll x, ll lazyvalue, ll girlIndex){
	if(r < currentNode->leftEnd || currentNode->rightEnd < l){
		currentNode->ans += lazyvalue;
		currentNode->lazyvalue += lazyvalue;
	}
	else{
		l = max(l, currentNode->leftEnd);
		r = min(r, currentNode->rightEnd);

		if(l == currentNode->leftEnd && r == currentNode->rightEnd){
			currentNode->ans += (lazyvalue + x);
			currentNode->lazyvalue += (lazyvalue + x);

			if(girlIndex != 0)
				currentNode->girlIndex = girlIndex;
		}
		else{
			lazyvalue += currentNode->lazyvalue;
			currentNode->lazyvalue = 0;
			UpdateNode(currentNode->leftChild, l, r, x, lazyvalue, girlIndex);
			UpdateNode(currentNode->rightChild, l, r, x, lazyvalue, girlIndex);

			if(currentNode->leftChild->ans <= currentNode->rightChild->ans){
				currentNode->ans = currentNode->leftChild->ans;
				currentNode->girlIndex = currentNode->leftChild->girlIndex;
			}
			else{
				currentNode->ans = currentNode->rightChild->ans;
				currentNode->girlIndex = currentNode->rightChild->girlIndex;
			}
		}
	}
}

pair< ll,int > QueryNode(node *currentNode, int l, int r, ll lazyvalue){
	if(r < currentNode->leftEnd || currentNode->rightEnd < l){
		currentNode->ans += lazyvalue;
		currentNode->lazyvalue += lazyvalue;
		return MP(inf, 0);
	}
	else{
		l = max(l, currentNode->leftEnd);
		r = min(r, currentNode->rightEnd);

		if(l == currentNode->leftEnd && r == currentNode->rightEnd){
			currentNode->ans += lazyvalue;
			currentNode->lazyvalue += lazyvalue;
			return MP(currentNode->ans, currentNode->girlIndex);
		}
		else{
			lazyvalue += currentNode->lazyvalue;
			currentNode->lazyvalue = 0;
			pair< ll,int > ans = min(QueryNode(currentNode->leftChild, l, r, lazyvalue), QueryNode(currentNode->rightChild, l, r, lazyvalue));

			if(currentNode->leftChild->ans <= currentNode->rightChild->ans){
				currentNode->ans = currentNode->leftChild->ans;
				currentNode->girlIndex = currentNode->leftChild->girlIndex;
			}
			else{
				currentNode->ans = currentNode->rightChild->ans;
				currentNode->girlIndex = currentNode->rightChild->girlIndex;
			}

			return ans;
		}
	}
}

void BuildSegmentTrees(int n){
	for(int chain = 1; chain <= totalChains; chain++)
		root[chain] = BuildSegmentTree(1, chainSize[chain]);

	for(int i = 1; i <= n; i++){
		UpdateNode(root[chainNo[i]], chainPosition[i], chainPosition[i], girls[i][nextGirl[i]], 0, girls[i][nextGirl[i]]);
		nextGirl[i]++;
	}
}
//----------------------------------------------- HLD Ends -----------------------------------------------//

//------------------------------------- LCA -------------------------------------//
int start[N], finish[N], t_time[N], indx[N], ind = 1, timer = 1, T[LOGN + 1][2*N], lg[2*N];

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

//------------------------------------- BIT -------------------------------------//
void UpdateBIT(int i, int n, ll x){
	for( ; i <= n; i += (i&-i))
		lazyValuesForSegmentTrees[i] += x;
}

ll QueryBIT(int i){
	ll ans = 0;

	for( ; i > 0; i -= (i&-i))
		ans += lazyValuesForSegmentTrees[i];

	return ans;
}
//---------------------------------- BIT Ends ----------------------------------//

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
			DFS(k);
			subtreeSize[i] += subtreeSize[k];
			T[0][ind++] = start[i];
		}
	}

	subtreeSize[i]++;
	finish[i] = timer;
}

void Update(int i, int n, int k){
	UpdateBIT(start[i], n, k);
	UpdateBIT(finish[i], n, -k);

	if(i != chainHead[chainNo[i]])
		UpdateNode(root[chainNo[i]], chainPosition[i], chainSize[chainNo[i]], k, 0, 0);
}

pair< ll,int > Query(int v, int u, int n){
	pair< ll,int > ans = MP(inf, 0);

	while(chainNo[v] != chainNo[u]){
		int k = start[chainHead[chainNo[v]]];
		
		ll lazyvalue = QueryBIT(k);
		UpdateBIT(k, n, -lazyvalue);
		UpdateBIT(k + 1, n, lazyvalue);
		
		ans = min(ans, QueryNode(root[chainNo[v]], 1, chainPosition[v], lazyvalue));
		v = parent[chainHead[chainNo[v]]];
	}

	int k = start[chainHead[chainNo[v]]];
		
	ll lazyvalue = QueryBIT(k);
	UpdateBIT(k, n, -lazyvalue);
	UpdateBIT(k + 1, n, lazyvalue);
		
	ans = min(ans, QueryNode(root[chainNo[v]], chainPosition[u], chainPosition[v], lazyvalue));

	return ans;
}

int main(){
	int n, m, q, i, j, k, x, y, z, t, u, v, w;

	scanf("%d%d%d", &n, &m, &q);

	for(x = 1; x < n; x++){
		scanf("%d%d", &i, &j);

		adj[i].PB(j);
		adj[j].PB(i);
	}

	for(i = 1; i <= m; i++){
		scanf("%d", &j);
		junctionNo[i] = j;
		girls[j].PB(i);
	}

	for(i = 1; i <= n; i++){
		girls[i].PB(inf);
		sort(girls[i].begin(), girls[i].end());
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

	while(q--){
		scanf("%d", &t);

		if(t == 2){
			scanf("%d%d", &i, &k);
			Update(i, n, k);
		}
		else{
			scanf("%d%d%d", &u, &v, &k);

			w = LCA(u,v);
			queue< int > ansQ;

			while(k--){
				pair< ll, int > ans = min(Query(u, w, n), Query(v, w, n));

				if(ans.first >= inf)
					break;

				i = ans.second;
				ansQ.push(i);
				i = junctionNo[i];
				ll temp = girls[i][nextGirl[i]] - girls[i][nextGirl[i] - 1];

				UpdateNode(root[chainNo[i]], chainPosition[i], chainPosition[i], temp, 0, girls[i][nextGirl[i]]);
				nextGirl[i]++;
			}

			printf("%d ", (int)ansQ.size());

			while(!ansQ.empty()){
				printf("%d ", ansQ.front());
				ansQ.pop();
			}

			printf("\n");
		}
	}

	return 0;
}