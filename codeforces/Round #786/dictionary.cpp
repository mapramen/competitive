#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  string s;
  cin >> s;

  int x = s[0] - 'a' + 1, y = s[1] - 'a' + 1;
  return (x - 1) * 25 + (y - (y > x));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}