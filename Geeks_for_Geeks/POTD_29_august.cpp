*/
class Solution
{
    public:
    
    Node* reverse(Node *head) 
    {
        Node *prev = nullptr, *current = head, *next = nullptr;
        
        while (current != nullptr) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    Node* compute(Node* head) {
        head = reverse(head);  // Reverse the list to start from the end

        Node* curr = head;
        Node* prev = nullptr;
        int maxSoFar = curr->data;  // initialize with the first node's data

        while (curr) 
        {
            if (curr->data < maxSoFar) 
            {
                if (!prev) {
                    head = curr->next;
                    delete curr;
                    curr = head;
                } else {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
            } 
            else 
            {
                maxSoFar = curr->data;  // update maxSoFar
                prev = curr;
                curr = curr->next;
            }
        }

        return reverse(head);  // Reverse the list again to restore the original order
    }
};

