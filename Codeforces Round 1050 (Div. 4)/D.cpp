// D. Destruction of the Dandelion Fields
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;  // the number of fields
    cin >> n;

    vector<int> odds;
    vector<int> evens;

    for (int i = 0; i < n; ++i) {
      int input;
      cin >> input;
      if (input % 2)
        odds.push_back(input);
      else
        evens.push_back(input);
    }

    // 홀수 밭의 개수가 0이면, 제초기를 켤 수 없다 -> 모든 밭 제초 불가
    if (odds.size() == 0) {
      cout << 0 << '\n';
    } else {
      // 홀수 밭이 하나라도 있으면, 짝수 밭은 모두 제초할 수 있다.
      // (제초기를 켠 홀수 밭 이후, 모든 짝수 밭 처리)
      long long ans = accumulate(evens.begin(), evens.end(), 0LL);

      // 홀수 밭이 k개라면, 상위 ((k+1)/2)개의 홀수 밭에서 제초 (나머지는 제초기를 켜지 않은 상태에서 방문)
      // 7 -> 4
      // 8 -> 4
      sort(odds.begin(), odds.end(), greater<int>());
      for (int i = 0; i < (odds.size() + 1) / 2; ++i) ans += odds[i];

      cout << ans << '\n';
    }
  }
  return 0;
}
