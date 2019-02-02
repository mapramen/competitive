#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define piii pair< pii, int >
#define PB push_back
#define MP make_pair
#define inf INT_MAX
#define N 100001
#define M 300001

int a[N], ans[M];
vector<int> compressedX;
vector< piii > queries;

typedef struct node{
  int leftEnd;
  int rightEnd;
  int ans;
  int lazyValue;
  node* leftChild;
  node* rightChild;
}node;

int CoordinateCompression(int n){
  set<int> s;
  s.insert(INT_MIN);
  for(int i = 1; i <= n; i++)
    s.insert(a[i]);

  for(auto x : s)
    compressedX.PB(x);

  s.clear();

  return (int)compressedX.size() - 1;
}

int GetCompressedValue(int x){
  return lower_bound(compressedX.begin(), compressedX.end(), x) - compressedX.begin();
}

int GetOriginalValue(int i){
  return compressedX[i];
}

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->ans = temp->lazyValue = inf;

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

void ResetSegmentTree(node *root){
  if(root != NULL){
    ResetSegmentTree(root->leftChild);
    ResetSegmentTree(root->rightChild);
    root->ans = root->lazyValue = inf;
  }
}

void LazyUpdateChild(node *currentNode, node *childNode){
  childNode->lazyValue = min(childNode->lazyValue, currentNode->lazyValue);
  childNode->ans = min(childNode->ans, childNode->lazyValue);
}

void LazyUpdateChildren(node *currentNode){
  LazyUpdateChild(currentNode, currentNode->leftChild);
  LazyUpdateChild(currentNode, currentNode->rightChild);
  currentNode->lazyValue = inf;
}

void UpdateNode(node *currentNode, int l, int r, int x){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return ;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd){
      currentNode->lazyValue = min(currentNode->lazyValue, x);
      currentNode->ans = min(currentNode->ans, currentNode->lazyValue);
    }
    else{
      LazyUpdateChildren(currentNode);
      UpdateNode(currentNode->leftChild, l, r, x);
      UpdateNode(currentNode->rightChild, l, r, x);
      currentNode->ans = min(currentNode->leftChild->ans, currentNode->rightChild->ans);
    }
  }
}

int QueryNode(node *currentNode, int l, int r){
  if(r < l || r < currentNode->leftEnd || currentNode->rightEnd < l)
    return inf;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      return currentNode->ans;
    else{
      LazyUpdateChildren(currentNode);
      return min(QueryNode(currentNode->leftChild, l, r), QueryNode(currentNode->rightChild, l, r));
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void ProcessQueries(node *root, node *croot, int n, int m){
  sort(queries.begin(), queries.end());

  for(int i = 1, k = 0; k < queries.size(); k++){
    int r, l;
    tie(r, l) = queries[k].first;

    for( ; i <= r; i++){
      int x = a[i], cx = GetCompressedValue(x), cy = m;
      while(cx <= cy){
        int j = n - QueryNode(croot, cx, cy);
        if(j > 0){
          UpdateNode(root, 1, j, a[j] - x);
          cy = GetCompressedValue((x + a[j] + 1) / 2) - 1;
        }
        else
          break;
      }
      UpdateNode(croot, cx, cx, n - i);
    }

    int x = queries[k].second;
    ans[x] = min(ans[x], QueryNode(root, l, l));
  }
}

int main(){
  int n, q, m;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  scanf("%d", &q);

  for(int x = 1; x <= q; x++){
    int l, r;
    scanf("%d%d", &l, &r);
    queries.PB(MP(MP(r, l), x));
    ans[x] = inf;
  }

  m = CoordinateCompression(n);
  node *root = BuildSegmentTree(1, n);
  node *croot = BuildSegmentTree(1, m);

  ProcessQueries(root, croot, n, m);

  for(int i = 1; 2 * i <= n; i++)
    swap(a[i], a[n - i + 1]);

  for(int x = 0; x < q; x++){
    int l, r;
    tie(r, l) = queries[x].first;
    queries[x].first.first = n - l + 1;
    queries[x].first.second = n - r + 1;
  }

  ResetSegmentTree(root);
  ResetSegmentTree(croot);
  ProcessQueries(root, croot, n, m);

  for(int i = 1; i <= q; i++)
    printf("%d\n", ans[i]);

  return 0;
}
