#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 90001
#define LOGN 19
#define CHAR_SIZE 256

char s[N];

void CopyArray(int n, int s[], int t[]){
  for(int i = 0; i <= n; ++i){
    t[i] = s[i];
  }
}

//-------------------------------------------- Suffix Array --------------------------------------------//
int suffixArray[N], posInSuffixArray[N], lcpArray[N], clas[N], order[N], cnt[N], temp[N], lg[N], lcpTable[LOGN][N];

void InitialiseBaseOrder(int n){
  for(int i = 0; i < CHAR_SIZE; ++i){
    cnt[i] = 0;
  }
  for(int i = 0; i <= n; ++i){
    ++cnt[s[i]];
  }
  for(int i = 1; i < CHAR_SIZE; ++i){
    cnt[i] += cnt[i - 1];
  }
  for(int i = n; i >= 0; --i){
    order[--cnt[s[i]]] = i;
  }
}

void InitialiseBaseClass(int n){
  clas[order[0]] = 0;
  for(int i = 1; i <= n; ++i){
    clas[order[i]] = clas[order[i - 1]] + (s[order[i]] != s[order[i - 1]]);
  }
}

void InitialiseBaseOrderAndClass(int n){
  InitialiseBaseOrder(n);
  InitialiseBaseClass(n);
}

void UpdateOrder(int n, int k){
  for(int i = 0; i <= n; ++i){
    cnt[i] = 0;
  }
  for(int i = 0; i <= n; ++i){
    int j = (order[i] - k + n + 1) % (n + 1);
    ++cnt[clas[j]];
  }
  for(int i = 1; i <= n; ++i){
    cnt[i] += cnt[i - 1];
  }
  for(int i = n; i >= 0; --i){
    int j = (order[i] - k + n + 1) % (n + 1);
    temp[--cnt[clas[j]]] = j;
  }
  CopyArray(n, temp, order);
}

void UpdateClass(int n, int k){
  temp[order[0]] = 0;
  for(int i = 1; i <= n; ++i){
    temp[order[i]] = temp[order[i - 1]] + (clas[order[i]] != clas[order[i - 1]] || clas[(order[i] + k) % (n + 1)] != clas[(order[i - 1] + k) % (n + 1)]);
  }
  CopyArray(n, temp, clas);
}

void UpdateOrderAndClass(int n, int k){
  UpdateOrder(n, k);
  UpdateClass(n, k);
}

void BuildSuffixArray(int n){
  InitialiseBaseOrderAndClass(n);
  for(int k = 0; (1 << k) < n; ++k){
    UpdateOrderAndClass(n, (1 << k));
  }
  for(int i = 1; i <= n; ++i){
    suffixArray[i] = order[i] + 1;
    posInSuffixArray[i] = clas[i - 1];
  }
}

int LCP(int n, int i, int j, int ans){
  ans = max(0, ans);
  i += ans, j += ans;
  for( ; i < n && j < n && s[i] == s[j]; ++i, ++j, ++ans);
  return ans;
}

void BuildLCPArray(int n){
  int ans = 0;
  for(int k = 0, i = order[0]; k <= n; ++k, i = (i + 1) % (n + 1)){
    ans = (clas[i] == n) ? 0 : LCP(n, i, order[clas[i] + 1], ans - 1);
    lcpArray[clas[i]] = ans;
  }
}

void BuildLCPSparseTable(int n){
  for(int i = 1; i <= n; ++i){
    lcpTable[0][i] = lcpArray[i];
  }

  for(int k = 1; (1 << k) <= n; ++k){
    for(int i = 1, j = i + (1 << (k - 1)); j <= n; ++i, ++j){
      lcpTable[k][i] = min(lcpTable[k - 1][i], lcpTable[k - 1][j]);
    }
  }
}

void BuildSuffixAndLCPArray(int n){
  for(int i = 2; i <= n; ++i){
    lg[i] = 1 + lg[(i / 2)];
  }
  BuildSuffixArray(n);
  BuildLCPArray(n);
  BuildLCPSparseTable(n);
}

int LCP_RMQ(int i, int j){
  --j;
  int k = lg[j - i + 1];
  return min(lcpTable[k][i], lcpTable[k][j - (1 << k) + 1]);
}

int LCP(int i, int j){
  i = posInSuffixArray[i], j = posInSuffixArray[j];
  if(i > j){
    swap(i, j);
  }
  return LCP_RMQ(i, j);
}
//-------------------------------------------- Suffix Array Ends --------------------------------------------//

int main(){
  scanf("%s", s);

  int n = strlen(s);
  BuildSuffixAndLCPArray(n);

  int q;
  scanf("%d", &q);

  while(q--){
    int k;
    scanf("%d", &k);

    int i = 1;
    for( ; i <= n && (n - suffixArray[i] + 1 - lcpArray[i - 1]) < k; ++i){
      k -= (n - suffixArray[i] + 1 - lcpArray[i - 1]);
    }

    for(k += lcpArray[i - 1], i = suffixArray[i]; k > 0; --k, ++i){
      putchar(s[i - 1]);
    }
    putchar('\n');
  }

  return 0;
}