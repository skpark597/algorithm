

#include <algorithm>
#include <vector>

using namespace std;

namespace util {
bool isEqualUnordered(vector<vector<int>>& vec0, vector<vector<int>>& vec1) {
  if (vec0.size() != vec1.size()) return false;

  vector<vector<int>> new_vec0 = vec0;
  vector<vector<int>> new_vec1 = vec1;

  sort(new_vec0.begin(), new_vec0.end());
  sort(new_vec1.begin(), new_vec1.end());

  return new_vec0 == new_vec1;
}

}  // namespace util