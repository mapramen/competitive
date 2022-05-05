#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

ll f[N];

void Initialise(){
  for(int i = 1; i < N; ++i){
    f[i] += f[i - 1];
    for(int j = 2 * i; j < N; j += i){
      f[j] += i;
    }
  }
}

ll Solve(){
  int n;
  scanf("%d", &n);
  return f[n];
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%lld\n", Solve());
  }
  
  return 0;
}