#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> ReadArray(int n){
  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  return a;
}

bool Check(vector<int> preorder, vector<int> postorder, vector<int> inorder){
  if(postorder.size() != preorder.size() || inorder.size() != preorder.size()){
    return false;
  }

  if(preorder.empty()){
    return true;
  }

  if(preorder.front() != postorder.back()){
    return false;
  }

  int i = 0;
  for( ; i < inorder.size() && inorder[i] != preorder.front(); ++i);

  if(i == inorder.size()){
    return false;
  }

  int left_size = i;

  vector<int> left_preorder = vector<int>(preorder.begin() + 1, preorder.begin() + left_size + 1);
  vector<int> left_postorder = vector<int>(postorder.begin(), postorder.begin() + left_size);
  vector<int> left_inorder = vector<int>(inorder.begin(), inorder.begin() + left_size);

  vector<int> right_preorder = vector<int>(preorder.begin() + left_size + 1, preorder.end());
  vector<int> right_postorder = vector<int>(postorder.begin() + left_size, postorder.end() - 1);
  vector<int> right_inorder = vector<int>(inorder.begin() + left_size + 1, inorder.end());

  return Check(left_preorder, left_postorder, left_inorder) && Check(right_preorder, right_postorder, right_inorder);
}

int main(){
  int n;
  scanf("%d", &n);

  vector<int> preorder = ReadArray(n);
  vector<int> postorder = ReadArray(n);
  vector<int> inorder = ReadArray(n);

  printf("%s\n", Check(preorder, postorder, inorder) ? "yes" : "no");

  return 0;
}