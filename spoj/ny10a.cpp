#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B (1 << 3)

void Solve(){
  int n;
  string s;

  scanf("%d", &n);
  cin >> s;

  vector<int> c(B);
  for(int i = 0, x = 0, m = s.size(); i < m; ++i){
    x = ((x << 1) | (s[i] == 'H')) & (B - 1);

    if(i >= 2){
      ++c[x];
    }
  }

  printf("%d ", n);
  for(int x: c){
    printf("%d ", x);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}