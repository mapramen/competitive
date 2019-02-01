#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

typedef struct node{
  int leftEnd;
  int rightEnd;
  int count;
  ll sum;
  node *leftChild;
  node *rightChild;
}node;

//---------------------------------------Merge Segment Tree---------------------------------------//
node *CreateNode(int leftEnd, int rightEnd, int count = 0, ll sum = 0ll, node *leftChild = NULL, node *rightChild = NULL){
  node *newNode = new node;
  newNode->leftEnd = leftEnd;
  newNode->rightEnd = rightEnd;
  newNode->count = count;
  newNode->sum = sum;
  newNode->leftChild = leftChild;
  newNode->rightChild = rightChild;
  return newNode;
}

void Combine(node *currentNode){
  if(currentNode == NULL){
    return ;
  }

  int count = 0;
  ll sum = 0;

  if(currentNode->leftChild){
    count += currentNode->leftChild->count;
    sum += currentNode->leftChild->sum;
  }

  if(currentNode->rightChild){
    count += currentNode->rightChild->count;
    sum += currentNode->rightChild->sum;
  }

  currentNode->count = count;
  currentNode->sum = sum;
}

node *Insert(node *currentNode, int l, int r, int i, ll &ans){
  if(i < l || r < i){
    if(r < i && currentNode != NULL){
      ans += currentNode->sum;
    }

    if(l > i && currentNode != NULL){
      ans += 1ll * i * currentNode->count;
    }
    return currentNode;
  }

  if(l == r || currentNode == NULL){
    currentNode = CreateNode(l, r, 1, 1ll * i);
  }

  if(l == r){
    return currentNode;
  }

  int mid = (l + r) / 2;
  currentNode->leftChild = Insert(currentNode->leftChild, l, mid, i, ans);
  currentNode->rightChild = Insert(currentNode->rightChild, mid + 1, r, i, ans);

  Combine(currentNode);

  return currentNode;
}

ll ComputeAns(node *leftChild, node *rightChild){
  if(leftChild != NULL && rightChild != NULL){
    return (rightChild->count) * (leftChild->sum);
  }
  else{
    return 0ll;
  }
}

node* Move(node *sourceNode, node *targetNode, ll &ans){
  if(sourceNode == targetNode || sourceNode == NULL){
    return targetNode;
  }

  if(targetNode == NULL){
    return sourceNode;
  }

  ans += ComputeAns(sourceNode->leftChild, targetNode->rightChild);
  ans += ComputeAns(targetNode->leftChild, sourceNode->rightChild);

  targetNode->leftChild = Move(sourceNode->leftChild, targetNode->leftChild, ans);
  targetNode->rightChild = Move(sourceNode->rightChild, targetNode->rightChild, ans);

  Combine(targetNode);

  free(sourceNode);

  return targetNode;
}
//------------------------------------Merge Segment Tree Ends------------------------------------//

node *root[N];
const int inf = 1E7;
map<int,int> M = {{-inf, 0}, {inf, 0}};

int Find(int x){
  int y = prev(M.upper_bound(x), 1)->first;
  if(x - y + 1 > M[y]){
    M[x] = 1;
    return x;
  }
  ++M[y];
  return y;
}

void Move(int y, int x, ll &ans){
  if(root[y]){
    ans += ((x - y) * (root[y]->sum));
  }
  root[x] = Move(root[y], root[x], ans);
  M[x] += M[y];
  M.erase(y);
}

int main(){
  int n;
  ll ans = 0;

  scanf("%d", &n);

  for(int temp = 1; temp <= n; ++temp){
    int z, i;
    scanf("%d%d", &z, &i);

    int x = Find(z);
    ans += (1ll * (x - z) * i);
    root[x] = Insert(root[x], 1, n, i, ans);

    for(int y = next(M.find(x))->first; y - x <= M[x]; y = next(M.find(x))->first){
      Move(y, x, ans);
    }

    for(int y = prev(M.find(x))->first; x - y <= M[y]; y = prev(M.find(x))->first){
      swap(x, y);
      Move(y, x, ans);
    }

    printf("%lld\n", ans);
  }

  return 0;
}
