#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int c[N];

int main(){
  int n, q;

  scanf("%d", &n);
  while(n--){
    int i;
    scanf("%d", &i);
    ++c[i];
  }

  for(int i = 1; i < N; ++i)
    for(int j = i + i; j < N; j += i)
      c[i] += c[j];

  scanf("%d", &q);
  while(q--){
    int k;
    scanf("%d", &k);
    printf("%d\n", c[k]);
  }

  return 0;
}
