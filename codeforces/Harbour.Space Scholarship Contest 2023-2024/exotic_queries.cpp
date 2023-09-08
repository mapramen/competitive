#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001
#define M (1 << 21)

vector<vector<int>> V(N), events(N);

struct Node {
  int count;
  Node* leftChild;
  Node* rightChild;

  Node(int count = 0, Node* leftChild = NULL, Node* rightChild = NULL) {
    this->count = count;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
  }
};

int GetCount(Node* a) {
  return a == NULL ? 0 : a->count;
}

int GetCount(Node* a, Node* b) {
  return GetCount(b) - GetCount(a);
}

Node* GetLeftChild(Node* a) {
  return a == NULL ? NULL : a->leftChild;
}

Node* GetRightChild(Node* a) {
  return a == NULL ? NULL : a->rightChild;
}

Node* Insert(int l, int r, Node* node, int i, int x) {
  if (i < l || r < i) {
    return node;
  }

  if (l == r) {
    return new Node(GetCount(node) + x);
  }

  int mid = l + (r - l) / 2;

  return new Node(
      GetCount(node) + x,
      Insert(l, mid, GetLeftChild(node), i, x),
      Insert(mid + 1, r, GetRightChild(node), i, x));
}

int Query(Node* root, int l, int r, int i) {
  if (i < l) {
    return 0;
  }

  if (r <= i) {
    return GetCount(root);
  }

  int mid = l + (r - l) / 2;
  return Query(GetLeftChild(root), l, mid, i) + Query(GetRightChild(root), mid + 1, r, i);
}

Node* roots[N + 1];

int T[M];

void Update(int k, int l, int r, int i, int x) {
  if (i < l || r < i) {
    return;
  }

  if (i == l && r == i) {
    T[k] = x;
    return;
  }

  int mid = (l + r) / 2;
  Update(2 * k + 1, l, mid, i, x);
  Update(2 * k + 2, mid + 1, r, i, x);
  T[k] = max(T[2 * k + 1], T[2 * k + 2]);
}

int Query(int k, int l, int r, int ql, int qr) {
  if (qr < l || r < ql || qr < ql) {
    return 0;
  }

  if (ql <= l && r <= qr) {
    return T[k];
  }

  int mid = (l + r) / 2;
  return max(Query(2 * k + 1, l, mid, ql, qr), Query(2 * k + 2, mid + 1, r, ql, qr));
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    V[x].push_back(i);
  }

  for (int x = 1; x <= n; ++x) {
    int l = n + 1;
    for (int r : V[x]) {
      int y = Query(0, 1, n, l + 1, r - 1);
      events[y].push_back(x);
      l = r;

      Update(0, 1, n, r, x);
    }
  }

  for (int x = n; x > 0; --x) {
    Node* root = roots[x + 1];
    if (!V[x].empty()) {
      root = Insert(1, n, root, x, 1);
    }

    for (int y : events[x]) {
      root = Insert(1, n, root, y, 1);
    }

    roots[x] = root;
  }

  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", Query(roots[l], 1, n, r));
  }

  return 0;
}