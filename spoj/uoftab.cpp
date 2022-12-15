#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5
#define M 300001

int a[N], s[N], o[N];
bitset<M> c;

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d%d", &a[i], &s[i], &o[i]);
    s[i] += a[i];
  }

  for(int x = 0; x < M; ++x){
    c.reset(x);
  }

  for(int i = 1; i <= n; ++i){
    for(int A = a[i], T = s[i], x = 0, y = o[i]; x < M; ++x, y = (y + 1) % T){
      if(y < A){
        c.set(x);
      }
    }
  }

  for(int x = 0; x < M; ++x){
    if(!c.test(x)){
      return x;
    }
  }

  return -1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int ans = Solve();
    if(ans != -1){
      printf("%d\n", ans);
    }
    else{
      printf("Foxen are too powerful\n");
    }
  }
  return 0;
}