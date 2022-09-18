#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<pll> ReadArray(int n, int m){
  vector<pll> a(1);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    int p = 1;
    while(x % m == 0){
      x /= m, p *= m;
    }

    if(a.back().first == x){
      a.back().second += p;
    }
    else{
      a.push_back({x, p});
    }
  }

  return a;
}

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<pll> a = ReadArray(n, m);

  int k;
  scanf("%d", &k);
  vector<pll> b = ReadArray(k, m);

  return a == b;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}