#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int n, a[N];
bool visited[N], win[N];

bool Solve(int i){
  if(visited[i]){
    return win[i];
  }

  int c = 0;

  for(int j = i + a[i]; j <= n; j += a[i]){
    if(a[j] <= a[i]){
      continue;
    }
    win[i] |= (1 ^ Solve(j));
    ++c;
  }

  for(int j = i - a[i]; j > 0; j -= a[i]){
    if(a[j] <= a[i]){
      continue;
    }
    win[i] |= (1 ^ Solve(j));
    ++c;
  }

  visited[i] = 1;

  return win[i];
}

int main(){
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    win[i] = Solve(i);
  }

  for(int i = 1; i <= n; ++i){
    putchar('A' + (1 ^ win[i]));
  }
  putchar('\n');

  return 0;
}
