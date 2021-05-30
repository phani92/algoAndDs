#include <iostream>
using namespace std;

int cntReqDeletions(string str)
{
  int cnt = 0;

  for (string::iterator itr = str.begin(); itr != str.end(); itr++)
  {
    if (*itr == *(itr + 1))
    {
      cnt++;
    }
  }

  return cnt;
};

int main()
{
  string str;
  int queryCnt;

  cin >> queryCnt;
  for (int i = 1; i <= queryCnt; i++)
  {
    getline(cin, str);
    cout << cntReqDeletions(str) << endl;
  }
  return 0;
}
