// https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=linked-lists&h_r=next-challenge&h_v=zen

#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode
{
public:
  int data;
  DoublyLinkedListNode *next;
  DoublyLinkedListNode *prev;

  DoublyLinkedListNode(int node_data)
  {
    this->data = node_data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList
{
public:
  DoublyLinkedListNode *head;
  DoublyLinkedListNode *tail;

  DoublyLinkedList()
  {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insert_node(int node_data)
  {
    DoublyLinkedListNode *node = new DoublyLinkedListNode(node_data);

    if (!this->head)
    {
      this->head = node;
    }
    else
    {
      this->tail->next = node;
      node->prev = this->tail;
    }

    this->tail = node;
  }
};

void print_doubly_linked_list(DoublyLinkedListNode *node, string sep, ofstream &fout)
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

void free_doubly_linked_list(DoublyLinkedListNode *node)
{
  while (node)
  {
    DoublyLinkedListNode *temp = node;
    node = node->next;

    free(temp);
  }
}

/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *llist, int data)
{
  DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
  DoublyLinkedListNode *temp = llist;

  if (!llist)
  {
    llist = newNode;
  }
  else
  {
    while (temp->data < data)
    {
      if (temp->next == NULL)
      {
        break;
      }
      temp = temp->next;
    }

    // Edge case for last occurrence
    if (temp->next == NULL)
    {
      if (temp->data > data)
      {
        temp->prev->next = newNode;
        newNode->prev = temp->prev;
        newNode->next = temp;
      }
      else
      {
        temp->next = newNode;
        newNode->prev = temp;
      }
    }
    // Insert in the middle
    else if (temp->prev != NULL)
    {
      temp->prev->next = newNode;
      newNode->next = temp;
      newNode->prev = temp->prev;
      temp->prev = newNode;
    }
    // Insert in the beginning
    else
    {
      newNode->next = temp;
      temp->prev = newNode;
      llist = newNode;
    }
  }

  return llist;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++)
  {
    DoublyLinkedList *llist = new DoublyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++)
    {
      int llist_item;
      cin >> llist_item;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    DoublyLinkedListNode *llist1 = sortedInsert(llist->head, data);

    print_doubly_linked_list(llist1, " ", fout);
    fout << "\n";

    free_doubly_linked_list(llist1);
  }

  fout.close();

  return 0;
}
