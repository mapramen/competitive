#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 51

int a[N];

bool Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  if(n % 2 == 1){
    return true;
  }

  int x = *min_element(a + 1, a + n + 1);
  for(int i = 1; i <= n; ++i){
    if(a[i] != x){
      continue;
    }
    return i % 2 != 1;
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Mike" : "Joe");
  }
  return 0;
}