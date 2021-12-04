#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

mt19937 rnd(random_device{}());
uniform_int_distribution<int> dis(1, INT_MAX);

struct Node
{
  int priority;
  ll value;
  int lazyMul;
  ll lazyAdd;
  int count;

  Node *leftChild;
  Node *rightChild;
};

void UpdateNode(Node* node, int mul, ll add){
  if(node == NULL){
    return;
  }

  if(mul == -1){
    node->value *= -1;
    node->lazyMul *= -1;
    node->lazyAdd *= -1;

    swap(node->leftChild, node->rightChild);
  }

  if(add != 0){
    node->value += add;
    node->lazyAdd += add;
  }
}

void LazyUpdateChildren(Node* node){
  if(node == NULL){
    return;
  }

  UpdateNode(node->leftChild, node->lazyMul, node->lazyAdd);
  UpdateNode(node->rightChild, node->lazyMul, node->lazyAdd);

  node->lazyMul = 1;
  node->lazyAdd = 0;
}

Node* InsertWithPriority(Node* root, ll value, int count, int priority){
  if(root == NULL){
    Node* node = new Node();

    node->priority = priority;

    node->value = value;
    node->lazyMul = 1;
    node->lazyAdd = 0;
    node->count = count;
    
    node->leftChild = NULL;
    node->rightChild = NULL;
    
    return node;
  }

  LazyUpdateChildren(root);

  if(root->value == value){
    root->priority = priority;
    root->count += count;
    return root;
  }

  if(value < root->value){
    Node* leftChild = InsertWithPriority(root->leftChild, value, count, priority);
    root->leftChild = leftChild;
    if(leftChild->priority < root->priority){
      LazyUpdateChildren(leftChild);
      root->leftChild = leftChild->rightChild;
      leftChild->rightChild = root;
      return leftChild;
    }
    return root;
  }

  Node* rightChild = InsertWithPriority(root->rightChild, value, count, priority);
  root->rightChild = rightChild;
  if(rightChild->priority < root->priority){
    LazyUpdateChildren(rightChild);
    root->rightChild = rightChild->leftChild;
    rightChild->leftChild = root;
    return rightChild;
  }
  
  return root;
}

Node* Insert(Node *root, ll value){
  return InsertWithPriority(root, value, 1, dis(rnd));
}

// <=, >
pair<Node*,Node*> Split(Node* root, ll value){
  root = InsertWithPriority(root, value, 0, INT_MIN);

  Node* right = root->rightChild;
  root->rightChild = NULL;

  return {root, right};
}

int GetCount(Node* root){
  if(root == NULL){
    return 0;
  }

  LazyUpdateChildren(root);
  if(root->value == 0){
    return root->count;
  }

  if(root->value > 0){
    return GetCount(root->leftChild);
  }

  return GetCount(root->rightChild);
}

ll Solve(){
  int n;
  scanf("%d", &n);

  Node *root = NULL;

  ll ans = 0;
  while(n--){
    ll x;
    scanf("%lld", &x);
    
    UpdateNode(root, -1, 0ll);
    UpdateNode(root, 1, x);
    root = Insert(root, x);

    ans += GetCount(root);

    root = Split(root, -1).second;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}