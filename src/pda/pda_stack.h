/**
 * @file    pda_stack.h
 *
 * @brief   Char stack structure used by the pushdown automata. I chose to 
 *          write a stack from scratch rather than using the STL version
 *          to keep the structure as simple and light-weight as possible.
 *
 * @author  Connor Nolan
**/

#ifndef __PDA_STACK_H__
#define __PDA_STACK_H__

class PDAStack
{
public:
    PDAStack();
    ~PDAStack();

    void push(char c);
    char pop();
    bool is_empty();

private:

    struct node
    {
        char c;
        node* next;
    };

    node* m_top;

};

#endif
