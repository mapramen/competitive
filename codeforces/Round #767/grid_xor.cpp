#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000

int a[N][N];

int GetContribution(int x, int r, int c){
  return x == 0 ? 0 : a[r][c];
}

int GetContribution(int r1, int r2, int c1, int c2, int x, int y){
  int ans = 0;
  for(int c = c1; c <= c2; ++c){
    ans ^= GetContribution(x, r1, c);
  }

  if(r2 != r1){
    for(int c = c1; c <= c2; ++c){
      ans ^= GetContribution(x, r2, c);
    }
  }

  for(int r = r1 + 1, z = x ^ y; r < r2; ++r, z ^= y){
    ans ^= (GetContribution(z, r, c1) ^ GetContribution(z, r, c2));
  }

  return ans;
}

int Solve(int n, int r1, int r2, int c1, int c2, int x){
  if(n <= 0){
    return 0;
  }

  return GetContribution(r1, r2, c1, c2, x, 1) 
  ^ GetContribution(r1 + 1, r2 - 1, c1 + 1, c2 - 1, x, 0)
  ^ Solve(n - 4, r1 + 2, r2 - 2, c1 + 2, c2 - 2, 1 ^ x);
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  return Solve(n, 0, n - 2, 0, n - 1, 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}