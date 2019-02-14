#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 10001

int p[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int x = 1; x <= n; x++)
    scanf("%d", &p[x]);

  while(m--){
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);

    int pos = l;
    for(int i = l; i <= r; i++)
      pos += (p[i] < p[x]);

    if(pos == x)
      printf("Yes\n");
    else
      printf("No\n");
  }
  
  return 0;
}
