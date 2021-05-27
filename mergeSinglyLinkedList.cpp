// https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem

#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode
{
public:
  int data;
  SinglyLinkedListNode *next;

  SinglyLinkedListNode(int node_data)
  {
    this->data = node_data;
    this->next = nullptr;
  }
};

class SinglyLinkedList
{
public:
  SinglyLinkedListNode *head;
  SinglyLinkedListNode *tail;

  SinglyLinkedList()
  {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insert_node(int node_data)
  {
    SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

    if (!this->head)
    {
      this->head = node;
    }
    else
    {
      this->tail->next = node;
    }

    this->tail = node;
  }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep, ofstream &fout)
{
  while (node)
  {
    fout << node->data;

    node = node->next;

    if (node)
    {
      fout << sep;
    }
  }
}

void free_singly_linked_list(SinglyLinkedListNode *node)
{
  while (node)
  {
    SinglyLinkedListNode *temp = node;
    node = node->next;

    free(temp);
  }
}

// Complete the findMergeNode function below.

/*
 * The logic to find merge node is amazing.
 * If there are two linked lists that meet at a given node then how to figure out the node ?
 * We can take two iterators for both the heads and start incrementing them
 * until both these counters meet.
 *
 * Make an interating pointer like this: it goes forward every time till the end,
 * and then jumps to the beginning of the opposite list, and so on.
 * Create two of these, pointing to two heads.
 * Advance each of the pointers by 1 every time, until they meet.
 * This will happen after either one or two passes.
 *
 * we have 2 lists: [a-b-c-x-y-z] and [p-q-x-y-z].
 * Path of first pointer [a,b,c,x,y,z,p,q,x],
 * path of second pointer [p,q,x,y,z,a,b,c,x]
 *
 * At one of the pass they both will meet and that is the node.
 * time complexity of this solution is O(n).
 */
int findMergeNode(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
  SinglyLinkedListNode *cnt1 = head1;
  SinglyLinkedListNode *cnt2 = head2;

  while (cnt1 != cnt2)
  {
    if (cnt1->next == NULL)
    {
      cnt1 = head2;
    }
    else
    {
      cnt1 = cnt1->next;
    }

    if (cnt2->next == NULL)
    {
      cnt2 = head1;
    }
    else
    {
      cnt2 = cnt2->next;
    }
  }

  return cnt1->data;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int tests;
  cin >> tests;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int tests_itr = 0; tests_itr < tests; tests_itr++)
  {
    int index;
    cin >> index;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedList *llist1 = new SinglyLinkedList();

    int llist1_count;
    cin >> llist1_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist1_count; i++)
    {
      int llist1_item;
      cin >> llist1_item;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      llist1->insert_node(llist1_item);
    }

    SinglyLinkedList *llist2 = new SinglyLinkedList();

    int llist2_count;
    cin >> llist2_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist2_count; i++)
    {
      int llist2_item;
      cin >> llist2_item;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      llist2->insert_node(llist2_item);
    }

    SinglyLinkedListNode *ptr1 = llist1->head;
    SinglyLinkedListNode *ptr2 = llist2->head;

    for (int i = 0; i < llist1_count; i++)
    {
      if (i < index)
      {
        ptr1 = ptr1->next;
      }
    }

    for (int i = 0; i < llist2_count; i++)
    {
      if (i != llist2_count - 1)
      {
        ptr2 = ptr2->next;
      }
    }

    ptr2->next = ptr1;

    int result = findMergeNode(llist1->head, llist2->head);

    fout << result << "\n";
  }

  fout.close();

  return 0;
}
