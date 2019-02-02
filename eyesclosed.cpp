#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  int n;
  double A;
  double B;
  double S;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->n = rightEnd - leftEnd + 1;
  temp->A = 1;
  temp->B = 0;
  temp->leftChild = NULL;
  temp->rightChild = NULL;

  return temp;
}

void Combine(node *currentNode){
  currentNode->S = currentNode->leftChild->S + currentNode->rightChild->S;
}

node* BuildSegmentTree(int i, int j){
  node *temp = CreateNode(i, j);

  if(i != j){
    int k = (i + j) / 2;
    temp->leftChild = BuildSegmentTree(i, k);
    temp->rightChild = BuildSegmentTree(k + 1, j);
    Combine(temp);
  }
  else{
    temp->S = a[i];
  }

  return temp;
}

void UpdateNode(node *currentNode, double a, double b){
  currentNode->A *= a;
  currentNode->B = a * currentNode->B + b;
  currentNode->S = a * currentNode->S + currentNode->n * b;
}

void LazyUpdateChildren(node *currentNode){
  if(currentNode->A != 1 || currentNode->B != 0){
    UpdateNode(currentNode->leftChild, currentNode->A, currentNode->B);
    UpdateNode(currentNode->rightChild, currentNode->A, currentNode->B);
    currentNode->A = 1;
    currentNode->B = 0;
  }
}

void Update(node *currentNode, int l, int r, double a, double b){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return ;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      UpdateNode(currentNode, a, b);
    else{
      LazyUpdateChildren(currentNode);
      Update(currentNode->leftChild, l, r, a, b);
      Update(currentNode->rightChild, l, r, a, b);
      Combine(currentNode);
    }
  }
}

double Query(node *currentNode, int l, int r){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return 0.0;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      return currentNode->S;
    else{
      LazyUpdateChildren(currentNode);
      double ans = Query(currentNode->leftChild, l, r) + Query(currentNode->rightChild, l, r);
      Combine(currentNode);
      return ans;
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

node *root;

void Update(){
  int l1, r1, l2, r2;

  scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

  int n1 = r1 - l1 + 1, n2 = r2 - l2 + 1;
  double a1 = (double)(n1 - 1) / n1, a2 = (double)(n2 - 1) / n2;
  double b1 = Query(root, l2, r2) / (1ll * n1 * n2), b2 = Query(root, l1, r1) / (1ll * n1 * n2);
  Update(root, l1, r1, a1, b1);
  Update(root, l2, r2, a2, b2);
}

void Query(){
  int l, r;
  scanf("%d%d", &l, &r);
  printf("%.15lf\n", Query(root, l, r));
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  root = BuildSegmentTree(1, n);

  while(q--){
    int t;
    scanf("%d", &t);
    if(t == 1)
      Update();
    else
      Query();
  }

  return 0;
}
