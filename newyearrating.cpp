#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, i, j, b, c, s;

  scanf("%d", &n);

  b = INT_MIN, c = INT_MAX, s = 0;

  while(n--){
    scanf("%d%d", &i, &j);

    if(j == 1)
      c = min(c, s);
    else
      b = max(b, s);

    s += i;
  }

  if(b == INT_MIN){
    printf("Infinity\n");
    return 0;
  }

  if(c <= b){
    printf("Impossible\n");
    return 0;
  }

  cout << s - b + 1899 << '\n';

  return 0;
}
