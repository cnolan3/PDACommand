/**
 * @file    grammar.cpp
 *
 * @author  Connor Nolan
**/

#include "grammar.h"

/**
 * grammar constructor
**/
grammar::grammar() {

}

/**
 * add a rule to the grammar
 *
 * @param    rhs right hand side of rule
 * @param    lhs left hand side of rule
**/
void grammar::addRule(int lhs, vector<unsigned int> rhs, void* (*action)(void** varBuf)) {
    rule r;
    r.rhs = rhs;
    r.lhs = lhs;
    r.action = action;

    m_rules.push_back(r);
}

/**
 * get a rule from the grammar by index
 *
 * @param    index index of rule
 *
 * @return   rule from grammar
**/
rule grammar::getRule(int index) {
    return m_rules[index];
}

/**
 * get all rules from grammar
 *
 * @return   vector of rules
**/
vector<rule> grammar::getRules() {
    return m_rules;
}
