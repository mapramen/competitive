#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];

bool Check(int n, int x){
  int i = 1, j = n;
  while(i < j){
    if(a[i] == x){
      ++i;
      continue;
    }

    if(a[j] == x){
      --j;
      continue;
    }

    if(a[i] != a[j]){
      return false;
    }

    ++i, --j;
  }
  return true;
}

bool Solve(){
  int n;
  scanf("%d", &n);
  
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1, j = n; i < j; ++i, --j){
    if(a[i] == a[j]){
      continue;
    }
    return Check(n, a[i]) || Check(n, a[j]);
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