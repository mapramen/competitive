#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  string s;

  cin >> n >> s;

  int ans = 0;
  for(int i = 0, px = -10; i < n; ++i){
    if(s[i] == '1'){
      continue;
    }
    int cx = i;
    ans += 2 - min(2, cx - px - 1);
    px = cx;
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