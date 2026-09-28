#ifndef LIST_H
#define LIST_H
typedef int ListEntry;
class List{
    public:
        List();
        ~List();
        bool empty();
        bool full();
        void insert(int p, ListEntry x);
        void remove(int p, ListEntry &x);
        void clear();
        void retrieve(int p, ListEntry &x);
        void replace(int p, ListEntry x);
        int size();
    private:
        struct ListNode;
        typedef ListNode* ListPointer;
        struct ListNode{
            ListEntry entry;
            ListPointer nextNode;
        };
        ListPointer head;
        void setPosition(int p, ListPointer &current);
        int count;
};
#endif