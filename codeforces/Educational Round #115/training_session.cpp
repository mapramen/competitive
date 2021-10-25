#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> V(N);
int C[N];

ll Calculate(int n){
  ll c1 = 0, c2 = 0, c3 = 0;
  for(int i = 1; i <= n; ++i){
    int c = V[i].size();
    c3 += c2 * c;
    c2 += c1 * c;
    c1 += c;
  }
  return c3;
}

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int a, b;
    scanf("%d%d", &a, &b);
    V[a].push_back(b);
    ++C[b];
  }

  ll ans2 = Calculate(n);

  ll ans3 = 0;
  for(int i = 1; i <= n; ++i){
    ll ansx = 0;
    for(int b: V[i]){
      ansx += C[b];
    }

    ll c = V[i].size();
    ansx *= 2 * (c - 1);
    ansx = c * (c - 1) * (c - 2) / 6 + (c * (c - 1) * (n - c + 2) - ansx) / 2;

    ans3 += ansx;

    V[i].clear();
  }

  for(int i = 1; i <= n; ++i){
    C[i] = 0;
  }

  return ans2 + ans3;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}