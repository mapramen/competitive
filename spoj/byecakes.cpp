#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 4

int a[B], A[B];

void Solve(){
  for(int i = 0; i < B; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 0; i < B; ++i){
    scanf("%d", &A[i]);
  }

  if(a[0] == -1){
    exit(0);
  }

  int n = 0;
  for(int i = 0; i < B; ++i){
    n = max(n, (a[i] + A[i] - 1) / A[i]);
  }

  for(int i = 0; i < B; ++i){
    printf("%d ", n * A[i] - a[i]);
  }
  printf("\n");
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}