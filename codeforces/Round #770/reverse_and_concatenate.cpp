#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, k;
  string s;

  scanf("%d%d", &n, &k);
  cin >> s;

  string t(s);
  reverse(t.begin(), t.end());

  if(s == t){
    return 1;
  }

  return k == 0 ? 1 : 2;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}