#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 20000001

int c[N];
bool dp[N];

void Initialize(){
  for(int i = 1; i * i < N; ++i){
    for(int j = i * i; j < N; j += i){
      c[j] += 2;
    }
    --c[i * i];
  }

  for(int i = 1, j = 0; i < N; ++i){
    if(i - j <= c[i]){
      dp[i] = true;
    }
    else{
      j = i;
    }
  }
}

bool Solve(){
  int n;
  scanf("%d", &n);
  return dp[n];
}

int main(){
  Initialize();
  
  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%s\n", Solve() ? "Ada" : "Vinit");
  }
  
  return 0;
}