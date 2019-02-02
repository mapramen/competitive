#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001

typedef struct node{
  int leftEnd;
  int rightEnd;
  int count;
  node *leftChild;
  node *rightChild;
}node;

//---------------------------------------Merge Segment Tree---------------------------------------//
node *CreateNode(int leftEnd, int rightEnd, int count = 0, node *leftChild = NULL, node *rightChild = NULL){
  node *newNode = new node;
  newNode->leftEnd = leftEnd;
  newNode->rightEnd = rightEnd;
  newNode->count = count;
  newNode->leftChild = leftChild;
  newNode->rightChild = rightChild;
  return newNode;
}

node *FreeNode(node *currentNode){
  if(currentNode != NULL && currentNode->count == 0){
    free(currentNode);
    currentNode = NULL;
  }
  return currentNode;
}

void Combine(node *currentNode){
  if(currentNode == NULL){
    return ;
  }

  int count = 0;
  count += ((currentNode->leftChild == NULL) ? 0 : currentNode->leftChild->count);
  count += ((currentNode->rightChild == NULL) ? 0 : currentNode->rightChild->count);
  currentNode->count = count;
}

node *Insert(node *currentNode, int l, int r, int i){
  if(i < l || r < i){
    return currentNode;
  }

  if(l == r){
    return CreateNode(l, r, 1);
  }

  int mid = (l + r) / 2;

  node *leftChild = Insert(currentNode != NULL ? currentNode->leftChild : NULL, l, mid, i);
  node *rightChild = Insert(currentNode != NULL ? currentNode->rightChild : NULL, mid + 1, r, i);
  node *newNode = CreateNode(l, r, 0, leftChild, rightChild);

  Combine(newNode);

  return newNode;
}

pair<node*, node*> Move(node *sourceNode, node *targetNode, int l, int r){
  if(sourceNode == targetNode || sourceNode == NULL || r < sourceNode->leftEnd || sourceNode->rightEnd < l){
    return MP(sourceNode, targetNode);
  }

  int leftEnd = sourceNode->leftEnd, rightEnd = sourceNode->rightEnd;

  if(l <= leftEnd && rightEnd <= r && targetNode == NULL){
    return MP(targetNode, sourceNode); //targetNode is NULL. MP(NULL, sourceNode) does not compile
  }

  if(targetNode == NULL){
    targetNode = CreateNode(leftEnd, rightEnd);
  }

  tie(sourceNode->leftChild, targetNode->leftChild) = Move(sourceNode->leftChild, targetNode->leftChild, l, r);
  tie(sourceNode->rightChild, targetNode->rightChild) = Move(sourceNode->rightChild, targetNode->rightChild, l, r);

  Combine(sourceNode);
  Combine(targetNode);

  sourceNode = FreeNode(sourceNode);
  targetNode = FreeNode(targetNode);

  return MP(sourceNode, targetNode);
}

int Query(node *currentNode, int l, int r){
  if(currentNode == NULL || r < currentNode->leftEnd || currentNode->rightEnd < l){
    return 0;
  }

  if(l <= currentNode->leftEnd && currentNode->rightEnd <= r){
    return currentNode->count;
  }

  return (Query(currentNode->leftChild, l, r) + Query(currentNode->rightChild, l, r));
}
//------------------------------------Merge Segment Tree Ends------------------------------------//

node *root[N];

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    root[x] = Insert(root[x], 1, n, i);
  }

  while(q--){
    int t, l, r, x;
    scanf("%d%d%d%d", &t, &l, &r, &x);
    if(t == 1){
      int y;
      scanf("%d", &y);
      tie(root[x], root[y]) = Move(root[x], root[y], l, r);
    }
    else{
      printf("%d\n", Query(root[x], l, r));
    }
  }

  return 0;
}
