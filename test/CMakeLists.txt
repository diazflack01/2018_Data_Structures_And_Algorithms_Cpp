
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(GTEST_INCLUDE_DIR "${EXTERNALS}/googletest/googltest/include")
set(GMOCK_INCLUDE_DIR "${EXTERNALS}/googletest/googlmock/include")

add_executable(algorithm_test
	main.cpp
	"${SRC_DIR}/SearchAlgo/LinearSearch.cpp"
	"${SRC_DIR}/SearchAlgo/BinarySearch.cpp"
	"${SRC_DIR}/SearchAlgo/HashTable.cpp"
	"${SRC_DIR}/SortAlgo/BubbleSort.cpp"
	"${SRC_DIR}/SortAlgo/InsertionSort.cpp"
	"${SRC_DIR}/SortAlgo/SelectionSort.cpp"
	"${SRC_DIR}/SortAlgo/MergeSort.cpp"
	"${SRC_DIR}/SortAlgo/QuickSort.cpp"
	"${SRC_DIR}/SortAlgo/ShellSort.cpp"
	"${SRC_DIR}/CompressionAlgo/Huffman.cpp"
	)

target_link_libraries(algorithm_test gtest gmock pthread)

target_include_directories(algorithm_test
	PRIVATE
	${GTEST_INCLUDE_DIR}
	${GMOCK_INCLUDE_DIR}
	${SRC_DIR}
	${PROJECT_SOURCE_DIR}/test
	${SRC_DIR}/Utils
	)

add_test(Algorithm_Test algorithm_test)