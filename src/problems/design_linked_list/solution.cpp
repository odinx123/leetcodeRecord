class MyLinkedList {
public:
    MyLinkedList() {
        head = nullptr;
        next = nullptr;
        val = 0;
    }

    MyLinkedList(int v) {
        next = nullptr;
        val = v;
    }
    
    int get(int index) {
        auto it = head;
        for (int i = 0; i < index; ++i) {
            if (it == nullptr)
                return -1;
            it = it->next;
        }
        
        if (it == nullptr) return -1;
        return it->val;
    }
    
    void addAtHead(int val) {
        if (head == nullptr)
            head = new MyLinkedList(val);
        else {
            auto temp = head;
            head = new MyLinkedList(val);
            head->next = temp;
        }
    }
    
    void addAtTail(int val) {
        if (head == nullptr) {
            head = new MyLinkedList(val);
            return;
        }
        for (auto it = head; it != nullptr; it=it->next) {
            if (it->next == nullptr) {
                it->next = new MyLinkedList(val);
                break;
            }
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            auto t = head;
            head = new MyLinkedList(val);
            head->next = t;
            return;
        }
        auto it = head;
        for (int i = 1; i < index; ++i) {
            if (it == nullptr)
                return;
            it = it->next;
        }
        if (it == nullptr)
            return;
        auto temp = it->next;
        it->next = new MyLinkedList(val);
        it->next->next = temp;
    }
    
    void deleteAtIndex(int index) {
        if (index == 0) {
            auto t = head;
            head = head->next;
            t->next = nullptr;
            delete t;
        }
        auto it = head;
        for (int i = 1; i < index; ++i) it = it->next;
        if (it == nullptr) return;
        auto temp = it->next;
        if (it != nullptr && temp != nullptr)
            it->next = temp->next;
        delete temp;
    }
private:
    int val;
    MyLinkedList* next;
    MyLinkedList* head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */