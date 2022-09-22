#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

char s[N];

ll Solve(){
  scanf("%s", s);

  ll c1 = 0, c2 = 0, c3 = 0;
  for(int i = 0; s[i] != '\0'; ++i){
    if(s[i] == 's'){
      ++c1, c3 += c2;
    }
    else if(s[i] == 'm'){
      c2 += c1;
    }
  }

  return c3;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}