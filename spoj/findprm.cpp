#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000001

int c[N];

void Initialize(){
  for(int i = 2; i < N; ++i){
    c[i] = 1;
  }

  for(int i = 2; i * i < N; ++i){
    for(int j = i * i; j < N; j += i){
      c[j] = 0;
    }
  }

  for(int i = 1; i < N; ++i){
    c[i] += c[i - 1];
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return c[n] - c[(n / 2)];
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}