#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 35001

int a[N], prvC[N], prv[N], dp[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  int lazy;
  int ans;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
  }
  else
    temp->leftChild = temp->rightChild = NULL;

  return temp;
}

void Merge(node *currentNode){
  currentNode->ans = max(currentNode->leftChild->ans, currentNode->rightChild->ans);
}

void ResetSegmentTree(node *currentNode){
  currentNode->lazy = 0;
  if(currentNode->leftEnd == currentNode->rightEnd)
    currentNode->ans = dp[currentNode->leftEnd];
  else{
    ResetSegmentTree(currentNode->leftChild);
    ResetSegmentTree(currentNode->rightChild);
    Merge(currentNode);
  }
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
      Merge(currentNode);
    }
  }
}

int Query(node *currentNode, int l, int r){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return 0;
  else{
    int ans;

    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && currentNode->rightEnd == r)
      ans = currentNode->ans;
    else{
      LazyUpdateChildren(currentNode);
      ans = max(Query(currentNode->leftChild, l, r), Query(currentNode->rightChild, l, r));
      Merge(currentNode);
    }

    return ans;
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n, m;
  node *root = BuildSegmentTree(0, N - 1);

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; i++)
    prvC[i] = 0;

  for(int i = 1; i <= n; i++){
    int c = a[i];
    prv[i] = prvC[c];
    prvC[c] = i;
  }

  for(int i = 1; i <= n; i++)
    dp[i] = INT_MIN;

  for(int k = 1; k <= m; k++){
    ResetSegmentTree(root);
    for(int i = 1; i <= n; i++){
      int j = prv[i];
      Update(root, j, i - 1, 1);
      dp[i] = Query(root, 0, i - 1);
    }

    for(int i = 0; i < k; i++)
      dp[i] = INT_MIN;
  }

  printf("%d\n", dp[n]);

	return 0;
}
