#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > v(N);
vector<int> d;
set<int> m;
int a[N], b[N];

void PreProcess(int n){
  for(int i = 1; i <= n; i++)
    v[i].PB(0);

  for(int i = 1, j = 1; i <= n; i = j){
    v[a[i]].PB(i);
    for( ; j <= n && a[j] == a[i]; j++);
  }

  for(int i = n; i > 0; i--)
    if(m.find(a[i]) == m.end()){
      m.insert(a[i]);
      d.PB(a[i]);
    }
}

int GetCount(int k, int i){
  i = min(i, v[k][v[k].size() - 1]);

  int j = lower_bound(v[k].begin(), v[k].end(), i) - v[k].begin();

  if(v[k][j] != i)
    j--;

  return j;
}

int Query(set<int>& s, int i, int j){
  int cnt = 0;
  for(auto x : s){
    int ansx = (GetCount(x, j) - GetCount(x, i));
    // cout << x << ' ' << i << ' ' << j << ' ' << ansx << '\n';
    cnt += ansx;
  }
  return cnt;
}

int main(){
  int n, q, i, j, k, l;

  scanf("%d", &n);

  for(i = 1; i <= n; i++)
    scanf("%d%d", &a[i], &b[i]);

  PreProcess(n);

  scanf("%d", &q);

  while(q--){
    scanf("%d", &l);

    set<int> s;

    while(l--){
      scanf("%d", &i);
      if(m.find(i) != m.end())
        s.insert(i);
    }

    for(i = 0; i < d.size() && s.find(d[i]) != s.end(); i++);

    if(i == d.size())
      printf("0 0\n");
    else{
      k = d[i];
      s.insert(k);

      int x = 1, y = v[k].size() - 1, z = 1;
      j = v[k][y];

      while(x <= y){
        int mid = x + (y - x) / 2;
        i = v[k][mid];

        if(Query(s, i, j) == j - i){
          z = mid;
          y = mid - 1;
        }
        else
          x = mid + 1;
      }

      i = v[k][z];

      printf("%d %d\n", k, b[i]);
    }
  }

  return 0;
}
