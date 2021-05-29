#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int a)
  {
    this->data = a;
    this->next = NULL;
  }
};

void insertNode(Node *head, Node *nodeToInsert, int position)
{
  Node *temp = head->next;

  for (int i = 0; i < position-1; i++)
  {
    // When we reach the end of the list and again point to the first element.
    // then add the node in the end.
    if (temp->next == head->next)
    {
      break;
    }
    temp = temp->next;
  }

  nodeToInsert->next = temp->next;
  temp->next = nodeToInsert;
  return;
}

void deleteNode(Node *head, Node *nodeToDelete){

  Node *temp = head->next;

  while(temp->next != nodeToDelete){
    temp = temp->next;
  }

  temp->next = temp->next->next;
  free(nodeToDelete);
  return;
};

void printNode(Node *head)
{
  Node *temp = head->next;

  while (temp->next != head->next)
  {
    cout << temp->data << endl;
    temp = temp->next;
  }

  if (temp == head)
  {
    cout << "End of list." << endl;
  }
  else
  {
    cout << temp->data << endl;
    cout << "End of list." << endl;
  }
}

int main()
{
  // Circular blank linked list
  Node *head = new Node(0);
  head->next = head;
  // printNode(head);

  Node *first = new Node(10);
  head->next = first;
  Node *second = new Node(20);
  first->next = second;
  Node *third = new Node(40);
  second->next = third;
  third->next = first;

  Node* nodeToInsert = new Node(30);
  insertNode(head, nodeToInsert, 2);

  deleteNode(head, third);

  // Assign head to point to the first node.
  printNode(head);

  return 0;
}