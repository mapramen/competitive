#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 31

ll a[N], b[N];

void Initialize(){
  a[1] = 1;

  for(int i = 2; i < N; ++i){
    a[i] = a[i - 1] + 2 * b[i - 1];
    b[i] = a[i - 1] + b[i - 1];
  }
}

ll Solve(){
  int n;
  scanf("%d", &n);
  return 3 * (a[n] + 2 * b[n]);
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%lld\n", Solve());
  }
  
  return 0;
}