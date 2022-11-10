#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001

int rt[N], c[N];

void Initialize(){
  for(int i = 1; i < N; ++i){
    int x = 1;
    for( ; x * x <= i; ++x);
    rt[i] = x - 1;
  }
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    c[i] = 1;
  }

  for(int i = n; i > 1 && m > 0; --i){
    while(c[i] > 0 && m > 0){
      int j = rt[i];
      --c[i], ++c[j], --m;
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += i * c[i];
  }

  return ans;
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