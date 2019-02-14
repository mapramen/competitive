#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define M 10001

vector< vector<int> > c(M), T(M);
int x[N], r[N], f[N];
vector< pii > a;

void BITUpdate(vector<int>& T, int i, int x){
  for( ; i < T.size(); i += (i&-i))
    T[i] += x;
}

int BITQuery(vector<int>& T, int i){
  int ans = 0;
  for( ; i > 0; i -= (i&-i))
    ans += T[i];
  return ans;
}

int GetCompressedValue(vector<int>& c, int x){
  return lower_bound(c.begin(), c.end(), x + 1) - c.begin() - 1;
}

int QueryX(int k, int x, int r){
  int i = GetCompressedValue(c[k], max(0, x - r - 1));
  int j = GetCompressedValue(c[k], x + r);
  int ans = BITQuery(T[k], j) - BITQuery(T[k], i);
  return ans;
}

int Query(int x, int r, int f, int m){
  int ans = 0;
  for(int k = max(1, f - m); k < min(M, f + m + 1); k++)
    ans += QueryX(k, x, r);
  return ans;
}

int main(){
  int n, m;
  ll ans = 0;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; i++){
    scanf("%d%d%d", &x[i], &r[i], &f[i]);
    c[f[i]].PB(x[i]);
    a.PB(MP(r[i], i));
  }

  for(int i = 1; i < M; i++){
    c[i].PB(0);
    c[i].PB(2E9 + 10);
    sort(c[i].begin(), c[i].end());
    T[i].resize(c[i].size());
  }

  sort(a.begin(), a.end(), greater< pii >());

  for(auto p : a){
    int i = p.second;
    ans += Query(x[i], r[i], f[i], m);
    BITUpdate(T[f[i]], GetCompressedValue(c[f[i]], x[i]), 1);
  }

  cout << ans << '\n';

  return 0;
}
