#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001

int S[N][N], C[N];
char s[N];

int main(){
  int n;
  scanf("%s", s);
  n = strlen(s);

  for(int i = 1; i <= n; i++)
    S[i][i] = 1;

  for(int i = 1; i < n; i++)
    S[i][i + 1] = (s[i - 1] == s[i]);

  for(int l = 3; l <= n; l++)
    for(int i = 1, j = i + l - 1; i <= n - l + 1; i++, j++)
      S[i][j] = ((s[i - 1] == s[j - 1]) && (S[i + 1][j - 1] == 1));

  for(int l = 2; l <= n; l++){
    for(int i = 1, j = i + l - 1, k = i + l / 2 - 1; i <= n - l + 1; i++, j++, k++){
      if(S[i][j] == 0)
        continue;
      S[i][j] = 1 + S[i][k];
      C[S[i][j]]++;
    }
  }

  C[1] += n;

  for(int i = n - 1; i > 0; i--)
    C[i - 1] += C[i];

  for(int i = 1; i <= n; i++)
    printf("%d ", C[i]);
  printf("\n");

  return 0;
}
