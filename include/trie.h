#ifndef TRIE_H
#define TRIE_H
#include <vector>
#include<iostream>

class Trie {
public:
    class Node {
    public:
        Node();
        Node(char , bool );
        std::vector<Node*> children;
        char data;
        bool is_finished;
    };
    Node* root;
    Trie(); //default constructor
    void insert(std::string);
    bool search(std::string) const ;
private:
};

#endif // TRIE_H