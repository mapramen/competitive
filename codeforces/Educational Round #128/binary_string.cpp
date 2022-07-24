#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 400001

char s[N];
int zero_count[N], one_count[N];

int GetZeroCount(int l, int r){
  return zero_count[r] - zero_count[l - 1];
}

int GetOneCount(int l, int r){
  return one_count[r] - one_count[l - 1];
}

int Solve(){
  scanf("%s", s);

  int n = strlen(s);
  for(int i = 1; i <= 2 * n; ++i){
    char c = s[(i - 1) % n];
    zero_count[i] = zero_count[i - 1] + (c == '0');
    one_count[i] = one_count[i - 1] + (c == '1');
  }

  int ans = n;
  for(int i = 1, j = 1; i <= n; ++i){
    for(j = max(i - 1, j - 5); j <= n; ++j){
      int zcount = GetZeroCount(i, j), ocount = GetOneCount(j + 1, i + n - 1);
      ans = min(ans, max(zcount, ocount));
      if(zcount > ocount){
        break;
      }
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