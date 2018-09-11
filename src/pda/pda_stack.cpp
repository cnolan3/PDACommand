/**
 * @file    pda_stack.cpp
 *
 * @brief   Stack object definitions.
 *
 * @author  Connor Nolan
**/

#include "pda_stack.h"

/**
 * PDAStack constructor, sets top of stack to null
**/
PDAStack::PDAStack() {
    m_top = nullptr;
}

/**
 * PDAStack destructor, deletes any nods left in the stack
**/
PDAStack::~PDAStack() {
    node* tmp;

    while(m_top != nullptr) {
        tmp = m_top;
        m_top = m_top->next;
        delete tmp;
    }
}

/**
 * clear the stack
**/
void PDAStack::clear() {
    node* tmp;

    while(m_top != nullptr) {
        tmp = m_top;
        m_top = m_top->next;
        delete tmp;
    }   
}

/**
 * Push a character onto the top of the stack.
 *
 * @param    c new character to push
**/
void PDAStack::push(char c) {
    node* tmp = new node;

    tmp->c = c;
    tmp->next = m_top;

    m_top = tmp;
}

/**
 * Pop the character from the top of the stack, returns 0 if the stack
 * is empty.
 *
 * @return   char at top of stack
**/
char PDAStack::pop() {
    if(m_top == nullptr)
        return 0;

    node* tmp = m_top;

    char ret = m_top->c;

    m_top = m_top->next;

    delete tmp;

    return ret;
}

/**
 * Tell if the stack is empty or not.
 *
 * @return   true if stack is empty, false if not
**/
bool PDAStack::is_empty() {
    return (m_top == nullptr);
}
