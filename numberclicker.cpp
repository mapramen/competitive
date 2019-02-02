#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MAX_STEPS 100

vector<int> PathToOne(int a, int b){
  vector<int> path;

  if(a == 0){
    path.PB(1);
  }
  else{
    while(path.size() <= MAX_STEPS && a != b){
      if(a > b){
        path.PB(2);
        a -= b;
      }
      else{
        path.PB(3);
        swap(a, b);
      }
    }
  }

  return path;
}

vector<int> PathToOne(int u, int x, int p){
  return PathToOne((1ll * u * x) % p, x);
}

void ReversePath(vector<int>& v){
  reverse(v.begin(), v.end());
  for(int i = 0; i < v.size(); ++i){
    if(v[i] <= 2){
      v[i] ^= 3;
    }
  }
}

void OptimisePath(vector<int>& v){
  vector<int> u;
  for(auto x : v){
    if(u.empty()){
      u.PB(x);
    }
    else{
      if((x + u.back()) % 3 == 0){
        u.pop_back();
      }
      else{
        u.PB(x);
      }
    }
  }

  v.clear();

  for(auto x : u){
    v.PB(x);
  }
}

vector<int> Solve(int u, int v, int p){
  vector<int> ans;

  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  default_random_engine generator (seed);

  uniform_int_distribution<int> distribution(1, p - 1);

  while(true){
    auto path1 = PathToOne(u, distribution(generator), p);
    auto path2 = PathToOne(v, distribution(generator), p);

    if(max(path1.size(), path2.size()) > MAX_STEPS){
      continue;
    }

    ReversePath(path2);

    ans.reserve(path1.size() + path2.size());
    ans.insert(ans.end(), path1.begin(), path1.end());
    ans.insert(ans.end(), path2.begin(), path2.end());

    break;
  }

  OptimisePath(ans);

  return ans;
}

int main(){
  int u, v, p;

  cin >> u >> v >> p;

  auto ans = Solve(u, v, p);

  cout << ans.size() << '\n';
  for(auto x : ans){
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}
