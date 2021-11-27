#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define MAXHASH 1

int a[N];
vector<int> primes;
map<pii,int> dp, temp;

bool IsPrime(int n){
  for(int x = 2; x * x <= n; ++x){
    if(n % x == 0){
      return false;
    }
  }
  return true;
}

vector<int> GetRandomPrimes(){
  if(!primes.empty()){
    return primes;
  }

  mt19937 rnd(random_device{}());
  uniform_int_distribution<int> dis(100000000/2,1000000000/2);

  while(primes.size() < MAXHASH){
    int n = 2 * dis(rnd) + 1;
    if(IsPrime(n)){
      primes.push_back(n);
    }
  }

  return primes;
}

bool Check(int n, int mod){
  dp[{0, 0}] = 1;

  for(int i = 1; i <= n; ++i){
    for(int x = max(0, a[i] - 1); x <= a[i]; ++x){
      for(auto [q, v]: dp){
        auto [y, p] = q;
        if(x != 0 && y > x){
          continue;
        }

        int ny = x == 0 ? y : x;
        int np = p ^ (a[i] - x);
        pii nq = {ny, np};
        temp[nq] = (temp[nq] + v) % mod;
      }
    }

    dp.swap(temp);
    temp.clear();
  }

  int sum = 0;
  for(auto [q, v]: dp){
    auto [y, p] = q;
    sum += (p == 0 ? v : -v);
    sum %= mod;
  }

  dp.clear();
  return sum == 0;
}

bool Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int mod: GetRandomPrimes()){
    if(!Check(n, mod)){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}