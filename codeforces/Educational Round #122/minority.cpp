#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  string s;
  cin >> s;

  int n = s.size(), zeros = 0;
  for(char c: s){
    zeros += (c == '0');
  }
  zeros = min(zeros, n - zeros);

  if(2 * zeros < n){
    return zeros;
  }

  return n == 2 ? 0 : zeros - 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}