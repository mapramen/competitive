#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

mt19937 rnd(random_device{}());
uniform_int_distribution<int> dis(1, INT_MAX);

struct Node {
  int priority;
  int size;
  char value;

  Node* left;
  Node* right;

  Node(char c)
      : priority(dis(rnd)), size(1), value(c), left(NULL), right(NULL) {
  }
};

inline int size(Node* treap) {
  return treap ? treap->size : 0;
}

inline void RefreshData(Node* treap) {
  if (treap == NULL) {
    return;
  }

  treap->size = size(treap->left) + 1 + size(treap->right);
}

pair<Node*, Node*> Split(Node* treap, int index) {
  if (treap == NULL) {
    return {NULL, NULL};
  }

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

  if (left->priority < right->priority) {
    left->right = Meld(left->right, right);
    RefreshData(left);
    return left;
  }

  right->left = Meld(left, right->left);
  RefreshData(right);
  return right;
}

void Print(Node* root) {
  if (root == NULL) {
    return;
  }

  Print(root->left);
  printf("%c", root->value);
  Print(root->right);
}

char s[N];

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  scanf("%s", s);

  Node* root = NULL;
  for (int i = 1; i <= n; ++i) {
    root = Meld(root, new Node(s[i - 1]));
  }

  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);

    pair<Node*, Node*> leftSplit = Split(root, l - 1);
    pair<Node*, Node*> rightSplit = Split(leftSplit.second, r - l + 1);

    root = Meld(Meld(leftSplit.first, rightSplit.second), rightSplit.first);
  }

  Print(root);
  printf("\n");

  return 0;
}