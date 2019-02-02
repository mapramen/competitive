#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > nextList(N);
vector< set<int> > M(N);

int a[N], b[N], nxt[N], qt[N], qi[N], qj[N];

typedef struct node{
  int leftEnd;
  int rightEnd;
  vector<int> C;
  vector<ll> T;
  node* leftChild;
  node* rightChild;
}node;

//----------------------------------------- Segment Tree -----------------------------------------//

void RemoveDuplicates(vector<int>& v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->C.clear();
  temp->T.clear();

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
    for(auto x : temp->leftChild->C)
      temp->C.PB(x);
    for(auto x : temp->rightChild->C)
      temp->C.PB(x);
  }
  else{
    temp->C.PB(0);
    for(auto x : nextList[leftEnd])
      temp->C.PB(x);
    temp->leftChild = temp->rightChild = NULL;
  }

  RemoveDuplicates(temp->C);
  temp->T.resize(temp->C.size());

  return temp;
}

int GetCompressedValue(vector<int>& C, int x){
  return lower_bound(C.begin(), C.end(), x) - C.begin();
}

void BITUpdate(vector<ll>& T, vector<int>& C, int i, int x){
  i = GetCompressedValue(C, i);
  for( ; i < T.size(); i += (i & -i))
    T[i] += x;
}

ll BITQuery(vector<ll>& T, vector<int>& C, int i){
  i = GetCompressedValue(C, i + 1) - 1;
  ll ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

void Update(node *currentNode, int i, int x, int val){
  if(i < currentNode->leftEnd || currentNode->rightEnd < i)
    return ;
  else{
    BITUpdate(currentNode->T, currentNode->C, x, val);
    if(currentNode->leftEnd != currentNode->rightEnd){
      if(i <= currentNode->leftChild->rightEnd)
        Update(currentNode->leftChild, i, x, val);
      else
        Update(currentNode->rightChild, i, x, val);
    }
  }
}

ll Query(node *currentNode, int l, int r, int k){
  if(r < currentNode->leftEnd || currentNode->rightEnd < l)
    return 0;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && currentNode->rightEnd == r)
      return BITQuery(currentNode->T, currentNode->C, k);
    else{
      return Query(currentNode->leftChild, l, r, k) + Query(currentNode->rightChild, l, r, k);
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int GetPreviousIndex(int i){
  auto it = M[a[i]].lower_bound(i);
  --it;
  return *it;
}

int GetNextIndex(int i){
  return *M[a[i]].upper_bound(i);
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int x = 1; x <= q; ++x)
    scanf("%d%d%d", &qt[x], &qi[x], &qj[x]);

  for(int i = 1; i <= n; ++i){
    M[i].insert(0);
    M[i].insert(n + 1);
    M[a[i]].insert(i);
    b[i] = a[i];
  }

  for(int i = 1; i <= n; ++i){
    nxt[i] = GetNextIndex(i);
    nextList[i].PB(nxt[i]);
  }

  for(int x = 1; x <= q; ++x){
    if(qt[x] == 2)
      continue;
    int i = qi[x], j = qj[x];

    int k = GetPreviousIndex(i);
    M[a[i]].erase(i);

    nxt[k] = GetNextIndex(k);
    nextList[k].PB(nxt[k]);

    a[i] = j;
    M[a[i]].insert(i);
    k = GetPreviousIndex(i);
    nxt[k] = i;
    nxt[i] = GetNextIndex(i);
    nextList[k].PB(nxt[k]);
    nextList[i].PB(nxt[i]);
  }

  for(int i = 1; i <= n; ++i){
    a[i] = b[i];
    M[i].clear();
    M[i].insert(0);
    M[i].insert(n + 1);
  }

  node *root = BuildSegmentTree(1, n);

  for(int i = n; i > 0; --i){
    nxt[i] = GetNextIndex(i);
    Update(root, i, nxt[i], nxt[i] - i);
    M[a[i]].insert(i);
  }

  for(int x = 1; x <= q; ++x){
    int i = qi[x], j = qj[x];

    if(qt[x] == 1){
      int k = GetPreviousIndex(i);
      Update(root, k, nxt[k], k - nxt[k]);
      M[a[i]].erase(i);
      nxt[k] = GetNextIndex(k);
      Update(root, k, nxt[k], nxt[k] - k);

      a[i] = j;
      M[a[i]].insert(i);
      k = GetPreviousIndex(i);
      Update(root, k, nxt[k], k - nxt[k]);
      nxt[k] = i;
      Update(root, k, nxt[k], nxt[k] - k);
      Update(root, i, nxt[i], i - nxt[i]);
      nxt[i] = GetNextIndex(i);
      Update(root, i, nxt[i], nxt[i] - i);
    }
    else{
      printf("%lld\n", Query(root, i, j, j));
    }
  }

	return 0;
}
