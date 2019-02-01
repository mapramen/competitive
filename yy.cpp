#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N], c[N];

int main(){
  for(int i = 1, s = 0; s < N; ++i){
    s += i;
    for(int j = s, k = s + i + 1; j < k && j < N; ++j)
      a[j] = s, c[j] = i;
  }

  int k;
  scanf("%d", &k);

  if(k == 0)
    putchar('a');

  for(int i = 0; k > 0; k -= a[k], ++i){
    int j = c[k] + 1;
    while(j--)
      putchar('a' + i);
  }
  putchar('\n');

  return 0;
}
