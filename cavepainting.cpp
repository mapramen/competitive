#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, k;
  set<ll> S;

  cin >> n >> k;

  for(ll i = 1; i <= k; ++i){
    int x = n % i;
    if(S.find(x) != S.end()){
      printf("No\n");
      return 0;
    }
    else
      S.insert(x);
  }

  printf("Yes\n");

  return 0;
}
