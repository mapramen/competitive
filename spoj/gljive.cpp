#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

bitset<N> dp;

int main(){
  int ansd = INT_MAX, anss = 0;
  
  for(int i = 1, s = 0; i <= 10; ++i){
    int x;
    scanf("%d", &x);
    s += x;

    int d = abs(s - 100);
    if(d <= ansd){
      ansd = d, anss = s;
    }
  }

  printf("%d\n", anss);

  return 0;
}