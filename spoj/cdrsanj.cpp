#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

pii a[N];
int f[N];

void Initialise(){
  for(int i = 1; i < N; ++i){
    a[i] = {INT_MAX, 0};
  }

  for(int i = 1; i < N; ++i){
    for(int j = i; j < N; j += i){
      a[j] = min(a[j], {i + j / i, i});
    }
  }

  f[1] = 1, f[2] = 2;
  for(int i = 3; i < N; ++i){
    if(a[i].second == 1){
      continue;
    }
    int x = a[i].second;
    f[i] = f[x] + f[i / x];
  }
}

int main(){
  Initialise();

  int x;
  scanf("%d", &x);

  printf("%d\n", f[x]);

  return 0;
}