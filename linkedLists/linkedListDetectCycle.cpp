#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
};

// The fast and slow algorithm is called as Floyds tortoise and hare algorithm.
// one counter runs at a double pace and the other at a slower pace.
// Time complexit is O(n) because the worst case is to wait for the slow counter
// to complete the loop.
Node *next(Node *node)
{
  if (node)
    node = node->next;
  return node;
}

bool has_cycle(Node *head)
{
  Node *slow = next(head);
  Node *fast = next(next(head));

  while (slow != fast)
  {
    slow = next(slow);
    fast = next(next(fast));
  }

  return fast;
}
