#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

typedef struct node
{
  int leftEnd;
  int rightEnd;
  ll lVal, rVal, upVal;
  int len, lDec, lInc, rDec, rInc, ans;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->lVal = temp->rVal = temp->upVal = 0;
  temp->lDec = temp->lInc = temp->rDec = temp->rInc = temp->ans = 1;
  temp->len = rightEnd - leftEnd + 1;

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

void LazyUpdate(node *currentNode, ll x){
  currentNode->lVal += x, currentNode->rVal += x, currentNode->upVal += x;
}

void MergeNode(node *currentNode, node *leftChild, node *rightChild){
  currentNode->lVal = leftChild->lVal, currentNode->rVal = rightChild->rVal, currentNode->upVal = 0, currentNode->ans = 0;
  int ans = 0;

  currentNode->lDec = leftChild->lDec;
  currentNode->rDec = rightChild->rDec;
  currentNode->lInc = leftChild->lInc;
  currentNode->rInc = rightChild->rInc;

  if(leftChild->rVal != rightChild->lVal){
    if(leftChild->lDec == leftChild->len && leftChild->rVal > rightChild->lVal)
      currentNode->lDec += rightChild->lDec;

    if(rightChild->rDec == rightChild->len && leftChild->rVal < rightChild->lVal)
      currentNode->rDec += leftChild->rDec;

    if(leftChild->lInc == leftChild->len){
      if(leftChild->rVal > rightChild->lVal)
        currentNode->lInc += rightChild->lDec;
      else
        if(leftChild->rDec == leftChild->len)
          currentNode->lInc += rightChild->lInc;
    }

    if(rightChild->rInc == rightChild->len){
      if(leftChild->rVal < rightChild->lVal)
        currentNode->rInc += leftChild->rDec;
      else
        if(rightChild->lDec == rightChild->len)
          currentNode->rInc += leftChild->rInc;
    }

    if(leftChild->rVal < rightChild->lVal){
      ans = max(ans, leftChild->rDec + rightChild->lInc);
      ans = max(ans, leftChild->rDec + rightChild->lDec);
    }
    else
      ans = max(ans, leftChild->rInc + rightChild->lDec);

    ans = max(ans, currentNode->lDec);
    ans = max(ans, currentNode->lInc);
    ans = max(ans, currentNode->rDec);
    ans = max(ans, currentNode->rInc);
  }

  ans = max(ans, leftChild->ans);
  ans = max(ans, rightChild->ans);

  currentNode->ans = ans;
}

void UpdateNode(node *currentNode, int l, int r, int x){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l){
    return ;
  }
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      LazyUpdate(currentNode, 1ll * x);
    else{
      LazyUpdate(currentNode->leftChild, currentNode->upVal);
      LazyUpdate(currentNode->rightChild, currentNode->upVal);
      UpdateNode(currentNode->leftChild, l, r, x);
      UpdateNode(currentNode->rightChild, l, r, x);
      MergeNode(currentNode, currentNode->leftChild, currentNode->rightChild);
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n, m, i, j, k;

  scanf("%d", &n);
  node *root = BuildSegmentTree(1, n);

  for(i = 1; i <= n; i++){
    scanf("%d", &k);
    UpdateNode(root, i, i, k);
  }

  scanf("%d\n", &m);

  while(m--){
    scanf("%d%d%d", &i, &j, &k);
    UpdateNode(root, i, j, k);
    printf("%d\n", root->ans);
  }

  return 0;
}
