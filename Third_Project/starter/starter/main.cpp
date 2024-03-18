#include <iostream>
#include "deque.h"
using namespace std;

void assertTrue(bool condition, const std::string& testName, const std::string& errorMessage) {
    if (!condition) {
        std::cout << testName << " FAILED: " << errorMessage << std::endl;
    } else {
        std::cout << testName << " passed." << std::endl;
    }
}

void testInsertRemoveEmptyDeque() {
    Deque<int> d;
    d.insertFirst(10);
    assertTrue(d.size() == 1, "testInsertRemoveEmptyDeque", "Size should be 1 after insertFirst.");

    d.removeFirst();
    assertTrue(d.isEmpty(), "testInsertRemoveEmptyDeque", "Deque should be empty after removeFirst.");
}

void testRepeatedInsertionsAndRemovals() {
    Deque<int> d;
    for (int i = 0; i < 10; ++i) {
        d.insertLast(i);
    }
    for (int i = 0; i < 5; ++i) {
        d.removeFirst();
    }
    for (int i = 0; i < 5; ++i) {
        d.insertFirst(i);
    }
    assertTrue(d.size() == 10, "testRepeatedInsertionsAndRemovals", "Size should be 10 after repeated insertions and removals.");
}

void testCopyEmptyDeque() {
    Deque<int> d;
    Deque<int> dCopy = d;
    assertTrue(dCopy.isEmpty(), "testCopyEmptyDeque", "Copied deque should be empty.");
}

void testSelfAssignment() {
    Deque<int> d;
    d.insertFirst(1);
    d = d; // Self-assignment
    assertTrue(d.size() == 1 && d.first() == 1, "testSelfAssignment", "Self-assignment should not alter the deque.");
}

void testInsertRemoveBothEnds() {
    Deque<int> d;
    d.insertFirst(1);
    d.insertLast(2);
    assertTrue(d.removeFirst() == 1, "testInsertRemoveBothEnds", "removeFirst should return 1.");
    assertTrue(d.removeLast() == 2, "testInsertRemoveBothEnds", "removeLast should return 2.");

    d.insertLast(3);
    d.insertFirst(4);
    assertTrue(d.removeLast() == 3 && d.removeFirst() == 4, "testInsertRemoveBothEnds", "Should correctly remove from both ends.");
}

void testLargeVolume() {
    Deque<int> d;
    for (int i = 0; i < 10000; ++i) {
        d.insertLast(i);
    }
    assertTrue(d.size() == 10000, "testLargeVolume", "Size should be 10000 after inserts.");
    for (int i = 0; i < 10000; ++i) {
        d.removeFirst();
    }
    assertTrue(d.isEmpty(), "testLargeVolume", "Deque should be empty after removals.");
}

void testComplexType() {
    struct ComplexType {
        int a;
        std::string b;
    // Default constructor
        ComplexType() : a(0), b("") {}
    // Constructor with parameters
        ComplexType(int x, std::string y) : a(x), b(y) {}
    };

    Deque<ComplexType> d;
    d.insertFirst(ComplexType(1, "test"));
    ComplexType ct = d.removeFirst();
    assertTrue(ct.a == 1 && ct.b == "test", "testComplexType", "Should handle complex types correctly.");
}

int main() {
    testInsertRemoveEmptyDeque();
    testRepeatedInsertionsAndRemovals();
    testCopyEmptyDeque();
    testSelfAssignment();
    testInsertRemoveBothEnds();
    testLargeVolume();
    testComplexType();
    std::cout << "All edge case tests completed.\n";
    return 0;
}
