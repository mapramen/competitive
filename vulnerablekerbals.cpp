#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > v(N);
int m, phi, dp[N], p[N];
bool visited[N];

int ModExp(int a, int n){
  ll x = a, y = 1 % m;
  while(n > 0){
    if(n % 2)
      y = (x * y) % m;
    x = (x * x) % m;
    n /= 2;
  }
  return (int)y;
}

int ModInverse(int a){
  return ModExp(a, phi - 1);
}

int EulerTotient(int n){
  int ans = 1;
  for(int i = 2; i <= n; i++){
    if(n % i != 0)
      continue;
    for(n /= i, ans *= (i - 1); n % i == 0; n /= i, ans *= i);
  }
  return ans;
}

int Print(int x){
  if(x == 0)
    return 1;
  int s = Print(p[x]);
  for(int k : v[x]){
    int g = __gcd(s, m);
    s /= g;
    int i = (1ll * (k / g) * ModInverse(s)) % m;
    printf("%d ", i);
    s = k;
  }
  return s;
}

int main(){
  int n, ansi = 0;
  vector<int> d;

  scanf("%d%d", &n, &m);

  while(n--){
    int i;
    scanf("%d", &i);
    visited[i] = 1;
  }

  for(int i = 0; i < m; i++){
    if(visited[i] == 1)
      continue;

    int g = __gcd(i, m);
    v[g].PB(i);
  }

  for(int i = 1; i <= m; i++){
    dp[i] = v[i].size();

    if(dp[i] == 0)
      continue;

    int k = 0;

    for(auto x : d){
      if(i % x == 0 && dp[x] > dp[k])
        k = x;
    }

    dp[i] += dp[k];
    p[i] = k;
    d.PB(i);

    if(dp[i] > dp[ansi])
      ansi = i;
  }

  phi = EulerTotient(m);
  printf("%d\n", dp[ansi]);
  Print(ansi);
  printf("\n");

  return 0;
}
