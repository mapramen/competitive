#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 4001

char s[N];
int parent[N], dp[N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 2; i <= n; ++i){
    scanf("%d", &parent[i]);
  }

  scanf("%s", s);

  for(int i = 1; i <= n; ++i){
    dp[i] = 0;
  }

  int ans = 0;
  for(int i = n; i != 0; --i){
    int cnt = dp[i] + (s[i - 1] == 'W' ? -1 : 1);
    dp[parent[i]] += cnt;
    dp[i] = cnt;
    ans += (cnt == 0);
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