#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 30001

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
  if(r <= k){
    return 0;
  }

  if(k < l){
    return GetCount(a, b);
  }

  int mid = l + (r - l) / 2;
  return Query(l, mid, GetLeftChild(a), GetLeftChild(b), k) + Query(mid + 1, r, GetRightChild(a), GetRightChild(b), k);
}

Node* roots[N];

int main(){
  int n;
  scanf("%d", &n);

  roots[0] = new Node(0);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    roots[i] = Insert(0, 1E9, roots[i - 1], x);
  }

  int q;
  scanf("%d", &q);

  int ans = 0;
  while(q--){
    int l, r, i;
    scanf("%d%d%d", &l, &r, &i);
    l ^= ans, r ^= ans, i ^= ans;

    if(l < 1){
      l = 1;
    }

    if(r > n){
      r = n;
    }

    ans = r < l ? 0 : Query(0, 1E9, roots[l - 1], roots[r], i);
    printf("%d\n", ans);
  }
  
  return 0;
}