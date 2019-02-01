#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
int n, start[N], finish[N], timer = 0, u[2 * N], v[2 * N], w[2 * N];
ll T[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  ll lazy;
  ll ans;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->lazy = 0;
  temp->ans = 0;
  temp->leftChild = NULL;
  temp->rightChild = NULL;

  return temp;
}

node* BuildSegmentTree(int i, int j){
  node *temp = CreateNode(i, j);

  if(i != j){
    int k = (i + j) / 2;
    temp->leftChild = BuildSegmentTree(i, k);
    temp->rightChild = BuildSegmentTree(k + 1, j);
  }

  return temp;
}

void TraverseSegmentTree(node *root){
  if(root){
    TraverseSegmentTree(root->leftChild);
    TraverseSegmentTree(root->rightChild);
    printf("%d %d\n", root->leftEnd, root->rightEnd);
  }
}

void UpdateNode(node *currentNode, ll x){
  currentNode->lazy += x;
  currentNode->ans += x;
}

void LazyUpdateChildren(node *currentNode){
  UpdateNode(currentNode->leftChild, currentNode->lazy);
  UpdateNode(currentNode->rightChild, currentNode->lazy);
  currentNode->lazy = 0;
}

void Merge(node *currentNode){
  currentNode->ans = min(currentNode->leftChild->ans, currentNode->rightChild->ans);
}

void Update(node *currentNode, int l, int r, int x){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return ;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);
    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      UpdateNode(currentNode, x);
    else{
      LazyUpdateChildren(currentNode);
      Update(currentNode->leftChild, l, r, x);
      Update(currentNode->rightChild, l, r, x);
      Merge(currentNode);
    }
  }
}

ll Query(node *currentNode, int l, int r){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return LLONG_MAX;
  else{
    ll ans;

    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);
    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      ans = currentNode->ans;
    else{
      LazyUpdateChildren(currentNode);
      ans = min(Query(currentNode->leftChild, l, r), Query(currentNode->rightChild, l, r));
      Merge(currentNode);
    }

    return ans;
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

node *root;

void DFS(int i){
  start[i] = ++timer;
  for(auto k : adj[i])
    DFS(k);
  finish[i] = timer;
}

void Update(int i, int x){
  for( ; i <= n; i += (i & -i))
    T[i] += x;
}

ll Query(int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

void PreProcess(int n){
  for(int x = 1; x <= 2 * n - 2; ++x){
    if(v[x] == 1){
      int k = u[x];
      Update(root, start[k], start[k], w[x]);
    }
    else{
      int k = v[x];
      Update(root, start[k], finish[k], w[x]);
      Update(start[k], w[x]);
      Update(finish[k] + 1, -w[x]);
    }
  }
}

void UpdateEdge(int i, int x){
  if(v[i] == 1){
    int k = u[i];
    Update(root, start[k], start[k], x - w[i]);
    w[i] = x;
  }
  else{
    int k = v[i];
    x -= w[i];
    w[i] += x;
    Update(root, start[k], finish[k], x);
    Update(start[k], x);
    Update(finish[k] + 1, -x);
  }
}

bool IsAncestor(int u, int v){
  return (start[u] <= start[v] && finish[v] <= finish[u]);
}

ll Query(int u, int v){
  ll ans = 0;
  if(!IsAncestor(u, v))
    ans = Query(root, start[u], finish[u]);
  ans += (Query(start[v]) - Query(start[u]));
  return ans;
}

int main(){
  int q;

  scanf("%d%d", &n, &q);

  for(int x = 1; x <= 2 * n - 2; ++x){
    scanf("%d%d%d", &u[x], &v[x], &w[x]);
    if(v[x] != 1)
      adj[u[x]].PB(v[x]);
  }

  DFS(1);

  root = BuildSegmentTree(1, n);

  PreProcess(n);

  while(q--){
    int t, u, v;
    scanf("%d%d%d", &t, &u, &v);
    if(t == 1)
      UpdateEdge(u, v);
    else
      printf("%lld\n", Query(u, v));
  }

	return 0;
}
