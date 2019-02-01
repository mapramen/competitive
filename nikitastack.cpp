#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  int lazyValue;
  int maxValue;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->lazyValue = temp->maxValue = 0;

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

void LazyUpdateChild(node *currentNode, node *childNode){
  childNode->lazyValue += currentNode->lazyValue;
  childNode->maxValue += currentNode->lazyValue;
}

void LazyUpdate(node *currentNode){
  LazyUpdateChild(currentNode, currentNode->leftChild);
  LazyUpdateChild(currentNode, currentNode->rightChild);
  currentNode->lazyValue = 0;
}

void MergeNode(node *currentNode, node *leftChild, node *rightChild){
  currentNode->maxValue = max(leftChild->maxValue, rightChild->maxValue);
}

void Update(node *currentNode, int l, int r, int x){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l){
    return ;
  }
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd){
      currentNode->lazyValue += x;
      currentNode->maxValue += x;
    }
    else{
      LazyUpdate(currentNode);

      Update(currentNode->leftChild, l, r, x);
      Update(currentNode->rightChild, l, r, x);

      MergeNode(currentNode, currentNode->leftChild, currentNode->rightChild);
    }
  }
}

int Query(node *currentNode){
  if(currentNode->maxValue <= 0)
    return -1;
  else{
    if(currentNode->leftEnd == currentNode->rightEnd){
      return a[currentNode->leftEnd];
    }
    else{
      LazyUpdate(currentNode);
      if(currentNode->leftChild->maxValue > 0)
        return Query(currentNode->leftChild);
      else
        return Query(currentNode->rightChild);
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n;
  scanf("%d", &n);

  node *root = BuildSegmentTree(1, n);

  for(int i = 1; i <= n; i++){
    int p, t;
    scanf("%d%d", &p, &t);
    p = n - p + 1;

    if(t == 1)
      scanf("%d", &a[p]);

    if(t == 0)
      Update(root, p, n, -1);
    else
      Update(root, p, n, 1);

    printf("%d\n", Query(root));
  }

  return 0;
}
