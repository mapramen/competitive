#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

int a[N];

void Solve(){
  int n;
  scanf("%d", &n);

  int s = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    s += a[i];
  }

  bool isPrime = true;
  for(int x = 2; x * x <= s && isPrime; ++x){
    isPrime = s % x != 0;
  }

  printf("%d\n", n - isPrime);

  for(int i = 1; i <= n; ++i){
    if(isPrime && a[i] % 2 == 1){
      isPrime = false;
      continue;
    }
    printf("%d ", i);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    Solve();
  }

  return 0;
}