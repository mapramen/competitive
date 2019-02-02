#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

void PrintVector(vector<int> v) {
  for(auto x : v)
    cout << x << ' ';
  cout << '\n';
}

void RemoveDuplicates(vector<int>& v){
  v.erase(unique(v.begin(), v.end()), v.end());
}

vector<int> Reduce(vector<int> a, int dx){
  vector<int> v;
  for(auto x : a){
    if(x % 2)
      x -= dx;
    x /= 2;
    if(x)
      v.PB(x);
  }
  RemoveDuplicates(v);
  return v;
}

vector<int> Solve(vector<int> a){
  vector<int> ans;

  if(a.size() == 0 || (a.size() == 1 && abs(a[0]) == 1))
    return a;

  int negativeOnes = 0, positiveOnes = 0;

  for(auto x : a){
    if(x % 2){
      if(x < 0)
        ++negativeOnes;
      else
        ++positiveOnes;
    }
  }

  if(negativeOnes + positiveOnes == 0){
    vector<int> v = Reduce(a, 0);
    ans = Solve(v);
    for(int i = 0; i < ans.size(); ++i)
      ans[i] *= 2;
  }
  else{
    for(int dx = -1; dx < 2; ++dx){
      if(dx == 0)
        continue;
      vector<int> v = Reduce(a, dx);
      auto ansx = Solve(v);
      for(int i = 0; i < ansx.size(); ++i)
        ansx[i] *= 2;
      ansx.PB(dx);

      if(ans.size() == 0 || ansx.size() < ans.size())
        swap(ans, ansx);
    }
  }

  return ans;
}

int main(){
  int n;
  vector<int> a;

  scanf("%d", &n);
  while(n--){
    int x;
    scanf("%d", &x);
    a.PB(x);
  }

  sort(a.begin(), a.end());
  RemoveDuplicates(a);

  auto ans = Solve(a);

  printf("%lu\n", ans.size());
  for(auto x : ans)
    printf("%d ", x);
  printf("\n");

  return 0;
}
