#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define B 26

int c[B];
char s[N];

int Solve(){
  int n;
  scanf("%d%s", &n, s);

  for(int k = 0; k < B; ++k){
    c[k] = 0;
  }

  int ans = 0;
  for(int i = 0; i < 2 * n - 2; ++i){
    int k = tolower(s[i]) - 'a';
    if(i % 2 == 0){
      ++c[k];
      continue;
    }

    ans += (c[k] == 0);
    c[k] = max(0, c[k] - 1);
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