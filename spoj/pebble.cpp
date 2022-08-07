#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

char s[N + 1];

int Solve(){
  if(scanf("%s", s + 1) == EOF){
    exit(0);
  }
  s[0] = '0';

  int ans = 0;
  for(int i = 1; s[i] != '\0'; ++i){
    ans += (s[i] != s[i - 1]);
  }

  return ans;
}

int main(){
  for(int k = 1; ; ++k){
    printf("Game #%d: %d\n", k, Solve());
  }
  return 0;
}