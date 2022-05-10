#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> Int2Vec(int n){
  vector<int> v;
  for( ; n > 0; n /= 10){
    v.push_back(n % 10);
  }
  reverse(v.begin(), v.end());
  return v;
}

int GetMul(int i){
  return i % 2 == 1 ? -1 : 1;
}

void Update(map<int,int>& dp_prev, int d, map<int,int>& dp_cur){
  for(pii p: dp_prev){
    int k = - p.first - d, val = p.second;
    dp_cur[k] += val;
  }
}

int CollectAns(map<int,int>& dp){
  int ans = 0;
  for(pii p: dp){
    if(p.first == 1){
      ans += p.second;
    }
  }
  return ans;
}

int Calculate(int n){
  if(n <= 0){
    return 0;
  }

  vector<int> v = Int2Vec(n);
  
  int m = v.size();
  vector<map<int,int>> dp_less(m + 1), dp_equal(m + 1);

  dp_equal[0][0] = 1;
  for(int i = 1; i <= m; ++i){
    for(int d = 0; d <= 9; ++d){
      Update(dp_less[i - 1], d, dp_less[i]);
    }

    for(int d = 0; d < v[i - 1]; ++d){
      Update(dp_equal[i - 1], d, dp_less[i]);
    }

    Update(dp_equal[i - 1], v[i - 1], dp_equal[i]);
  }

  return CollectAns(dp_less[m]) + CollectAns(dp_equal[m]);
}

int Solve(){
  int a, b;
  scanf("%d%d", &a, &b);
  return Calculate(b) - Calculate(a - 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}