#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector<int> a(N);
vector< vector<int> > compressedX(N), T(N);
vector< pii > queries;

void InsertInto2DBIT(int i, int a_i){
  for( ; i < compressedX.size(); i += (i & -i))
    compressedX[i].PB(a_i);
}

void PreProcess(int n){
  for(int i = 1; i <= n; i++){
    sort(compressedX[i].begin(), compressedX[i].end());
    compressedX[i].erase(unique(compressedX[i].begin(), compressedX[i].end()), compressedX[i].end());
    T[i].resize(compressedX[i].size());
  }

  for(int i = 1; i <= n; i++)
    a[i] = i;
}

int GetCompressedValue(vector<int>& c, int a){
  return lower_bound(c.begin(), c.end(), a) - c.begin();
}

void Update1DBIT(vector<int>& T, int i, int x){
  for( ; i < T.size(); i += (i & -i))
    T[i] += x;
}

void Update2DBIT(int i, int x){
  int a_i = a[i];

  for( ; i < T.size(); i += (i & -i)){
    int j = GetCompressedValue(compressedX[i], a_i);
    Update1DBIT(T[i], j + 1, x);
  }
}

int Query1DBIT(vector<int>& T, int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

int Query2DBIT(int i){
  int a_i = a[i], ans = 0;
  for( ; i > 0; i -= (i & -i)){
    int j = GetCompressedValue(compressedX[i], a_i);
    ans += Query1DBIT(T[i], j);
  }
  return ans;
}

void Initialise(int n){
  for(int i = 1; i <= n; i++)
    Update2DBIT(i, 1);
}

void Update(int i, int j, int x){
  Update2DBIT(i, x);
  Update2DBIT(j, x);
}

int Query(int i){
  int lowerCnt = Query2DBIT(i);
  return (a[i] - 1 - lowerCnt) + (i - 1 - lowerCnt);
}

int GetInvCntChange(int i, int j){
  if(i > j)
    swap(i, j);

  int invCntChange = - (Query(i) + Query(j));

  Update(i, j, -1);
  swap(a[i], a[j]);
  Update(i, j, 1);

  invCntChange += (Query(i) + Query(j));
  invCntChange += ((a[i] < a[j]) - (a[i] > a[j]));

  return invCntChange;
}

int main(){
  int n, q;
  ll invCnt = 0;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; i++){
    a[i] = i;
    InsertInto2DBIT(i, i);
    compressedX[i].PB(0);
    compressedX[i].PB(n + 1);
  }

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    swap(a[l], a[r]);
    InsertInto2DBIT(l, a[l]);
    InsertInto2DBIT(r, a[r]);
    queries.PB(MP(l, r));
  }

  PreProcess(n);
  Initialise(n);

  for(int q = 0; q < queries.size(); q++){
    int l = queries[q].first, r = queries[q].second;
    invCnt += GetInvCntChange(l, r);
    printf("%lld\n", invCnt);
  }

  return 0;
}
