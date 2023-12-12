#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 300001

char op[2];

struct Node {
  int lazy_value;
  ll sum;
  Node* left_child;
  Node* right_child;

  Node(int lazy_value, ll sum, Node* left_child = NULL, Node* right_child = NULL) {
    this->lazy_value = lazy_value;
    this->sum = sum;
    this->left_child = left_child;
    this->right_child = right_child;
  }
};

int GetLazyValue(Node* a) {
  return a == NULL ? 0 : a->lazy_value;
}

ll GetSum(Node* a) {
  return a == NULL ? 0 : a->sum;
}

Node* GetLeftChild(Node* a) {
  return a == NULL ? NULL : a->left_child;
}

Node* GetRightChild(Node* a) {
  return a == NULL ? NULL : a->right_child;
}

Node* GetUpdatedNode(Node* node, int l, int r, int x) {
  if (x == 0) {
    return node;
  }

  return new Node(
      GetLazyValue(node) + x,
      GetSum(node) + 1ll * (r - l + 1) * x,
      GetLeftChild(node),
      GetRightChild(node));
}

Node* Insert(Node* node, int l, int r, int ql, int qr, int x) {
  if (qr < l || r < ql) {
    return node;
  }

  if (ql <= l && r <= qr) {
    return GetUpdatedNode(node, l, r, x);
  }

  int mid = l + (r - l) / 2;

  Node* left_child = GetUpdatedNode(GetLeftChild(node), l, mid, GetLazyValue(node));
  Node* right_child = GetUpdatedNode(GetRightChild(node), mid + 1, r, GetLazyValue(node));

  left_child = Insert(left_child, l, mid, ql, qr, x);
  right_child = Insert(right_child, mid + 1, r, ql, qr, x);

  return new Node(0, GetSum(left_child) + GetSum(right_child), left_child, right_child);
}

ll Query(Node* node, int l, int r, int ql, int qr, int x = 0) {
  if (qr < l || r < ql) {
    return 0;
  }

  if (ql <= l && r <= qr) {
    return GetSum(node) + 1ll * (r - l + 1) * x;
  }

  int mid = l + (r - l) / 2;

  return Query(GetLeftChild(node), l, mid, ql, qr, x + GetLazyValue(node)) +
         Query(GetRightChild(node), mid + 1, r, ql, qr, x + GetLazyValue(node));
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  Node* root = NULL;

  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    root = Insert(root, 1, n, i, i, x);
  }

  vector<Node*> roots{root};

  scanf("%d", &q);

  while (q--) {
    scanf("%s", op);

    if (op[0] == 'C') {
      int l, r, d;
      scanf("%d%d%d", &l, &r, &d);
      root = Insert(root, 1, n, l, r, d);
      roots.push_back(root);
      continue;
    }

    if (op[0] == 'Q') {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%lld\n", Query(root, 1, n, l, r));
      continue;
    }

    if (op[0] == 'H') {
      int l, r, t;
      scanf("%d%d%d", &l, &r, &t);
      printf("%lld\n", Query(roots[t], 1, n, l, r));
      continue;
    }

    if (op[0] == 'B') {
      int t;
      scanf("%d", &t);
      roots.resize(t + 1);
      root = roots[t];
    }
  }

  return 0;
}