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
  char value;

  Node* leftChild;
  Node* rightChild;
};

int GetCount(Node* a) {
  return a == NULL ? 0 : a->count;
}

void RefreshNodeData(Node* a) {
  if (a == NULL) {
    return;
  }
  a->count = GetCount(a->leftChild) + 1 + GetCount(a->rightChild);
}

Node* Meld(Node* a, Node* b) {
  if (a == NULL) {
    return b;
  }

  if (b == NULL) {
    return a;
  }

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

Node* InsertNode(Node* root, int index, char value) {
  if (root == NULL) {
    Node* new_node = new Node();
    new_node->priority = dis(rnd);
    new_node->value = value;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;

    RefreshNodeData(new_node);
    return new_node;
  }

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

  int cnt = GetCount(root->leftChild) + 1;

  if (cnt == index) {
    root->priority = INT_MIN;
  } else if (cnt < index) {
    AssignMostPriority(root->rightChild, index - cnt);
  } else {
    AssignMostPriority(root->leftChild, index);
  }
}

pair<Node*, Node*> Split(Node* root, int index) {
  AssignMostPriority(root, index);
  root = ReBalance(root, index);

  Node* left = root->leftChild;

  root->leftChild = NULL;
  root->priority = 0;
  RefreshNodeData(root);

  return {left, root};
}

Node* Insert(Node* root, int index, char value) {
  return ReBalance(InsertNode(root, index, value), index);
}

void Print(Node* root) {
  if (root == NULL) {
    return;
  }

  Print(root->leftChild);
  printf("%c", root->value);
  Print(root->rightChild);
}

char s[N];

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  scanf("%s", s);

  Node* root = NULL;
  for (int i = 1; i <= n; ++i) {
    root = Insert(root, i, s[i - 1]);
  }

  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);

    if (r == n) {
      continue;
    }

    auto [l1, r1] = Split(root, l);
    auto [l2, r2] = Split(r1, r - l + 2);

    root = Meld(l1, Meld(r2, l2));
  }

  Print(root);
  printf("\n");

  return 0;
}