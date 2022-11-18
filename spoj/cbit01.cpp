#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

bool win[N];

void Initialize(){
  for(int i = 1; i < N; ++i){
    bool ans = true;
    for(int x = 1; x * x <= i && ans; ++x){
      ans = win[i - x * x];
    }
    win[i] = !ans;
  }
}

bool Solve(){
  int n;
  scanf("%d", &n);
  return win[n];
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%s\n", Solve() ? "Win" : "Lose");
  }
  
  return 0;
}