#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];

void Print(int n){
  printf("YES\n");
  for(int i = 1; i <= n; ++i)
    printf("%d ", a[i]);
  printf("\n");
}

void P(int n){
  if(n % 2){
    printf("NO");
    return ;
  }

  for(int i = 1; i <= n; ++i)
    a[i] = i;

  for(int k = 0; (1 << k) < n; ++k)
    for(int i = 1, j = i + (1 << k); j <= n; ++i, ++j)
      swap(a[i], a[j]);

  Print(n);
}

void Q(int n){
  if((n & (n - 1)) == 0){
    printf("NO\n");
    return ;
  }

  for(int k = 1; k <= n; k = (k << 1)){
    vector<int> v;
    for(int i = 1, x = k; x <= n; ++i, x += k){
      if(i % 2)
        v.PB(x);
    }
    for(int i = 0, m = v.size(); i < m; ++i)
      a[v[i]] = v[(i + 1) % m];
  }

  Print(n);
}

int main(){
  int n;

  scanf("%d", &n);

  P(n);
  Q(n);

  return 0;
}
