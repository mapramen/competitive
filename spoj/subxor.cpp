#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 20
#define N 100001
#define M (B * N)

int T[2][M], C[M], total = 0;

void Reset(){
  for(int i = 0; i <= total; ++i){
    T[0][i] = 0, T[1][i] = 0, C[i] = 0;
  }
}

void Add(int x){
  int i = 0;
  for(int k = B - 1; k != -1; --k){
    int j = (x & (1 << k)) != 0;
    if(T[j][i] == 0){
      T[j][i] = ++total;
    }
    i = T[j][i];
    ++C[i];
  }
}

int Query(int x, int y){
  int i = 0, ans = 0;
  
  for(int k = B - 1; k != -1; --k){
    int jx = (x & (1 << k)) != 0;
    int jy = (y & (1 << k)) != 0;

    if(jy == 1){
      ans += C[T[jx][i]];
    }

    if(T[jy ^ jx][i] == 0){
      break;
    }
    
    i = T[jy ^ jx][i];
  }

  return ans;
}

ll Solve(){
  Reset();

  int n, k;
  scanf("%d%d", &n, &k);

  Add(0);

  ll ans = 0;
  
  for(int i = 1, s = 0; i <= n; ++i){
    int x;
    scanf("%d", &x);
    s ^= x;
    ans += Query(s, k);
    Add(s);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}