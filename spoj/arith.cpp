#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

tuple<vector<int>,vector<int>,char> ReadInput(){
  string s;
  cin >> s;

  vector<int> a, b;
  char op;

  bool fill_second = false;
  for(char c: s){
    if(fill_second){
      b.push_back(c - '0');
      continue;
    }

    if(!isdigit(c)){
      op = c;
      fill_second = true;
      continue;
    }

    a.push_back(c - '0');
  }

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  return {a, b, op};
}

vector<int> Normalize(vector<int> a){
  while(!a.empty() && a.back() == 0){
    a.pop_back();
  }

  if(a.empty()){
    a = {0};
  }

  return a;
}

vector<int> Add(vector<int> a, vector<int> b){
  vector<int> c;
  for(int i = 0, carry = 0; i < a.size() || i < b.size() || carry != 0; ++i, carry /= 10){
    if(i < a.size()){
      carry += a[i];
    }
    if(i < b.size()){
      carry += b[i];
    }
    c.push_back(carry % 10);
  }
  return Normalize(c);
}

vector<int> Subtract(vector<int> a, vector<int> b){
  vector<int> c;
  for(int i = 0, carry = 1; i < a.size() || i < b.size() || carry != 0; ++i, carry /= 10){
    carry += i < a.size() ? (a[i] - 1) + 10 : -1;
    if(i < b.size()){
      carry -= b[i];
    }
    c.push_back(carry % 10);
  }
  return Normalize(c);
}

vector<int> Multiply(vector<int> a, int x){
  vector<int> c;
  for(int i = 0, carry = 0; i < a.size() || carry != 0; ++i, carry /= 10){
    if(i < a.size()){
      carry += x * a[i];
    }
    c.push_back(carry % 10);
  }
  return Normalize(c);
}

void Fill(string& s, vector<int>& a, int padding_right){
  for(int i = 0, j = s.size() - 1 - padding_right; i < a.size(); ++i, --j){
    s[j] = '0' + a[i];
  }
}

void FillDash(string& t, string& s){
  for(int i = 0; i < s.size(); ++i){
    if(s[i] != ' '){
      t[i] = '-';
    }
  }
}

void Solve(){
  vector<int> a, b;
  char op;

  tie(a, b, op) = ReadInput();

  vector<vector<int>> A{a, b};

  if(op == '+'){
    A.push_back(Add(a, b));
  }
  else if(op == '-'){
    A.push_back(Subtract(a, b));
  }
  else{
    vector<int> result;

    int i = 0;
    for(int x: b){
      vector<int> c = Multiply(a, x);
      A.push_back(c);
      
      reverse(c.begin(), c.end());
      for(int k = 1; k <= i; ++k){
        c.push_back(0);
      }
      reverse(c.begin(), c.end());

      result = Add(result, c);
      ++i;
    }

    if(A.size() != 3){
      A.push_back(result);
    }
  }

  int m = max(a.size(), b.size() + 1);
  for(vector<int>& c: A){
    m = max(m, (int)c.size());
  }

  int n = A.size() + 1 + (A.size() != 3);

  vector<string> S(n);
  for(int i = 0; i < n; ++i){
    S[i] = string(m, ' ');
  }

  Fill(S[0], a, 0);
  Fill(S[1], b, 0);

  S[1][m - 1 - b.size()] = op;

  for(int i = 2; i < A.size() - 1; ++i){
    Fill(S[i + 1], A[i], i - 2);
  }

  Fill(S.back(), A.back(), 0);

  FillDash(S[2], S[1]);
  FillDash(S[2], S[3]);
  FillDash(S[n - 2], S[n - 1]);

  for(string& s: S){
    cout << s << '\n';
  }
  cout << '\n';
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}