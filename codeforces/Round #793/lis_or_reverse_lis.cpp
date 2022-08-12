#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  map<int,int> C;
  while(n--){
    int x;
    scanf("%d", &x);
    ++C[x];
  }

  int more_than_one_cnt = 0, one_cnt = 0;
  for(auto &[k, v]: C){
    if(v == 1){
      ++one_cnt;
    }
    else{
      ++more_than_one_cnt;
    }
  }

  return more_than_one_cnt + (1 + one_cnt) / 2;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}