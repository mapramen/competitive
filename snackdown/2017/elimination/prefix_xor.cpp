#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 400001

int a[N], nxt[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  ll ans;
  ll count;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Persistent Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd, ll count = 0ll){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->ans = 0;
  temp->count = count;
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

node* PersistentTreeInsert(node *currentNode, int l, int r){
  if(currentNode == NULL || l > currentNode->rightEnd || r < currentNode->leftEnd)
    return currentNode;

  node *newNode = CreateNode(currentNode->leftEnd, currentNode->rightEnd, currentNode->count);

  if(l <= currentNode->leftEnd && currentNode->rightEnd <= r){
    ++(newNode->count);
    newNode->leftChild = currentNode->leftChild;
    newNode->rightChild = currentNode->rightChild;
  }
  else{
    newNode->leftChild = PersistentTreeInsert(currentNode->leftChild, l, r);
    newNode->rightChild = PersistentTreeInsert(currentNode->rightChild, l, r);
  }

  if(newNode->leftEnd != newNode->rightEnd){
    newNode->ans = newNode->leftChild->ans + newNode->rightChild->ans;
  }

  newNode->ans += (newNode->rightEnd - newNode->leftEnd + 1) * (newNode->count);

  return newNode;
}

void TraverseSegmentTree(node *root){
  if(root){
    TraverseSegmentTree(root->leftChild);
    TraverseSegmentTree(root->rightChild);
    printf("%d %d\n", root->leftEnd, root->rightEnd);
  }
}

ll Query(node *u, node *v, int r, int count = 0){
  if(u == NULL || r < u->leftEnd){
    return 0ll;
  }

  if(v->rightEnd <= r){
    return (v->ans - u->ans) + 1ll * count * (v->rightEnd - v->leftEnd + 1);
  }

  count += (v->count - u->count);

  return Query(u->leftChild, v->leftChild, r, count) + Query(u->rightChild, v->rightChild, r, count);
}
//-------------------------------------- Persistent Segment Tree Ends --------------------------------------//

node *root[N];

void PreProcess(int n){
  nxt[n] = n + 1;
  for(int i = n - 1; i > 0; --i){
    nxt[i] = (a[i + 1] == 0) ? nxt[i + 1] : i + 1;
  }

  root[0] = BuildSegmentTree(1, n);
  for(int i = 1; i <= n; ++i){
    int x = 0, j = i;
    for( ; j <= n && x <= (x ^ a[j]); x ^= a[j], j = nxt[j]);
    root[i] = PersistentTreeInsert(root[i - 1], i, j - 1);
  }
}

ll Query(int l, int r){
  return Query(root[l - 1], root[r], r);
}

int main(){
  int n, q;
  ll ans = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  PreProcess(n);

  scanf("%d", &q);
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    l = (l + ans) % n + 1, r = (r + ans) % n + 1;
    ans = Query(l, r);
    printf("%lld\n", ans);
  }

  return 0;
}
