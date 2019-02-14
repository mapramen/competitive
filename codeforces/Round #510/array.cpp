#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

ll s[N];
vector<ll> C, T;

void RemoveDuplicates(vector<ll>& v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

int GetCompressedValue(vector<ll>& v, ll x){
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

void Update(int i, int x){
  for( ; i < T.size(); i += (i & -i)){
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

void Update(ll x){
  int i = GetCompressedValue(C, x);
  Update(i, 1);
}

int main(){
  ll n, t;

  scanf("%lld%lld", &n, &t);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &s[i]);
    s[i] += s[i - 1];
    C.PB(s[i - 1]);
    C.PB(s[i] - t);
  }

  C.PB(LLONG_MIN);
  RemoveDuplicates(C);
  T.resize(C.size());

  ll ans = 0;
  Update(0ll);
  for(int i = 1; i <= n; ++i){
    ans += (i - Query(GetCompressedValue(C, s[i] - t)));
    Update(s[i]);
  }

  printf("%lld\n", ans);

  return 0;
}
