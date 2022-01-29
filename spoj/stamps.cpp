#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  int n, m;
  scanf("%d%d", &m, &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end(), greater<int>());

  int k = 0;
  for( ; k < n && m > 0; ++k){
    m -= a[k];
  }

  return m > 0 ? "impossible" : to_string(k);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Scenario #%d:\n%s\n\n", k, Solve().c_str());
  }
  return 0;
}