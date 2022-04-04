#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 26

ll a[N], b[N], c[N];

void Initialise(){
  a[0] = 1, a[1] = 1, b[1] = 1, c[1] = 1;

  for(int i = 2; i < N; ++i){
    a[i] = a[i - 2] + a[i - 1] + 2 * b[i - 1] + c[i - 1];
    b[i] = b[i - 1] + a[i - 1];
    c[i] = c[i - 2] + a[i - 1];
  }
}

ll Solve(){
  int n;
  scanf("%d", &n);
  return a[n];
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("%d %lld\n", k, Solve());
  }
  
  return 0;
}