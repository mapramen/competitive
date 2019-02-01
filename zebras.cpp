#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

set<int> zeros, ones;

int main(){
  int n;
  string s;
  vector< vector<int> > ans;

  cin >> s;

  for(int i = 0; i < s.size(); ++i){
    if(s[i] == '0')
      zeros.insert(i);
    else
      ones.insert(i);
  }

  while(zeros.size() > 0 || ones.size() > 0){
    if(ones.size() == 0){
      for(auto x : zeros){
        vector<int> v;
        v.PB(x);
        ans.PB(v);
      }
      break;
    }

    if(zeros.size() == 0 || *zeros.begin() > *ones.begin() || *zeros.rbegin() < *ones.rbegin()){
      printf("-1\n");
      return 0;
    }

    vector<int> v;
    int i = 0, j = -1;
    while(true){
      if(i == 0){
        if(zeros.upper_bound(j) != zeros.end()){
          j = *zeros.upper_bound(j);
          zeros.erase(j);
          v.PB(j);
        }
        else
          break;
      }
      else{
        if(ones.upper_bound(j) != ones.end()){
          j = *ones.upper_bound(j);
          ones.erase(j);
          v.PB(j);
        }
        else
          break;
      }

      i = 1 - i;
    }
    ans.PB(v);
  }

  printf("%lu\n", ans.size());
  for(auto v : ans){
    printf("%lu ", v.size());
    for(auto x : v)
      printf("%d ", x + 1);
    printf("\n");
  }

  return 0;
}
