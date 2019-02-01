#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int d[N];

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    int a;
    scanf("%d", &a);
    if(a == 0)
      d[i] = 0;
    else
      d[i] = n + 1;
  }

  for(int i = 2; i <= n; i++)
    d[i] = min(d[i], 1 + d[i - 1]);

  for(int i = n - 1; i > 0; i--)
    d[i] = min(d[i], 1 + d[i + 1]);

  for(int i = 1; i <= n; i++)
    printf("%d ", d[i]);
  printf("\n");
  
  return 0;
}
