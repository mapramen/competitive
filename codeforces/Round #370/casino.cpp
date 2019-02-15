#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define PB push_back
#define MP make_pair

typedef struct node{
  int leftEnd;
  int rightEnd;
  double a, b;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->a = temp->b = 1.0;

  return temp;
}

node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = CreateNode(leftEnd, rightEnd);

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
  }
  else
    temp->leftChild = temp->rightChild = NULL;

  return temp;
}

void MergeNode(node *currentNode, node *leftChild, node *rightChild){
  double ai = leftChild->a, bi = leftChild->b;
  double aj = rightChild->a, bj = rightChild->b;
  currentNode->a = ai * aj / (1 - (1 - aj) * (1 - bi));
  currentNode->b = bi * bj / (1 - (1 - aj) * (1 - bi));
}

void UpdateNode(node *currentNode, int i, double a, double b){
  if(i < currentNode->leftEnd || currentNode->rightEnd < i){
    return ;
  }
  else{
    if(i == currentNode->leftEnd && i == currentNode->rightEnd){
      double p = a / b;
      currentNode->a = p, currentNode->b = 1 - p;
    }
    else{
      UpdateNode(currentNode->leftChild, i, a, b);
      UpdateNode(currentNode->rightChild, i, a, b);
      MergeNode(currentNode, currentNode->leftChild, currentNode->rightChild);
    }
  }
}

pdd QueryNode(node *currentNode, int l, int r){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return MP(1.0, 1.0);
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      return MP(currentNode->a, currentNode->b);
    else{
      double ai, bi, aj, bj, ak, bk;
      tie(ai, bi) = QueryNode(currentNode->leftChild, l, r);
      tie(aj, bj) = QueryNode(currentNode->rightChild, l, r);
      ak = ai * aj / (1 - (1 - aj) * (1 - bi));
      bk = bi * bj / (1 - (1 - aj) * (1 - bi));
      return MP(ak, bk);
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n, m, i, j, k;
  double a, b;

  scanf("%d%d", &n, &m);
  node *root = BuildSegmentTree(1, n);

  for(i = 1; i <= n; i++){
    scanf("%lf%lf", &a, &b);
    UpdateNode(root, i, a, b);
  }

  while(m--){
    scanf("%d", &k);
    if(k == 1){
      scanf("%d%lf%lf", &i, &a, &b);
      UpdateNode(root, i, a, b);
    }
    else{
      scanf("%d%d", &i, &j);
      tie(a, b) = QueryNode(root, i, j);
      printf("%.10lf\n", a);
    }
  }

  return 0;
}
