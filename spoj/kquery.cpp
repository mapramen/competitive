#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 30001

class Node {
  public:
  Node(int _l, int _r){
    l = _l, r = _r, val = 0;
    leftChild = NULL, rightChild = NULL;
  }

  Node* Insert(int i){
    if(i < l || r < i){
      return this;
    }

    if(l == i && r == i){
      return new Node(l, r, val + 1);
    }

    CreateChildNodesIfNeeded();

    return new Node(l, r, val + 1, leftChild->Insert(i), rightChild->Insert(i));
  }

  int Query(int i){
    if(r <= i){
      return 0;
    }

    if(i < l){
      return val;
    }

    CreateChildNodesIfNeeded();

    return leftChild->Query(i) + rightChild->Query(i);
  }

  private:
  int l;
  int r;
  int val;

  Node* leftChild;
  Node* rightChild;

  void CreateChildNodesIfNeeded(){
    if(leftChild == NULL){
      int mid = (l + r) / 2;
      leftChild = new Node(l, mid);
      rightChild = new Node(mid + 1, r);
    }
  }

  Node(int _l, int _r, int _val, Node* _leftChild = NULL, Node* _rightChild = NULL){
    l = _l, r = _r, val = _val;
    leftChild = _leftChild, rightChild = _rightChild;
  }
};

Node* roots[N];

int main(){
  int n;
  scanf("%d", &n);

  roots[0] = new Node(1, 1E9);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    roots[i] = roots[i - 1]->Insert(x);
  }

  int q;
  scanf("%d", &q);

  while(q--){
    int l, r, i;
    scanf("%d%d%d", &l, &r, &i);
    printf("%d\n", roots[r]->Query(i) - roots[l - 1]->Query(i));
  }
  
  return 0;
}