#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1500

void PrintSuccessProbabilities(int k, int D){
  for(int d = 2; d <= D; ++d){
    double p = pow(k, d - 1);
    p *= (k - 1);
    p /= (pow(k, d) - 1);
    printf("%.15lf ", p);
  }
  printf("\n");
}

int main(){
  for(ll k = 2; k < N; ++k){
    ll s = 0, d = -1;
    for(ll p = 1; s + p <= N; s += p, p *= k, ++d);
    ll D = 2 * d;
    printf("k = %lld d = %lld D = %lld s = %lld\n", k, d, D, s);
    PrintSuccessProbabilities(k, d + 1);
  }

  return 0;
}
