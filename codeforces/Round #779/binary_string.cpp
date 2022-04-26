#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, m;
  string s;

  cin >> n >> m >> s;

  int ones = 0;
  for(char c: s){
    ones += c == '1';
  }

  if((1ll * ones * m) % n != 0){
    printf("-1\n");
    return;
  }

  ones = (1ll * ones * m) / n;

  int i = 0;
  for(int j = 0, c = 0; i < n; ++i){
    for( ; j - i < m; ++j){
      c += (s[j % n] == '1');
    }

    if(ones == c){
      break;
    }

    c -= (s[i] == '1');
  }

  int j = i + m - 1;
  if(j < n){
    printf("1\n%d %d\n", i + 1, j + 1);
  }
  else{
    printf("2\n%d %d\n%d %d\n", 1, j % n + 1, i + 1, n);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}