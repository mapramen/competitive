#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 61

int grundyTable[N][N], grundyNumber[N];

int main(){
  int n, ans = 0;

  for(int i = 0; i < N; i++){
    for(int j = 1; j <= i; j++){
      set<int> s;

      for(int x = 0; x < N; x++)
        s.insert(x);

      for(int k = 0; k < j; k++)
        s.erase(grundyTable[i - j][k]);

      grundyTable[i][j] = *s.begin();
    }

    set<int> s;
    for(int x = 0; x < N; x++)
      s.insert(x);

    for(int j = 1; j <= i; j++)
      s.erase(grundyTable[i - j][j - 1]);

    grundyNumber[i] = *s.begin();
  }

  scanf("%d", &n);

  while(n--){
    int x;
    scanf("%d", &x);
    ans ^= grundyNumber[x];
  }

  if(ans)
    printf("NO\n");
  else
    printf("YES\n");

  return 0;
}
