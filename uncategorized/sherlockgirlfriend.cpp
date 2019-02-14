#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100005

bool isPrime[N];

int main(){
  int n, ans;

  scanf("%d", &n);
  n++;

  for(int i = 2; i <= n; i++)
    isPrime[i] = 1;

  for(int i = 2; i * i <= n; i++){
    if(isPrime[i] == 1){
      for(int j = i + i; j <= n; j += i)
        if(isPrime[j])
          isPrime[j] = 0;
    }
  }

  ans = 1 + (n > 3);

  printf("%d\n", ans);
  for(int i = 2; i <= n; i++){
    int color = isPrime[i] == 0 ? 2 : 1;
    printf("%d ", color);
  }
  printf("\n");

  return 0;
}
