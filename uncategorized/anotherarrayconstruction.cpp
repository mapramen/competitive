#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];
set<int> s;

bool IsValid(int n){
  for(auto x : s){
    if(1ll * x * x > n)
      break;
    if(n % x == 0)
      return 0;
  }
  return s.find(n) == s.end();
}

void AddPrimes(int n){
  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0){
      s.insert(i);
      while(n % i == 0)
        n /= i;
    }
  }
  if(n > 1)
    s.insert(n);
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  int k = 1;
  for(int i = 1; i <= n; ++i, ++k){
    if(IsValid(a[i])){
      AddPrimes(a[i]);
    }
    else{
      for(++a[i]; IsValid(a[i]) == 0; ++a[i]);
      AddPrimes(a[i]);
      break;
    }
  }

  ++k;

  for(int x = 2; k <= n; ++k, ++x){
    for( ; IsValid(x) == 0; ++x);
    a[k] = x;
    AddPrimes(x);
  }

  for(int i = 1; i <= n; ++i)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}
