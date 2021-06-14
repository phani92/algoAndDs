#include <iostream>
#include <mem.h>
using namespace std;

class array
{
  int totalSize;
  int usedSize;
  int *arr;

public:
  // Default constructor
  array()
  {
    totalSize = 0;
    usedSize = 0;
    arr = NULL;
  }

  // Overloaded constructor
  array(int tSize)
  {
    totalSize = tSize;
    usedSize = 0;
    arr = new int[totalSize];
  }

  // Set values in the array
  bool add(int val)
  {
    if (usedSize < totalSize)
    {
      arr[usedSize] = val;
      usedSize++;
      return true;
    }
    else
    {
      // Request new block of memory
      resize(totalSize);
    }
    return false;
  }

  // inserts a value in the array
  bool insert(int val, int pos)
  {
    // Return if there is no space or the requested position is out of array size.
    if ((usedSize >= totalSize) || (pos >= totalSize))
    {
      return false;
    }

    // Adjust the next elements
    for (int i = usedSize; i >= pos; i--)
    {
      arr[i+1] = arr[i];
    }
    // inserts the element
    arr[pos] = val;

    return true;
  }

  // Delete a value at a given index
  bool remove(int pos)
  {
    int nxt;

    // Return if there is no space or the requested position is out of array size.
    if (pos > totalSize)
    {
      return false;
    }

    for (int i = pos; i < usedSize; i++)
    {
      arr[pos] = arr[i + 1];
    }
    usedSize--;
    return true;
  }

  // Resize the array with new requested size
  bool resize(int reqSize)
  {
    totalSize += reqSize;
    int *newMemPtr = new int[totalSize];
    memcpy(newMemPtr, arr, usedSize * sizeof(int));
    free(arr);
    arr = newMemPtr;
    return true;
  }

  // Display values
  void show(void)
  {
    for (int i = 0; i < usedSize; i++)
    {
      cout << "Value at index: " << i << " is " << arr[i] << endl;
    }
  }

  // Destructor
  ~array()
  {
    free(arr);
  }
};

int main()
{
  int n = 5;
  array example(n);

  for (int i = 0; i < n-1; i++)
  {
    example.add(i + 10);
  };

  example.insert(10, 2);
  example.remove(4);
  example.add(25);

  example.resize(5);

  for (int i = 0; i < 5; i++)
  {
    example.add(i);
  };

  example.show();

  return 0;
}