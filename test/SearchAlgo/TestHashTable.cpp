#include <gtest/gtest.h>
#include <string>

#include <SearchAlgo/HashTable.hpp>

TEST(SeparateChainingHashTable, Insert)
{
    using namespace SeparateChaining;
    HashMap<int, std::string, 5> map;
    map.insert(0, "pogi");
    map.insert(10, "pogi2");
    EXPECT_STREQ("pogi", (map.hashTable[0]->value).c_str()); 
    EXPECT_STREQ("pogi2", (map.hashTable[0]->next->value).c_str());
}

TEST(SeparateChainingHashTable, GetHashNode)
{
    using namespace SeparateChaining;
    HashMap<int, std::string, 5> map;
    map.insert(0, "pogi");
    map.insert(10, "pogi2");
    auto* nodeAtKey0 = map.getHashNode(0);
    auto* nodeAtKey10 = map.getHashNode(10);
    auto* nodeAtKey12 = map.getHashNode(12);
    EXPECT_TRUE((nullptr != nodeAtKey0));
    EXPECT_TRUE((nullptr != nodeAtKey10));
    EXPECT_TRUE((nullptr == nodeAtKey12));
    EXPECT_EQ(0, nodeAtKey0->key);
    EXPECT_STREQ("pogi", nodeAtKey0->value.c_str());
    EXPECT_EQ(10, nodeAtKey10->key);
    EXPECT_STREQ("pogi2", nodeAtKey10->value.c_str());
}

TEST(SeparateChainingHashTable, DeleteHashNode_FirstElemKey)
{
    using namespace SeparateChaining;
    HashMap<int, std::string, 5> map;
    map.insert(0, "pogi");
    map.insert(10, "pogi10");
    map.insert(15, "pogi15");

    auto deletedNode = map.deleteHashNode(0);
    EXPECT_EQ(0, deletedNode.key);
    EXPECT_STREQ("pogi", deletedNode.value.c_str());

    auto* nodeAtKey10 = map.getHashNode(10);
    auto* nodeAtKey15 = map.getHashNode(15);

    ASSERT_TRUE((nullptr != nodeAtKey10));
    ASSERT_TRUE((nullptr != nodeAtKey15));
    EXPECT_EQ(10, nodeAtKey10->key);
    EXPECT_STREQ("pogi10", nodeAtKey10->value.c_str());
    EXPECT_EQ(15, nodeAtKey15->key);
    EXPECT_STREQ("pogi15", nodeAtKey15->value.c_str());
}

TEST(SeparateChainingHashTable, DeleteHashNode_MidElemKey)
{
    using namespace SeparateChaining;
    HashMap<int, std::string, 5> map;
    map.insert(0, "pogi");
    map.insert(10, "pogi10");
    map.insert(15, "pogi15");

    auto deletedNode = map.deleteHashNode(10);
    EXPECT_EQ(10, deletedNode.key);
    EXPECT_STREQ("pogi10", deletedNode.value.c_str());

    auto* remainingNode1 = map.getHashNode(0);
    auto* remainingNode2 = map.getHashNode(15);

    ASSERT_TRUE((nullptr != remainingNode1));
    ASSERT_TRUE((nullptr != remainingNode2));
    EXPECT_EQ(0, remainingNode1->key);
    EXPECT_STREQ("pogi", remainingNode1->value.c_str());
    EXPECT_EQ(15, remainingNode2->key);
    EXPECT_STREQ("pogi15", remainingNode2->value.c_str());
}

TEST(SeparateChainingHashTable, DeleteHashNode_LastElemKey)
{
    using namespace SeparateChaining;
    HashMap<int, std::string, 5> map;
    map.insert(0, "pogi");
    map.insert(10, "pogi10");
    map.insert(15, "pogi15");

    auto deletedNode = map.deleteHashNode(15);
    EXPECT_EQ(15, deletedNode.key);
    EXPECT_STREQ("pogi15", deletedNode.value.c_str());

    auto* remainingNode1 = map.getHashNode(0);
    auto* remainingNode2 = map.getHashNode(10);

    ASSERT_TRUE((nullptr != remainingNode1));
    ASSERT_TRUE((nullptr != remainingNode2));
    EXPECT_EQ(0, remainingNode1->key);
    EXPECT_STREQ("pogi", remainingNode1->value.c_str());
    EXPECT_EQ(10, remainingNode2->key);
    EXPECT_STREQ("pogi10", remainingNode2->value.c_str());
}

