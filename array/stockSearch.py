## Apply the array data structure to store, retreive and delete apple's stock
## by date where the dates are arranged in an increasing index.

import random

## Random stock array
stockArr = [random.randint(0,500) for i in range(0,10)]

## Traverse a list - O(n)
def traverse():
  for element in stockArr:
    print(element)

## Insert a number at the end
def insertBack(val):
  stockArr.append(int(val))

## Insert a number at the end
def insertFront(val):
  stockArr.insert(0,int(val))

## Delete a value from a given index
def delete(idx):
  stockArr.pop[idx]

if __name__ == "__main__":
  insertFront(10)
  traverse()
