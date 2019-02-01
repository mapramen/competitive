#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

typedef struct node{
  int leftEnd;
  int rightEnd;
  int cnt;
  int ans;
  int lazy;
  node* leftChild;
  node* rightChild;
}node;

int l[N], r[N], k[N];
node *root;
vector<int> v, c;

//----------------------------------------- Segment Tree -----------------------------------------//
node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->ans = 0;
  temp->lazy = 0;

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
    temp->cnt = temp->leftChild->cnt + temp->rightChild->cnt;
  }
  else{
    temp->cnt = c[leftEnd];
    temp->leftChild = temp->rightChild = NULL;
  }

  return temp;
}

void UpdateNode(node *currentNode, int val){
  if(currentNode->lazy == val)
    return ;

  currentNode->lazy = val;
  if(val)
    currentNode->ans = currentNode->cnt;
  else
    currentNode->ans = 0;
}

void LazyUpdateChildren(node *currentNode){
  if(currentNode->lazy != 2){
    UpdateNode(currentNode->leftChild, currentNode->lazy);
    UpdateNode(currentNode->rightChild, currentNode->lazy);
    currentNode->lazy = 2;
  }
}

void Merge(node *currentNode){
  currentNode->ans = currentNode->leftChild->ans + currentNode->rightChild->ans;
}

void Update(node *currentNode, int l, int r, int val){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return ;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd){
      UpdateNode(currentNode, val);
    }
    else{
      LazyUpdateChildren(currentNode);
      Update(currentNode->leftChild, l, r, val);
      Update(currentNode->rightChild, l, r, val);
      Merge(currentNode);
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void PreProcess(int n, int q){
  vector<int> u;
  for(int i = 1; i <= q; ++i){
    u.PB(l[i]);
    u.PB(r[i]);
  }
  u.PB(0);
  u.PB(n + 1);

  sort(u.begin(), u.end());
  u.erase(unique(u.begin(), u.end()), u.end());

  for(int i = 0; i < u.size() - 1; ++i){
    v.PB(u[i]);
    c.PB(1);
    if(u[i + 1] != u[i] + 1){
      v.PB((u[i] + u[i + 1]) / 2);
      c.PB(u[i + 1] - u[i] - 1);
    }
  }

  for(int i = 1; i <= q; ++i){
    l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
    r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
    --k[i];
  }

  root = BuildSegmentTree(1, v.size() - 1);
  Update(root, 1, v.size() - 1, 1);
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= q; ++i)
    scanf("%d%d%d", &l[i], &r[i], &k[i]);

  PreProcess(n, q);

  for(int i = 1; i <= q; ++i){
    Update(root, l[i], r[i], k[i]);
    printf("%d\n", root->ans);
  }

  return 0;
}
