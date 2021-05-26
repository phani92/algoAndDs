// https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

#include <iostream>
#include <vector>
using namespace std;

// int minSwap(vector<int>arr)
// {
//   int minSwap = 0;
//   int temp;
//   int n = arr.size();

//   for(int i=0; i<(n-1); i++){
//     if(arr[i] != i+1){
//       // 1 .. 5-1 = 4 positions
//       for(int j=i+1; j<(n-i+2); j++){
//         if(arr[j] == i+1){
//           temp = arr[i];
//           arr[i] = arr[j];
//           arr[j] = temp;
//           break;
//         }
//       }
//       minSwap++;
//     }
//   }
//   return minSwap;
// };

int minSwap(vector<int> arr)
{
  int i, c = 0, n = arr.size();
  for (i = 0; i < n; i++)
  {
    if (arr[i] == (i + 1))
      continue;

    swap(arr[i], arr[arr[i] - 1]);
    c++;
    i--;
  }
  return c;
};

int main()
{
  int n, temp;
  vector<int> arr;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    arr.push_back(temp);
  }

  cout << minSwap(arr) << endl;
  return 0;
}