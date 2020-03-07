#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define tiii tuple< int, int, int >

map<int,int> horizontalSegments, verticalSegments;
ordered_set<int> S;

ll Solve(){
  int n;

  scanf("%d", &n);

  while(n--){
    int l, r;
    scanf("%d%d", &l, &r);

    if(horizontalSegments.count(l) == 0){
      horizontalSegments[l] = r;
    }
    else{
      horizontalSegments[l] = max(horizontalSegments[l], r);
    }

    if(verticalSegments.count(r) == 0){
      verticalSegments[r] = l;
    }
    else{
      verticalSegments[r] = min(verticalSegments[r], l);
    }
  }

  vector< tiii > v;

  for(auto p : horizontalSegments){
    int l, r;
    tie(l, r) = p;

    v.push_back(make_tuple(l + 1, -l, 1));
    v.push_back(make_tuple(r + 1, -l, 2));
  }

  for(auto p : verticalSegments){
    int l, r;
    tie(r, l) = p;

    v.push_back(make_tuple(r, -l, 3));
  }

  sort(v.begin(), v.end());

  ll ans = 1;
  
  for(auto t : v){
    int l, x, e;
    tie(l, x, e) = t;

    if(e == 1){
      S.insert(x);
    }
    else if(e == 2){
      S.erase(x);
    }
    else{
      ans += S.order_of_key(x + 1);
    }
  }

  horizontalSegments.clear(), verticalSegments.clear(), S.clear();

  return ans;
}

int main(){
  int t;
  
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }

  return 0;
}