#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Query(int c){
  printf("+ %d\n", c);
  fflush(stdout);

  int x;
  scanf("%d", &x);
  return x;
}

int main(){
  int n;
  scanf("%d", &n);

  int l = 1, r = n - 1;
  while(l < r){
    int mid = l + (r - l) / 2;

    int p = r / n + 1;
    int c = p * n - (mid + 1);
    l += c, r += c, mid += c;

    if(Query(c) == p){
      l = mid + 1;
    }
    else{
      r = mid;
    }
  }

  printf("! %d\n", r);
  fflush(stdout);

  return 0;
}