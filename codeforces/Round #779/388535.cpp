#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 16

pair<vector<int>,vector<int>> SplitByKthBit(int k, vector<int>& a){
  vector<int> ones, zeros;
  for(int x: a){
    if((x & (1 << k)) != 0){
      ones.push_back(x);
    }
    else{
      zeros.push_back(x);
    }
  }
  a.clear();
  return {zeros, ones};
}

int Calculate(int k, int mask, vector<int> a, vector<int> b){
  if(a.size() != b.size()){
    return -1;
  }

  if(a.empty()){
    return 0;
  }

  if(k == -1){
    return mask;
  }

  auto [zero_a, one_a] = SplitByKthBit(k, a);
  auto [zero_b, one_b] = SplitByKthBit(k, b);

  int ans1 = Calculate(k - 1, mask, zero_a, zero_b);
  int ans2 = Calculate(k - 1, mask, one_a, one_b);

  if(ans1 >= 0 && ans2 >= 0){
    return ans1 | ans2;
  }

  mask += (1 << k);

  return Calculate(k - 1, mask, zero_a, one_b) | Calculate(k - 1, mask, one_a, zero_b);
}

int Solve(){
  int l, r;
  scanf("%d%d", &l, &r);

  vector<int> a(r - l + 1);
  for(int& x: a){
    scanf("%d", &x);
  }

  vector<int> b;
  for(int i = l; i <= r; ++i){
    b.push_back(i);
  }

  return Calculate(B, 0, a, b);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}