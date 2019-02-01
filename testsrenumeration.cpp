#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define L 6

char numStrings[3 * N][L + 1], tempStr[L + 1];
int n, n1, n2, n3, nxt;
set<int> exampleFiles, testFiles, exampleNos, testNos;
queue<int> examplePriorities, testPriorities, missing;
vector< pii > moves;

int GetInt(){
  bool check = 1;
  int num = 0;
  for(int i = 0; tempStr[i] != '\0' && check == 1; ++i){
    char c = tempStr[i];
    check = (c >= '0' && c <= '9');
    if(check)
      num = 10 * num + (c - '0');
  }
  if(check == 0 || num > n || num < 1 || strlen(tempStr) != strlen(to_string(num).c_str())){
    num = ++nxt;
    strcpy(numStrings[num], tempStr);
  }
  return num;
}

void Fix(int i);
void Fix(int i, set<int>& myFiles, set<int>& otherFiles, set<int>& myNos, set<int>& otherNos);

void AddMoves(int s, int t){
  moves.PB(MP(s, t));
}

void Fix(int i, set<int>& myFiles, set<int>& otherFiles, set<int>& myNos, set<int>& otherNos){
  if(myNos.find(i) == myNos.end())
    return ;

  myNos.erase(i);

  auto ot = otherFiles.find(i);
  if(ot != otherFiles.end()){
    if(otherNos.size() == 0){
      AddMoves(i, ++n3);
      otherFiles.erase(i);
      otherFiles.insert(n3);
    }
    else{
      int j = *otherNos.begin();
      Fix(j);
      AddMoves(i, j);
      otherFiles.erase(i);
      otherNos.erase(j);
    }
  }
}

void Fix(int i){
  if(i <= n1)
    Fix(i, exampleFiles, testFiles, exampleNos, testNos);
  else
    Fix(i, testFiles, exampleFiles, testNos, exampleNos);
}

void FixMissing(set<int>& myFiles, queue<int>& myPriorities, set<int>& myNos){
  int i = missing.front(), j;
  missing.pop();
  if(myPriorities.size()){
    j = myPriorities.front();
    myPriorities.pop();
    missing.push(j);
  }
  else
    j = *myFiles.begin();
  AddMoves(j, i);
  myFiles.erase(j);
  myNos.erase(i);
}

int main(){
  scanf("%d", &n);

  for(int i = 0; i <= 2 * n; ++i)
    strcpy(numStrings[i], to_string(i).c_str());

  nxt = 2 * n;

  for(int i = 1; i <= n; ++i){
    int s, t;
    scanf("%s%d", tempStr, &t);
    s = GetInt();
    if(t)
      exampleFiles.insert(s);
    else
      testFiles.insert(s);
  }

  n1 = exampleFiles.size(), n2 = n1 + testFiles.size(), n3 = n;

  for(int i = 1; i <= n; ++i){
    if(exampleFiles.find(i) == exampleFiles.end() && testFiles.find(i) == testFiles.end())
      missing.push(i);
  }

  for(int i = 1; i <= n1; ++i){
    if(exampleFiles.find(i) == exampleFiles.end())
      exampleNos.insert(i);
    else
      exampleFiles.erase(i);

    if(testFiles.find(i) != testFiles.end())
      testPriorities.push(i);
  }

  for(int i = n1 + 1; i <= n2; ++i){
    if(testFiles.find(i) == testFiles.end())
      testNos.insert(i);
    else
      testFiles.erase(i);

    if(exampleFiles.find(i) != exampleFiles.end())
      examplePriorities.push(i);
  }

  while(missing.size()){
    int i = missing.front();
    if(i <= n1)
      FixMissing(exampleFiles, examplePriorities, exampleNos);
    else
      FixMissing(testFiles, testPriorities, testNos);
  }

  while(exampleNos.size()){
    int i = *exampleNos.begin();
    Fix(i);
    int j = *exampleFiles.begin();
    AddMoves(j, i);
    exampleFiles.erase(j);
  }

  while(testNos.size()){
    int i = *testNos.begin();
    Fix(i);
    int j = *testFiles.begin();
    AddMoves(j, i);
    testFiles.erase(j);
  }

  printf("%d\n", (int)moves.size());
  for(auto p : moves){
    printf("move %s %s\n", numStrings[p.first], numStrings[p.second]);
  }

  return 0;
}
