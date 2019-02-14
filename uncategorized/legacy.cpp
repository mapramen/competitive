#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 100001

int n;
tiii queries[N];
ll d[N], inf = 1E18;
bool queryApplied[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  ll lazyValue;
  ll distance;
  int vertex;
  stack<int> queryNos;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->lazyValue = inf;
  temp->distance = inf;
  temp->vertex = leftEnd;

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

void LazyUpdateChild(node *currentNode, node *childNode){
  if(childNode->vertex <= n){
    childNode->lazyValue = min(childNode->lazyValue, currentNode->lazyValue);
    childNode->distance = min(childNode->distance, currentNode->lazyValue);
  }
}

void LazyUpdateChildren(node *currentNode){
  LazyUpdateChild(currentNode, currentNode->leftChild);
  LazyUpdateChild(currentNode, currentNode->rightChild);
  currentNode->lazyValue = inf;
}

void AddQueryNo(node *currentNode, int l, int r, int queryNo){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l){
    return ;
  }
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      currentNode->queryNos.push(queryNo);
    else{
      AddQueryNo(currentNode->leftChild, l, r, queryNo);
      AddQueryNo(currentNode->rightChild, l, r, queryNo);
    }
  }
}

void MergeNode(node *currentNode, node *leftChild, node *rightChild){
  tie(currentNode->distance, currentNode->vertex) = min(MP(leftChild->distance, leftChild->vertex), MP(rightChild->distance, rightChild->vertex));
}

void UpdateNode(node *currentNode, int l, int r, ll x, bool nullify){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l){
    return ;
  }
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd){
      if(nullify){
        currentNode->lazyValue = currentNode->distance = x;
        currentNode->vertex = n + 1;
      }
      else{
        if(currentNode->vertex <= n){
          currentNode->lazyValue = min(currentNode->lazyValue, x);
          currentNode->distance = min(currentNode->distance, x);
        }
      }
    }
    else{
      LazyUpdateChildren(currentNode);
      UpdateNode(currentNode->leftChild, l, r, x, nullify);
      UpdateNode(currentNode->rightChild, l, r, x, nullify);
      MergeNode(currentNode, currentNode->leftChild, currentNode->rightChild);
    }
  }
}

void ApplyQueries(node *root, node *currentNode, int i){
  if(i < currentNode->leftEnd || currentNode->rightEnd < i)
    return ;
  else{
    while(!currentNode->queryNos.empty()){
      int queryNo = currentNode->queryNos.top();
      currentNode->queryNos.pop();

      if(queryApplied[queryNo])
        continue;

      int l, r, w;
      tie(l, r, w) = queries[queryNo];
      UpdateNode(root, l, r, d[i] + w, 0);
      queryApplied[queryNo] = 1;
    }

    if(currentNode->leftEnd != currentNode->rightEnd){
      ApplyQueries(root, currentNode->leftChild, i);
      ApplyQueries(root, currentNode->rightChild, i);
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int s, q;

  scanf("%d%d%d", &n, &q, &s);

  node *root = BuildSegmentTree(1, n);

  for(int x = 1; x <= q; x++){
    int t;
    scanf("%d", &t);
    if(t == 1){
      int u, v, w;
      scanf("%d%d%d", &v, &u, &w);
      queries[x] = MT(u, u, w);
      AddQueryNo(root, v, v, x);
    }
    else{
      int v, l, r, w;
      scanf("%d%d%d%d", &v, &l, &r, &w);
      if(t == 2){
        queries[x] = MT(l, r, w);
        AddQueryNo(root, v, v, x);
      }
      else{
        queries[x] = MT(v, v, w);
        AddQueryNo(root, l, r, x);
      }
    }
  }

  for(int i = 1; i <= n; i++)
    d[i] = -1;

  UpdateNode(root, s, s, 0ll, 0);

  while(root->distance != inf && root->vertex <= n){
    int i = root->vertex;
    d[i] = root->distance;
    ApplyQueries(root, root, i);
    UpdateNode(root, i, i, inf, 1);
  }

  for(int i = 1; i <= n; i++)
    printf("%lld ", d[i]);
  printf("\n");

  return 0;
}
