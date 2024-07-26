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

