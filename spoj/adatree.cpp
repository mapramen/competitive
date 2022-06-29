#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001
#define MAXA 1000000

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

void Query(Node* a, Node* b, int l, int r, int h, int& ans){
  if(ans != 0 || h < l || GetCount(a, b) == 0){
    return;
  }

  if(l == r){
    ans = l;
    return;
  }

  int mid = l + (r - l) / 2;

  Query(GetRightChild(a), GetRightChild(b), mid + 1, r, h, ans);
  Query(GetLeftChild(a), GetLeftChild(b), l, mid, h, ans);
}

Node* roots[N];

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    roots[i] = Insert(roots[i - 1], 1, MAXA, x);
  }

  while(q--){
    int l, r, h;
    scanf("%d%d%d", &l, &r, &h);
    ++l, ++r;

    int ans = 0;
    Query(roots[l - 1], roots[r], 1, MAXA, h, ans);

    printf("%d\n", ans);
  }

  return 0;
}