//Class of node
class Node {
public:
    int data;
    Node* next;
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

//insert a node
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node(newData, head);
    head = newNode;
}
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node(newData);

    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtMiddle(Node*& head, int newData, int position) {
    Node* newNode = new Node(newData);
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
   Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; ++i) {  //imp
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of range" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;  //imp
    temp->next = newNode;  //imp
}

//delete a node:
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) return; // If the list is empty, nothing to delete

    Node* temp = head;
    head = head->next;
    delete temp;
}
void deleteFromEnd(Node*& head) {
    if (head == nullptr) return; // If the list is empty, nothing to delete
    if (head->next == nullptr) { // If there is only one element in the list
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
void deleteFromMiddle(Node*& head, int position) {
    if (head == nullptr) return; // If the list is empty, nothing to delete

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; ++i) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Position out of range" << endl;
        return;
    }
   if(temp->next->next==nullptr) {
    deleteFromEnd(head);
   }
   else{
     Node* nodeToDelete = temp->next;
     temp->next=temp->next->next;
   delete nodeToDelete;
   }
}

//delete node in double LL at kth index:
void deleteAtIndex(Node*& head, int k) {
    if (head == nullptr) return; // If the list is empty
    Node* current = head;
    if (k == 0) {  // Special case for the first node
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete current;
        return;
    }
    int index = 0;
    while (current != nullptr && index < k) {
        current = current->next;
        index++;
    }
    if (current == nullptr) {
        cout << "Index out of range" << endl;
        return;
  }
    if (current->prev != nullptr) current->prev->next = current->next;
    if (current->next != nullptr)  current->next->prev = current->prev; 
    delete current;
}

//Rerverse a DLL:Using stack
Node* reverseDLL(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
     temp->data = st.top();
    st.pop();
     temp = temp->next;
    }
    return head;
}
//link exchange:
Node* reverseDLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }
    Node* prev = NULL;  
    Node* current = head;   
    while (current != NULL) {
        prev = current->back;   // Store a reference to the previous node
        current->back = current->next;   // Swap the previous and next pointers
          current->next = prev;      // This step reverses the links
       current = current->back;  // Move to the next node in the original list 
    } return prev->back;}

//middle of LL:(Tortoise and Hare algorithm)
Node *findMiddle(Node *head) {
    Node *slow = head; 
    Node *fast = head; 
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next; 
        fast = fast->next->next; 
    }
    return slow; 
}

//reverse LL:
  ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* t=curr->next;
            curr->next=prev;
            prev=curr;
            curr=t;
        }
        return prev;
    }

//detect cycle/loop in LL:
in middle func:in while loop at end just include if(slow==fast) return true;

//starting point of LL:
if(slow==fast) { then just make slow =head and just use while(slow!=fast){ s=s->next,f=f->next} return slow} return nullptr;

//check palindrome in LL:can be check by stack by t->d==st.top().Or by finding middle ele,then reverseLL from slow->next and call these node as newH,then f=head,
//s=newH.THen in while loop check (s->d==f->d) and if not just reverseLL(newH).
bool isPalindrome(ListNode* head) {
         if (head == NULL || head->next == NULL) {   
        return true; 
    }
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* newHead=reverseLL(slow->next);
    ListNode* first=head;
    ListNode* second=newHead;
    while(second!=nullptr){
        if(first->val != second->val){
            reverseLL(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLL(newHead);
    return true;
    }

//length of loop in LL:
if(slow==fast){fast=fast->n, c=1,while(slow!=fast){slow=slow->n,c++} ret c;


