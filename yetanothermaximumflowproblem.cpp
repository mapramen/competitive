#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector< pii > > v(N);
int a[N], b[N];
ll c[N], inf = LLONG_MAX / 2;

typedef struct node{
  int leftEnd;
  int rightEnd;
  ll lazy;
  ll ans;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->lazy = 0;
  temp->ans = 0;

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
  }
  else
    temp->leftChild = temp->rightChild = NULL;

  return temp;
}

void Merge(node *currentNode){
  currentNode->ans = min(currentNode->leftChild->ans, currentNode->rightChild->ans);
}

void ResetSegmentTree(node *currentNode){
  currentNode->lazy = 0, currentNode->ans = 0;
  if(currentNode->leftEnd != currentNode->rightEnd){
    ResetSegmentTree(currentNode->leftChild);
    ResetSegmentTree(currentNode->rightChild);
  }
}

void UpdateNode(node *currentNode, ll val){
  currentNode->lazy += val;
  currentNode->ans += val;
}

void LazyUpdateChildren(node *currentNode){
  if(currentNode->lazy){
    UpdateNode(currentNode->leftChild, currentNode->lazy);
    UpdateNode(currentNode->rightChild, currentNode->lazy);
    currentNode->lazy = 0;
  }
}

void Update(node *currentNode, int l, int r, ll val){
  if(r < l || r < currentNode->leftEnd || currentNode->rightEnd < l)
    return ;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);
    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      UpdateNode(currentNode, val);
    else{
      LazyUpdateChildren(currentNode);
      Update(currentNode->leftChild, l, r, val);
      Update(currentNode->rightChild, l, r, val);
      Merge(currentNode);
    }
  }
}

ll Query(node *currentNode, int l, int r){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return inf;
  else{
    ll ans;

    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && currentNode->rightEnd == r)
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

void PreProcess(int n){
  root = BuildSegmentTree(0, n);

  for(int i = 1; i < n; ++i)
    Update(root, i, i, b[i]);

  for(int i = 1; i <= n; ++i){
    for(auto p : v[i]){
      int j, k;
      tie(j, k) = p;
      Update(root, 0, j - 1, k);
    }
    c[i] = Query(root, 0, n - 1);
  }

  ResetSegmentTree(root);

  Update(root, 0, 0, inf);

  for(int i = 1; i <= n; ++i)
    Update(root, i, i, c[i] + a[i]);
}

int main(){
  int n, m, q;

  scanf("%d%d%d", &n, &m, &q);

  for(int i = 1; i < n; ++i)
    scanf("%d%d", &a[i], &b[i]);

  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    v[i].PB(MP(j, k));
  }

  PreProcess(n);

  printf("%lld\n", root->ans);
  while(q--){
    int i, w;
    scanf("%d%d", &i, &w);
    w -= a[i];
    Update(root, i, i, w);
    a[i] += w;
    printf("%lld\n", root->ans);
  }

  return 0;
}
