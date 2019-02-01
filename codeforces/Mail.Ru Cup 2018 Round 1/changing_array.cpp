#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define B 30
#define M (B * N)

int T[M][2], C[M], nxt;

void Insert(int x){
  for(int i = 0, k = B - 1; k > -1; --k){
    int j = ((x & (1 << k)) > 0);
    if(T[i][j] == 0){
      T[i][j] = ++nxt;
    }
    i = T[i][j];
    ++C[i];
  }
}

int Query(int x){
  int i = 0;
  for(int k = B - 1; k > -1; --k){
    int j = ((x & (1 << k)) > 0);
    if(T[i][j] == 0){
      return 0;
    }
    i = T[i][j];
  }
  return C[i];
}

int main(){
  int n, k;

  scanf("%d%d", &n, &k);

  int allMask = (1 << k) - 1;
  ll ans = 0;
  Insert(0);

  for(int i = 1, y = 0; i <= n; ++i){
    int x;
    scanf("%d", &x);
    y ^= x;

    int zeros = Query(y), ones = Query(allMask ^ y);
    if(zeros < ones){
      ans += (i - zeros);
    }
    else{
      ans += (i - ones);
      y ^= allMask;
    }

    Insert(y);
  }

  printf("%lld\n", ans);

  return 0;
}
