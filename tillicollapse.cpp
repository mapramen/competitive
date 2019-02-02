#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N], ans[N], c[N];
vector< vector<int> > indexList(N), kList(N);

typedef struct node{
  int leftEnd;
  int rightEnd;
  int cnt;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->cnt = 0;

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

void UpdateNode(node *currentNode, int i, int x){
  if(i < currentNode->leftEnd || currentNode->rightEnd < i){
    return ;
  }
  else{
    if(i == currentNode->leftEnd && i == currentNode->rightEnd)
      currentNode->cnt += x;
    else{
      UpdateNode(currentNode->leftChild, i, x);
      UpdateNode(currentNode->rightChild, i, x);
      currentNode->cnt = currentNode->leftChild->cnt + currentNode->rightChild->cnt;
    }
  }
}

int QueryNode(node *currentNode, int k){
  if(currentNode->cnt <= k)
    return currentNode->rightEnd;
  else{
    if(currentNode->leftEnd == currentNode->rightEnd){
      if(currentNode->cnt <= k)
        return currentNode->rightEnd;
      else
        return 0;
    }
    else{
      if(currentNode->leftChild->cnt > k)
        return QueryNode(currentNode->leftChild, k);
      else
        return max(currentNode->leftChild->rightEnd, QueryNode(currentNode->rightChild, k - currentNode->leftChild->cnt));
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void UpdateNextIndex(node *root, int i){
  UpdateNode(root, indexList[i][c[i]++], -1);
  UpdateNode(root, indexList[i][c[i]], 1);
}

int main(){
  int n;
  node *root;
  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    indexList[i].PB(0);

  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
    indexList[a[i]].PB(i);
  }

  root = BuildSegmentTree(1, n);

  for(int i = 1; i <= n; i++){
    indexList[i].PB(n + 1);
    UpdateNextIndex(root, i);
    kList[1].PB(i);
  }

  for(int i = 1; i <= n; i++){
    for(auto k : kList[i]){
      ans[k]++;
      int j = QueryNode(root, k) + 1;
      if(j <= n)
        kList[j].PB(k);
    }
    UpdateNextIndex(root, a[i]);
  }

  for(int k = 1; k <= n; k++)
    printf("%d ", ans[k]);
  printf("\n");

  return 0;
}
