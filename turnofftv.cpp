#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int l[N], r[N], inf = INT_MAX;
vector<int> a;

typedef struct node{
  int leftEnd;
  int rightEnd;
  int ans;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//
node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
    temp->ans = min(temp->leftChild->ans, temp->rightChild->ans);
  }
  else{
    temp->ans = a[leftEnd];
    temp->leftChild = temp->rightChild = NULL;
  }

  return temp;
}

int Query(node *currentNode, int l, int r){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return inf;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && currentNode->rightEnd == r)
      return currentNode->ans;
    else
      return min(Query(currentNode->leftChild, l, r), Query(currentNode->rightChild, l, r));
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int CoordinateCompress(int n){
  vector<int> v;

  for(int i = 1; i <= n; ++i){
    v.PB(l[i] - 1);
    v.PB(l[i]);
  }

  for(int i = 1; i <= n; ++i){
    v.PB(r[i]);
    v.PB(r[i] + 1);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  a.resize(v.size());

  for(int i = 1; i <= n; ++i){
    l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
    a[l[i]]++;
  }

  for(int i = 1; i <= n; ++i){
    r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
    a[r[i] + 1]--;
  }

  return (int)(v.size() - 1);
}

int main(){
  int n, ansI = -1;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d%d", &l[i], &r[i]);

  int m = CoordinateCompress(n);

  for(int i = 1; i <= m; ++i)
    a[i] += a[i - 1];

  for(int i = 1; i <= m; ++i){
    if(a[i] == 0)
      a[i] = inf;
  }

  node *root = BuildSegmentTree(1, m);

  for(int i = 1; i <= n && ansI == -1; ++i){
    if(Query(root, l[i], r[i]) > 1)
      ansI = i;
  }

  printf("%d\n", ansI);

  return 0;
}
