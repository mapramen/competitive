#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

vector<int> primes;
int a[N];

void PreProcess(int n){
  int g = 0, m = 0;

  for(int i = 1; i <= n && g != 1; ++i){
    g = __gcd(g, a[i]);
  }

  for(int i = 1; i <= n; ++i){
    a[i] /= g;
    m = max(m, a[i]);
  }

  for(int i = 2; i * i <= m; ++i){
    bool isPrime = 1;
    for(auto j : primes){
      if(i % j == 0){
        isPrime = 0;
        break;
      }
    }
    if(isPrime){
      primes.PB(i);
    }
  }
}

int main(){
  int n;
  map<int,int> M;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  PreProcess(n);

  for(int i = 1; i <= n; ++i){
    int x = a[i];
    for(int i = 0; i < primes.size() && primes[i] <= x; ++i){
      int p = primes[i];
      if(x % p == 0){
        ++M[p];
        while(x % p == 0){
          x /= p;
        }
      }
    }
    if(x > 1){
      ++M[x];
    }
  }

  int ans = 0;
  for(auto p : M){
    ans = max(ans, p.second);
  }

  ans = ans == 0 ? -1 : n - ans;

  printf("%d\n", ans);

  return 0;
}
