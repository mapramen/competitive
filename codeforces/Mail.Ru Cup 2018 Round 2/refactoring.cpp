#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector<string> initials, targets;
vector<int> start, finish, length;

void TakeInputs(){
  char s[5001];
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    scanf("%s", s);
    initials.PB(string(s));
  }
  for(int i = 1; i <= n; ++i){
    scanf("%s", s);
    targets.PB(string(s));
  }
}

int RearrangeInputs(){
  int m = 0;
  for(int n = initials.size(), j = 0, i = 0; i < n; ++i){
    if(initials[i] != targets[i]){
      swap(initials[i], initials[j]);
      swap(targets[i], targets[j]);
      ++j;
      m = j;
    }
  }
  return m;
}

void CalculateBoundaries(int m){
  start.resize(m), finish.resize(m), length.resize(m);
  for(int x = 0; x < m; ++x){
    string &s = initials[x], &t = targets[x];
    int &i = start[x], &j = finish[x], &l = length[x];
    for(i = 0; s[i] == t[i]; ++i);
    for(j = s.size() - 1; s[j] == t[j]; --j);
    l = j - i + 1;
  }
}

bool PreCheck(int m){
  string s, t;
  for(int i = 0; i < m; ++i){
    string sx = string(initials[i], start[i], length[i]), tx = string(targets[i], start[i], length[i]);
    if(s != "" && (sx != s || tx != t)){
      return 0;
    }
    else{
      s = sx, t = tx;
    }
  }
  return 1;
}

bool BoundaryCheck(int m, int k){
  char c = '\0', d = '\0';
  for(int x = 0; x < m; ++x){
    int i = (k < 0) ? start[x] + k : finish[x] + k;
    if(i < 0 || i >= initials[x].size()){
      return 0;
    }
    char cx = initials[x][i], dx = targets[x][i];
    if(c != '\0' && (cx != c || dx != d)){
      return 0;
    }
    else{
      c = cx, d = dx;
    }
  }
  for(int x = 0; x < m; ++x){
    if(k < 0){
      --start[x];
    }
    else{
      ++finish[x];
    }
    ++length[x];
  }
  return 1;
}

bool Check(int n, string s, string t){
  for(int x = 0; x < n; ++x){
    int i = initials[x].find(s);
    if(i != string::npos){
      initials[x].replace(i, s.size(), t);
    }
    if(initials[x] != targets[x]){
      return 0;
    }
  }
  return 1;
}

pair<string,string> Solve(int n, int m){
  if(!PreCheck(m)){
    return MP("", "");
  }

  while(BoundaryCheck(m, -1));
  while(BoundaryCheck(m, 1));

  string s = string(initials[0], start[0], length[0]), t = string(targets[0], start[0], length[0]);

  return Check(n, s, t) ? MP(s, t) : MP("", "");
}

int main(){
  TakeInputs();

  int n = initials.size(), m = RearrangeInputs();
  CalculateBoundaries(m);

  string s, t;
  tie(s, t) = Solve(n, m);

  if(s == ""){
    cout << "NO\n";
  }
  else{
    cout << "YES" << '\n' << s << '\n' << t << '\n';
  }

  return 0;
}
