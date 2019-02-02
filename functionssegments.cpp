#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define function tuple< int, int, int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define make_function make_tuple
#define N 75001
#define inf 1000000000

vector< function > F(1);
vector<int> v;

typedef struct node{
  int leftEnd;
  int rightEnd;
  ll a;
  ll b;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Persistent Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd, ll a, ll b){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->a = a;
  temp->b = b;
  temp->leftChild = NULL;
  temp->rightChild = NULL;

  return temp;
}

node* BuildSegmentTree(int i, int j){
  node *temp = CreateNode(v[i - 1] + 1, v[j], 0ll, 0ll);

  if(i != j){
    int k = (i + j) / 2;
    temp->leftChild = BuildSegmentTree(i, k);
    temp->rightChild = BuildSegmentTree(k + 1, j);
  }

  return temp;
}

node* PersistentTreeInsert(node *currentNode, int l, int r, int a, int b){
  if(currentNode == NULL || l > currentNode->rightEnd || r < currentNode->leftEnd)
    return currentNode;

  node *newNode = new node;
  newNode->leftEnd = currentNode->leftEnd;
  newNode->rightEnd = currentNode->rightEnd;
  newNode->a = currentNode->a;
  newNode->b = currentNode->b;

  l = max(l, currentNode->leftEnd);
  r = min(r, currentNode->rightEnd);

  if(l == currentNode->leftEnd && r == currentNode->rightEnd)
    newNode->a += a, newNode->b += b, newNode->leftChild = currentNode->leftChild, newNode->rightChild = currentNode->rightChild;
  else{
    newNode->leftChild = PersistentTreeInsert(currentNode->leftChild, l, r, a, b);
    newNode->rightChild = PersistentTreeInsert(currentNode->rightChild, l, r, a, b);
  }

  return newNode;
}

void TraverseSegmentTree(node *root){
  if(root){
    TraverseSegmentTree(root->leftChild);
    TraverseSegmentTree(root->rightChild);
    printf("%d %d\n", root->leftEnd, root->rightEnd);
  }
}

void PersistentTreeQuery(node *u, node *v, int x, ll &a, ll &b){
  a += v->a - u->a, b += v->b - u->b;

  if(v->leftChild != NULL && x <= v->leftChild->rightEnd)
    PersistentTreeQuery(u->leftChild, v->leftChild, x, a, b);
  else{
    if(v->rightChild != NULL && x >= v->rightChild->leftEnd)
      PersistentTreeQuery(u->rightChild, v->rightChild, x, a, b);
  }
}
//-------------------------------------- Persistent Segment Tree Ends --------------------------------------//

node *root[N];

void PreProcess(){
  int n = F.size() - 1;
  v.PB(-1);
  v.PB(0);
  for(int x = 1; x <= n; ++x){
    v.PB(get<0>(F[x]));
    v.PB(get<1>(F[x]));
  }
  v.PB(inf);

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  root[0] = BuildSegmentTree(1, v.size() - 1);

  for(int i = 1; i <= n; ++i){
    int x1, x2, y1, a, b, y2;
    tie(x1, x2, y1, a, b, y2) = F[i];
    root[i] = PersistentTreeInsert(root[i - 1], 0, x1, 0, y1);
    root[i] = PersistentTreeInsert(root[i], x1 + 1, x2, a, b);
    root[i] = PersistentTreeInsert(root[i], x2 + 1, inf, 0, y2);
  }
}

ll Query(int l, int r, int x){
  ll a = 0, b = 0;
  PersistentTreeQuery(root[l - 1], root[r], x, a, b);
  return (a * x + b);
}

int main(){
  int n, m;

  scanf("%d", &n);
  while(n--){
    int x1, x2, y1, a, b, y2;
    scanf("%d%d%d%d%d%d", &x1, &x2, &y1, &a, &b, &y2);
    F.PB(make_function(x1, x2, y1, a, b, y2));
  }

  PreProcess();

  scanf("%d", &m);

  ll ans = 0;
  while(m--){
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    x = (ans + x) % inf;
    ans = Query(l, r, x);
    printf("%lld\n", ans);
  }

	return 0;
}
