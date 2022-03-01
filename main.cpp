#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol750;

/*
Input: grid =
[[1, 0, 0, 1, 0],
 [0, 0, 1, 0, 1],
 [0, 0, 0, 1, 0],
 [1, 0, 1, 0, 1]]
Output: 1
Explanation: There is only one corner rectangle,
with corners grid[1][2], grid[1][4], grid[3][2], grid[3][4].
*/
tuple<vector<vector<int>>, int>
testFixture1()
{
  auto grid = vector<vector<int>>{
      {1, 0, 0, 1, 0},
      {0, 0, 1, 0, 1},
      {0, 0, 0, 1, 0},
      {1, 0, 1, 0, 1}};

  return make_tuple(grid, 1);
}

/*
Input: grid =
[[1, 1, 1],
 [1, 1, 1],
 [1, 1, 1]]
Output: 9
Explanation: There are four 2x2 rectangles,
four 2x3 and 3x2 rectangles, and one 3x3 rectangle.
*/
tuple<vector<vector<int>>, int>
testFixture2()
{
  auto grid = vector<vector<int>>{
      {1, 1, 1},
      {1, 1, 1},
      {1, 1, 1}};

  return make_tuple(grid, 9);
}

/*
Input: grid =
[[1, 1, 1, 1]]
Output: 0
Explanation: Rectangles must have four distinct corners.
*/
tuple<vector<vector<int>>, int>
testFixture3()
{
  auto grid = vector<vector<int>>{
      {1, 1, 1, 1}};

  return make_tuple(grid, 0);
}

void test1()
{
  auto f = testFixture1();
  auto s = get<0>(f);
  auto t = get<1>(f);
  cout << "Test 1 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::countRects(get<0>(f));
  cout << "result: " << result << endl;
}

void test2()
{
  auto f = testFixture2();
  auto s = get<0>(f);
  auto t = get<1>(f);
  cout << "Test 2 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::countRects(get<0>(f));
  cout << "result: " << result << endl;
}

void test3()
{
  auto f = testFixture3();
  auto s = get<0>(f);
  auto t = get<1>(f);
  cout << "Test 3 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::countRects(get<0>(f));
  cout << "result: " << result << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}