#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  vector<int> a(n + 1);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    int j = a[a[i]];
    if(j != i){
      return false;
    }
  }

  return true;
}

int main(){
  while(true){
    printf("%s\n", Solve() ? "ambiguous" : "not ambiguous");
  }
  return 0;
}