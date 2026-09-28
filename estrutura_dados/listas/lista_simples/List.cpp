#include "List.h"
#include <iostream>
using namespace std;

List::List()
{
    head = NULL;
    count = 0;
}

List::~List()
{
    clear();
}

bool List::empty()
{
    return count == 0;
}

void List::clear()
{
    ListPointer q;
    while (head != NULL)
    {
        q = head;
        head = head->nextNode;
        delete q;
    }
    count = 0;
}

void List::setPosition(int p, ListPointer &current)
{
    current = head;
    for (int i = 2; i <= p; i++)
    {
        current = current->nextNode;
    }
}

void List::insert(int p, ListEntry x)
{
    if (p < 1 || p > count + 1)
    {
        cout << "Posição inválida! Saindo... " << endl;
        abort();
    }

    ListPointer newNode = new ListNode;
    if (newNode == NULL)
    {
        cout << "Espaco em memoria insuficiente para novo elemento! Saindo..." << endl;
        abort();
    }
    newNode->entry = x;

    if (p == 1)
    {
        newNode->nextNode = head;
        head = newNode;
    }
    else
    {
        ListPointer current;
        setPosition(p - 1, current);
        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }
    count++;
}

void List::remove(int p, ListEntry &x)
{
    if (p < 1 || p > count)
    {
        cout << "Posicao invalida! Saindo... " << endl;
        abort();
    }
    ListPointer node, current;
    if (p == 1)
    {
        node = head;
        head = head->nextNode;
    }
    else
    {
        setPosition(p - 1, current);
        node = current->nextNode;
        current->nextNode = node->nextNode;
    }
    x = node->entry;
    delete node;
    count--;
}

void List::replace(int p, ListEntry x){
    if(p < 1 || p > count){
        cout << "Posicao invalida! Saindo..." <<endl;
        abort();
    }
    if(p == 1) head->entry = x;
    else{
        ListPointer current;
        setPosition(p, current);
        current->entry = x;
    }
}

void List::retrieve(int p, ListEntry &x){
    if(p < 1 || p > count){
        cout << "Posicao invalida! Saindo... " <<endl;
        abort();
    }
    if(p == 1) x = head->entry;
    else{
        ListPointer current;
        setPosition(p, current);
        x = current->entry;
    }
}

int List::size(){
    return count;
}