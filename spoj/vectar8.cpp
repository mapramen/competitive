#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int c[N];

bool HasZero(int n){
  for( ; n > 0; n /= 10){
    if(n % 10 == 0){
      return true;
    }
  }
  return false;
}

int RemoveLeading(int n){
  int p = 1;
  while(p <= n){
    p *= 10;
  }
  p /= 10;
  return n % p;
}

void Initialize(){
  for(int i = 2; i < N; ++i){
    c[i] = 1;
  }

  for(int i = 2; i < N; ++i){
    for(int j = 2 * i; j < N; j += i){
      c[j] = 0;
    }
  }

  for(int i = 10; i < N; ++i){
    if(c[i] == 0 || HasZero(i)){
      c[i] = 0;
      continue;
    }
    c[i] = c[RemoveLeading(i)];
  }

  for(int i = 2; i < N; ++i){
    c[i] += c[i - 1];
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return c[n];
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