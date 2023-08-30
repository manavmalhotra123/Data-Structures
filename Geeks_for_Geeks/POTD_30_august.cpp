Node* deleteNode(Node* head, int x) {
    // If list is empty or x is invalid
    if (!head || x <= 0) return head;

    // If the head node is the one to be deleted
    if (x == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;  // free memory
        return head;
    }

    Node* temp = head;
    int n = 1;
    while (temp && n < x - 1) {  // go up to the node before the x-th node
        temp = temp->next;
        n++;
    }

    // If position x is valid and the next node exists
    if (temp && temp->next) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;  // free memory
    }

    return head;
}

