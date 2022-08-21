#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int GetValue(char c){
  return c - '0';
}

int GetSum(string s){
  int x = 0;
  for(char c: s){
    x += GetValue(c);
  }
  return x;
}

int Solve(){
  int n, k;
  string s;
  cin >> n >> k >> s;

  int m = GetSum(s);
  if(m == 0){
    return 0;
  }
  
  int x = n + 1, y = n + 1;
  for(int i = 0; i < n; ++i){
    if(s[i] == '0'){
      continue;
    }
    if(x > n){
      x = i;
    }
    y = i;
  }
  y = n - 1 - y;

  if(m == 1){
    if(y <= k){
      return 1;
    }
    if(x <= k){
      return 10;
    }
    return 11;
  }

  if(x + y <= k){
    return 11 * (m - 1);
  }

  if(y != 0 && y <= k){
    return 11 * m - GetValue(s.front()) - 10;
  }

  if(x != 0 && x <= k){
    return 11 * m - 1 - 10 * GetValue(s.back());
  }

  return 11 * m - GetValue(s.front()) - 10 * GetValue(s.back());
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}