#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define B 30

int a[N], T[2][B * N], C[2 * B * N], nxt;

void Update(int val, int x){
  int i = 0;
  for(int k = B - 1; k > -1; --k){
    int j = (val & (1 << k)) > 0;
    if(T[j][i] == 0)
      T[j][i] = ++nxt;
    C[i] += x;
    i = T[j][i];
  }
  C[i] += x;
}

int GetMin(int val){
  int i = 0, ans = 0;
  for(int k = B - 1; k > -1; --k){
    int j = (val & (1 << k)) > 0;
    if(T[j][i] != 0 && C[T[j][i]] > 0)
      i = T[j][i];
    else
      ans |= (1 << k), i = T[1 - j][i];
  }
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; ++i){
    int j;
    scanf("%d", &j);
    Update(j, 1);
  }

  for(int i = 1; i <= n; ++i){
    int j = GetMin(a[i]);
    Update(j ^ a[i], -1);
    a[i] = j;
  }

  for(int i = 1; i <= n; ++i)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}
