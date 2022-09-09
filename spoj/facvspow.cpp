#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2750000

long double s[N];

void Initialize(){
  for(int i = 2; i < N; ++i){
    s[i] = s[i - 1] + logl(i);
  }

  for(int i = 1; i < N; ++i){
    s[i] /= i;
    s[i] = expl(s[i]);
  }
}

int Solve(){
  int a;
  scanf("%d", &a);
  return upper_bound(s, s + N, a) - s;
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