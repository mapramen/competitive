#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2000001

int T[N], a[N], b[N], p[N];

void Update(int n, int i, int x){
  for( ; i <= n; i += (i & -i)){
    T[i] += x;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

void ReadArray(int n, int a[N]){
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
}

void Solve(int li, int ri, int lp, int rp){
  if(li > ri){
    return;
  }

  if(lp == rp){
    for( ; li <= ri; ++li){
      p[li] = lp;
    }
    return;
  }

  int midi = li + (ri - li) / 2;
  int bmid = b[midi];

  int c = 0;
  for(int p = lp; p < rp; ++p){
    c += (a[p] < bmid);
  }

  int cmin = c, pmid = lp;
  for(int p = lp + 1; p <= rp; ++p){
    c -= (a[p - 1] < bmid);
    c += (a[p - 1] > bmid);
    if(c < cmin){
      cmin = c, pmid = p;
    }
  }

  p[midi] = pmid;
  Solve(li, midi - 1, lp, pmid);
  Solve(midi + 1, ri, pmid, rp);
}

ll GetInversionCount(vector<int> &v){
  int n = v.size();

  vector<int> C(v);
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  ll ans = 0;
  for(int i = v.size() - 1; i > -1; --i){
    int cx = lower_bound(C.begin(), C.end(), v[i]) - C.begin() + 1;
    ans += Query(cx - 1);
    Update(n, cx, 1);
  }

  for(int i = 1; i <= n; ++i){
    T[i] = 0;
  }

  C.clear();
  return ans;
}

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  ReadArray(n, a);
  ReadArray(m, b);

  sort(b + 1, b + m + 1);

  Solve(1, m, 1, n + 1);

  vector<int> c;
  for(int i = 1, j = 1; i <= m; ++i){
    for( ; j <= n && j < p[i]; ++j){
      c.push_back(a[j]);
    }
    c.push_back(b[i]);
  }

  for(int j = p[m]; j <= n; ++j){
    c.push_back(a[j]);
  }

  return GetInversionCount(c);
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%lld\n", Solve());
  }

  return 0;
}