#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int h[N];
ll inf = LLONG_MAX / 2;

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

void UpdateNode(node *currentNode, ll x){
  currentNode->lazy += x;
  currentNode->ans += x;
}

void LazyUpdateChildren(node *currentNode){
  if(currentNode->lazy != 0){
    UpdateNode(currentNode->leftChild, currentNode->lazy);
    UpdateNode(currentNode->rightChild, currentNode->lazy);
    currentNode->lazy = 0;
  }
}

void Combine(node *currentNode){
  currentNode->ans = min(currentNode->leftChild->ans, currentNode->rightChild->ans);
}

void Update(node *currentNode, int l, int r, ll x){
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
      Combine(currentNode);
    }
  }
}

ll Query(node *currentNode, int l, int r){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return inf;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      return currentNode->ans;
    else{
      LazyUpdateChildren(currentNode);
      double ans = min(Query(currentNode->leftChild, l, r), Query(currentNode->rightChild, l, r));
      Combine(currentNode);
      return ans;
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n, m, x, y, a, b;
  ll ans;

  scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &x, &y);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &h[i]);

  node *root1 = BuildSegmentTree(0, n), *root2 = BuildSegmentTree(0, n);

  for(int i = 1; i <= n; ++i){
    ll val1 = 1ll * x * (m - h[i]), val2 = 1ll * y * h[i];

    Update(root1, 0, i - 1, val1);
    Update(root2, 0, i - 1, val2);

    ll ans2 = Query(root1, i - b, i - a), ans1 = Query(root2, i - b, i - a);

    Update(root1, i, i, ans1);
    Update(root2, i, i, ans2);

    ans = min(ans1, ans2);

    // printf("%d %lld %lld %lld %lld %lld\n", i, val1, val2, ans1, ans2, ans);
  }

  if(ans >= inf)
    ans = -1;

  printf("%lld\n", ans);

  return 0;
}
