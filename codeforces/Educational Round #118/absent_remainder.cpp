#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  
  int y = *min_element(a + 1, a + n + 1);
  for(int i = 1, k = n / 2; i <= n && k > 0; ++i){
    if(a[i] == y){
      continue;
    }
    printf("%d %d\n", a[i], y);
    --k;
  }
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    Solve();
  }

  return 0;
}