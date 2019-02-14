#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001
#define M 1020

vector<int> ones(M), zeros(M), P(M);
vector< vector<int> > v(N);
int operand1[N], operand2[N], operation[N];
map< string,int > varMap;

void CalculateMin(int m){
  for(int i = M - m; i < M; i++)
    if(ones[i] < zeros[i])
      putchar('1');
    else
      putchar('0');
  putchar('\n');
}

void CalculateMax(int m){
  for(int i = M - m; i < M; i++)
    if(ones[i] > zeros[i])
      putchar('1');
    else
      putchar('0');
  putchar('\n');
}

int main(){
  int n, m;

  cin >> n >> m;

  for(int i = 0; i <= n; i++)
    v[i].resize(M);

  varMap[string("?")] = 0;
  for(int x = 1; x <= n; x++){
    string s;
    cin >> s;
    varMap[s] = x;
    cin >> s;

    cin >> s;
    if(varMap.find(s) != varMap.end()){
      operand1[x] = varMap[s];
      cin >> s;
      int op;
      if(s == "AND")
        op = 0;
      else if(s == "OR")
        op = 1;
      else
        op = 2;
      operation[x] = op;
      cin >> s;
      operand2[x] = varMap[s];
    }
    else{
      for(int j = m - 1, i = M - 1; j > -1; j--, i--)
        v[x][i] = s[j] - '0';
      operation[x] = 0;
      operand1[x] = operand2[x] = x;
    }
  }

  for(int i = M - 1, j = m - 1; j > -1; j--, i--){
    v[0][i] = 1;

    for(int x = 1; x <= n; x++){
      int oprnd1 = v[operand1[x]][i], oprnd2 = v[operand2[x]][i], optn = operation[x];

      if(optn == 0)
        v[x][i] = (oprnd1 & oprnd2);
      else if(optn == 1)
        v[x][i] = (oprnd1 | oprnd2);
      else
        v[x][i] = (oprnd1 ^ oprnd2);

      ones[i] += v[x][i];
    }
  }

  for(int i = M - 1, j = m - 1; j > -1; j--, i--){
    v[0][i] = 0;

    for(int x = 1; x <= n; x++){
      int oprnd1 = v[operand1[x]][i], oprnd2 = v[operand2[x]][i], optn = operation[x];

      if(optn == 0)
        v[x][i] = (oprnd1 & oprnd2);
      else if(optn == 1)
        v[x][i] = (oprnd1 | oprnd2);
      else
        v[x][i] = (oprnd1 ^ oprnd2);

      zeros[i] += v[x][i];
    }
  }

  CalculateMin(m);
  CalculateMax(m);

  return 0;
}
