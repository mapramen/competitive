#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

char s[N];

int Solve(){
  int n, k;
  scanf("%d%d%s", &n, &k, s);

  int ans = k;
  for(int i = 0, j = 0, c = 0; j < n; ++i){
    for( ; j < n && j - i < k; ++j){
      c += (s[j] == 'W');
    }
    ans = min(ans, c);
    c -= (s[i] == 'W');
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