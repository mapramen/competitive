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

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    int x = a[i];
    bool found = false;

    for(int j = 1; j <= i && !found; ++j){
      found = a[i] % (j + 1) != 0;
    }

    if(!found){
      return false;
    }
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