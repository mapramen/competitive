#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001

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

pii Query(int l, int r, Node* a, Node* b){
  if(l == r){
    return {l, GetCount(a, b)};
  }

  int mid = l + (r - l) / 2;

  int leftCount = GetCount(GetLeftChild(a), GetLeftChild(b));
  int rightCount = GetCount(GetRightChild(a), GetRightChild(b));
  
  return leftCount > rightCount
    ? Query(l, mid, GetLeftChild(a), GetLeftChild(b))
    : Query(mid + 1, r, GetRightChild(a), GetRightChild(b));
}

Node* roots[N];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  roots[0] = new Node(0);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    roots[i] = Insert(1, m, roots[i - 1], x);
  }

  int q;
  scanf("%d", &q);

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    
    int color, cnt;
    tie(color, cnt) = Query(1, m, roots[l - 1], roots[r]);

    if(2 * cnt <= r - l + 1){
      printf("no\n");
    }
    else{
      printf("yes %d\n", color);
    }
  }
  
  return 0;
}