#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 31

ll a[N];

void Initialise(){
  a[0] = 1, a[2] = 3;
  for(int i = 4; i < N; i += 2){
    a[i] = 4 * a[i - 2] - a[i - 4];
  }
}

ll Solve(){
  int n;
  scanf("%d", &n);

  if(n == -1){
    exit(0);
  }

  return a[n];
}

int main(){
  Initialise();

  while(true){
    printf("%lld\n", Solve());
  }
  return 0;
}