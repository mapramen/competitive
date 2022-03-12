#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

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

Node* Insert(int l, int r, Node* node, int x){
  if(x < l || r < x){
    return node;
  }

  if(l == r){
    return new Node(GetCount(node) + 1);
  }

  int mid = l + (r - l) / 2;

  return new Node(
    GetCount(node) + 1,
    Insert(l, mid, GetLeftChild(node), x),
    Insert(mid + 1, r, GetRightChild(node), x));
}

int Query(int l, int r, Node* a, Node* b, int k){
  if(l == r){
    return l;
  }

  int mid = l + (r - l) / 2;

  int c = GetCount(GetLeftChild(a), GetLeftChild(b));

  return k <= c
    ? Query(l, mid, GetLeftChild(a), GetLeftChild(b), k)
    : Query(mid + 1, r, GetRightChild(a), GetRightChild(b), k - c);
}

Node* roots[N];

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  roots[0] = new Node();

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    roots[i] = Insert(-1E9, 1E9, roots[i - 1], x);
  }

  while(q--){
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", Query(-1E9, 1E9, roots[l - 1], roots[r], k));
  }
  
  return 0;
}