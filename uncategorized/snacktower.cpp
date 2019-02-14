#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

bool present[N];

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1, j = n; i <= n; i++){
    int k;
    scanf("%d", &k);
    present[k] = 1;

    for( ; j > 0 && present[j]; j--)
      printf("%d ", j);
    printf("\n");
  }

  return 0;
}
