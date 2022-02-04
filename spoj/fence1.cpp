#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

double Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  return n * n / (2 * M_PI);
}

int main(){
  while(true){
    printf("%.2f\n", Solve());
  }
  return 0;
}