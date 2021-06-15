#include <iostream>
#include <sstream>
using namespace std;

class DubLinkListNode
{
public:
  int data;
  DubLinkListNode *prev;
  DubLinkListNode *next;

  DubLinkListNode(int a)
  {
    this->data = a;
    this->prev = NULL;
    this->next = NULL;
  }
};

void addNode(DubLinkListNode *head, DubLinkListNode *node)
{
  DubLinkListNode *temp = head;

  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = node;
  node->prev = temp;
};

void mth_to_last(DubLinkListNode *head, int m)
{
  DubLinkListNode *temp = head;
  int cnt = 0;

  while (temp->next != NULL)
  {
    temp = temp->next;
    cnt++;
  }

  if (m > cnt)
  {
    cout << "NIL" << endl;
    return;
  }

  for (int i = 0; i < m; i++)
  {
    temp = temp->prev;
  }

  cout << temp->data << endl;
};

int main()
{
  int m;
  int temp;
  cin >> m;

  // Receive input as a string
  string input;
  getline(std::cin, input);
  getline(std::cin, input);

  // Put the string into a stringstream
  std::stringstream stream(input);

  stream >> temp;
  DubLinkListNode *head = new DubLinkListNode(temp);

  // Create the Doubly linked list.
  while (1)
  {
    if (!stream)
      break;

    // Adds stream integers into the list
    stream >> temp;
    DubLinkListNode *tempNode = new DubLinkListNode(temp);
    addNode(head, tempNode);
  }

  mth_to_last(head, m);

  return 0;
}