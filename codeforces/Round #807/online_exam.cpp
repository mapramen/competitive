#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000
#define B 12

mt19937 rnd(random_device{}());
uniform_int_distribution<int> dis(0, 1);

int cnt[B + 1];
int initial_guess_query[N], guess_query[N], correct_guess_query[N], initial_quess_query_ans;

int Query(int n, int query[]){
  for(int i = 0; i < n; ++i){
    putchar(query[i] == 1 ? 'T' : 'F');
  }
  putchar('\n');
  fflush(stdout);

  int ans;
  scanf("%d", &ans);

  if(ans == n){
    exit(0);
  }

  return ans;
}

int Query(int n, int correct_guess, int guess){
  return n - __builtin_popcount(guess ^ correct_guess);
}

void InitializeGuessQuery(int n){
  for(int i = 0; i < n; ++i){
    guess_query[i] = initial_guess_query[i];
  }
}

void UpdatePossibleCorrectGuesses(int n, vector<int>& possible_correct_guesses, int guess, int cnt){
  vector<int> ans;
  for(int possible_correct_guess: possible_correct_guesses){
    if(Query(n, possible_correct_guess, guess) == cnt){
      ans.push_back(possible_correct_guess);
    }
  }
  swap(ans, possible_correct_guesses);
  ans.clear();
}

int ExtractGuess(int n, int query[], int l, int r){
  int mask = 0;
  for(int i = l; i <= r; ++i){
    mask = 2 * mask + query[i];
  }
  return mask;
}

double GetEntropy(int n, vector<int>& possible_correct_guesses, int guess){
  for(int possible_correct_guess: possible_correct_guesses){
    ++cnt[Query(n, possible_correct_guess, guess)];
  }

  double ans = 0;
  for(int i = 0, m = possible_correct_guesses.size(); i <= n; ++i){
    if(cnt[i] == 0){
      continue;
    }
    
    double p = 1.0 * cnt[i] / m;
    cnt[i] = 0;

    ans += - p * log2(p);
  }

  return ans;
}

int GetBestGuess(int n, vector<int>& possible_correct_guesses){
  pair<double,int> best_guess{0, 0};
  for(int guess = 0; guess < (1 << n); ++guess){
    best_guess = max(best_guess, {GetEntropy(n, possible_correct_guesses, guess), guess});
  }
  return best_guess.second;
}

void SetQuery(int n, int query[], int l, int r, int guess){
  for(int i = r; i >= l; --i, guess /= 2){
    query[i] = guess % 2;
  }
}

void CorrectGuess(int n, int l, int r){
  int m = r - l + 1;

  vector<int> possible_correct_guesses(1 << m);
  iota(possible_correct_guesses.begin(), possible_correct_guesses.end(), 0);

  InitializeGuessQuery(n);
  SetQuery(n, guess_query, l, r, ((1 << m) - 1) ^ ExtractGuess(n, initial_guess_query, l, r));

  int rest_query_ans = (initial_quess_query_ans + Query(n, guess_query) - m) / 2;

  UpdatePossibleCorrectGuesses(m, possible_correct_guesses, ExtractGuess(n, initial_guess_query, l, r), initial_quess_query_ans - rest_query_ans);

  while(possible_correct_guesses.size() != 1){
    int best_guess = GetBestGuess(m, possible_correct_guesses);
    SetQuery(n, guess_query, l, r, best_guess);
    UpdatePossibleCorrectGuesses(m, possible_correct_guesses, best_guess, Query(n, guess_query) - rest_query_ans);
  }

  SetQuery(n, correct_guess_query, l, r, possible_correct_guesses.front());
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    initial_guess_query[i] = dis(rnd);
  }

  initial_quess_query_ans = Query(n, initial_guess_query);

  for(int i = 0; i < n; i += B){
    CorrectGuess(n, i, min(n, i + B) - 1);
  }

  Query(n, correct_guess_query);

  return 0;
}