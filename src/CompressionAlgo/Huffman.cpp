#include "Huffman.hpp"
#include <iostream>
#include <algorithm>

std::vector<Node*> createCharToFreqDictionary(const std::string& s)
{
    std::vector<Node*> ret;
    for(auto sit = s.begin(); sit != s.end(); ++sit)
    {
        auto match = std::find_if(ret.begin(), ret.end(),
            [&sit](const Node* n){ return (n->ch == *sit) ? true : false; });
        
        if(match != ret.end())
        {
            (*match)->freq++;
            continue;
        }
        ret.push_back(new Node(*sit));
    }
    return ret;
}

Node* createHuffmanTree(std::vector<Node*>& charToFreqDict)
{
    auto compareFunction = [](Node* l, Node* r){ return l->freq < r->freq; };
    while(charToFreqDict.size() > 1)
    {
        std::sort(charToFreqDict.begin(), charToFreqDict.end(), compareFunction);
        Node* ln = charToFreqDict.front();
        Node* rn = *(charToFreqDict.begin()+1);
        charToFreqDict.erase(charToFreqDict.begin(), charToFreqDict.begin()+2);
        charToFreqDict.push_back(new Node(ln->freq+rn->freq, ln, rn));
    }
    return charToFreqDict.front();
}

void createHuffmanHashTable(Node* huffmanTree, std::map<char, std::string>& mm, std::string s)
{
    if(huffmanTree->left != nullptr)
    {
        createHuffmanHashTable(huffmanTree->left, mm, s+"0");
    }
    if(huffmanTree->right != nullptr)
    {
        createHuffmanHashTable(huffmanTree->right, mm, s+"1");
    }
    if(huffmanTree->left == nullptr && huffmanTree->right == nullptr)
    {
        // std::cout << huffmanTree->ch << " : " << s << std::endl;
        mm.insert(std::make_pair(huffmanTree->ch, s));
    }
}

void printCodes(Node* huffmanTree, std::string s)
{
    if(huffmanTree->left != nullptr)
    {
        printCodes(huffmanTree->left, s+"0");
    }
    if(huffmanTree->right != nullptr)
    {
        printCodes(huffmanTree->right, s+"1");
    }
    if(huffmanTree->left == nullptr && huffmanTree->right == nullptr)
    {
        std::cout << huffmanTree->ch << " : " << s << std::endl;
    }
}