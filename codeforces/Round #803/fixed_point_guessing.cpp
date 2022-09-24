#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Query(int l, int r){
  printf("? %d %d\n", l, r);
  fflush(stdout);

  int cnt = r - l + 1;
  for(int k = l; k <= r; ++k){
    int x;
    scanf("%d", &x);
    cnt -= (x < l || r < x);
  }

  return cnt % 2 == 1;
}

void PrintAns(int x){
  printf("! %d\n", x);
  fflush(stdout);
}

void Solve(){
  int n;
  scanf("%d", &n);

  int x = 1, y = n;
  while(x < y){
    int mid = x + (y - x) / 2;
    if(Query(x, mid)){
      y = mid;
    }
    else{
      x = mid + 1;
    }
  }

  PrintAns(x);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}