#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

bool present[N];

int main(){
  int n;
  scanf("%d", &n);

  while(n--){
    int i;
    scanf("%d", &i);
    present[i] = true;
  }

  int ans = 0;
  for(int i = N - 1; i != 0; --i){
    if(present[i]){
      continue;
    }

    int g = 0;
    for(int j = 2 * i; j < N; j += i){
      if(present[j]){
        g = __gcd(g, j);
      }
    }

    if(g == i){
      present[i] = true;
      ++ans;
    }
  }

  printf("%d\n", ans);
  
  return 0;
}