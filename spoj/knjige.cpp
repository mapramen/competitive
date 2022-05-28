#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001

int a[N];

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int ans = n;
  for(int i = n; i != 0; --i){
    ans -= (a[i] == ans);
  }

  printf("%d\n", ans);
  
  return 0;
}