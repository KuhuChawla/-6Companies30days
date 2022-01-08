void linkdelete(struct Node  *head, int M, int N)
    {
        Node *temp = head, *t; 
        int count; 
        while (temp) { 
        for (count = 1; count < M && 
                temp!= NULL; count++) 
            temp = temp->next; 
        if (temp == NULL) 
            return; 
        t = temp->next; 
        for (count = 1; count<=N && t!= NULL; count++) 
        { 
            Node *curr = t; 
            t = t->next; 
            free(curr); 
        } 

        temp->next = t; 
        temp = t; 
        } 
    }