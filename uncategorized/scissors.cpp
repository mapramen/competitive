#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001

char s[N], t[N];
int failure[N], prefixFailure[N], suffixFailure[N], leftEnd[N], maxPrefixFailure[N];

void ReverseString(char s[], int n = -1){
  n = (n >= 0) ? n : strlen(s);
  for(int i = 0; 2 * i < n; ++i)
    swap(s[i], s[n - 1 - i]);
}

int ComputeFailureValue(int j, int k, char c){
  while((j >= k) || (j != 0 && t[j] != c)){
    j = failure[j];
  }
  j += (t[j] == c);
  return j;
}

void ComputeFailureFunction(char s[], int failureS[], int n, int k = N, bool isPattern = 1){
  for(int i = 1 + isPattern, j = 0; i <= n; ++i){
    char c = s[i - 1];
    j = ComputeFailureValue(j, k, c);
    failureS[i] = j;
  }
}

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  scanf("%s%s", s, t);

  ComputeFailureFunction(t, failure, m);
  ComputeFailureFunction(s, prefixFailure, n, n, 0);

  for(int i = 1; i <= n; ++i){
    if(prefixFailure[i] == m){
      int j = max(1, i - 2 * k + 1);
      printf("Yes\n%d %d\n", j, j + k);
      return 0;
    }
  }

  ComputeFailureFunction(s, prefixFailure, n, k, 0);

  ReverseString(t, m);

  ComputeFailureFunction(t, failure, m);

  for(int i = 2; i <= n; ++i)
    maxPrefixFailure[i] = max(prefixFailure[i], maxPrefixFailure[i - 1]);

  for(int i = n, j = 0; i > 0; --i){
    j = ComputeFailureValue(j, m - maxPrefixFailure[i - 1], s[i - 1]);
    suffixFailure[i] = j;
  }

  for(int i = 1, j = 0; i <= n; ++i){
    if(j + suffixFailure[i] >= m && leftEnd[m - suffixFailure[i]] >= k && i + k - 1 <= n){
      printf("Yes\n%d %d\n", leftEnd[m - suffixFailure[i]] - k + 1, i);
      return 0;
    }
    leftEnd[prefixFailure[i]] = i;
    j = max(j, prefixFailure[i]);
  }

  printf("No\n");

  return 0;
}
