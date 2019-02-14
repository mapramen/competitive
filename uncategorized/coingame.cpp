#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n, ans = 0;
    scanf("%d", &n);
    while(n--){
      int a;
      scanf("%d", &a);
      while(a % 2 == 0){
        ++ans;
        a /= 2;
      }
    }
    if(ans % 2)
      printf("Charlie\n");
    else
      printf("Alan\n");
  }

  return 0;
}
