/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    Node* currentA = headA;
    Node* currentB = headB;
    
    if(currentA->next == nullptr && currentB->next != nullptr ||
       currentA->next != nullptr && currentB->next == nullptr){
            return 0;
        }
    
    while(currentA != nullptr && currentB != nullptr){
        if(currentA->data != currentB->data ||
          currentA->next == nullptr && currentB->next != nullptr ||
          currentA->next != nullptr && currentB->next == nullptr){
            return 0;
        }
        currentA = currentA->next;
        currentB = currentB->next;        
    }
    
    return 1;
}
