#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 101
#define N 200001

typedef struct node{
  int leftEnd;
  int rightEnd;
  int p[B];
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
void ResetMapping(int p[]){
  for(int i = 1; i < B; ++i)
    p[i] = i;
}

node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  ResetMapping(temp->p);

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
  }
  else
    temp->leftChild = temp->rightChild = NULL;

  return temp;
}

void LazyUpdateChild(int a[], int b[]){
  for(int i = 1; i < B; ++i)
    a[i] = b[a[i]];
}

void LazyUpdateChildren(node *currentNode){
  LazyUpdateChild(currentNode->leftChild->p, currentNode->p);
  LazyUpdateChild(currentNode->rightChild->p, currentNode->p);
  ResetMapping(currentNode->p);
}

void Update(node *currentNode, int l, int r, int x, int y){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return ;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd){
      for(int i = 1; i < B; ++i){
        if(currentNode->p[i] == x)
          currentNode->p[i] = y;
      }
    }
    else{
      LazyUpdateChildren(currentNode);
      Update(currentNode->leftChild, l, r, x, y);
      Update(currentNode->rightChild, l, r, x, y);
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int a[N];

void Print(node *root){
  if(root->leftEnd == root->rightEnd){
    printf("%d ", root->p[a[root->leftEnd]]);
  }
  else{
    LazyUpdateChildren(root);
    Print(root->leftChild);
    Print(root->rightChild);
  }
}

int main(){
  int n, q;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  scanf("%d", &q);

  node *root = BuildSegmentTree(1, n);

  while(q--){
    int l, r, x, y;
    scanf("%d%d%d%d", &l, &r, &x, &y);
    Update(root, l, r, x, y);
  }

  Print(root);
  printf("\n");

  return 0;
}
