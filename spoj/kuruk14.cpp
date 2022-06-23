#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

int c[N];

void Reset(){
  for(int i = 0; i < N; ++i){
    c[i] = 0;
  }
}

bool Solve(){
  int n;
  scanf("%d", &n);

  Reset();
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ++c[x];
  }

  for(int i = 1; i <= n; ++i){
    if(c[i - 1] + c[n - i] != 2){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}