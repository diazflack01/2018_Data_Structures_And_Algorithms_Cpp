#include <gtest/gtest.h>
#include <forward_list>

/*
Methods to test:
	begin
	end
	empty
	insert_after
	erase_after
	find
	push_front
	pop_front
*/


class TestSinglyLinkedList : public ::testing::Test
{

};

TEST_F(TestSinglyLinkedList, pushFronTest)
{
	std::forward_list<int> fw;
	for(auto i = 0u; i < 5; ++i)
		fw.push_front(i);

#if 0
	SinglyLinkedList<int> sl;
	for(auto i = 0u; i < 5; ++i)
		sl.push_front(i);

	for(auto it = fw.begin(); it != fw.end(); ++it)
	{
		sl.begin()
	}
#endif

	SUCCEED();
}