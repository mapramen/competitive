#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void CoordinateCompress(vector<int>& a){
  vector<int> c(a);
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());

  for(int& x: a){
    x = lower_bound(c.begin(), c.end(), x) - c.begin() + 1;
  }
}

set<pii> GetIntervals(vector<int>& a, set<pii>& segments){
  int n = a.size();
  vector<vector<int>> V(n + 1);

  for(int i = 0; i < n; ++i){
    V[a[i]].push_back(i);
  }

  set<pii> segment_endpoints, intervals;
  for(int i = 0; i < n; ++i){
    while(!segments.empty() && segments.begin()->first <= i){
      segment_endpoints.insert({segments.begin()->second, segments.begin()->first});
      segments.erase(segments.begin());
    }

    while(!segment_endpoints.empty() && segment_endpoints.begin()->first < i){
      segment_endpoints.erase(segment_endpoints.begin());
    }

    if(segment_endpoints.empty()){
      continue;
    }

    vector<int>& v = V[a[i]];
    if(v.back() == i){
      continue;
    }

    int j = lower_bound(v.begin(), v.end(), i + 1) - v.begin();
    j = v[j];
    if(j <= segment_endpoints.rbegin()->first){
      intervals.insert({i, j});
    }

    int k = segment_endpoints.rbegin()->first;
    k = upper_bound(v.begin(), v.end(), k) - v.begin() - 1;
    k = v[k];
    if(k > i){
      intervals.insert({i, k});
    }
  }

  return intervals;
}

set<pii> starting_before, ending_before, starting_in, ending_in, ending_after;

bool Check(int n, set<pii>& intervals, int m){
  if(intervals.empty()){
    return true;
  }

  starting_before.clear(), ending_before.clear(), starting_in.clear(), ending_in.clear(), ending_after.clear();

  auto it = intervals.begin();
  for(int i = 0, j = m - 1; j < n; ++i, ++j){
    for( ; it != intervals.end() && it->first <= j; ++it){
      starting_in.insert(*it);
    }

    while(!ending_after.empty() && ending_after.begin()->first <= j){
      ending_in.insert(*ending_after.begin());
      ending_after.erase(ending_after.begin());
    }

    while(!starting_in.empty() && starting_in.begin()->first < i){
      if(starting_in.begin()->second <= j){
        ending_in.insert({starting_in.begin()->second, starting_in.begin()->first});
      }
      else{
        ending_after.insert({starting_in.begin()->second, starting_in.begin()->first});
      }
      starting_in.erase(starting_in.begin());
    }

    while(!ending_in.empty() && ending_in.begin()->first < i){
      ending_before.insert(*ending_in.begin());
      ending_in.erase(ending_in.begin());
    }

    if(starting_before.empty() && ending_before.empty() && it == intervals.end() && ending_after.empty()){
      return true;
    }
  }

  return false;
}

int BinarySearch(int n, set<pii>& intervals){
  int x = 0, y = n, ans = n;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, intervals, mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  CoordinateCompress(a);

  set<pii> segments;
  while(m--){
    int l, r;
    scanf("%d%d", &l, &r);
    segments.insert({l - 1, r - 1});
  }
  
  set<pii> intervals = GetIntervals(a, segments);

  // for(auto [i, j]: intervals){
  //   printf("interval (%d,%d)\n", i, j);
  // }

  return BinarySearch(n, intervals);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}