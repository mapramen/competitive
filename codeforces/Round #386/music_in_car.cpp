#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define M 10000

typedef struct node{
  int leftEnd;
  int rightEnd;
  int cnt;
  int ans;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->cnt = temp->ans = 0;

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

void MergeNode(node *currentNode, node *leftChild, node *rightChild){
  currentNode->cnt = leftChild->cnt + rightChild->cnt;
  currentNode->ans = leftChild->ans + rightChild->ans;
}

void UpdateNode(node *currentNode, int i, int x){
  if(i < currentNode->leftEnd || currentNode->rightEnd < i){
    return ;
  }
  else{
    if(i == currentNode->leftEnd && i == currentNode->rightEnd){
      currentNode->cnt += x;
      currentNode->ans += x * (i / 2);
    }
    else{
      UpdateNode(currentNode->leftChild, i, x);
      UpdateNode(currentNode->rightChild, i, x);
      MergeNode(currentNode, currentNode->leftChild, currentNode->rightChild);
    }
  }
}

int QueryNode(node *currentNode, int w){
  w = min(w, currentNode->cnt);
  if(w == 0)
    return 0;
  else{
    if(currentNode->cnt == w)
      return currentNode->ans;
    else{
      if(currentNode->leftEnd == currentNode->rightEnd)
        return w * (currentNode->ans / currentNode->cnt);
      else{
        int w2 = min(w, currentNode->rightChild->cnt);
        int w1 = w - w2;
        return QueryNode(currentNode->leftChild, w1) + QueryNode(currentNode->rightChild, w2);
      }
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int a[N], t[N];

int main(){
  int n, w, k, i, j, ans, ansx, tx;
  node *root = BuildSegmentTree(1, M);

  scanf("%d%d%d", &n, &w, &k);

  for(i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(i = 1; i <= n; i++)
    scanf("%d", &t[i]);

  for(i = j = 1, ans = ansx = tx = 0; i <= n; i++){
    for( ; j <= n; j++){
      if(tx - QueryNode(root, w) <= k)
        ans = max(ans, ansx);
      else
        break;

      ansx += a[j], tx += t[j];
      UpdateNode(root, t[j], 1);
    }

    if(tx - QueryNode(root, w) <= k)
      ans = max(ans, ansx);

    ansx -= a[i], tx -= t[i];
    UpdateNode(root, t[i], -1);
  }

  printf("%d\n", ans);

  return 0;
}
