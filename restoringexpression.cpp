#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 1000001

char s[N];
int a[N];
bool found = 0;
vector< tiii > v;

bool IsNumberNotValid(int i, int n){
  int c = 0;
  for(int j = i + n; i < j && a[i] == 0 && c < 2; ++i, ++c);
  return (c == 2 || (c == 1 && n != 1));
}

void PrintSubString(int i, int j){
  for( ; i <= j; ++i)
    putchar(s[i]);
}

void CheckAndPrint(int i, int j, int k){
  if(found)
    return ;

  int n = i + 1, m = j - i, l = k - j;

  int x = 0;
  for(int y = 0; y < l; --i, --j, --k, ++y, x /= 10){
    if(y < n)
      x += (s[i] - '0');
    if(y < m)
      x += (s[j] - '0');
    int d = x % 10;
    if(s[k] != '0' + d){
      return ;
    }
  }

  found = (x == 0);

  if(found){
    i = n - 1, j = n + m - 1, k = n + m + l - 1;
    PrintSubString(0, i);
    putchar('+');
    PrintSubString(i + 1, j);
    putchar('=');
    PrintSubString(j + 1, k);
    putchar('\n');
  }
}

void Check(int n, int m, int l){
  if(found || min(n, min(m, l)) <= 0 || max(n, m) > l)
    return ;

  int i = n - 1, j = n + m - 1, k = n + m + l - 1, x = i - n + 1, y = j - m + 1, z = k - l + 1;

  if(IsNumberNotValid(x, n) || IsNumberNotValid(y, m) || IsNumberNotValid(z, l))
    return ;

  if(n == m && m == l && a[x] + a[y] <= 9 && a[z] >= a[x] + a[y] && a[z] <= a[x] + a[y] + 1)
    v.PB(MT(i, j, k));

  if(n == m && l > m && a[z] == 1 && a[x] + a[y] >= 9)
    v.PB(MT(i, j, k));

  if(n < m && m == l && a[z] >= a[y] && a[z] <= a[y] + 1)
    v.PB(MT(i, j, k));

  if(n < m && m < l && a[z] == 1 && a[y] == 9)
    v.PB(MT(i, j, k));

  if(n > m && n == l && a[z] >= a[x] && a[z] <= a[x] + 1)
    v.PB(MT(i, j, k));

  if(n > m && l > n && a[z] == 1 && a[x] == 9)
    v.PB(MT(i, j, k));
}

int main(){
  scanf("%s", s);
  int n = strlen(s);

  for(int i = 0; i < n; ++i)
    a[i] = s[i] - '0';

  for(int l = 1; l <= n; ++l){
    Check(l, n - l - l, l);
    Check(l - 1, n - l - l + 1, l);
    Check(n - l - l, l, l);
    Check(n - l - l + 1, l - 1, l);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for(int t = 0; t < v.size() && found == 0; ++t){
    int i, j, k;
    tie(i, j, k) = v[t];
    CheckAndPrint(i, j, k);
  }

  return 0;
}
