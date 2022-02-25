#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int c[N];

void Initialise(){
  for(int i = 1; i < N; ++i){
    for(int j = i; j < N; j += i){
      ++c[j];
    }
  }
}

int Solve(){
  int a, b;
  scanf("%d%d", &a, &b);
  return c[__gcd(a, b)];
}

int main(){
  int t;
  scanf("%d", &t);

  Initialise();

  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}