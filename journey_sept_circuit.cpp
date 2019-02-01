#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

int n;
ll inf = 1E12, d[N], c[N], p[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  ll ans;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->ans = inf;

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
  }
  else
    temp->leftChild = temp->rightChild = NULL;

  return temp;
}

void Update(node *currentNode, int i, ll val){
  if(i < currentNode->leftEnd || currentNode->rightEnd < i)
    return ;
  else{
    if(i == currentNode->leftEnd && i == currentNode->rightEnd)
      currentNode->ans = min(currentNode->ans, val);
    else{
      Update(currentNode->leftChild, i, val);
      Update(currentNode->rightChild, i, val);
      currentNode->ans = min(currentNode->leftChild->ans, currentNode->rightChild->ans);
    }
  }
}

ll Query(node *currentNode, int l, int r){
  if(r < l || r < currentNode->leftEnd || currentNode->rightEnd < l)
    return inf;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      return currentNode->ans;
    else
      return min(Query(currentNode->leftChild, l, r), Query(currentNode->rightChild, l, r));
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int BinarySearchRightEnd(int i, ll c){
  int x = i, y = n - 1, z = i - 1;
  while(x <= y){
    int j = x + (y - x) / 2;
    if(d[j] - d[i - 1] <= c)
      z = j, x = j + 1;
    else
      y = j - 1;
  }
  return z + 1;
}

int main(){
  int q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i < n; ++i)
    scanf("%lld", &d[i]);

  for(int i = 1; i < n; ++i)
    scanf("%lld", &c[i]);

  for(int i = 1; i < n; ++i)
    scanf("%lld", &p[i]);

  for(int i = 1; i <= n; ++i)
    d[i] += d[i - 1];

  node *root = BuildSegmentTree(1, n);
  Update(root, n, 0);

  for(int i = n - 1; i > 0; --i){
    int l = i, r = BinarySearchRightEnd(i, c[i]);
    Update(root, i, p[i] + Query(root, l, r));
  }

  while(q--){
    ll k;
    scanf("%lld", &k);
    int l = 1, r = BinarySearchRightEnd(1, k);
    ll ans = Query(root, l, r);
    if(ans == inf)
      ans = -1;
    printf("%lld\n", ans);
  }

	return 0;
}
