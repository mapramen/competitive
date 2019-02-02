#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

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

int Query(node *currentNode, int l, int r){
  if(currentNode == NULL || r < l || r < currentNode->leftEnd || l > currentNode->rightEnd){
    return 0;
  }
  else{
    if(currentNode->leftEnd >= l && currentNode->rightEnd<= r){
      return currentNode->cnt;
    }
    else{
      return Query(currentNode->leftChild, l, r) + Query(currentNode->rightChild, l, r);
    }
  }
}
//-------------------------------------- Persistent Segment Tree Ends --------------------------------------//
node *root[N];

int main(){
  int n;

  scanf("%d", &n);

  root[0] = BuildSegmentTree(1, n);

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    int j;
    scanf("%d", &j);
    j = min(n, j);

    root[i] = NULL;
    ans += Query(root[min(i - 1, j)], i, n);

    root[i] = Insert(root[i - 1], j);
  }

  printf("%lld\n", ans);

  return 0;
}
