#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001
#define MOD 1000000007

int ModularExponentation(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int ModularInverse(int a){
  return ModularExponentation(a, MOD - 2);
}

struct Node{
  int count;
  int ans;
  Node* leftChild;
  Node* rightChild;

  Node(int count = 0, int ans = 1, Node* leftChild = NULL, Node* rightChild = NULL){
    this->count = count;
    this->ans = ans;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
  }
};

int GetCount(Node* a){
  return a == NULL ? 0 : a->count;
}

int GetAns(Node* a){
  return a == NULL ? 1 : a->ans;
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
    return new Node(GetCount(node) + 1, (1ll * GetAns(node) * x) % MOD);
  }

  int mid = l + (r - l) / 2;

  return new Node(
    GetCount(node) + 1,
    (1ll * GetAns(node) * x) % MOD,
    Insert(GetLeftChild(node), l, mid, x),
    Insert(GetRightChild(node), mid + 1, r, x));
}

pii Query(Node* a, Node* b, int l, int r, int h){
  int cnt = GetCount(a, b);
  if(h < l || cnt == 0){
    return {0, 1};
  }

  if(r <= h){
    return {cnt, (1ll * GetAns(b) * ModularInverse(GetAns(a))) % MOD};
  }

  int mid = l + (r - l) / 2;

  pii left_ans = Query(GetRightChild(a), GetRightChild(b), mid + 1, r, h);
  pii right_ans = Query(GetLeftChild(a), GetLeftChild(b), l, mid, h);

  return {left_ans.first + right_ans.first, (1ll * left_ans.second * right_ans.second) % MOD};
}

Node* roots[N];

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    roots[i] = Insert(roots[i - 1], 1, N, x);
  }

  while(q--){
    int l, r, h;
    scanf("%d%d%d", &l, &r, &h);
    ++l, ++r;

    pii query_ans = Query(roots[l - 1], roots[r], 1, N, h);
    printf("%d\n", query_ans.first != 0 ? query_ans.second : 1);
  }

  return 0;
}