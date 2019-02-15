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
  ll lazyMulB;
  ll lazyMulC;
  ll ans;
  node* leftChild;
  node* rightChild;
}node;

int a[N];
ll A = 276601605, B = 691504013, C = 308495997, MOD = 1000000009, powB[N], powC[N], sumPowB[N], sumPowC[N];
node *root;

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;
  int length = rightEnd - leftEnd + 1;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->lazyMulB = temp->lazyMulC = 0;

  if(leftEnd == rightEnd)
    temp->ans = a[leftEnd];

  return temp;
}

node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = CreateNode(leftEnd, rightEnd);

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
    temp->ans = (temp->leftChild->ans + temp->rightChild->ans) % MOD;
  }
  else
    temp->leftChild = temp->rightChild = NULL;

  return temp;
}

void UpdateNode(node *currentNode, ll lazyMulB, ll lazyMulC){
  int length = currentNode->rightEnd - currentNode->leftEnd + 1;
  currentNode->lazyMulB = (currentNode->lazyMulB + lazyMulB) % MOD;
  currentNode->lazyMulC = (currentNode->lazyMulC + lazyMulC) % MOD;
  ll ansIncrease = A * (MOD + (lazyMulB * sumPowB[length]) % MOD - (lazyMulC * sumPowC[length]) % MOD);
  currentNode->ans = (currentNode->ans + ansIncrease) % MOD;
}

void LazyUpdateChildren(node *currentNode){
  int length = currentNode->rightChild->leftEnd - currentNode->leftChild->leftEnd;
  ll lazyMulB = currentNode->lazyMulB, lazyMulC = currentNode->lazyMulC;
  UpdateNode(currentNode->leftChild, lazyMulB, lazyMulC);

  lazyMulB = (lazyMulB * powB[length]) % MOD, lazyMulC = (lazyMulC * powC[length]) % MOD;
  UpdateNode(currentNode->rightChild, lazyMulB, lazyMulC);

  currentNode->lazyMulB = currentNode->lazyMulC = 0;
}

void Update(node *currentNode, int i, int l, int r){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return ;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && currentNode->rightEnd == r){
      UpdateNode(currentNode, powB[l - i], powC[l - i]);
    }
    else{
      LazyUpdateChildren(currentNode);
      Update(currentNode->leftChild, i, l, r);
      Update(currentNode->rightChild, i, l, r);
      currentNode->ans = (currentNode->leftChild->ans + currentNode->rightChild->ans) % MOD;
    }
  }
}

ll Query(node *currentNode, int l, int r){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return 0ll;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && currentNode->rightEnd == r)
      return currentNode->ans;
    else{
      LazyUpdateChildren(currentNode);
      ll ans1 = Query(currentNode->leftChild, l, r);
      ll ans2 = Query(currentNode->rightChild, l, r);
      currentNode->ans = (currentNode->leftChild->ans + currentNode->rightChild->ans) % MOD;
      return (ans1 + ans2) % MOD;
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void PreProcess(int n){
  powB[0] = powC[0] = 1;
  for(int i = 1; i <= n; i++){
    powB[i] = (B * powB[i - 1]) % MOD;
    powC[i] = (C * powC[i - 1]) % MOD;
  }

  for(int i = 1; i <= n; i++){
    sumPowB[i] = (sumPowB[i - 1] + powB[i]) % MOD;
    sumPowC[i] = (sumPowC[i - 1] + powC[i]) % MOD;
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  PreProcess(n);
  root = BuildSegmentTree(1, n);

  while(m--){
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    if(t == 1)
      Update(root, l, l, r);
    else
      printf("%lld\n", Query(root, l, r));
  }

	return 0;
}
