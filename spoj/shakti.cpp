#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);
  return n % 2 == 0;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s Shaktiman\n", Solve() ? "Thankyou" : "Sorry");
  }
  return 0;
}