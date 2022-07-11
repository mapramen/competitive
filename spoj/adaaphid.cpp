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
  ll key;
  int value;
  int ans;

  Node *leftChild;
  Node *rightChild;
};

int GetNodeAns(Node* a){
  return a == NULL ? 0 : a->ans;
}

void RefreshNodeData(Node* a){
  if(a == NULL){
    return;
  }
  a->ans = GetNodeAns(a->leftChild) + a->value + GetNodeAns(a->rightChild);
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

Node* ReBalance(Node* root, ll key){
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

Node* InsertNode(Node* root, ll key, int value){
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

  if(root->key == key){
    root->value += value;
  }
  else if(root->key < key){
    root->rightChild = InsertNode(root->rightChild, key, value);
  }
  else{
    root->leftChild = InsertNode(root->leftChild, key, value);
  }

  RefreshNodeData(root);
  return root;
}

Node* Insert(Node* root, ll key, int value){
  return ReBalance(InsertNode(root, key, value), key);
}

int Query(Node* root, ll key){
  if(root == NULL){
    return 0;
  }
  return root->key <= key
  ? GetNodeAns(root->leftChild) + root->value + Query(root->rightChild, key)
  : Query(root->leftChild, key);
}

int main(){
  int q;
  scanf("%d", &q);

  Node *root = NULL;
  ll ans = 0;
  while(q--){
    ll a, v;
    scanf("%lld%lld", &a, &v);
    a ^= ans, v ^= ans;

    root = Insert(root, a, v);
    ans = Query(root, a);

    printf("%lld %lld\n", a, ans);
  }

  return 0;
}