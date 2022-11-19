#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tq tuple<int,int,int>
#define N 200001

vector<vector<int>> divisors(2 * N), V(N);
vector<vector<pii>> queries(N);
int T[N];
ll qans[N];

int LCM(int a, int b){
  return a * (b / __gcd(a, b));
}

int LCM(int a, int b, int c){
  return LCM(a, LCM(b, c));
}

void Initialize(){
  for(int i = 1; i < 2 * N; ++i){
    for(int k = i; k < 2 * N; k += i){
      divisors[k].push_back(i);
    }
  }

  for(int k = 1; k < N; ++k){
    vector<int>& divisor = divisors[2 * k];
    for(int y = 0; divisor[y] < k; ++y){
      int j = divisor[y], lcm_jk = LCM(j, k);
      for(int x = 0; x < y; ++x){
        int i = divisor[x], lcm = LCM(i, lcm_jk);
        if(lcm == k || lcm == 2 * k && i + j > k){
          V[i].push_back(k);
        }
      }
    }
  }
}

void Update(int i){
  for( ; i < N; i += (i & -i)){
    ++T[i];
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);

  for(int k = 1; k <= t; ++k){
    int l, r;
    scanf("%d%d", &l, &r);
    queries[l].push_back({r, k});
  }

  Initialize();
  
  for(int l = N - 1; l != 0; --l){
    for(int r: V[l]){
      Update(r);
    }
    
    for(auto [r, k]: queries[l]){
      ll n = r - l + 1;
      qans[k] = n * (n - 1) * (n - 2) / 6 - Query(r);
    }
  }

  for(int k = 1; k <= t; ++k){
    printf("%lld\n", qans[k]);
  }
  
  return 0;
}