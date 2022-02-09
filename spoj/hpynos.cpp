#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int F(int n){
  int ans = 0;
  for( ; n > 0; n /= 10){
    int d = n % 10;
    ans += d * d;
  }
  return ans;
}

int GetLength(int n){
  int steps = 0;

  for(int checkpoint_length = 1; n != 1; checkpoint_length *= 2){
    int checkpoint = n;
    for(int step = 0; step < checkpoint_length && n != 1; ++step, ++steps){
      n = F(n);
      if(n == checkpoint){
        return -1;
      }
    }
  }

  return steps;
}

int main(){
  int n;
  scanf("%d", &n);
  printf("%d\n", GetLength(n));
  return 0;
}