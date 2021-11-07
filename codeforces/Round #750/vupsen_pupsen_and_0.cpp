#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N], b[N];
vector<pii> v;

bool CheckAndFill(int i, int j, int k){
  if(a[i] + a[j] == 0){
    return false;
  }

  int x = a[i] + a[j], y = a[k];
  int g = __gcd(abs(x), abs(y));
  int z = x * y / g;

  b[i] = z / x, b[j] = z / x, b[k] = -z / y;
  return true;
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    v.push_back({abs(a[i]), i});
  }
  sort(v.begin(), v.end());

  while((!v.empty() && v.size() % 2 == 0) || v.size() > 3){
    auto [ai, i] = v.back();
    v.pop_back();

    auto [aj, j] = v.back();
    v.pop_back();

    int x = a[i] * a[j] / __gcd(ai, aj);
    b[i] = x / a[i], b[j] = -x / a[j];
  }

  if(!v.empty()){
    int i = v[0].second, j = v[1].second, k = v[2].second;
    CheckAndFill(i, j, k) || CheckAndFill(i, k, j) || CheckAndFill(j, k, i);
  }

  v.clear();
  for(int i = 1; i <= n; ++i){
    printf("%d ", b[i]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    Solve();
  }

  return 0;
}