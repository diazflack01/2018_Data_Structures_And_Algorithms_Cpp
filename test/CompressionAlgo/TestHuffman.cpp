#include <gtest/gtest.h>
#include <map>
#include <CompressionAlgo/Huffman.hpp>

std::map<char, unsigned> createResultsTableMap(const std::string& s)
{
    std::map<char, unsigned> m;
    for(auto it = s.begin(); it != s.end(); ++it)
    {
        auto match = m.find(*it);
        if(match == m.end())
        {
            m.insert(std::make_pair(*it, 1));
            continue;
        }
        m[*it]++;
    }
    return m;
}

TEST(Huffman, createDictionary)
{
    const std::string INPUT = "aaabbbcccewqodapqowdsa";
    const auto RESULT_TABLE = createResultsTableMap(INPUT);
    auto dict = createCharToFreqDictionary(INPUT);

    for(auto it = dict.begin(); it != dict.end(); it++)
    {
        const auto& node = **it;
        const auto pairToFind = std::make_pair(node.ch, node.freq);
        auto match = RESULT_TABLE.find(pairToFind.first);
        ASSERT_TRUE((match != RESULT_TABLE.end()));
        EXPECT_EQ(match->second, pairToFind.second);
    }
}

TEST(Huffman, createHuffmanTree)
{
    const std::string INPUT = "aaabbbcccewqodapqowdsa";
    auto dict = createCharToFreqDictionary(INPUT);
    auto* huffmanTree = createHuffmanTree(dict);
    printCodes(huffmanTree);
    SUCCEED();
}

TEST(Huffman, createHuffmanHashTable)
{
    std::map<char, std::string> huffManHasTable;
    const std::string INPUT = "aaabbbcccewqodapqowdsa";
    auto dict = createCharToFreqDictionary(INPUT);
    auto* huffmanTree = createHuffmanTree(dict);
    createHuffmanHashTable(huffmanTree, huffManHasTable, "");
    std::cout << "Huffman HashTable" << std::endl;
    for(auto it = huffManHasTable.begin(); it != huffManHasTable.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
    SUCCEED();
}
