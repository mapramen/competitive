#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define LOGN 18

char s[N], t[N];
int T[LOGN][2 * N], SA[N];

void BuildSuffixArray(int n){
  for(int i = 1; i <= n; ++i)
    T[0][i] = (s[i - 1] - 'a' + 1);

  for(int k = 1; k < LOGN; ++k){
    vector< pair< pii, int> > v;
    v.PB(MP(MP(0, 0), 0));
    for(int i = 1, j = 1 + (1 << (k - 1)); i <= n; ++i, ++j)
      v.PB(MP(MP(T[k - 1][i], T[k - 1][j]), i));
    sort(v.begin(), v.end());
    for(int i = 1, x = 0; i <= n; ++i){
      x += (v[i].first != v[i - 1].first);
      int j = v[i].second;
      T[k][j] = x;
    }
  }

  for(int i = 1; i <= n; ++i){
    int j = T[LOGN - 1][i];
    SA[j] = i;
  }
}

int LCP(int i, int j){
  if(i > j)
    swap(i, j);

  int ans = 0;
  for(int k = LOGN - 1; k > -1; --k){
    if(T[k][i] == T[k][j]){
      ans += (1 << k);
      i += (1 << k);
      j += (1 << k);
    }
  }

  return ans;
}

int Compare(int k){
  k = SA[k] - 1;
  for(int i = 0; ; ++i, ++k){
    if(t[i] == '\0'){
      return 0;
    }

    if(s[k] == '\0'){
      return 1;
    }

    char c = t[i], d = s[k];
    if(c < d){
      return -1;
    }

    if(c > d){
      return 1;
    }
  }
}

int BinarySearchLeftEnd(int n){
  int x = 1, y = n, z = n + 1;
  while(x <= y){
    int mid = x + (y - x) / 2;
    int compare = Compare(mid);
    if(compare == 0)
      z = mid, y = mid - 1;
    else if(compare > 0)
      x = mid + 1;
    else
      y = mid - 1;
  }
  return z;
}

int BinarySearchRightEnd(int n){
  int x = 1, y = n, z = -1;
  while(x <= y){
    int mid = x + (y - x) / 2;
    int compare = Compare(mid);
    if(compare == 0)
      z = mid, x = mid + 1;
    else if(compare > 0)
      x = mid + 1;
    else
      y = mid - 1;
  }
  return z;
}

int main(){
  int n;

  scanf("%s", s);
  n = strlen(s);

  BuildSuffixArray(n);

  int q;
  scanf("%d", &q);
  while(q--){
    int k, m;
    scanf("%d%s", &k, t);
    m = strlen(t);

    int l = BinarySearchLeftEnd(n), r = BinarySearchRightEnd(n), ans = n + 1;
    if(l + k - 1 <= r){
      vector<int> v;
      for(int i = l; i <= r; ++i)
        v.PB(SA[i]);
      sort(v.begin(), v.end());

      int minPossibleAns = m + k - 1;
      for(int i = 0; i < v.size() - k + 1 && ans != minPossibleAns; ++i)
        ans = min(ans, v[i + k - 1] - v[i] + m);
    }

    if(ans > n)
      ans = -1;

    printf("%d\n", ans);
  }

  return 0;
}
