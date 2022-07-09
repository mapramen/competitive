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

  for(int i = 1, j = n; i < j; ){
    if(a[i] < 0){
      ++i;
      continue;
    }

    if(a[j] > 0){
      --j;
      continue;
    }

    a[i] *= -1, a[j] *= -1;
    ++i, --j;
  }

  for(int i = 2; i <= n; ++i){
    if(a[i] < a[i - 1]){
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