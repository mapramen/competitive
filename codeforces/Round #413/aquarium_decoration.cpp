#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

bool a[N], b[N], t[N];
vector<int> c(N), p(N), v1, v2, v3;
ll T1[N], T2[N];

bool cmp(int i, int j){
  return MP(c[i], i) < MP(c[j], j);
}

void PreProcess(int n){
  vector<int> px(n + 1), cx(n + 1);

  for(int i = 1; i <= n; i++){
    cx[i] = c[i];
    px[i] = i;
  }

  sort(px.begin() + 1, px.begin() + n + 1, cmp);

  for(int i = 1; i <= n; i++){
    p[px[i]] = i;
    c[i] = cx[px[i]];
  }
}

void Print(vector<int> v){
  for(auto x : v)
    cout << x << ' ';
  cout << '\n';
}

void Update(ll T[], int n, int i, int x){
  for( ; i <= n; i += (i&-i))
    T[i] += x;
}

ll Query(ll T[], int i){
  ll ans = 0;
  for( ; i > 0; i -= (i&-i))
    ans += T[i];
  return ans;
}

ll GetAns(int n, int m){
  int x = 0, y = n, z = 0;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Query(T1, mid) <= m)
      z = mid, x = mid + 1;
    else
      y = mid - 1;
  }
  return Query(T2, z);
}

void Toggle(int i, int n){
  if(i == 0)
    return ;
  t[i] = 1 - t[i];
  int x = (t[i] == 0) ? -1 : 1;
  Update(T1, n, i, x);
  x = (t[i] == 0) ? -c[i] : c[i];
  Update(T2, n, i, x);
}

int main(){
  int n, m, k, s;
  ll ans = LLONG_MAX;

  scanf("%d%d%d", &n, &m, &k);

  for(int i = 1; i <= n; i++)
    scanf("%d", &c[i]);

  PreProcess(n);

  scanf("%d", &s);
  while(s--){
    int i;
    scanf("%d", &i);
    i = p[i];
    a[i] = 1;
  }

  scanf("%d", &s);
  while(s--){
    int i;
    scanf("%d", &i);
    i = p[i];
    b[i] = 1;
  }

  for(int i = 1; i <= n; i++){
    if(a[i] == 0 && b[i] == 0);
    else if(a[i] == 1 && b[i] == 1)
      v3.PB(i);
    else if(a[i] == 1)
      v1.PB(i);
    else
      v2.PB(i);
    Toggle(i, n);
  }

  c.resize(n + 1);
  p.resize(n + 1);

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  sort(v3.begin(), v3.end());

  v3.PB(0);

  int i1 = 0, i2 = 0, i3 = 0, k1 = 0, k2 = 0;
  int n1 = v1.size(), n2 = v2.size(), n3 = v3.size();
  ll s1 = 0, s2 = 0, s3 = 0;

  for(i1 = i2 = i3 = 0; i3 < n3; i3++){
    for( ; i1 < n1 && k1 < k; i1++, k1++){
      s1 += c[v1[i1]];
      Toggle(v1[i1], n);
    }

    if(k1 > k){
      for(--i1; i1 > -1 && k1 > k; i1--, k1--){
        s1 -= c[v1[i1]];
        Toggle(v1[i1], n);
      }
      i1++;
    }

    for( ; i2 < n2 && k2 < k; i2++, k2++){
      s2 += c[v2[i2]];
      Toggle(v2[i2], n);
    }

    if(k2 > k){
      for(--i2; i2 > -1 && k2 > k; i2--, k2--){
        s2 -= c[v2[i2]];
        Toggle(v2[i2], n);
      }
      i2++;
    }

    if(k1 == k && k2 == k && i1 + i2 + i3 <= m)
      ans = min(ans, s1 + s2 + s3 + GetAns(n, m - i1 - i2 - i3));

    s3 += c[v3[i3]];
    Toggle(v3[i3], n);
    k1++;
    k2++;
  }

  if(ans == LLONG_MAX)
    ans = -1;

  printf("%lld\n", ans);

  return 0;
}
