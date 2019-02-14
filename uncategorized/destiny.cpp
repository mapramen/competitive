#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define inf 1000000000

int a[N], ans;

typedef struct node{
  int leftEnd;
  int rightEnd;
  int cnt;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Persistent Segment Tree -----------------------------------------//
node* BuildSegmentTree(int i, int j){
  node *newNode = new node;

  newNode->leftEnd = i;
  newNode->rightEnd = j;
  newNode->cnt = 0;

  if(i != j){
    int k = (i + j) / 2;
    newNode->leftChild = BuildSegmentTree(i, k);
    newNode->rightChild = BuildSegmentTree(k + 1, j);
  }
  else{
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
  }

  return newNode;
}

node* Insert(node *currentNode, int x){
  if(currentNode == NULL || x > currentNode->rightEnd || x < currentNode->leftEnd)
    return currentNode;

  node *newNode = new node;
  newNode->leftEnd = currentNode->leftEnd;
  newNode->rightEnd = currentNode->rightEnd;
  newNode->cnt = currentNode->cnt + 1;
  newNode->leftChild = Insert(currentNode->leftChild, x);
  newNode->rightChild = Insert(currentNode->rightChild, x);

  return newNode;
}

void TraverseSegmentTree(node *root){
  if(root){
    TraverseSegmentTree(root->leftChild);
    TraverseSegmentTree(root->rightChild);
    printf("%d %d\n", root->leftEnd, root->rightEnd);
  }
}

void Query(node *u, node *v, int k){
  int cnt = v->cnt - u->cnt;

  if(cnt <= k)
    return ;

  if(v->rightEnd == v->leftEnd){
    ans = v->rightEnd;
    return ;
  }

  Query(u->leftChild, v->leftChild, k);

  if(ans == inf)
    Query(u->rightChild, v->rightChild, k);
}
//-------------------------------------- Persistent Segment Tree Ends --------------------------------------//
node *root[N];

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  root[0] = BuildSegmentTree(1, n);

  for(int i = 1; i <= n; ++i)
    root[i] = Insert(root[i - 1], a[i]);

  while(q--){
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    ans = inf;
    Query(root[l - 1], root[r], (r - l + 1) / k);
    if(ans == inf)
      ans = -1;
    printf("%d\n", ans);
  }

	return 0;
}
