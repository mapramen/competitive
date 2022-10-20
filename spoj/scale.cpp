#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n, x;
  scanf("%d%d", &n, &x);

  vector<int> a, b;
  for(int i = 0; i < n; ++i, x /= 3){
    int r = x % 3;
    if(r == 0){
      continue;
    }

    if(r == 1){
      b.push_back(i);
      continue;
    }

    a.push_back(i);
    x += 2;
  }

  if(x != 0){
    printf("-1\n");
    return 0;
  }

  for(int i: a){
    printf("%d ", i + 1);
  }
  printf("\n");

  for(int i: b){
    printf("%d ", i + 1);
  }
  printf("\n");

  return 0;
}