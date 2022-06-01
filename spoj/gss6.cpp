#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int INF = 1E9;

mt19937 rnd(random_device{}());
uniform_int_distribution<int> dis(1, INT_MAX);

struct NodeData
{
  int sum;
  int ans;
  int prefix_ans;
  int suffix_ans;
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
  return {value, value, value, value};
}

int GetCount(Node* a){
  return a == NULL ? 0 : a->count;
}

NodeData CombineNodeData(NodeData left, NodeData right){
  return {
    max(-INF, left.sum + right.sum),
    max(max(left.ans, right.ans), left.suffix_ans + right.prefix_ans),
    max(left.prefix_ans, left.sum + right.prefix_ans),
    max(right.suffix_ans, right.sum + left.suffix_ans)
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

void AssignMostPriority(Node* root, int index){
  if(root == NULL){
    return;
  }

  int cnt = GetCount(root->leftChild) + 1;

  if(cnt == index){
    root->priority = INT_MIN;
  }
  else if (cnt < index){
    AssignMostPriority(root->rightChild, index - cnt);
  }
  else{
    AssignMostPriority(root->leftChild, index);
  }
}

Node* Insert(Node* root, int index, int value){
  return ReBalance(InsertNode(root, index, value), index);
}

Node* Delete(Node* root, int index){
  AssignMostPriority(root, index);
  root = ReBalance(root, index);
  return Meld(root->leftChild, root->rightChild);
}

Node* Replace(Node* root, int index, int value){
  return Insert(Delete(root, index), index, value);
}

NodeData outside_range_ans = {0, -INF, -INF, -INF};

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
  int n;
  scanf("%d", &n);

  Node* root = NULL;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    root = Insert(root, i, x);
  }

  int q;
  scanf("%d", &q);

  char op[2];
  while(q--){
    int x, y;
    scanf("%s", op);

    if(op[0] == 'I'){
      scanf("%d%d", &x, &y);
      root = Insert(root, x, y);
    }
    else if(op[0] == 'D'){
      scanf("%d", &x);
      root = Delete(root, x);
    }
    else if(op[0] == 'R'){
      scanf("%d%d", &x, &y);
      root = Replace(root, x, y);
    }
    else{
      scanf("%d%d", &x, &y);
      printf("%d\n", Query(root, 1, x, y).ans);
    }
  }

  return 0;
}