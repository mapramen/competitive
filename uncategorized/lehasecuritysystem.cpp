#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 10

int a[N];
ll p10[B];
vector<int> newUpdateVector(B);
vector<ll> s(B);

typedef struct node{
  int leftEnd;
  int rightEnd;
  vector<int> updateVector;
  vector< ll > mulVector;
  ll ans;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
void ResetUpdateVector(vector<int>& updateVector){
  for(int i = 0; i < B; i++)
    updateVector[i] = i;
}

node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->updateVector.resize(B);
  temp->mulVector.resize(B);
  temp->ans = 0;

  ResetUpdateVector(temp->updateVector);

  for(int i = 0; i < B; i++)
    temp->mulVector[i] = 0;

  if(leftEnd == rightEnd){
    int x = a[leftEnd];
    temp->ans = x;
    for(int j = 0; x > 0; x /= 10, j++){
      int i = x % 10;
      temp->mulVector[i] += p10[j];
    }
  }

  return temp;
}

void Combine(node *currentNode){
  node *leftChild = currentNode->leftChild, *rightChild = currentNode->rightChild;
  for(int i = 0; i < B; i++)
    currentNode->mulVector[i] = leftChild->mulVector[i] + rightChild->mulVector[i];
  currentNode->ans = leftChild->ans + rightChild->ans;
}

node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = CreateNode(leftEnd, rightEnd);

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
    Combine(temp);
  }
  else
    temp->leftChild = temp->rightChild = NULL;

  return temp;
}

void ApplyUpdates(node *currentNode, vector<int>& updateVector){
  currentNode->ans = 0;
  for(int i = 0; i < B; i++)
    s[i] = 0;
  for(int i = 0; i < B; i++)
    s[updateVector[i]] += currentNode->mulVector[i];
  for(int i = 0; i < B; i++){
    currentNode->mulVector[i] = s[i];
    currentNode->ans += i * s[i];
  }
}

void UpdateUpdateVector(vector<int>& updateVector, vector<int>& newUpdates){
  for(int i = 0; i < B; i++)
    updateVector[i] = newUpdates[updateVector[i]];
}

void LazyUpdateChildren(node *currentNode){
  node *leftChild = currentNode->leftChild, *rightChild = currentNode->rightChild;
  UpdateUpdateVector(leftChild->updateVector, currentNode->updateVector);
  UpdateUpdateVector(rightChild->updateVector, currentNode->updateVector);
  ApplyUpdates(leftChild, currentNode->updateVector);
  ApplyUpdates(rightChild, currentNode->updateVector);
  ResetUpdateVector(currentNode->updateVector);
}

void UpdateNode(node *currentNode, int l, int r, int i, int j){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l){
    return ;
  }
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd){
      ResetUpdateVector(newUpdateVector);
      newUpdateVector[i] = j;
      ApplyUpdates(currentNode, newUpdateVector);
      UpdateUpdateVector(currentNode->updateVector, newUpdateVector);
    }
    else{
      LazyUpdateChildren(currentNode);
      UpdateNode(currentNode->leftChild, l, r, i, j);
      UpdateNode(currentNode->rightChild, l, r, i, j);
      Combine(currentNode);
    }
  }
}

ll QueryNode(node *currentNode, int l, int r){
  ll ans = 0;
  if(r < currentNode->leftEnd || currentNode->rightEnd < l){
    ans = 0;
  }
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      ans = currentNode->ans;
    else{
      LazyUpdateChildren(currentNode);
      ans = QueryNode(currentNode->leftChild, l, r) + QueryNode(currentNode->rightChild, l, r);
      Combine(currentNode);
    }
  }
  return ans;
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void Initialise(){
  p10[0] = 1;
  for(int i = 1; i < B; i++)
    p10[i] = 10 * p10[i - 1];
}

int main(){
  int n, q;
  node *root;

  scanf("%d%d", &n, &q);
  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  Initialise();

  root = BuildSegmentTree(1, n);

  while(q--){
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    if(t == 1){
      int i, j;
      scanf("%d%d", &i, &j);
      UpdateNode(root, l, r, i, j);
    }
    else
      printf("%lld\n", QueryNode(root, l, r));
  }

  return 0;
}
