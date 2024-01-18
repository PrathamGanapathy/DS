struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* l = head;
    struct ListNode* r = head;
    int difference = right - left;
    if (left == right){
        return head;
    }
    for(int i = 0; i < left-1; i++){
        l = l->next;
    }
    for(int i = 0; i < right-1; i++){
        r = r->next;
    }
    printf("%d\n%d\n", l->val, r->val);
    while (difference >= 0){
        // printf("%d %d\n", l->val, r->val);
        int temp = l->val;
        l->val = r->val;
        r->val = temp;
        l = l->next;
        r = l;
        for(int i = 0; i < difference-2; i++){
            r = r->next;
        }   
        difference -=2;
    }
    return head;
}
