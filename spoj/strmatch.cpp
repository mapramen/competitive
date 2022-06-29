#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5000001
#define B 26

char S[N];
int T[B][N], C[N], nxt = 0;

string ReadString(){
  scanf("%s", S);
  return string(S);
}

void AddString(string s){
  int i = 0;
  for(char c: s){
    int k = c - 'a';
    if(T[k][i] == 0){
      T[k][i] = ++nxt;
    }
    i = T[k][i];
    ++C[i];
  }
}

int GetCount(string s){
  int i = 0;
  for(char c: s){
    int k = c - 'a';
    if(T[k][i] == 0){
      return 0;
    }
    i = T[k][i];
  }
  return C[i];
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  string s = ReadString();
  for(int i = 0; i < n; ++i){
    AddString(string(s.begin() + i, s.end()));
  }

  while(q--){
    printf("%d\n", GetCount(ReadString()));
  }
  
  return 0;
}