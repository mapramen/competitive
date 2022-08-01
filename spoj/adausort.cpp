#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i].first);
    a[i].second = -(i + 1);
  }
  sort(a.begin(), a.end());

  for(pii p: a){
    printf("%d ", -p.second);
  }
  printf("\n");
  
  return 0;
}