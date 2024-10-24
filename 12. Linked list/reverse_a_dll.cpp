class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        if  (head == NULL || head->next == NULL) return head;
        Node* curr = head;
        while (curr != NULL) {
            Node* forward = curr->next;
            curr->next = curr->prev;
            curr->prev = forward;
            curr = forward;
        }
        return curr;
    }
};
