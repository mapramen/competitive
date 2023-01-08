#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

char s[N];

int Solve(){
  int n;
  scanf("%d%s", &n, s);

  for(int i = 2; i <= n; ++i){
    if(s[i - 2] == 'R' && s[i - 1] == 'L'){
      return 0;
    }
  }

  for(int i = 2; i <= n; ++i){
    if(s[i - 2] == 'L' && s[i - 1] == 'R'){
      return i - 1;
    }
  }

  return -1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}