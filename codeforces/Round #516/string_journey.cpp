#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001
#define LOGN 19
#define B 256

char s[N];

void CopyArray(int n, int s[], int t[]){
  for(int i = 0; i <= n; ++i){
    t[i] = s[i];
  }
}

//-------------------------------------------- Suffix Array --------------------------------------------//
int suffixArray[N], posInSuffixArray[N], lcpArray[N], clas[N], order[N], cnt[N], temp[N], lg[N], lcpTable[LOGN][N];

void InitialiseBaseOrder(int n){
  for(int i = 0; i < B; ++i){
    cnt[i] = 0;
  }
  for(int i = 0; i <= n; ++i){
    ++cnt[s[i]];
  }
  for(int i = 1; i < B; ++i){
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

//----------------------------------------- Segment Tree -----------------------------------------//
int T[(1 << 20)];

void Update(int k, int l, int r, int i, int x){
  if(i < l || r < i){
    return ;
  }
  else{
    if(i == l && i == r){
      T[k] = x;
    }
    else{
      Update(2 * k + 1, l, (l + r) / 2, i, x);
      Update(2 * k + 2, (l + r) / 2 + 1, r, i, x);
      T[k] = max(T[2 * k + 1], T[2 * k + 2]);
    }
  }
}

int Query(int k, int l, int r, int ql, int qr){
  if(qr < ql || qr < l || r < ql){
    return 0;
  }
  else{
    if(ql <= l && r <= qr){
      return T[k];
    }
    else{
      return max(Query(2 * k + 1, l, (l + r) / 2, ql, qr), Query(2 * k + 2, (l + r) / 2 + 1, r, ql, qr));
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int c[N];

int BinarySearchLeftEnd(int n, int i, int k){
  int ans = i;
  for(int x = 1, y = i - 1; x <= y; ){
    int mid = x + (y - x) / 2;
    if(LCP_RMQ(mid, i) >= k){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int BinarySearchRightEnd(int n, int i, int k){
  int ans = i;
  for(int x = i + 1, y = n; x <= y; ){
    int mid = x + (y - x) / 2;
    if(LCP_RMQ(i, mid) >= k){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }
  return ans;
}

bool Check(int n, int i, int k){
  i = posInSuffixArray[i];
  int l = BinarySearchLeftEnd(n, i, k), r = BinarySearchRightEnd(n, i, k);
  return (k <= Query(0, 1, n, l, r));
}

int main(){
  int n;

  scanf("%d%s", &n, s);

  BuildSuffixAndLCPArray(n);

  int ans = 0;
  for(int i = n, j = n, k = 0; i > 0; --i){
    for( ; k > 0 && (Check(n, i, k) || Check(n, i + 1, k)) == false; --k, Update(0, 1, n, posInSuffixArray[j], c[j]), --j);
    c[i] = ++k;
    ans = max(ans, c[i]);
  }

  printf("%d\n", ans);

  return 0;
}
