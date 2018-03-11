#pragma once

#include <string>
#include <vector>
#include <map>

struct Node
{
    Node(const unsigned f, Node* l ,Node* r) : freq(f), left(l), right(r) {}
    Node(const char c) : ch(c), freq(1), left(nullptr), right(nullptr) {}
    char ch;
    unsigned freq;
    Node* left;
    Node* right;
};

std::vector<Node*> createCharToFreqDictionary(const std::string& s);

Node* createHuffmanTree(std::vector<Node*>& charToFreqDict);

// std::map<char, std::string> createHuffmanHashTable(Node* huffmanTree);

void createHuffmanHashTable(Node* huffmanTree, std::map<char, std::string> m, std::string s);

void printCodes(Node* huffmanTree, std::string s = "");