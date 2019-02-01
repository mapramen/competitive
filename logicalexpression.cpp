#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 8
#define N (1 << B)

int L[N], processed[N], inf = 29, found = 0, xmask = 15, ymask = 51, zmask = 85, allmask = 255;
string E[N];
stack<int> P;
stack<char> S;
vector< vector<string> > V(N);

void EvaluateLast(){
  char c = S.top();
  S.pop();

  if(c == '('){

  }
  else if(c == '!'){
    int x = (allmask ^ P.top());
    P.pop();
    P.push(x);
  }
  else if(c == '&'){
    int x = P.top();
    P.pop();
    x &= P.top();
    P.pop();
    P.push(x);
  }
  else{
    int x = P.top();
    P.pop();
    x |= P.top();
    P.pop();
    P.push(x);
  }
}

int Evaluate(string& s){
  while(!S.empty())
    S.pop();

  while(!P.empty())
    P.pop();

  S.push('(');

  for(auto c : s){
    if(c == 'x'){
      P.push(xmask);
    }
    else if(c == 'y'){
      P.push(ymask);
    }
    else if(c == 'z'){
      P.push(zmask);
    }
    else if(c == '(' || c == '!'){
      S.push(c);
    }
    else if(c == ')'){
      while(S.top() != '(')
        EvaluateLast();
      EvaluateLast();
    }
    else if(c == '&'){
      while(S.top() == '!')
        EvaluateLast();
      S.push(c);
    }
    else{
      while(S.top() == '!' || S.top() == '&')
        EvaluateLast();
      S.push(c);
    }
  }

  while(!S.empty())
    EvaluateLast();

  return P.top();
}

void UpdateExtras(int i, string& s){
  int l = s.size();
  V[i].clear();
  V[i].PB(s);
  if(s.front() != '!' && l + 1 < inf)
    V[i].PB("!" + s);
  if(l + 2 < inf){
    V[i].PB("(" + s + ")");
    if(l + 3 < inf){
      V[i].PB("!(" + s + ")");
    }
  }
}

void CheckAndUpdate(string s){
  int val = Evaluate(s), l = s.size();
  if(l < L[val] || (l == L[val] && s < E[val])){
    E[val] = s;
    L[val] = l;
    processed[val] = 0;
    UpdateExtras(val, s);
  }
}

void PushChild(string s1, string op, string s2){
  CheckAndUpdate(min(s1 + op + s2, s2 + op + s1));
}

bool cmp(const string& a, const string& b){
  return (a.size() < b.size() || (a.size() == b.size() && a < b));
}

int GetFrontIndex(){
  int i = 0, ans = N;
  for( ; i < N && processed[i] == 1; ++i);
  ans = i;
  for(++i; i < N; ++i){
    if(processed[i] == 0 && cmp(E[i], E[ans])){
      ans = i;
    }
  }
  return ans;
}

void Initialise(){
  for(int x = 0; x < N; ++x){
    processed[x] = 1;
    L[x] = inf;
  }

  CheckAndUpdate("x");
  CheckAndUpdate("y");
  CheckAndUpdate("z");

  while(true){
    int ind = GetFrontIndex();

    if(ind == N)
      break;

    processed[ind] = 1;

    string s = E[ind];
    int l = s.size();

    if(s.front() != '!' && l + 1 < inf)
      CheckAndUpdate("!" + s);

    if(l + 3 < inf)
      CheckAndUpdate("!(" + s + ")");

    for(int x = 0; x < N; ++x){
      if(processed[x] == 0 || L[x] == inf)
        continue;
      for(auto s1 : V[x]){
        for(auto s2 : V[ind]){
          int l = s1.size() + 1 + s2.size();
          if(l < inf){
            PushChild(s1, "&", s2);
            PushChild(s1, "|", s2);
          }
        }
      }
    }
  }
}

int main(){
  Initialise();

  int t;
  cin >> t;

  while(t--){
    string s;
    cin >> s;
    cout << E[stoi(s, nullptr, 2)] << '\n';
  }

  return 0;
}
