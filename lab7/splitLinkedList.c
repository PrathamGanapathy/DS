struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    struct ListNode* temp = head; int n = 0;
    for(; temp != NULL; temp=temp->next, n++);
    struct ListNode** lists = (struct ListNode**)malloc(k*sizeof(struct ListNode*));
    for(int i = 0; i < k; i++) lists[i] = NULL;
    int earlier_lists = n%k, size=n/k;
    int current = 0; bool list_over = false;
    temp = head;
    *returnSize = k;
    for(int i = earlier_lists; i > 0; i--){
            // printf("Entering here\n");
            struct ListNode* temp1 = temp;
            lists[current++] = temp;
            for(int j = 0; j < size; j++) temp1 = temp1->next;
            temp = temp1->next;
            temp1->next = NULL;
    }
    // printf("%d %d %d", lists[0]->val, lists[1]->val, lists[2]->val);
    if (temp == NULL) return lists;
    for(int i = 0; i < k-earlier_lists; i++){
            struct ListNode* temp1 = temp;
            if (temp1 == NULL) break;
            for(int j = 0; j < size-1; j++) temp1 = temp1->next;
            lists[current++] = temp;
            temp = temp1->next;
            temp1->next = NULL;
            // for(int l = 0; l < k; l++){
            //     for(struct ListNode* temp2 = lists[l]; temp2 != NULL; temp2 = temp2->next){
            //         printf("%d ", temp2->val);
            //     }
            //     printf("\n");
            // }
    }
    return lists;
}
