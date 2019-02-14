#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define inf INT_MAX
#define N 100001

vector<int> compressedX, a;
int b[N], l[N], r[N], x[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  int ans;
  int lazyValue;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->ans = inf;
  temp->lazyValue = -1;

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

void ResetSegmentTree(node *root){
  if(root != NULL){
    ResetSegmentTree(root->leftChild);
    ResetSegmentTree(root->rightChild);
    root->ans = inf;
    root->lazyValue = -1;
  }
}

void LazyUpdateChild(node *currentNode, node *childNode){
  if(currentNode->lazyValue >= 0){
    childNode->lazyValue = currentNode->lazyValue;
    childNode->ans = currentNode->lazyValue;
  }
}

void LazyUpdateChildren(node *currentNode){
  LazyUpdateChild(currentNode, currentNode->leftChild);
  LazyUpdateChild(currentNode, currentNode->rightChild);
  currentNode->lazyValue = -1;
}

void UpdateNode(node *currentNode, int l, int r, int x){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return ;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd){
      currentNode->lazyValue = x;
      currentNode->ans = x;
    }
    else{
      LazyUpdateChildren(currentNode);
      UpdateNode(currentNode->leftChild, l, r, x);
      UpdateNode(currentNode->rightChild, l, r, x);
      currentNode->ans = min(currentNode->leftChild->ans, currentNode->rightChild->ans);
    }
  }
}

int QueryNode(node *currentNode, int l, int r){
  if(r < l || r < currentNode->leftEnd || currentNode->rightEnd < l)
    return inf;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      return currentNode->ans;
    else{
      LazyUpdateChildren(currentNode);
      return min(QueryNode(currentNode->leftChild, l, r), QueryNode(currentNode->rightChild, l, r));
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int GetCompressedValue(int x){
  return lower_bound(compressedX.begin(), compressedX.end(), x) - compressedX.begin();
}

node *PreProcess(int n, int k, int q){
  int m = 0;
  vector<int> v;

  for(int i = 1; i <= k; i++)
    v.PB((i - 1) * n + 1), v.PB(i * n);

  for(int i = 1; i <= q; i++)
    v.PB(l[i]), v.PB(r[i]);

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  m = v.size();
  for(int i = 0; i < v.size() - 1; i++)
    m += (v[i + 1] > v[i] + 1);

  node *root = BuildSegmentTree(1, max(n, m));
  compressedX.PB(0);
  a.PB(0);

  for(int i = 1; i <= n; i++)
    UpdateNode(root, i, i, b[i]);

  for(int i = 0; i < v.size() - 1; i++){
    int ansx = QueryNode(root, (v[i] - 1) % n + 1, (v[i] - 1) % n + 1);
    compressedX.PB(v[i]);
    a.PB(ansx);

    if(v[i] + 1 < v[i + 1]){
      ansx = QueryNode(root, v[i] % n + 1, (v[i + 1] - 2) % n + 1);
      compressedX.PB(v[i] + 1);
      a.PB(ansx);
    }
  }

  compressedX.PB(v[v.size() - 1]);
  a.PB(QueryNode(root, (v[v.size() - 1] - 1) % n + 1, (v[v.size() - 1] - 1) % n + 1));

  ResetSegmentTree(root);
  for(int i = 1; i < a.size(); i++)
    UpdateNode(root, i, i, a[i]);

  for(int i = 1; i <= q; i++){
    l[i] = GetCompressedValue(l[i]);
    r[i] = GetCompressedValue(r[i]);
  }

  return root;
}

int main(){
  int n, k, q;

  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; i++)
    scanf("%d", &b[i]);

  scanf("%d", &q);

  for(int i = 1; i <= q; i++){
    int t;
    scanf("%d%d%d", &t, &l[i], &r[i]);
    if(t == 1)
      scanf("%d", &x[i]);
  }

  node *root = PreProcess(n, k, q);

  for(int i = 1; i <= q; i++){
    if(x[i])
      UpdateNode(root, l[i], r[i], x[i]);
    else
      printf("%d\n", QueryNode(root, l[i], r[i]));
  }

  return 0;
}
