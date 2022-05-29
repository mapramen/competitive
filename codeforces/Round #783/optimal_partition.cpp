#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 500002

ll a[N];
int T[N];
vector<ll> C;

void Reset(int n){
  C.clear();
  C.push_back(LLONG_MIN);
}

void Update(int i, int x){
  for( ; i < C.size(); i += (i & -i)){
    T[i] = max(T[i], x);
  }
}

int Query(int i){
  int ans = INT_MIN;
  for( ; i > 0; i -= (i & -i)){
    ans = max(ans, T[i]);
  }
  return ans;
}

int GetCompressedValue(ll x){
  return lower_bound(C.begin(), C.end(), x) - C.begin();
}

int GetCost(int x){
  return x == 0
    ? 0
    : x < 0 ? -1 : 1;
}

int Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
    C.push_back(a[i]);
  }
  C.push_back(0);

  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  for(int i = 1; i < C.size(); ++i){
    T[i] = INT_MIN;
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    Update(GetCompressedValue(a[i - 1]), ans - i + 1);
    ans = max(ans + GetCost(a[i] - a[i - 1]), Query(GetCompressedValue(a[i]) - 1) + i);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}