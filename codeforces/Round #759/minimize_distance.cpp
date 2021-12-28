#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll TurnBackDistance(vector<int>& a, int k){
  ll ans = 0;

  int n = a.size();
  for(int i = n - 1; i >= 0; i -= k){
    ans += 2 * a[i];
  }

  return ans;
}

ll OneWayDistance(vector<int>& a, int k){
  if(a.empty()){
    return 0ll;
  }
  
  return TurnBackDistance(a, k) - a.back();
}

ll Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> a, b;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    if(x < 0){
      a.push_back(-x);
    }
    else{
      b.push_back(x);
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  return min(TurnBackDistance(a, k) + OneWayDistance(b, k), TurnBackDistance(b, k) + OneWayDistance(a, k));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}