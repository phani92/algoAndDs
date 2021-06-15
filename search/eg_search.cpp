#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int linearSearch(vector<int> arr, int val)
{
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] == val)
    {
      return 1;
    }
  }
  return -1;
};

int binarySearch(vector<int> arr, int val)
{
  int low = 0;
  int high = arr.size() - 1;
  int mid;

  sort(arr.begin(), arr.end());

  while (low <= high)
  {
    mid = (high + low) / 2;
    if (val == arr[mid])
    {
      return 1;
    }
    else if (val < arr[mid])
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  return -1;
};

int main()
{
  vector<int> arr;
  vector<int>::iterator it;
  int temp;

  for (int i = 0; i < 100; i++)
  {
    temp = rand() % 100;
    arr.push_back(temp);
  }

  it = arr.begin();
  arr.insert(it + 3, 20);
  cout << "linear search output is " << linearSearch(arr, 20) << endl;

  arr.erase(it + 3);
  cout << "Binary search output is " << binarySearch(arr, 20) << endl;

  return 0;
}