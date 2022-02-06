#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  if(n == 4){
    if(k == 0){
      printf("0 3\n1 2\n");
    }
    else if(k == 1){
      printf("0 2\n1 3\n");
    }
    else if(k == 2){
      printf("0 1\n2 3\n");
    }
    else{
      printf("-1\n");
    }
    return;
  }

  int m = n / 2;

  if(k != n - 1){
    printf("0 %d\n", n - 1 - k);
    for(int i = 1; i < m; ++i){
      if(i == k || i + k == n - 1){
        continue;
      }
      printf("%d %d\n", i, n - 1 - i);
    }
    if(k != 0){
      printf("%d %d\n", k, n - 1);
    }
    return;
  }

  printf("0 1\n");
  printf("2 %d\n", n - 4);
  printf("3 %d\n", n - 3);

  for(int i = 4; i < m; ++i){
    printf("%d %d\n", i, n - 1 - i);
  }

  printf("%d %d\n", n - 2, n - 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}