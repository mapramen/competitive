#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  vector<int> v;

  scanf("%d", &n);

  while(n >= 4){
    v.PB(n);
    v.PB(n - 3);
    n -= 4;
  }

  if(n)
    v.PB(n);

  printf("%d\n%d ", (n % 4 == 1 || n % 4 == 2), (int)v.size());
  for(auto x : v)
    printf("%d ", x);
  printf("\n");

  return 0;
}
