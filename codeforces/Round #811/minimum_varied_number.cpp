#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  string s;
  for(int d = 9; d > 0 && n > 0; --d){
    if(d <= n){
      s.push_back('0' + d);
      n -= d;
    }
  }
  reverse(s.begin(), s.end());

  return stoi(s.c_str());
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}