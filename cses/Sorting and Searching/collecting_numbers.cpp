#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int idx[N];

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    idx[x] = i;
  }

  int ans = 1;
  for(int i = 2; i <= n; ++i){
    ans += (idx[i] < idx[i - 1]);
  }

  printf("%d\n", ans);
  
  return 0;
}