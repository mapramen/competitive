#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);

void Sort(vector<int>& v){
  sort(v.begin(), v.end());
}

void RemoveDuplicates(vector<int>& v){
  Sort(v);
  v.erase(unique(v.begin(), v.end()), v.end());
}

void CompressValues(vector<int>& a){
  vector<int> v(a);
  RemoveDuplicates(v);
  for(int i = 1; i < a.size(); ++i)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
}

bool Check(vector<int>& a){
  bool check = 1;
  map< int, int > M;
  for(int i = a.size() - 1; i > -1 && check == 1; --i){
    vector<int> v;
    for(auto p : M)
      v.PB(p.second);
    Sort(v);
    Sort(adj[i]);
    check = (v == adj[i]);
    M[a[i]] = i;
  }
  return check;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0; i <= n; ++i)
      adj[i].clear();

    while(m--){
      int i, j;
      scanf("%d%d", &i, &j);
      adj[i].PB(j);
    }

    vector<int> a(n + 1);

    m = 0;
    for(auto x : adj[0])
      a[x] = ++m;

    for(int i = 1; i <= n; ++i){
      int j = 0;
      for(auto x : adj[i])
        if(a[x] == 0)
          j = x;
      if(j)
        a[j] = a[i];
    }

    if(Check(a)){
      for(int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
      printf("\n");
    }
    else
      printf("-1\n");
  }

  return 0;
}
