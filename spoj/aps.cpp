#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000001

ll a[N];

void Initialise(){
  for(int i = 2; i < N; ++i){
    if(a[i] != 0){
      continue;
    }
    for(int j = i; j < N; j += i){
      if(a[j] == 0){
        a[j] = i;
      }
    }
  }

  for(int i = 2; i < N; ++i){
    a[i] += a[i - 1];
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
  while(t--){
    printf("%lld\n", Solve());
  }
  
  return 0;
}