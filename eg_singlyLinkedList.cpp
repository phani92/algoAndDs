#include <iostream>
using namespace std;

// Linked list struct
struct Node
{
  int Val;
  Node *next;
};

// Inserts an element in the front of the array.
void insertFront(Node **head, int val)
{
  if (*head == NULL)
  {
    cout << "Error as head is pointing to null" << endl;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->Val = val;
  newNode->next = *head;
  *head = newNode;
}

/*
* I tried to assign memory with the help of new keyword like
* Node* newNode = new Node();
* The above declaration did not work because it was always declared the struct
* as a new variable with a memory in the stack. The moment the control came out
* of the function the memory was lost.
* Therefore, now we use a double pointer and pass a memory location of a pointer and
* also use malloc to create new node.
* Important is Phani to remember the usage of new keyword and double pointers in
* linked list.
*/

// Inserts an element in the end of the array.
void insertBack(Node **head, int val)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  struct Node *last = *head;

  newNode->Val = val;
  newNode->next = NULL;

  if (*head == NULL)
  {
    *head = newNode;
    return;
  }

  while (last->next != NULL)
  {
    last = last->next;
  }

  last->next = newNode;
}

void insertMiddle(Node **head, int val, int pos)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->Val = val;
  Node *temp = *head;

  for (int i = 0; i < pos - 1; i++)
  {
    temp = temp->next;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

void deleteFront(Node **head)
{
  if (*head == NULL)
  {
    cout << "Error as head is pointing to null" << endl;
  }

  if ((*head)->next == NULL)
  {
    cout << "Head points to null" << endl;
  }

  *head = (*head)->next;
}

void deleteEnd(Node **head)
{
  Node *temp = *head;

  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = NULL;
}

void deleteMiddle(Node **head, int pos)
{
  Node *temp = *head;
  for (int i = 0; i < pos - 1; i++)
  {
    if (temp->next != NULL)
    {
      temp = temp->next;
    }
  }

  temp->next = temp->next->next;
}

// Traverse through the list
void show(Node *node)
{
  while (node != NULL)
  {
    cout << "Value is " << node->Val << endl;
    node = node->next;
  }
}

int main()
{
  Node *head = NULL;

  insertBack(&head, 20);
  insertBack(&head, 30);
  insertBack(&head, 40);
  insertBack(&head, 50);
  insertBack(&head, 60);
  insertBack(&head, 70);

  insertFront(&head, 10);
  insertMiddle(&head, 90, 3);

  deleteFront(&head);
  deleteEnd(&head);
  deleteMiddle(&head, 2);

  show(head);
  return 0;
}
