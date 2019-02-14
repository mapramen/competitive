#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, i, j, k;
  string s;
  set<int> m;
  queue<int> d, r;

  cin >> n >> s;

  for(i = 0; i < n; i++){
    m.insert(i);
    if(s[i] == 'D')
      d.push(i);
    else
      r.push(i);
  }

  for(i = 0; !d.empty() && !r.empty(); i = (i + 1) % n){
    if(m.lower_bound(i) == m.end()){
      i = -1;
      continue;
    }

    i = *(m.lower_bound(i));

    if(s[i] == 'D'){
      m.erase(r.front());
      r.pop();
      d.push(d.front());
      d.pop();
    }
    else{
      m.erase(d.front());
      d.pop();
      r.push(r.front());
      r.pop();
    }
  }

  if(d.size())
    cout << "D\n";
  else
    cout << "R\n";

  return 0;
}
