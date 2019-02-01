#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

bool IsPrime(int n){
  if(n == 1)
    return 0;
  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0)
      return 0;
  }
  return 1;
}

int main(){
  int n, m, k;

  scanf("%d%d", &n, &m);

  k = n - 1;
  for( ; IsPrime(k) == 0; ++k);

  printf("%d %d\n", k, k);

  printf("1 2 %d\n", k - n + 2);
  for(int i = 2; i < n; ++i)
    printf("%d %d %d\n", i, i + 1, 1);

  m -= (n - 1);
  ++k;

  for(int i = 1; i <= n && m > 0; ++i){
    for(int j = i + 2; j <= n && m > 0; ++j, --m){
      printf("%d %d %d\n", i, j, k);
    }
  }

  return 0;
}
