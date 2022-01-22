#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  int ans = 0;
  for(int i = 1; i * i <= n; ++i){
    for(int j = i * i; j <= n; j += i){
      ++ans;
    }
  }

  printf("%d\n", ans);
  
  return 0;
}