#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define M 11

const ll N = 10000000000;
map<ll,int> lenghtMap;
map< ll, string > dp[M + 1];

void Update(ll n, string s){
  if(s.size() >= to_string(n).size()){
    return;
  }

  int currentLength = M + 1;
  int newLength = s.size();

  if(lenghtMap.find(n) == lenghtMap.end()){
    lenghtMap[n] = newLength;
    dp[newLength][n] = s;
    currentLength = newLength;
  }
  else{
    currentLength = lenghtMap[n];
  }

  if(newLength >= currentLength){
    return ;
  }

  lenghtMap[n] = newLength;
  dp[currentLength].erase(n);
  dp[newLength][n] = s;
}

int main(){
  for(ll i = 2; i * i <= N; ++i){
    for(ll x = i * i, j = 2; x <= N; x *= i, ++j){
      string s = to_string(i) + "^" + to_string(j);
      for(int tlength = 3; tlength + s.size() + 1 <= M; ++tlength){
        for(auto p : dp[tlength]){
          ll y;
          string t;
          tie(y, t) = p;
          if(y >= N / x){
            break;
          }
          Update(x * y, t + "*" + s);
        }
      }
      Update(x, s);
    }
  }

  for(int i = 0; i <= M; ++i){
    if(dp[i].size() == 0){
      continue;
    }
    cout << i << ' ' << dp[i].begin()->first << ' ' << dp[i].begin()->second << '\n';
  }

  return 0;
}
