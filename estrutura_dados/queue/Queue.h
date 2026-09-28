#ifndef QUEUE_H
#define QUEUE_H
typedef int QueueEntry;
class Queue
{
    public:
        Queue();
        ~Queue();
        void append(QueueEntry x);
        void serve(QueueEntry &x);
        void clear();
        int size();
        void getFront(QueueEntry &x);
        void getRear(QueueEntry &x);
        bool empty();
        bool full();
    private:
        struct QueueNode;
        typedef QueueNode* QueuePointer;
        struct QueueNode
        {
            QueueEntry entry;
            QueuePointer nextNode;
        };
        QueuePointer head, tail;
        int count;
};
#endif
