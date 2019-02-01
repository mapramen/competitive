#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;

  scanf("%d", &n);

  if(n < 3){
    printf("No\n");
    return 0;
  }

  int m = (n + 1) / 2;

  printf("Yes\n1 %d\n", m);

  printf("%d ", n - 1);
  for(int i = 1; i <= n; ++i){
    if(i == m){
      continue;
    }
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}
