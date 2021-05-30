#include <iostream>
#include <vector>

using namespace std;

class Comparator
{
public:
  template <class T1, class T2>
  bool compare(T1 var1, T2 var2)
  {
    if (var1 == var2)
    {
      return true;
    }

    return false;
  }
};

// class Comparator
// {
// public:
//   bool compare(int num1, int num2)
//   {
//     if (num1 == num2)
//     {
//       return true;
//     }

//     return false;
//   }

//   bool compare(string s1, string s2)
//   {
//     if (s1 == s2)
//     {
//       return true;
//     }

//     return false;
//   }

//   bool compare(vector<int> arr1, vector<int> arr2)
//   {
//     if (arr1 == arr2)
//     {
//       return true;
//     }

//     return false;
//   }
// };

int main()
{
  Comparator comp;
  int testCases;
  cin >> testCases;
  while (testCases--)
  {
    int condition;
    cin >> condition;
    getchar();
    if (condition == 1)
    {
      string s1;
      getline(cin, s1);
      string s2;
      getline(cin, s2);
      if (comp.compare(s1, s2))
      {
        cout << "Same\n";
      }
      else
      {
        cout << "Different\n";
      }
    }
    else if (condition == 2)
    {
      int num1;
      cin >> num1;
      int num2;
      cin >> num2;
      if (comp.compare(num1, num2))
      {
        cout << "Same\n";
      }
      else
      {
        cout << "Different\n";
      }
    }
    else if (condition == 3)
    {
      int len1;
      cin >> len1;
      int len2;
      cin >> len2;

      vector<int> arr1;
      vector<int> arr2;

      for (int i = 0; i < len1; i++)
      {
        int val;
        cin >> val;
        arr1.push_back(val);
      }

      for (int i = 0; i < len2; i++)
      {
        int val;
        cin >> val;
        arr2.push_back(val);
      }

      if (comp.compare(arr1, arr2))
      {
        cout << "Same\n";
      }
      else
      {
        cout << "Different\n";
      }
    }
  }
  return 0;
}
