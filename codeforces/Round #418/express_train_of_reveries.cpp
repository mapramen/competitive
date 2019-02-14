#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

int a[N], b[N], c[N];
bool visited[N];

bool Check(int x, int n){
  int s = n * (n + 1) / 2, cnt = 0;

  for(int i = 1; i <= n; i++)
    visited[i] = 0;

  for(int i = 1; i <= n; i++){
    if(i == x)
      continue;
    int j = a[i];
    c[i] = j;
    s -= (1 - visited[j]) * j;
    cnt += (1 - visited[j]);
    visited[j] = 1;
  }

  if(cnt < n - 1)
    return 0;

  c[x] = s;

  cnt = 0;
  for(int i = 1; i <= n; i++)
    cnt += (b[i] == c[i]);

  return (cnt >= n - 1);
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; i++)
    scanf("%d", &b[i]);

  for(int i = 1; i <= n && Check(i, n) == 0; i++);

  for(int i = 1; i <= n; i++)
    printf("%d ", c[i]);
  printf("\n");

  return 0;
}
