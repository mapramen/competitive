#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<int> p(n + 1);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &p[i]);
  }

  for(int i = 1; i <= n; ++i){
    if(p[i] == i){
      continue;
    }

    int j = i;
    for( ; p[j] != i; ++j);

    while(i < j){
      swap(p[i], p[j]);
      ++i, --j;
    }

    break;
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", p[i]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}