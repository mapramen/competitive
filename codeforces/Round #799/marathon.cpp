#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 4

int a[N];

int Solve(){
  for(int i = 0; i < N; ++i){
    scanf("%d", &a[i]);
  }

  int ans = 0;
  for(int i = 0; i < N; ++i){
    ans += (a[i] > a[0]);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}