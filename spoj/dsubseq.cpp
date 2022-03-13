#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 26
#define N 100001
#define MOD 1000000007

char s[N];
int c[B];

int Solve(){
  scanf("%s", s);

  for(int k = 0; k < B; ++k){
    c[k] = 0;
  }

  int ans = 1;
  for(int i = 0; s[i] != '\0'; ++i){
    int k = s[i] - 'A';
    
    int d = (MOD + ans - c[k]) % MOD;
    c[k] = (c[k] + d) % MOD;
    ans = (ans + d) % MOD;
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