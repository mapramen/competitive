#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define LOGN 17

//----------------------------------------- LCA -----------------------------------------//
int startTime[N], finishTime[N], startTimeVertex[N], eulerTourIndexes[N];
int lg[2 * N], LCASparseTable[1 + LOGN][2 * N];
int eulerTourIndex = 0, timer = 0;

void BuildLCASparseTable(int n){
  n = 2 * n;

  for(int i = 2; i < n; ++i){
    lg[i] = 1 + lg[(i / 2)];
  }

  for(int k = 1; k <= LOGN; ++k){
    for(int i = 1, j = 1 + (1 << (k - 1)), m = n - (1 << k) + 1; i < m; ++i, ++j){
      LCASparseTable[k][i] = min(LCASparseTable[k - 1][i], LCASparseTable[k - 1][j]);
    }
  }
}

int LCA(int i, int j){
  i = eulerTourIndexes[i], j = eulerTourIndexes[j];
  
  if(i > j){
    swap(i, j);
  }

  int k = lg[j - i + 1];
  int ans = startTimeVertex[min(LCASparseTable[k][i], LCASparseTable[k][j - (1 << k) + 1])];
  return ans;
}
//--------------------------------------- LCA Ends ---------------------------------------//

struct Node{
  int count;
  Node* leftChild;
  Node* rightChild;

  Node(int count = 0, Node* leftChild = NULL, Node* rightChild = NULL){
    this->count = count;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
  }
};

int GetCount(Node *a){
  return a == NULL ? 0 : a->count;
}

int GetCount(Node* a, Node* b){
  return GetCount(b) - GetCount(a);
}

Node* GetLeftChild(Node* a){
  return a == NULL ? NULL : a->leftChild;
}

Node* GetRightChild(Node* a){
  return a == NULL ? NULL : a->rightChild;
}

int GetLeftChildCount(Node* a){
  return GetCount(GetLeftChild(a));
}

Node* Insert(int l, int r, Node* node, int x){
  if(x < l || r < x){
    return node;
  }

  if(l == r){
    return new Node(GetCount(node) + 1);
  }

  int mid = (0ll + l + r) / 2;

  return new Node(
    GetCount(node) + 1,
    Insert(l, mid, GetLeftChild(node), x),
    Insert(mid + 1, r, GetRightChild(node), x));
}

bool Query(int l, int r, Node* a, Node* b, Node* pa, Node* pb, int k){
  if(l == r){
    return GetCount(a) + GetCount(b) - GetCount(pa) - GetCount(pb) > 0;
  }
  
  int mid = (0ll + l + r) / 2;

  return k <= mid
    ? Query(l, mid, GetLeftChild(a), GetLeftChild(b), GetLeftChild(pa), GetLeftChild(pb), k)
    : Query(mid + 1, r, GetRightChild(a), GetRightChild(b), GetRightChild(pa), GetRightChild(pb), k);
}

vector<vector<int>> adj(N);
int a[N], parent[N];
Node* roots[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
  eulerTourIndex = 0, timer = 0;
}

void DFS(int i, int p){
  parent[i] = p;

  roots[i] = Insert(0, N, roots[p], a[i]);

  startTime[i] = ++timer;
  startTimeVertex[startTime[i]] = i;
  eulerTourIndexes[i] = ++eulerTourIndex;
  LCASparseTable[0][eulerTourIndexes[i]] = startTime[i];

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
    LCASparseTable[0][++eulerTourIndex] = startTime[i];
  }

  finishTime[i] = timer;
}

void Solve(){
  int n, q;
  if(scanf("%d%d", &n, &q) == EOF){
    exit(0);
  }

  Reset(n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  roots[0] = new Node(0);
  DFS(1, 0);
  BuildLCASparseTable(n);

  while(q--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);

    int v = LCA(i, j);
    printf("%s\n", Query(0, N, roots[i], roots[j], roots[v], roots[parent[v]], k) ? "Find" : "NotFind");
  }
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}