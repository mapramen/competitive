#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 8001
#define P 31
#define MOD 1000000007

char s[N];
int n, f[N], numDigits[N], dp[N];

void PreProcess(){
  n = strlen(s);
  for(int i = 1; i <= n; i++)
    numDigits[i] = 1 + numDigits[(i / 10)];
  numDigits[0] = 1;

  for(int i = 1; i <= n; i++)
    dp[i] = i + numDigits[i];
}

int main(){
  int z = 0;
  scanf("%s", s);
  PreProcess();

  for(int i = 0; i < n; i++){
    f[i + 1] = i;
    for(int j = i + 2; j <= n; j++){
      int k = f[j - 1];
      while(true){
        if(s[k] == s[j - 1]){
          f[j] = k + 1;
          break;
        }
        else
          if(k != i)
            k = f[k];
          else{
            f[j] = k;
            break;
          }
      }
    }

    for(int j = i + 1; j <= n; j++){
      int l = j - i, x = j - f[j], c;
      if(l % x == 0)
        c = x;
      else
        c = l;
      dp[j] = min(dp[j], dp[i] + c + numDigits[l / c]);
    }
  }

  printf("%d\n", dp[n]);

  return 0;
}
