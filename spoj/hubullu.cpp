#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n, f;
  scanf("%d%d", &n, &f);
  return f == 0;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s wins.\n", Solve() ? "Airborne" : "Pagfloyd");
  }
  return 0;
}