TEST(SeparateChainingHashTable, DeleteHashNode_InvalidElemKey)
{
    using namespace SeparateChaining;
    HashMap<int, std::string, 5> map;
    map.insert(0, "pogi");
    map.insert(10, "pogi10");
    map.insert(15, "pogi15");

    auto deletedNode = map.deleteHashNode(69);
    EXPECT_EQ(0, deletedNode.key);
    EXPECT_STREQ("", deletedNode.value.c_str());
}

TEST(LinearProbingHashTable, Insert_2ElemWithSimilarHashIndex)
{
    using namespace LinearProbing;
    HashMap<std::string, std::string, 2> map;
    map.insert("ab", "ab_pogi");
    EXPECT_STREQ("ab", (map.hashTable[1]->key).c_str());
    EXPECT_STREQ("ab_pogi", (map.hashTable[1]->value).c_str()); 
    map.insert("ba", "ba_pogi");
    EXPECT_STREQ("ba", (map.hashTable[0]->key).c_str());
    EXPECT_STREQ("ba_pogi", (map.hashTable[0]->value).c_str()); 
    map.insert("a", "a_pogi");
    map.insert("ab", "pek!!!!");
    EXPECT_STREQ("ab", (map.hashTable[1]->key).c_str());
    EXPECT_STREQ("pek!!!!", (map.hashTable[1]->value).c_str()); 
}

TEST(LinearProbingHashTable, GetNode_InvalidElemKey)
{
    using namespace LinearProbing;
    HashMap<std::string, std::string, 2> map;
    map.insert("ab", "ab_pogi");
    map.insert("ba", "ba_pogi");
    auto* searchedNode = map.getNode("gg");
    ASSERT_TRUE((nullptr == searchedNode));
    searchedNode = map.getNode("ab");
    ASSERT_TRUE((nullptr != searchedNode));
}

TEST(LinearProbingHashTable, GetNode_ValidElemKey)
{
    using namespace LinearProbing;
    HashMap<std::string, std::string, 2> map;
    map.insert("ab", "ab_pogi");
    map.insert("ba", "ba_pogi");
    auto* searchedNode = map.getNode("ab");
    EXPECT_STREQ("ab", searchedNode->key.c_str());
    EXPECT_STREQ("ab_pogi", searchedNode->value.c_str());
    searchedNode = map.getNode("ba");
    EXPECT_STREQ("ba", searchedNode->key.c_str());
    EXPECT_STREQ("ba_pogi", searchedNode->value.c_str());
}

TEST(QuadraticProbingHashTable, Insert_2ElemWithSimilarHashIndex)
{
    using namespace QuadraticProbing;
    HashMap<std::string, std::string, 5> map;
    map.insert("abc", "abc_pogi");
    EXPECT_STREQ("abc", (map.hashTable[4]->key).c_str());
    EXPECT_STREQ("abc_pogi", (map.hashTable[4]->value).c_str()); 
    map.insert("bac", "bac_pogi");
    EXPECT_STREQ("bac", (map.hashTable[0]->key).c_str());
    EXPECT_STREQ("bac_pogi", (map.hashTable[0]->value).c_str());
    map.insert("acb", "acb_pogi");
    EXPECT_STREQ("acb", (map.hashTable[3]->key).c_str());
    EXPECT_STREQ("acb_pogi", (map.hashTable[3]->value).c_str());

    map.insert("abc", "pekkk");
    EXPECT_STREQ("abc", (map.hashTable[4]->key).c_str());
    EXPECT_STREQ("pekkk", (map.hashTable[4]->value).c_str());
}

TEST(QuadraticProbingHashTable, GetNode_InvalidElemKey)
{
    using namespace QuadraticProbing;
    HashMap<std::string, std::string, 5> map;
    map.insert("abc", "abc_pogi");
    map.insert("bac", "bac_pogi");
    auto* searchedNode = map.getNode("gg");
    ASSERT_TRUE((nullptr == searchedNode));
    searchedNode = map.getNode("abc");
    ASSERT_TRUE((nullptr != searchedNode));
}

TEST(QuadraticProbingHashTable, GetNode_ValidElemKey)
{
    using namespace QuadraticProbing;
    HashMap<std::string, std::string, 5> map;
    map.insert("abc", "abc_pogi");
    map.insert("bac", "bac_pogi");
    auto* searchedNode = map.getNode("abc");
    EXPECT_STREQ("abc", searchedNode->key.c_str());
    EXPECT_STREQ("abc_pogi", searchedNode->value.c_str());
    searchedNode = map.getNode("bac");
    EXPECT_STREQ("bac", searchedNode->key.c_str());
    EXPECT_STREQ("bac_pogi", searchedNode->value.c_str());
}