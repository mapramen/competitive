#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

const int inf = 1E9;
int a[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  int lazy;
  int ans;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
void Combine(node *currentNode){
  currentNode->ans = min(currentNode->leftChild->ans, currentNode->rightChild->ans);
}

node* BuildSegmentTree(int leftEnd, int rightEnd, int dx){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->lazy = 0;

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid, dx);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd, dx);
    Combine(temp);
  }
  else{
    temp->ans = a[leftEnd] + dx * leftEnd;
    temp->leftChild = temp->rightChild = NULL;
  }

  return temp;
}

void UpdateNode(node *childNode, int val){
  childNode->lazy += val;
  childNode->ans += val;
}

void LazyUpdateChildren(node *currentNode){
  UpdateNode(currentNode->leftChild, currentNode->lazy);
  UpdateNode(currentNode->rightChild, currentNode->lazy);
  currentNode->lazy = 0;
}

void Update(node *currentNode, int l, int r, int val){
  if(r < l || r < currentNode->leftEnd || currentNode->rightEnd < l)
    return ;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);
    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      UpdateNode(currentNode, val);
    else{
      LazyUpdateChildren(currentNode);
      Update(currentNode->leftChild, l, r, val);
      Update(currentNode->rightChild, l, r, val);
      Combine(currentNode);
    }
  }
}

int Query(node *currentNode, int l, int r){
  if(r < l || r < currentNode->leftEnd || currentNode->rightEnd < l)
    return inf;
  else{
    int ans;

    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && currentNode->rightEnd == r)
      ans = currentNode->ans;
    else{
      LazyUpdateChildren(currentNode);
      ans = min(Query(currentNode->leftChild, l, r), Query(currentNode->rightChild, l, r));
      Combine(currentNode);
    }

    return ans;
  }
}

int FirstNegativeValueIndex(node *currentNode){
  if(currentNode->ans >= 0)
    return inf;
  else{
    if(currentNode->leftEnd == currentNode->rightEnd){
      return currentNode->leftEnd;
    }
    else{
      LazyUpdateChildren(currentNode);
      Combine(currentNode);
      if(currentNode->leftChild->ans < 0){
        return FirstNegativeValueIndex(currentNode->leftChild);
      }
      else{
        return FirstNegativeValueIndex(currentNode->rightChild);
      }
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  node *timeTree = BuildSegmentTree(1, n, 1);
  node *indexTree = BuildSegmentTree(1, n, 0);

  int ans = inf;
  for(int i = 1; i <= n; ++i){
    Update(indexTree, i, n, -1);
    Update(indexTree, 1, i - 1, 1);

    Update(timeTree, i, n, -1);
    Update(timeTree, 1, i - 1, 1);

    int j = FirstNegativeValueIndex(indexTree);

    int ansx = max(Query(timeTree, 1, j - 1), Query(timeTree, j, n));

    ans = min(ans, ansx);
  }

  if(ans == inf)
    ans = -1;

  printf("%d\n", ans);

  return 0;
}
