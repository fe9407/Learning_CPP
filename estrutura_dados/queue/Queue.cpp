#include "Queue.h"
#include <cstdlib>
#include <iostream>

Queue::Queue()
{
    tail = head = NULL;
    count = 0;
}

Queue::~Queue()
{
    clear();
}

bool Queue::full()
{
    return false;
}

bool Queue::empty()
{
    return count == 0;
}

void Queue::clear()
{
    QueuePointer p;
    while(head != NULL)
    {
        p = head;
        head = head->nextNode;
        delete p;
    }
    tail = NULL;
    count = 0;
}

int Queue::size()
{
    return count;
}

void Queue::append(QueueEntry x)
{
    QueuePointer p;

    p = new QueueNode;
    if(p == NULL)
    {
        std::cout << "Sem espaco para novo elemento! Saindo..." << std::endl;
        abort();
    }

    p->entry = x;
    p->nextNode = NULL;

    if(empty()){
        head = p;
    } else {
        tail->nextNode = p;
    }

    tail = p;
    count++;
}

void Queue::serve(QueueEntry &x)
{
    QueuePointer p;
    if(empty())
    {
        std::cout << "Fila vazia! Sem elementos para remover! Saindo..." << std::endl;
        abort();
    }
    x = head->entry;
    p = head;
    head = head->nextNode;
    delete p;
    count--;

    if(count == 0)
    {
        tail = NULL;
    }
}

void Queue::getFront(QueueEntry &x)
{
    if(empty())
    {
        std::cout << "Nao ha elementos na fila! Saindo..." << std::endl;
        abort();
    }
    x = head->entry;
}

void Queue::getRear(QueueEntry &x)
{
    if(empty())
    {
        std::cout << "Nao ha elementos na fila! Saindo..." << std::endl;
        abort();
    }
    x = tail->entry;
}

//tarefa:
/*
 Implementar: void getFront(QueueEntry &x)
 Implementar: void getRear(QueueEntry &x)
 */
