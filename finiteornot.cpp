#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    ll p, q, b;

    scanf("%lld%lld%lld", &p, &q, &b);

    q /= __gcd(p, q);

    for(b = __gcd(q, b); b != 1; q /= b, b = __gcd(q, b));

    if(q == 1){
      printf("Finite\n");
    }
    else{
      printf("Infinite\n");
    }
  }

  return 0;
}
