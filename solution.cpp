#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>

using namespace sol750;
using namespace std;

/*takeaways
  - look at two rows at a time and see how many rectangles we can form
    1 0 [1] [1] [1]
    0 0 [1] [1] [1]
    - to form a rectangle you need two horizontal and two vertical lines
    - we scan two rows at a time only so only two horizontal lines to
      choose from
      nCr = n! / ((n – r)! r!) => choose 2 (r) from 2 (2) only have one
      possibility = 1
    - we have 3 vertical lines to choose from so the number of combinations
      is:
      3C2 = 3!/(1! 2!) = 3
    - so total rectangles generated : 1 x 3 = 3
    - since we only look at two rows at a time so you can only have
      one horizontal combination.
      1 x nC2 = n!/((n-2)! 2!) = n(n-1)/2

  - so given two rows in the grid, we just have to calculate how many vertical
    lines can be formed by counting how many cols that have 1's on both rows

*/

int Solution::countRects(vector<vector<int>> &grid)
{
  const int m = grid.size();
  const int n = grid[0].size();
  auto result = 0;

  for (auto i = 0; i < m; i++)
  {
    auto ones = vector<int>();
    /* for optimization purpose
       - we only have to look at these locations
         from row i+1 to m-1
    */
    for (auto j = 0; j < n; j++)
      if (grid[i][j] == 1)
        ones.push_back(j);
    /* compare wit other rows one by one
     */
    for (auto j = i + 1; j < m; j++)
    {
      auto vLines = 0;
      /* you can form a vertical line only if
         both row i and row j have 1's at the
         same column
      */
      for (auto k = 0; k < ones.size(); k++)
        if (grid[j][ones[k]])
          vLines++;

      /* choose 2 out of "vLines" vertical lines
         for form a rectangle
      */
      result += (vLines * (vLines - 1) / 2);
    }
  }

  return result;
}
