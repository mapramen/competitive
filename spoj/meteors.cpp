#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 300001

vector<vector<int>> orbits(N);
int meteors[N], ans[N];
tiii queries[N];
ll T[N];

void Add(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

void Add(int l, int r, int x){
  Add(l, x), Add(r + 1, -x);
}

ll Query(int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

void Apply(tiii query, int mul){
  int l = get<0>(query), r = get<1>(query), x = mul * get<2>(query);
  if(l <= r){
    Add(l, r, x);
  }
  else{
    Add(l, N - 1, x);
    Add(1, r, x);
  }
}

bool IsStationSatisfied(int station){
  ll ans = meteors[station];
  for(int i: orbits[station]){
    ans -= Query(i);
    if(ans <= 0){
      return true;
    }
  }
  return false;
}

void BinarySearch(int l, int r, vector<int> stations){
  if(l > r){
    return;
  }

  int mid = (l + r) / 2;
  for(int i = l; i <= mid; ++i){
    Apply(queries[i], 1);
  }

  vector<int> satisfied_stations, unsatisfied_stations;
  for(int station: stations){
    if(IsStationSatisfied(station)){
      ans[station] = mid;
      satisfied_stations.push_back(station);
    }
    else{
      unsatisfied_stations.push_back(station);
    }
  }

  BinarySearch(mid + 1, r, unsatisfied_stations);

  for(int i = l; i <= mid; ++i){
    Apply(queries[i], -1);
  }

  BinarySearch(l, mid - 1, satisfied_stations);
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= m; ++i){
    int station;
    scanf("%d", &station);
    orbits[station].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &meteors[i]);
  }

  int q;
  scanf("%d", &q);

  for(int k = 1; k <= q; ++k){
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    queries[k] = {l, r, x};
  }

  vector<int> stations(n);
  for(int i = 1; i <= n; ++i){
    stations[i - 1] = i, ans[i] = INT_MAX;
  }

  BinarySearch(1, q, stations);

  for(int i = 1; i <= n; ++i){
    if(ans[i] == INT_MAX){
      printf("NIE\n");
    }
    else{
      printf("%d\n", ans[i]);
    }
  }

  return 0;
}