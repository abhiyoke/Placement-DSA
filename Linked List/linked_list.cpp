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

