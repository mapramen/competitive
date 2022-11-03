#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 61

char s[N];
int a[N];

bool IsPresent(int n, int d){
  for(int i = 0; i < n; ++i){
    if(a[i] == d){
      return true;
    }
  }
  return false;
}

ll Solve(){
  scanf("%s", s);

  int n = strlen(s);
  for(int i = 0; i < n; ++i){
    a[i] = -1;
  }

  for(int i = 0; i < n; ++i){
    if(a[i] != -1){
      continue;
    }

    int d = i == 0 ? 1 : 0;
    for( ; IsPresent(i, d); ++d);

    for(int j = i; j < n; ++j){
      if(s[j] == s[i]){
        a[j] = d;
      }
    }
  }

  int base = 1 + *max_element(a, a + n);

  ll ans = 0;
  for(int i = 0; i < n; ++i){
    ans = ans * base + a[i];
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %lld\n", k, Solve());
  }
  return 0;
}