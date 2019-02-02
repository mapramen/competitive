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
#define K 300001
#define B 18
#define M ((1 << B) + B * K)

//----------------------------------------- Persistent Segment Tree -----------------------------------------//
int leftChild[M], rightChild[M], ans[M], nxt;

int NewNodeIndex(){
  return nxt++;
}

int BuildSegmentTree(int l, int r){
  int k = NewNodeIndex();
  ans[k] = INT_MAX;
  if(l != r){
    leftChild[k] = BuildSegmentTree(l, (l + r) / 2);
    rightChild[k] = BuildSegmentTree((l + r) / 2 + 1, r);
  }
  return k;
}

int Insert(int k, int l, int r, int i, int x){
  if(i < l || r < i){
    return k;
  }

  int nk = NewNodeIndex();

  if(i == l && r == i){
    ans[nk] = min(x, ans[k]);
  }
  else{
    leftChild[nk] = Insert(leftChild[k], l, (l + r) / 2, i, x);
    rightChild[nk] = Insert(rightChild[k], (l + r) / 2 + 1, r, i, x);
    ans[nk] = max(ans[leftChild[nk]], ans[rightChild[nk]]);
  }

  return nk;
}

int Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return INT_MIN;
  }

  if(ql <= l && r <= qr){
    return ans[k];
  }

  return max(Query(leftChild[k], l, (l + r) / 2, ql, qr), Query(rightChild[k], (l + r) / 2 + 1, r, ql, qr));
}
//-------------------------------------- Persistent Segment Tree Ends --------------------------------------//

int rootIndexes[K];
vector< tiii > v;

int main(){
  int n, q, k;

  scanf("%d%d%d", &n, &q, &k);

  for(int x = 1; x <= k; ++x){
    int l, r, i;
    scanf("%d%d%d", &l, &r, &i);
    v.PB(MT(l, r, i));
  }

  sort(v.begin(), v.end());

  rootIndexes[k] = BuildSegmentTree(1, n);

  for(int x = k - 1; x > -1; --x){
    int l, r, i;
    tie(l, r, i) = v[x];
    rootIndexes[x] = Insert(rootIndexes[x + 1], 1, n, i, r);
  }

  v.PB(MT(INT_MAX, 0, 0));

  while(q--){
    int l, r, a, b;
    scanf("%d%d%d%d", &a, &b, &l, &r);
    int x = lower_bound(v.begin(), v.end(), MT(l, 0, 0)) - v.begin();
    printf("%s\n", Query(rootIndexes[x], 1, n, a, b) <= r ? "yes" : "no");
    fflush(stdout);
  }

  return 0;
}
