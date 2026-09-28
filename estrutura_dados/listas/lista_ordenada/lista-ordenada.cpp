#include "lista-ordenada.h"
#include <cstdlib>
#include <iostream>

//construtor
OrderedList::OrderedList()
{
    sentinel = new ListNode;
    head = sentinel;
    count = 0;
}

//destrutor
OrderedList::~OrderedList()
{
    ListPointer q;
    while(head != sentinel)
    {
        q = head;
        head = head->nextNode;
        delete q;
    }
    delete sentinel;
}

bool OrderedList::empty()
{
    return (head == sentinel);
}

bool OrderedList::full()
{
    return false;
}

void OrderedList::insert(int x)
{
    ListPointer p, q;

    //buscar local de inserção
    sentinel->entry = x;
    p = head;
    while(p->entry < x) p = p->nextNode;

    q = new ListNode;
    if(q == NULL)
    {
        std::cout << "Memoria insuficiente!!!";
        abort();
    }

    if(p == sentinel) {
        p->nextNode = q;
        sentinel = q;
    } else {
        *q = *p;
        p->entry = x;
        p->nextNode = q;
    }
    count++;
}

void OrderedList::remove(int x)
{
    ListPointer p=NULL, q=head;

    //Buscar local de remoção
    sentinel->entry = x;
    while(q->entry < x)
    {
        p = q;
        q = q->nextNode;
    }

    //Encontrou x?
    if(q->entry != x || q == sentinel) return;

    if(q == head) {
        head = q->nextNode;
    } else {
        p->nextNode = q->nextNode;
    }

    delete q;
    count--;
}

int OrderedList::search(int x)
{
    int posicao=1;
    ListPointer q = head;

    sentinel->entry = x;
    while(q->entry < x)
    {
        q = q->nextNode;
        posicao++;
    }

    if(q->entry != x || q == sentinel){
        return 0;
    } else {
        return posicao;
    }
}

void OrderedList::clear()
{
    ListPointer q;

    while(head != sentinel)
    {
        q = head;
        head = head->nextNode;
        delete q;
    }

    count = 0;
}

int OrderedList::size()
{
    return count;
}
