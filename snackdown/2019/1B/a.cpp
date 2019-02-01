#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 50

int a[N], c = 0;

void Fun(int i = 0, int x = 1, int s = N){
  if(x > s || s < 0){
    return;
  }
  if(i){
    // for(int j = 0; j < i; ++j){
    //   printf("%d ", a[j]);
    // }
    // printf("\n");
    ++c;
  }
  Fun(i, x + 1, s);
  a[i] = x;
  Fun(i + 1, x, s - x);
}

int main(){
  Fun();
  printf("%d\n", c);
  return 0;
}
