#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

bool ans[N];

int main(){
  int K, L, m;
  scanf("%d%d%d", &K, &L, &m);

  for(int i = 1; i < N; ++i){
    bool win = ans[i - 1];
    if(i >= K){
      win = win && ans[i - K];
    }

    if(i >= L){
      win = win && ans[i - L];
    }

    ans[i] = !win;
  }

  while(m--){
    int n;
    scanf("%d", &n);
    putchar(ans[n] ? 'A' : 'B');
  }
  putchar('\n');
  
  return 0;
}