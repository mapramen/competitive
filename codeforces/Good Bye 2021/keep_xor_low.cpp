#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 998244353

int SubsetCount(vector<int>& v){
  int ans = 1, p = 2;
  for(int n = v.size(); n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * p * ans) % MOD;
    }
    p = (1ll * p * p) % MOD;
  }
  return ans;
}

int NonEmptySubsetCount(vector<int>& v){
  return (MOD + SubsetCount(v) - 1) % MOD;
}

pair<vector<int>,vector<int>> SplitByKThBit(vector<int> v, int k){
  vector<int> zeros, ones;
  for(int x: v){
    if((x & (1 << k)) == 0){
      zeros.push_back(x);
    }
    else{
      ones.push_back(x);
    }
  }

  v.clear();
  return {zeros, ones};
}

int Solve(vector<int>& zeros, vector<int>& ones, int k, int x){
  if(zeros.empty() || ones.empty()){
    return 0;
  }
  
  if(k < 0){
    return (1ll * NonEmptySubsetCount(zeros) * NonEmptySubsetCount(ones)) % MOD;
  }

  auto [a0, a1] = SplitByKThBit(zeros, k);
  auto [b0, b1] = SplitByKThBit(ones, k);

  if((x & (1 << k)) == 0){
    return (Solve(a0, b0, k - 1, x) + Solve(a1, b1, k - 1, x)) % MOD;
  }

  int ans = (1ll * NonEmptySubsetCount(a0) * NonEmptySubsetCount(b0) + 1ll * NonEmptySubsetCount(a1) * NonEmptySubsetCount(b1)) % MOD;
  int ans1 = Solve(a0, b1, k - 1, x), ans2 = Solve(a1, b0, k - 1, x);

  ans = (ans + 1ll * (1 + NonEmptySubsetCount(a1) + NonEmptySubsetCount(b0)) * ans1) % MOD;
  ans = (ans + 1ll * (1 + NonEmptySubsetCount(a0) + NonEmptySubsetCount(b1)) * ans2) % MOD;
  ans = (ans + 1ll * ans1 * ans2) % MOD;

  return ans;
}

int Solve(vector<int>& v, int k, int x){
  if(v.empty() || k < 0){
    return NonEmptySubsetCount(v);
  }

  auto [zeros, ones] = SplitByKThBit(v, k);

  if((x & (1 << k)) == 0){
    return (Solve(zeros, k - 1, x) + Solve(ones, k - 1, x)) % MOD;
  }

  return (0ll + NonEmptySubsetCount(zeros) + NonEmptySubsetCount(ones) + Solve(zeros, ones, k - 1, x)) % MOD;
}

int main(){
  int n, x;
  scanf("%d%d", &n, &x);

  vector<int> v(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &v[i]);
  }

  printf("%d\n", Solve(v, 29, x));

  return 0;
}