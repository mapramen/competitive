#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 4

int a[N];

int Solve(){
  for(int i = 0; i < N; ++i){
    if(scanf("%d", &a[i]) == EOF){
      exit(0);
    }
  }

  sort(a, a + N);
  return a[2] + a[3];
}

int main(){
  for(int k = 1; ; ++k){
    printf("Case %d: %d\n", k, Solve());
  }
  return 0;
}