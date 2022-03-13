#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  ll m = 0;
  for(int x: a){
    if(x > m + 1){
      break;
    }
    m += x;
  }

  printf("%lld\n", m + 1);
  
  return 0;
}