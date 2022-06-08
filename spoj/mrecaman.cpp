#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 500001

int a[N];
set<int> S;

void Initialize(){
  a[0] = 0;
  S.insert(0);

  for(int i = 1; i < N; ++i){
    int x = a[i - 1] - i;
    a[i] = x > 0 && S.count(x) == 0 ? x : x + 2 * i;
    S.insert(a[i]);
  }
}

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == -1){
    exit(0);
  }

  return a[n];
}

int main(){
  Initialize();

  while(true){
    printf("%d\n", Solve());
  }
  
  return 0;
}