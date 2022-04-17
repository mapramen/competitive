#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N];

bool Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  int i = min_element(a, a + n) - a;
  if(a[i] != 1){
    return false;
  }

  int px = a[i];
  i = (i + 1) % n;
  for(int k = 1; k < n; ++k, i = (i + 1) % n){
    int cx = a[i];
    if(cx == 1 || cx - px > 1){
      return false;
    }
    px = cx;
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}