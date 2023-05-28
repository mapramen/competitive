#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

int INF = 1E9;

mt19937 rnd(random_device{}());
uniform_int_distribution<int> dis(1, INT_MAX);

struct Node {
  int priority;
  int count;
  int value;
  ll sum;
  bool invert;

  Node* leftChild;
  Node* rightChild;
};

int GetCount(Node* a) {
  return a == NULL ? 0 : a->count;
}

ll GetSum(Node* a) {
  return a == NULL ? 0 : a->sum;
}

void RefreshNodeData(Node* a) {
  if (a == NULL) {
    return;
  }
  a->count = GetCount(a->leftChild) + 1 + GetCount(a->rightChild);
  a->sum = GetSum(a->leftChild) + a->value + GetSum(a->rightChild);
}

void UpdateNode(Node* a) {
  if (a == NULL) {
    return;
  }

  a->invert = !a->invert;
}

void LazyUpdate(Node* a) {
  if (a == NULL || !a->invert) {
    return;
  }

  a->invert = false;

  Node* leftChild = a->leftChild;
  a->leftChild = a->rightChild;
  a->rightChild = leftChild;

  UpdateNode(a->leftChild);
  UpdateNode(a->rightChild);

  RefreshNodeData(a);
}

Node* Meld(Node* a, Node* b) {
  if (a == NULL) {
    return b;
  }

  if (b == NULL) {
    return a;
  }

  LazyUpdate(a);
  LazyUpdate(b);

  Node* c;
  if (a->priority < b->priority) {
    a->rightChild = Meld(a->rightChild, b);
    c = a;
  } else {
    b->leftChild = Meld(a, b->leftChild);
    c = b;
  }

  RefreshNodeData(c);
  return c;
}

Node* ReBalance(Node* root, int index) {
  if (root == NULL) {
    return NULL;
  }

  LazyUpdate(root);

  int cnt = GetCount(root->leftChild) + 1;

  if (index < cnt) {
    Node* leftChild = ReBalance(root->leftChild, index);
    if (leftChild->priority < root->priority) {
      root->leftChild = leftChild->rightChild;
      RefreshNodeData(root);

      leftChild->rightChild = root;
      root = leftChild;
    } else {
      root->leftChild = leftChild;
    }
  }

  if (index > cnt) {
    Node* rightChild = ReBalance(root->rightChild, index - cnt);
    if (rightChild->priority < root->priority) {
      root->rightChild = rightChild->leftChild;
      RefreshNodeData(root);

      rightChild->leftChild = root;
      root = rightChild;
    } else {
      root->rightChild = rightChild;
    }
  }

  RefreshNodeData(root);
  return root;
}

Node* InsertNode(Node* root, int index, int value) {
  if (root == NULL) {
    Node* new_node = new Node();
    new_node->priority = dis(rnd);
    new_node->value = value;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    new_node->invert = false;

    RefreshNodeData(new_node);
    return new_node;
  }

  LazyUpdate(root);

  int cnt = GetCount(root->leftChild) + 1;
  if (cnt < index) {
    root->rightChild = InsertNode(root->rightChild, index - cnt, value);
  } else {
    root->leftChild = InsertNode(root->leftChild, index, value);
  }

  RefreshNodeData(root);
  return root;
}

void AssignMostPriority(Node* root, int index) {
  if (root == NULL) {
    return;
  }

  LazyUpdate(root);

  int cnt = GetCount(root->leftChild) + 1;

  if (cnt == index) {
    root->priority = INT_MIN;
  } else if (cnt < index) {
    AssignMostPriority(root->rightChild, index - cnt);
  } else {
    AssignMostPriority(root->leftChild, index);
  }
}

tuple<Node*, Node*, Node*> Split(Node* root, int index) {
  if (root == NULL) {
    return {NULL, NULL, NULL};
  }

  AssignMostPriority(root, index);
  root = ReBalance(root, index);

  Node* left = root->leftChild;
  Node* right = root->rightChild;

  root->leftChild = NULL;
  root->rightChild = NULL;

  root->priority = dis(rnd);
  RefreshNodeData(root);

  return {left, root, right};
}

Node* Insert(Node* root, int index, int value) {
  return ReBalance(InsertNode(root, index, value), index);
}

ll Query(Node* root, int i) {
  if (root == NULL) {
    return 0;
  }

  LazyUpdate(root);

  int cnt = GetCount(root->leftChild) + 1;
  return cnt <= i
             ? GetSum(root->leftChild) + root->value + Query(root->rightChild, i - cnt)
             : Query(root->leftChild, i);
}

ll Query(Node* root, int l, int r) {
  return Query(root, r) - Query(root, l - 1);
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  Node* root = NULL;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    root = Insert(root, i, x);
  }

  while (q--) {
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);

    if (t == 1) {
      if (l == r) {
        continue;
      }

      auto [l1, x, r1] = Split(root, l);
      auto [l2, y, r2] = Split(r1, r - l);

      UpdateNode(l2);
      root = Meld(l1, Meld(y, Meld(l2, Meld(x, r2))));
    } else {
      printf("%lld\n", Query(root, l, r));
    }
  }

  return 0;
}