#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

bool visited[N];

int main(){
  int n;

  scanf("%d", &n);

  printf("1 ");
  for(int i = 1, j = n; i <= n; ++i){
    int k;
    scanf("%d", &k);
    visited[k] = 1;
    for( ; j > 0 && visited[j] == 1; --j);
    int ans = 1 + i + j - n;
    printf("%d ", ans);
  }
  printf("\n");

  return 0;
}
