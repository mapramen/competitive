#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, a = 1, b = 2, c = 3;

  scanf("%d", &n);

  while(n--){
    int d;
    scanf("%d", &d);

    if(d == a)
      swap(b, c);
    else if(d == b)
      swap(a, c);
    else{
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");

  return 0;
}
