#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
int a[N], parent[N], d[N], start[N], finish[N], ind[N], timer = 0;

typedef struct node{
  int leftEnd;
  int rightEnd;
  vector<int> C;
  vector<int> D;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->C.clear();
  temp->D.clear();
  temp->leftChild = NULL;
  temp->rightChild = NULL;

  return temp;
}

void RemoveDuplicates(vector<int>& v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

int GetCompressedValue(vector<int>& v, int x){
  if(v.back() <= x)
    return v.size() - 1;

  if(x < v.front())
    return -1;
    
  int i = lower_bound(v.begin(), v.end(), x) - v.begin();
  if(v[i] != x)
    --i;
  return i;
}

node* BuildSegmentTree(int i, int j){
  node *temp = CreateNode(i, j);

  if(i == j){
    int k = ind[i];
    temp->C.PB(d[k]);
    temp->D.PB(a[k]);
  }
  if(i != j){
    int k = (i + j) / 2;
    temp->leftChild = BuildSegmentTree(i, k);
    temp->rightChild = BuildSegmentTree(k + 1, j);

    for(auto x : temp->leftChild->C)
      temp->C.PB(x);

    for(auto x : temp->rightChild->C)
      temp->C.PB(x);

    RemoveDuplicates(temp->C);
    temp->D.resize(temp->C.size());

    for(int i = 0; i < temp->D.size(); ++i)
      temp->D[i] = INT_MAX;

    for(int i = 0; i < temp->leftChild->C.size(); ++i){
      int k = GetCompressedValue(temp->C, temp->leftChild->C[i]), x = temp->leftChild->D[i];
      temp->D[k] = min(temp->D[k], x);
    }

    for(int i = 0; i < temp->rightChild->C.size(); ++i){
      int k = GetCompressedValue(temp->C, temp->rightChild->C[i]), x = temp->rightChild->D[i];
      temp->D[k] = min(temp->D[k], x);
    }

    for(int i = 1; i < temp->D.size(); ++i)
      temp->D[i] = min(temp->D[i], temp->D[i - 1]);
  }

  return temp;
}

int Query(vector<int>& C, vector<int>& D, int x){
  int i = GetCompressedValue(C, x);
  if(i < 0)
    return INT_MAX;
  else
    return D[i];
}

int Query(node *currentNode, int l, int r, int x){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return INT_MAX;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      return Query(currentNode->C, currentNode->D, x);
    else
      return min(Query(currentNode->leftChild, l, r, x), Query(currentNode->rightChild, l, r, x));
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

node *root;

void DFS(int i){
  d[i] = 1 + d[parent[i]];
  start[i] = ++timer;
  ind[start[i]] = i;
  for(auto k : adj[i]){
    if(k != parent[i]){
      parent[k] = i;
      DFS(k);
    }
  }
  finish[i] = timer;
}

int Query(int u, int k){
  return Query(root, start[u], finish[u], k + d[u]);
}

int main(){
  int n, r, q;

  scanf("%d%d", &n, &r);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(r);

  root = BuildSegmentTree(1, n);

  scanf("%d", &q);

  int ans = 0;
  while(q--){
    int u, k;
    scanf("%d%d", &u, &k);
    u = (u + ans) % n + 1, k = (k + ans) % n;
    ans = Query(u, k);
    printf("%d\n", ans);
  }

	return 0;
}
