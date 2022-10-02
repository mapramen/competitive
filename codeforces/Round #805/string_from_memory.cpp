#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

char s[N];

int Solve(){
  scanf("%s", s);

  int ans = 0;
  for(int i = 0, mask = (1 << 27) - 1; s[i] != '\0'; ++i){
    mask |= (1 << (s[i] - 'a'));
    if(__builtin_popcount(mask) > 3){
      ++ans;
      mask = 0;
    }
    mask |= (1 << (s[i] - 'a'));
  }

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