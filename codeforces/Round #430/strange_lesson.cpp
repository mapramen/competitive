#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 19
#define N (1 << B)

int T[2][B * N + 1], c[B * N + 1], nxt = 0;
vector<int> v;

void Insert(int x, int val){
  int i = 0;
  for(int k = B - 1; k > -1; --k){
    int j = ((x & (1 << k)) > 0);
    if(T[j][i] == 0)
      T[j][i] = ++nxt;
    c[i] += val;
    i = T[j][i];
  }
  c[i] += val;
}

int Query(int x){
  int ans = 0;
  for(int i = 0, k = B - 1; k > -1; --k){
    int j = ((x & (1 << k)) > 0);
    if(c[T[j][i]] < 0)
      i = T[j][i];
    else
      ans |= (1 << k), i = T[1 - j][i];
  }
  return ans;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    int j;
    scanf("%d", &j);
    v.PB(j);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for(int i = 0; i < N; ++i)
    Insert(i, -1);

  for(auto i : v)
    Insert(i, 1);

  int x = 0;
  while(m--){
    int i;
    scanf("%d", &i);
    x = (x ^ i);
    printf("%d\n", Query(x));
  }

  return 0;
}
