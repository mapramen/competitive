#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < (1 << n); ++i){
    int g = i ^ (i >> 1);
    for(int k = 0; k < n; ++k){
      putchar('0' + g % 2);
      g /= 2;
    }
    printf("\n");
  }

  return 0;
}