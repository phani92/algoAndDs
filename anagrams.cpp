#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int makeAnagram(string a, string b)
{
  int deletionCnt = 0;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  string::iterator itrA = a.begin();
  string::iterator itrB = b.begin();

  for (itrA; !(itrA != a.end() && itrB != b.end()); itrA++)
  {
    if (*itrA < *itrB)
    {
      deletionCnt++;
    }
    else if (*itrA == *itrB)
    {
      itrB++;
    }
    else if (*itrA > *itrB)
    {
      deletionCnt++;
      itrB++;
    }
    else
    {
      cout << "Additional condition not checked : ";
      cout << "itrA is " << *itrA << ","
           << " itrB is " << *itrB << endl;
    }
  }

  if (itrA == a.end())
  {
    deletionCnt += (b.end() - itrB);
  }
  else if (itrB == b.end())
  {
    deletionCnt += (a.end() - itrA);
  }

  return deletionCnt;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string a;
  getline(cin, a);

  string b;
  getline(cin, b);

  int res = makeAnagram(a, b);

  fout << res << "\n";

  fout.close();

  return 0;
}
