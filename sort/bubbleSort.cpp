#include <bits/stdc++.h>

using namespace std;

void countSwaps(vector<int> a)
{
  int swapCnt = 0;
  int temp;

  for (int i = 0; i < a.size() - 1; i++)
  {
    for (int j = i + 1; j < a.size(); j++)
    {
      if (a[i] > a[j])
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        swapCnt++;
      }
    }
  }

  cout << "Array is sorted in " << swapCnt << " swaps." << endl;
  cout << "First Element: " << *(a.begin()) << endl;
  cout << "Last Element: " << *(a.end() - 1) << endl;
}

int main()
{
  vector<int> a;

  for (int i = 0; i < 10; i++)
  {
    a.push_back(rand() % 100 + 1);
  }

  countSwaps(a);
  return 0;
}
