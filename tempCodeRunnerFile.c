if (ptr != NULL && ptr->data != key)
    {
        head = ptr->next;
        return;
    }