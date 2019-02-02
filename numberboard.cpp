#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 10

char s[N];
int c[B];

int main(){
  int k, ans = 0;
  scanf("%d%s", &k, s);

  for(int i = 0; s[i] != '\0'; i++){
    int j = s[i] - '0';
    c[j]++;
    k -= j;
  }

  while(k > 0){
    for(int i = 0; i < B; i++){
      if(c[i]){
        ans++;
        k -= (B - 1 - i);
        c[i]--;
        break;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
