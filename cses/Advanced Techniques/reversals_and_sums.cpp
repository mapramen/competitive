#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

mt19937 rnd(random_device{}());
uniform_int_distribution<int> dis(1, INT_MAX);

struct Node {
  int priority;
  int size;
  int value;
  ll sum;
  bool invert;

  Node* left;
  Node* right;

  Node(int val)
      : priority(dis(rnd)), size(1), value(val), sum(val), left(NULL), right(NULL) {
  }
};

inline int size(Node* treap) {
  return treap ? treap->size : 0;
}

inline long long sum(Node* treap) {
  return treap ? treap->sum : 0;
}

inline void RefreshData(Node* treap) {
  if (treap == NULL) {
    return;
  }

  treap->size = size(treap->left) + 1 + size(treap->right);
  treap->sum = sum(treap->left) + treap->value + sum(treap->right);
}

void UpdateNode(Node* treap) {
  if (treap == NULL) {
    return;
  }
  treap->invert = !treap->invert;
}

void LazyUpdateChildren(Node* treap) {
  if (treap == NULL || !treap->invert) {
    return;
  }

  swap(treap->left, treap->right);
  UpdateNode(treap->left);
  UpdateNode(treap->right);
  treap->invert = false;
}

pair<Node*, Node*> Split(Node* treap, int index) {
  if (treap == NULL) {
    return {NULL, NULL};
  }

  LazyUpdateChildren(treap);

  if (size(treap->left) < index) {
    pair<Node*, Node*> rightSplit = Split(treap->right, index - size(treap->left) - 1);
    treap->right = rightSplit.first;
    RefreshData(treap);
    return {treap, rightSplit.second};
  }

  pair<Node*, Node*> leftSplit = Split(treap->left, index);
  treap->left = leftSplit.second;
  RefreshData(treap);
  return {leftSplit.first, treap};
}

Node* Meld(Node* left, Node* right) {
  if (left == NULL) {
    return right;
  }

  if (right == NULL) {
    return left;
  }

  LazyUpdateChildren(left);
  LazyUpdateChildren(right);

  if (left->priority < right->priority) {
    left->right = Meld(left->right, right);
    RefreshData(left);
    return left;
  }

  right->left = Meld(left, right->left);
  RefreshData(right);
  return right;
}

ll Query(Node* treap, int l, int ql, int qr) {
  if (treap == NULL) {
    return 0;
  }

  int r = l + size(treap) - 1;

  if (qr < l || r < ql) {
    return 0;
  }

  if (ql <= l && r <= qr) {
    return sum(treap);
  }

  LazyUpdateChildren(treap);

  int i = l + size(treap->left);
  if (qr < i) {
    return Query(treap->left, l, ql, qr);
  }

  if (i < ql) {
    return Query(treap->right, i + 1, ql, qr);
  }

  return Query(treap->left, l, ql, qr) + (treap->value) + Query(treap->right, i + 1, ql, qr);
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  Node* root = NULL;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    root = Meld(root, new Node(x));
  }

  while (q--) {
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);

    if (t == 1) {
      pair<Node*, Node*> leftSplit = Split(root, l - 1);
      pair<Node*, Node*> rightSplit = Split(leftSplit.second, r - l + 1);
      UpdateNode(rightSplit.first);
      root = Meld(leftSplit.first, Meld(rightSplit.first, rightSplit.second));
    } else {
      printf("%lld\n", Query(root, 1, l, r));
    }
  }

  return 0;
}