#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define L 19
#define M 3
#define N (L + M + 1)

ll C[N][N];
int f[10];

void Initialise(){
  for(int i = 0; i < N; ++i){
    C[i][0] = 1;
    for(int j = 1; j <= i; ++j){
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
}

ll nCr(int n, int m){
  if(n < 0 || m < 0 || n < m || n >= N || m >= N){
    return 0ll;
  }
  return C[n][m];
}

ll Compute(int n){
  int c = 0;
  for(int i = 1; i < 10; ++i){
    c += f[i];
  }

  ll ans = 0;
  for(int i = 0, x = 1; c + i <= M; ++i, x *= 9){
    ans += (nCr(n, i) * x);
  }

  return ans;
}

ll Count(ll n){
  ll ans = 0;
  string s = to_string(n);

  for(int i = 0; i < 10; ++i){
    f[i] = 0;
  }

  int m = s.size();
  for(auto c : s){
    --m;
    for(char d = '0'; d < c; ++d){
      ++f[(d - '0')];
      ans += Compute(m);
      --f[(d - '0')];
    }
    ++f[(c - '0')];
  }

  ans += Compute(m);

  return ans;
}

int main(){
  int t;

  Initialise();

  scanf("%d", &t);
  while(t--){
    ll l, r;
    scanf("%lld%lld", &l, &r);
    ll ans = Count(r) - Count(l - 1);
    printf("%lld\n", ans);
  }

  return 0;
}
