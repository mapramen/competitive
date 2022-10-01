#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2

int Solve(){
  int cnt = 0;
  for(int x = 0; x < N; ++x){
    for(int y = 0; y < N; ++y){
      int z;
      scanf("%d", &z);
      cnt += z;
    }
  }

  if(cnt == 0){
    return 0;
  }

  return cnt == 4 ? 2 : 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}