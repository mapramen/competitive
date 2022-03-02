#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  int ans = 0;
  for(int i = 0, j = 0; j < n; ++i){
    for( ; j < n && a[j] - a[i] < k; ++j);
    ans += (j < n && a[j] - a[i] == k);
  }

  printf("%d\n", ans);
  
  return 0;
}