#include <gtest/gtest.h>

#include <Graph/Graph.hpp>

TEST(TestGraph, DfsWithRet)
{
	Graph<int> g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    const auto ACTUAL = g.DfsWithRet(2);
    const std::vector<int> EXPECTED = {2, 0, 1, 3};

    ASSERT_EQ(EXPECTED.size(), ACTUAL.size());
    for(auto i = 0u; i < EXPECTED.size(); ++i)
    {
    	EXPECT_EQ(EXPECTED[i], ACTUAL[i]);
    }
}

TEST(TestGraph, BfsWithRet)
{
	Graph<int> g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    const auto ACTUAL = g.BfsWithRet(2);
    const std::vector<int> EXPECTED = {2, 0, 3, 1};

    ASSERT_EQ(EXPECTED.size(), ACTUAL.size());
    for(auto i = 0u; i < EXPECTED.size(); ++i)
    {
    	EXPECT_EQ(EXPECTED[i], ACTUAL[i]);
    }
}