#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1100001
#define MOD 100000
#define MAX_PRINT_COUNT 100

struct Node{
  int count;
  Node* leftChild;
  Node* rightChild;

  Node(int count = 0, Node* leftChild = NULL, Node* rightChild = NULL){
    this->count = count;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
  }
};

int GetCount(Node *a){
  return a == NULL ? 0 : a->count;
}

int GetCount(Node* a, Node* b){
  return GetCount(b) - GetCount(a);
}

Node* GetLeftChild(Node* a){
  return a == NULL ? NULL : a->leftChild;
}

Node* GetRightChild(Node* a){
  return a == NULL ? NULL : a->rightChild;
}

Node* Insert(Node* node, int l, int r, int x){
  if(x < l || r < x){
    return node;
  }

  if(l == r){
    return new Node(GetCount(node) + 1);
  }

  int mid = l + (r - l) / 2;

  return new Node(
    GetCount(node) + 1,
    Insert(GetLeftChild(node), l, mid, x),
    Insert(GetRightChild(node), mid + 1, r, x));
}

void Print(int x, int cnt){
  while(cnt--){
    printf("%d ", x);
  }
}

void Query(Node* a, Node* b, int l, int r, int cnt){
  cnt = min(cnt, GetCount(a, b));

  if(cnt == 0){
    return;
  }

  if(l == r){
    Print(l, cnt);
  }

  int mid = l + (r - l) / 2;

  int left_cnt = GetCount(GetLeftChild(a), GetLeftChild(b));
  
  Query(GetLeftChild(a), GetLeftChild(b), l, mid, cnt);
  Query(GetRightChild(a), GetRightChild(b), mid + 1, r, max(0, cnt - left_cnt));
}

Node* roots[N];

void Initialize(){
  roots[0] = new Node(0);

  for(int i = 1, a = -1, b = 1; i < N; ++i){
    tie(a, b) = make_pair(b, (a + b) % MOD);
    roots[i] = Insert(roots[i - 1], 0, MOD - 1, b);
  }
}

void Solve(){
  int l, r;
  scanf("%d%d", &l, &r);
  r += l;

  Query(roots[l - 1], roots[r], 0, MOD - 1, MAX_PRINT_COUNT);
  printf("\n");
}

int main(){
  Initialize();
  
  int t;
  scanf("%d", &t);

  for(int k = 1; k <= t; ++k){
    printf("Case %d: ", k);
    Solve();
  }

  return 0;
}