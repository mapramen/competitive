#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define B 4

mt19937 rnd(random_device{}());
uniform_int_distribution<int> dis(1, INT_MAX);

struct Node
{
  int priority;
  int key;
  int value;
  int ans;

  Node *leftChild;
  Node *rightChild;
};

int GetNodeAns(Node* a){
  return a == NULL ? INT_MAX : a->ans;
}

void RefreshNodeData(Node* a){
  if(a == NULL){
    return;
  }
  a->ans = min(a->value, min(GetNodeAns(a->leftChild), GetNodeAns(a->rightChild)));
}

Node* Meld(Node* a, Node* b){
  if(a == NULL){
    return b;
  }

  if(b == NULL){
    return a;
  }

  Node* c;
  if(a->priority < b->priority){
    a->rightChild = Meld(a->rightChild, b);
    c = a;
  }
  else{
    b->leftChild = Meld(a, b->leftChild);
    c = b;
  }

  RefreshNodeData(c);
  return c;
}

Node* ReBalance(Node* root, int key){
  if(root == NULL){
    return NULL;
  }
  
  if(key < root->key){
    Node* leftChild = ReBalance(root->leftChild, key);
    if(leftChild->priority < root->priority){
      root->leftChild = leftChild->rightChild;
      RefreshNodeData(root);

      leftChild->rightChild = root;
      root = leftChild;
    }
    else{
      root->leftChild = leftChild;
    }
  }

  if(key > root->key){
    Node* rightChild = ReBalance(root->rightChild, key);
    if(rightChild->priority < root->priority){
      root->rightChild = rightChild->leftChild;
      RefreshNodeData(root);

      rightChild->leftChild = root;
      root = rightChild;
    }
    else{
      root->rightChild = rightChild;
    }
  }

  RefreshNodeData(root);
  return root;
}

Node* InsertNode(Node* root, int key, int value){
  if(root == NULL){
    Node *new_node = new Node();
    new_node->priority = dis(rnd);
    new_node->key = key;
    new_node->value = value;
    new_node->ans = value;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;

    RefreshNodeData(new_node);
    return new_node;
  }

  if(root->key < key){
    root->rightChild = InsertNode(root->rightChild, key, value);
  }
  else{
    root->leftChild = InsertNode(root->leftChild, key, value);
  }

  RefreshNodeData(root);
  return root;
}

Node* Insert(Node* root, int key, int value){
  return ReBalance(InsertNode(root, key, value), key);
}

int Query(Node* root, int key){
  if(root == NULL){
    return INT_MAX;
  }

  return root->key <= key
  ? min(min(GetNodeAns(root->leftChild), root->value), Query(root->rightChild, key))
  : Query(root->leftChild, key);
}

int a[B][N];
Node* roots[N];

void Update(int i, int x, int y){
  for( ; i < N; i += (i & -i)){
    roots[i] = Insert(roots[i], x, y);
  }
}

bool Query(int i, int x, int y){
  bool ans = true;
  for( ; i != 0; i -= (i & -i)){
    ans = ans && y < Query(roots[i], x);
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    for(int j = 0; j < B; ++j){
      scanf("%d", &a[j][i]);
    }
  }

  vector<int> idxs(n);
  iota(idxs.begin(), idxs.end(), 1);
  sort(idxs.begin(), idxs.end(), [](int i, int j) { return a[0][i] < a[0][j]; });

  int ans = 0;
  for(int i: idxs){
    ans += Query(a[1][i], a[2][i], a[3][i]);
    Update(a[1][i], a[2][i], a[3][i]);
  }

  printf("%d\n", ans);

  return 0;
}