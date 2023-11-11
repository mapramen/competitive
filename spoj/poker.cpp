#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> GetSuitCounts(vector<string>& hand) {
  map<char, int> suit_count;
  for (int i = 0; i < 5; ++i) {
    ++suit_count[hand[i][1]];
  }

  vector<int> suit_count_vec;
  for (auto& suit : suit_count) {
    suit_count_vec.push_back(suit.second);
  }
  sort(suit_count_vec.begin(), suit_count_vec.end());

  return suit_count_vec;
}

vector<int> GetRankCounts(vector<string>& hand) {
  map<char, int> rank_count;
  for (int i = 0; i < 5; ++i) {
    ++rank_count[hand[i][0]];
  }

  vector<int> rank_count_vec;
  for (auto& rank : rank_count) {
    rank_count_vec.push_back(rank.second);
  }
  sort(rank_count_vec.begin(), rank_count_vec.end());

  return rank_count_vec;
}

int GetLowerValue(char c) {
  if (c == 'A') {
    return 1;
  }

  if (c == 'T') {
    return 10;
  }

  if (c == 'J') {
    return 11;
  }

  if (c == 'Q') {
    return 12;
  }

  if (c == 'K') {
    return 13;
  }

  return c - '0';
}

int GetHigherValue(char c) {
  return c == 'A' ? 14 : GetLowerValue(c);
}

bool IsContinuos(vector<string>& hand, function<int(char)> get_value) {
  vector<int> values;
  for (int i = 0; i < 5; ++i) {
    values.push_back(get_value(hand[i][0]));
  }

  sort(values.begin(), values.end());

  for (int i = 1; i < 5; ++i) {
    if (values[i] != values[i - 1] + 1) {
      return false;
    }
  }

  return true;
}

bool IsFlush(vector<string>& hand) {
  vector<int> suit_count = GetSuitCounts(hand);
  return suit_count.back() == 5;
}

bool IsRoyalFlush(vector<string>& hand) {
  if (!IsFlush(hand)) {
    return false;
  }

  sort(hand.begin(), hand.end());
  return hand[0][0] == 'A' && hand[1][0] == 'J' && hand[2][0] == 'K' && hand[3][0] == 'Q' && hand[4][0] == 'T';
}

bool IsStraight(vector<string>& hand) {
  return IsContinuos(hand, GetLowerValue) || IsContinuos(hand, GetHigherValue);
}

bool IsStraightFlush(vector<string>& hand) {
  return IsFlush(hand) && IsStraight(hand);
}

bool IsFourOfAKind(vector<string>& hand) {
  vector<int> rank_count = GetRankCounts(hand);
  return rank_count.back() == 4;
}

bool IsFullHouse(vector<string>& hand) {
  vector<int> rank_count = GetRankCounts(hand);
  return rank_count.back() == 3 && rank_count.size() == 2;
}

bool IsThreeOfAKind(vector<string>& hand) {
  vector<int> rank_count = GetRankCounts(hand);
  return rank_count.back() == 3;
}

bool IsTwoPairs(vector<string>& hand) {
  vector<int> rank_count = GetRankCounts(hand);
  return rank_count.back() == 2 && rank_count.size() == 3;
}

bool IsOnePair(vector<string>& hand) {
  vector<int> rank_count = GetRankCounts(hand);
  return rank_count.back() == 2;
}

string Solve() {
  vector<string> hand(5);
  for (int i = 0; i < 5; ++i) {
    cin >> hand[i];
  }

  if (IsRoyalFlush(hand)) {
    return "royal flush";
  }

  if (IsStraightFlush(hand)) {
    return "straight flush";
  }

  if (IsFourOfAKind(hand)) {
    return "four of a kind";
  }

  if (IsFullHouse(hand)) {
    return "full house";
  }

  if (IsFlush(hand)) {
    return "flush";
  }

  if (IsStraight(hand)) {
    return "straight";
  }

  if (IsThreeOfAKind(hand)) {
    return "three of a kind";
  }

  if (IsTwoPairs(hand)) {
    return "two pairs";
  }

  if (IsOnePair(hand)) {
    return "pair";
  }

  return "high card";
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}