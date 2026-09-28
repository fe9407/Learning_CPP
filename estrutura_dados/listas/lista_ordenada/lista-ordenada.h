#ifndef ORDED_LIST_H
#define ORDED_LIST_H
typedef int ListEntry;
class OrderedList
{
    public:
        OrderedList();
        ~OrderedList();
        void insert(int x);
        void remove(int x);
        int search(int x);
        int size();
        bool empty();
        bool full();
        void clear();
    private:
        // declaração de tipos
        struct ListNode; // declaracao forward
        typedef ListNode * ListPointer;
        struct ListNode
        {
            int entry; // tipo de dado colocado na lista
            ListPointer nextNode; // ligação para próximo elemento na lista
        };
        // declaração de campos
        ListPointer head, sentinel; // início da lista e sentinela
        int count; // número de elementos
};
#endif
