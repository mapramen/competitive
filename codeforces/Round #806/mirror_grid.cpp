#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

char s[N][N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  int ans = 0;
  for(int i = 0, j = n - 1; i < j; ++i, --j){
    for(int k = i; k < j; ++k){
      int cnt = 0;
      cnt += (s[i][k] == '1');
      cnt += (s[k][j] == '1');
      cnt += (s[j][j - (k - i)] == '1');
      cnt += (s[j - (k - i)][i] == '1');
      ans += min(cnt, 4 - cnt);
    }
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