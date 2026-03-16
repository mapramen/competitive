#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

mt19937 rnd(random_device{}());
uniform_int_distribution<int> dis(1, INT_MAX);

const pii INF_MIN_DATA = {INT_MAX, 0};

struct Node {
  int priority;
  int size;
  int value;
  int min_value;
  bool invert;

  Node* left;
  Node* right;

  Node(int val)
      : priority(dis(rnd)), size(1), value(val), left(NULL), right(NULL) {
    min_value = val;
  }
};

inline int size(Node* treap) {
  return treap ? treap->size : 0;
}

inline int min_value(Node* treap) {
  return treap ? treap->min_value : INT_MAX;
}

inline void RefreshData(Node* treap) {
  if (treap == NULL) {
    return;
  }

  treap->size = 1 + size(treap->left) + size(treap->right);
  treap->min_value = min(treap->value, min(min_value(treap->left), min_value(treap->right)));
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

int Query(Node* treap, int l) {
  if (treap == NULL) {
    return 0;
  }

  LazyUpdateChildren(treap);

  int i = l + size(treap->left);

  int min_val = min_value(treap);
  if (min_val == treap->value) {
    return i;
  }

  if (min_val == min_value(treap->left)) {
    return Query(treap->left, l);
  }

  return Query(treap->right, i + 1);
}

int main() {
  int n;
  scanf("%d", &n);

  Node* root = NULL;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    root = Meld(root, new Node(x));
  }

  printf("%d\n", n);
  for (int l = 1; l <= n; ++l) {
    int i = Query(root, 1);

    int r = l + i - 1;
    printf("%d %d\n", l, r);

    pair<Node*, Node*> leftSplit = Split(root, i - 1);
    pair<Node*, Node*> rightSplit = Split(leftSplit.second, 1);
    UpdateNode(leftSplit.first);
    root = Meld(leftSplit.first, rightSplit.second);
  }

  return 0;
}