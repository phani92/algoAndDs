#include <iostream>
#include <set>
using namespace std;

long substringCalculator(string s)
{
  // We can solve the problem by creating a hashset of the distinct substrings.
  set<string> substringSet;

  // List All Substrings into the hashset
  for (int i = 0; i <= s.length(); i++)
  {
    for (int j = 1; j <= s.length() - i; j++)
    {
      // Insert each substring into the Set
      substringSet.insert(s.substr(i, j));
    }
  }

  // Length of the HashSet is the size of the distinct substrings
  return substringSet.size();
};

int main()
{
  return 0;
}
