#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 6

int credits[N];

double ReadAssessment() {
  string s;
  cin >> s;

  if (s == "ab") {
    return 0;
  }

  return stod(s);
}

double CalculateAssessmentMark(vector<double> assessments) {
  sort(assessments.begin(), assessments.end());
  return 45.0 * (assessments[1] + assessments[2]) / 40;
}

double CalculateAttendanceMark(double attendance_percentage) {
  if (attendance_percentage < 51) {
    return 5;
  }

  if (attendance_percentage < 61) {
    return 4;
  }

  if (attendance_percentage < 71) {
    return 3;
  }

  if (attendance_percentage < 81) {
    return 2;
  }

  if (attendance_percentage < 91) {
    return 1;
  }

  return 0;
}

double CalculateFinalExamMark(double final_exam_marks) {
  return final_exam_marks / 2;
}

int CalculatePoints() {
  vector<double> assessments = {ReadAssessment(), ReadAssessment(), ReadAssessment()};

  double final_exam_marks = ReadAssessment();
  double attendance_percentage = ReadAssessment();

  double total_marks = CalculateAssessmentMark(assessments) + CalculateAttendanceMark(attendance_percentage) + CalculateFinalExamMark(final_exam_marks);

  if (total_marks >= 91) {
    return 10;
  }

  if (total_marks >= 81) {
    return 9;
  }

  if (total_marks >= 71) {
    return 8;
  }

  if (total_marks >= 61) {
    return 7;
  }

  if (total_marks >= 51) {
    return 6;
  }

  if (total_marks == 50) {
    return 5;
  }

  return 0;
}

pair<bool, double> Solve() {
  for (int i = 0; i < N; i++) {
    scanf("%d", &credits[i]);
  }

  bool pass = true;
  int total_credits = 0;
  double weighted_sum_of_points = 0.0;

  for (int i = 0; i < N; ++i) {
    int points = CalculatePoints();
    if (points == 0) {
      pass = false;
    }
    total_credits += credits[i];
    weighted_sum_of_points += credits[i] * points;
  }

  double gpa = weighted_sum_of_points / total_credits;
  return {pass, gpa};
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    auto [pass, gpa] = Solve();
    printf("%s, %.2lf\n", pass ? "PASSED" : "FAILED", gpa);
  }
  return 0;
}