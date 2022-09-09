#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

mt19937 rnd(random_device{}());
uniform_int_distribution<int> dis(1, INT_MAX);

struct NodeData
{
  int ans;
};

struct Node
{
  int priority;
  int count;
  int value;
  NodeData nodeData;

  Node *leftChild;
  Node *rightChild;
};

NodeData CreateNodeData(int value){
  return {value};
}

int GetCount(Node* a){
  return a == NULL ? 0 : a->count;
}

NodeData CombineNodeData(NodeData left, NodeData right){
  return {
    max(left.ans, right.ans)
  };
}

NodeData CombineNodeData(Node* a, Node* b){
  if(a == NULL){
    return b->nodeData;
  }

  if(b == NULL){
    return a->nodeData;
  }

  return CombineNodeData(a->nodeData, b->nodeData);
}

void RefreshNodeData(Node* a){
  if(a == NULL){
    return;
  }

  a->count = GetCount(a->leftChild) + 1 + GetCount(a->rightChild);
  a->nodeData = CreateNodeData(a->value);
  a->nodeData = CombineNodeData(a->leftChild, a);
  a->nodeData = CombineNodeData(a, a->rightChild);
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

Node* ReBalance(Node* root, int index){
  if(root == NULL){
    return NULL;
  }

  int cnt = GetCount(root->leftChild) + 1;
  
  if(index < cnt){
    Node* leftChild = ReBalance(root->leftChild, index);
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

  if(index > cnt){
    Node* rightChild = ReBalance(root->rightChild, index - cnt);
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

Node* InsertNode(Node* root, int index, int value){
  if(root == NULL){
    Node *new_node = new Node();
    new_node->priority = dis(rnd);
    new_node->value = value;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;

    RefreshNodeData(new_node);
    return new_node;
  }

  int cnt = GetCount(root->leftChild) + 1;
  if(cnt < index){
    root->rightChild = InsertNode(root->rightChild, index - cnt, value);
  }
  else{
    root->leftChild = InsertNode(root->leftChild, index, value);
  }

  RefreshNodeData(root);
  return root;
}

Node* Insert(Node* root, int index, int value){
  return ReBalance(InsertNode(root, index, value), index);
}

NodeData outside_range_ans = {INT_MIN};

NodeData Query(Node* root, int l, int ql, int qr){
  if(root == NULL){
    return outside_range_ans;
  }

  int r = l + GetCount(root) - 1;
  if(qr < l || r < ql){
    return outside_range_ans;
  }

  if(ql <= l && r <= qr){
    return root->nodeData;
  }

  int node_index = l + GetCount(root->leftChild);

  NodeData left = Query(root->leftChild, l, ql, qr);
  NodeData mid = ql <= node_index && node_index <= qr ? CreateNodeData(root->value) : outside_range_ans;
  NodeData right = Query(root->rightChild, node_index + 1, ql, qr);

  return CombineNodeData(CombineNodeData(left, mid), right);
}

int main(){
  int q;
  scanf("%d", &q);

  char op[2];
  Node *root = NULL;

  while(q--){
    int x, y;
    scanf("%s%d%d", op, &x, &y);

    if(op[0] == 'A'){
      root = Insert(root, y, x);
    }
    else{
      printf("%d\n", Query(root, 1, x, y).ans);
    }
  }

  return 0;
}