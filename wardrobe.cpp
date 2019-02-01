#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 10001

bitset<N> A, B, C, D;
int a[N];
vector<int> b;

int main(){
  int n, l, r;

  scanf("%d%d%d", &n, &l, &r);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  B.set(0);
  for(int i = 1; i <= n; ++i){
    int j;
    scanf("%d", &j);
    if(j == 0)
      B |= (B << a[i]);
    else
      b.PB(a[i]);
  }

  b.PB(0);
  sort(b.begin(), b.end());

  for(int i = 1; i < b.size(); ++i)
    b[i] += b[i - 1];

  int ans = 0;
  for(int i = b.size() - 1, j = l; i > 0; --i){
    b[i] -= b[i - 1];
    A |= (A << b[i]);
    A |= B;
    B = (B << b[i]);

    for( ; j < r - b[i - 1] + 1; ++j)
      C.set(j);

    if(j > l){
      D = (A & C);
      if(D.any()){
        ans = i;
        break;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
