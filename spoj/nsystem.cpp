#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int GetValue(int d, char a, char b, int p){
  return a == b ? d * p : 0;
}

int Mcxi2Int(string s){
  int d = 1, n = 0;

  for(char c: s){
    if('0' <= c && c <= '9'){
      d = c - '0';
      continue;
    }

    n += GetValue(d, c, 'm', 1000);
    n += GetValue(d, c, 'c', 100);
    n += GetValue(d, c, 'x', 10);
    n += GetValue(d, c, 'i', 1);

    d = 1;
  }

  return n;
}

int ReadInt(){
  string s;
  cin >> s;
  return Mcxi2Int(s);
}

void Append(string& s, int d, char c){
  if(d == 0){
    return;
  }

  if(d != 1){
    s.push_back('0' + d);
  }
  s.push_back(c);
}

string Int2Mcxi(int n){
  string s;

  Append(s, n / 1000, 'm');
  Append(s, (n % 1000) / 100, 'c');
  Append(s, (n % 100) / 10, 'x');
  Append(s, n % 10, 'i');

  return s;
}

string Solve(){
  return Int2Mcxi(ReadInt() + ReadInt());
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}