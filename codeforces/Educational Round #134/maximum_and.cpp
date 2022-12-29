#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 30

vector<pair<vector<int>,vector<int>>> V;

void CheckAndPush(vector<int>& a, vector<int>& b){
  if(a.empty()){
    return;
  }
  V.push_back({a, b});
}

int GetKthBitOnCount(int k, vector<int>& a){
  int cnt = 0;
  for(int& x: a){
    cnt += (x & (1 << k)) == 0;
  }
  return cnt;
}

pair<vector<int>,vector<int>> SplitByKthBit(int k, vector<int>& a){
  vector<int> a0, a1;
  for(int& x: a){
    if((x & (1 << k)) == 0){
      a0.push_back(x);
    }
    else{
      a1.push_back(x);
    }
  }
  a.clear();
  return {a0, a1};
}

void SplitByKthBit(int k){
  if(V.empty()){
    return;
  }
  
  auto [a, b] = V.back();
  V.pop_back();

  SplitByKthBit(k);

  auto [a0, a1] = SplitByKthBit(k, a);
  auto [b0, b1] = SplitByKthBit(k, b);
  
  CheckAndPush(a0, b1);
  CheckAndPush(a1, b0);
}

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  vector<int> b(n);
  for(int& x: b){
    scanf("%d", &x);
  }

  CheckAndPush(a, b);

  int ans = 0;
  for(int k = B - 1; k != -1; --k){
    bool should_split = true;
    for(auto [a, b]: V){
      should_split = should_split && (GetKthBitOnCount(k, a) == a.size() - GetKthBitOnCount(k, b));
    }

    if(!should_split){
      continue;
    }

    ans |= (1 << k);
    SplitByKthBit(k);
  }

  V.clear();
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}