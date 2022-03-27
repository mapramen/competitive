#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N], b[N];

int Cost(int a[], int n, int x){
  int ans = INT_MAX;
  for(int i = 1; i <= n; ++i){
    ans = min(ans, abs(a[i] - x));
  }
  return ans;
}

ll Cost(int n, int i, int j){
  if(i == 0 && j == 0){
    return 0;
  }

  if(i != 0 && j != 0){
    return abs(a[i] - b[j]);
  }

  return i == 0 ? Cost(a, n, b[j]) : Cost(b, n, a[i]);
}

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  ll ans = LLONG_MAX;
  vector<int> v{0, 0, 1, n};
  do
  {
    ll ansx = Cost(n, 0, v[0]) + Cost(n, 0, v[1]) + Cost(n, 1, v[2]) + Cost(n, n, v[3]);
    ans = min(ans, ansx);
  }while(next_permutation(v.begin(), v.end()));
  
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}