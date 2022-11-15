#include "trie.h"
#include <iostream>
#include <vector>

Trie::Trie()
    : root {}
{
    return;
};


Trie::Node::Node()
    : data { '\0' }
    , is_finished { false }
{
    // std::cout << "Node default Constructor" << std::endl;
    return;
}

Trie::Node::Node(char _data, bool _is_finished)
    : data { _data }
    , is_finished { _is_finished }
{
    // std::cout << "Node Constructor" << std::endl;
    return;
}

void Trie::insert(std::string str)
{
    bool found { false };
    Trie::Node* x { root };
    for (size_t i; i < str.size(); i++) {
        for (size_t j; j < x->children.size(); j++) {
            if (str[i] == x->children[j]->data) {
                x = x->children[j];
                found = true;
                continue;
            }
        }
        if (!found) {
            Trie::Node temp { str[i], false };

            x->children.push_back(&temp);
            x = x->children[x->children.size() - 1];
        }
        found = false;
    }
    x->is_finished = true;
}

bool Trie::search(std::string query) const
{
    bool found { false };
    Trie::Node* x { root };
    for (size_t i; i < query.size(); i++) {
        for (size_t j; j < x->children.size(); j++) {
            if (query[i] == x->children[j]->data) {
                x = x->children[j];
                found = true;
                continue;
            }
        }
        if (!found) {
            return found;
        }
        found = false;
    }
    if (x->is_finished)
        return true;
    else
        return false;
}