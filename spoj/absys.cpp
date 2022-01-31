#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int ReadInt(){
  string s;
  cin >> s;

  for(char c: s){
    if(c == 'm' || c == '+' || c == '='){
      return -1;
    }
  }

  return stoi(s);
}

string Solve(){
  int a = ReadInt(); ReadInt();
  int b = ReadInt(); ReadInt();
  int c = ReadInt();

  if(a == -1){
    a = c - b;
  }
  
  if(b == -1){
    b = c - a;
  }

  if(c == -1){
    c = a + b;
  }

  return to_string(a) + " + " + to_string(b) + " = " + to_string(c);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}