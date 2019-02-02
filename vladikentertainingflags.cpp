#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 11
#define M 100001

int n, a[N][M], leftGroup[N], rightGroup[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  int ans;
  int leftGroup[N];
  int rightGroup[N];
  node* leftChild;
  node* rightChild;
}node;

void UpdateGroup(int group[], int x, int y, int z){
  for(int i = 1; i <= n; i++){
    if(group[i] == x || group[i] == y)
      group[i] = z;
  }
}

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->ans = 0;
  temp->leftChild = NULL;
  temp->rightChild = NULL;

  if(leftEnd == rightEnd && rightEnd > 0){
    temp->ans = n;

    for(int i = 1, x = (rightEnd - 1) * n + 1; i <= n; i++, x++){
      temp->leftGroup[i] = x;
      temp->rightGroup[i] = x;
    }

    for(int i = 2, x = (rightEnd - 1) * n + 1; i <= n; i++, x++){
      if(a[i][rightEnd] != a[i - 1][rightEnd])
        continue;

      temp->ans--;
      temp->leftGroup[i] = temp->leftGroup[i - 1];
      temp->rightGroup[i] = temp->rightGroup[i - 1];
    }
  }

  return temp;
}

void Merge(node *leftChild, node *rightChild, node *currentNode){
  if(leftChild->rightEnd != 0){
    currentNode->ans = leftChild->ans + rightChild->ans;

    for(int i = 1; i <= n; i++){
      leftGroup[i] = leftChild->rightGroup[i];
      rightGroup[i] = rightChild->leftGroup[i];
    }

    for(int i = 1; i <= n; i++){
      currentNode->leftGroup[i] = leftChild->leftGroup[i];
      currentNode->rightGroup[i] = rightChild->rightGroup[i];
    }

    for(int l = leftChild->rightEnd, r = rightChild->leftEnd, i = 1; i <= n; i++){
      if(a[i][l] != a[i][r] || leftGroup[i] == rightGroup[i])
        continue;

      int x = leftGroup[i], y = rightGroup[i], z = min(x, y);
      UpdateGroup(currentNode->leftGroup, x, y, z);
      UpdateGroup(currentNode->rightGroup, x, y, z);
      UpdateGroup(leftGroup, x, y, z);
      UpdateGroup(rightGroup, x, y, z);
      currentNode->ans--;
    }

    currentNode->leftEnd = leftChild->leftEnd;
    currentNode->rightEnd = rightChild->rightEnd;
  }
  else{
    currentNode->leftEnd = rightChild->leftEnd;
    currentNode->rightEnd = rightChild->rightEnd;
    currentNode->ans = rightChild->ans;

    for(int i = 1; i <= n; i++){
      currentNode->leftGroup[i] = rightChild->leftGroup[i];
      currentNode->rightGroup[i] = rightChild->rightGroup[i];
    }
  }
}

node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = CreateNode(leftEnd, rightEnd);

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
    Merge(temp->leftChild, temp->rightChild, temp);
  }

  return temp;
}

void Query(node *currentNode, node *queryNode, int l, int r){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return ;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      Merge(queryNode, currentNode, queryNode);
    else{
      Query(currentNode->leftChild, queryNode, l, r);
      Query(currentNode->rightChild, queryNode, l, r);
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void ResetNode(node *currentNode){
  currentNode->leftEnd = currentNode->rightEnd = currentNode->ans = 0;
  for(int i = 1; i <= n; i++)
    currentNode->leftGroup[i] = currentNode->rightGroup[i] = 0;
}

int main(){
  int m, q;

  scanf("%d%d%d", &n, &m, &q);

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      scanf("%d", &a[i][j]);

  node *root = BuildSegmentTree(1, m);
  node *queryNode = new node;

  while(q--){
    int l, r;
    ResetNode(queryNode);
    scanf("%d%d", &l, &r);
    Query(root, queryNode, l, r);
    printf("%d\n", queryNode->ans);
  }

	return 0;
}
