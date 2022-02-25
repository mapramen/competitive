#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

char s[10];

int main(){
  int n;
  scanf("%d", &n);

  int quarters = 0, halves = 0, three_quarters = 0;
  while(n--){
    scanf("%s", s);

    if(s[2] == '2'){
      ++halves;
    }
    else if(s[0] == '1'){
      ++quarters;
    }
    else{
      ++three_quarters;
    }
  }

  int ans = 1 + (halves / 2) + (halves % 2) + three_quarters;

  halves %= 2;
  quarters = max(0, quarters - three_quarters - 2 * halves);

  ans += (quarters / 4 + (quarters % 4 != 0));

  printf("%d\n", ans);
  
  return 0;
}