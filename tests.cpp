// Name: Zaheer Safi
// Date: 11/06/2023
// CS_251 Project_4 : Priority qeueue implmentation using Binary search tree Test cases.

#define CATCH_CONFIG_MAIN

#include "prqueue.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("prqueue constructor") 
{
    SECTION("Empty priority queue")
    {
        prqueue<int> pq;
        REQUIRE(pq.size() == 0);
        REQUIRE(pq.toString() == "");
    }

    SECTION("Priority queue with one element") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        REQUIRE(pq.size() == 1);
    }
}

TEST_CASE("prqueue size") 
{
    SECTION("Size of an empty priority queue") 
    {
        prqueue<int> pq;
        REQUIRE(pq.size() == 0);
    }

    SECTION("Size after enqueue") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);
        pq.enqueue(20, 5);
        pq.enqueue(10, 2);
        pq.enqueue(100, 3);
        pq.enqueue(1000, 4);
        REQUIRE(pq.size() == 6);
    }

}

TEST_CASE("prqueue enqueue") 
{
    SECTION("Enqueue with different priorities") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);
        pq.enqueue(99, 3);
        REQUIRE(pq.size() == 3);
        REQUIRE(pq.toString() == "1 value: 17\n2 value: 42\n3 value: 99\n");
    }


    SECTION("Enqueue with duplicate priorities") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 2);
        pq.enqueue(99, 3);
        pq.enqueue(100, 5);
        pq.enqueue(225, 3);
        pq.enqueue(200, 1);
        pq.enqueue(120, 2);
        
        REQUIRE(pq.size() == 7);
        REQUIRE(pq.toString() == "1 value: 200\n2 value: 42\n2 value: 17\n2 value: 120\n3 value: 99\n3 value: 225\n5 value: 100\n");
    }
}

TEST_CASE("prqueue enqueue - String Values") 
{
    prqueue<std::string> pq;

    SECTION("Enqueue a single element") {
        pq.enqueue("apple", 2);
        REQUIRE(pq.size() == 1);
    }

    SECTION("Enqueue elements with different priorities") {
        pq.enqueue("apple", 2);
        pq.enqueue("banana", 1);
        pq.enqueue("cherry", 5);
        REQUIRE(pq.size() == 3);
    }

    SECTION("Enqueue elements with duplicate priorities") {
        pq.enqueue("apple", 2);
        pq.enqueue("banana", 2);
        pq.enqueue("cherry", 2);
        REQUIRE(pq.size() == 3);
    }
}

TEST_CASE("prqueue enqueue - Character Values") 
{
    prqueue<char> pq;

    SECTION("Enqueue a single element") {
        pq.enqueue('A', 2);
        REQUIRE(pq.size() == 1);
    }

    SECTION("Enqueue elements with different priorities") {
        pq.enqueue('A', 2);
        pq.enqueue('B', 1);
        pq.enqueue('C', 5);
        REQUIRE(pq.size() == 3);
    }

    SECTION("Enqueue elements with duplicate priorities") {
        pq.enqueue('A', 2);
        pq.enqueue('B', 2);
        pq.enqueue('C', 2);
        REQUIRE(pq.size() == 3);
    }
}

TEST_CASE("prqueue toString with integers") 
{
    SECTION("Empty priority queue") {
        prqueue<int> pq;
        REQUIRE(pq.toString() == "");
    }

    SECTION("Priority queue with elements") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);
        pq.enqueue(99, 3);
        REQUIRE(pq.toString() == "1 value: 17\n2 value: 42\n3 value: 99\n");
    }    
}

TEST_CASE("prqueue toString more - Integer Values") 
{
    prqueue<int> pq;

    SECTION("Empty queue should produce an empty string") {
        REQUIRE(pq.toString() == "");
    }

    SECTION("Enqueue elements and check the string representation") {
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);
        pq.enqueue(20, 5);
        REQUIRE(pq.toString() == "1 value: 17\n2 value: 42\n5 value: 20\n");
    }

    SECTION("Enqueue elements with duplicate priorities") {
        pq.enqueue(42, 2);
        pq.enqueue(17, 2);
        pq.enqueue(20, 2);
        REQUIRE(pq.toString() == "2 value: 42\n2 value: 17\n2 value: 20\n");
    }
}

TEST_CASE("prqueue toString - String Values") 
{
    prqueue<std::string> pq;

    SECTION("Empty queue should produce an empty string") {
        REQUIRE(pq.toString() == "");
    }

    SECTION("Enqueue elements and check the string representation") {
        pq.enqueue("apple", 2);
        pq.enqueue("banana", 1);
        pq.enqueue("cherry", 5);
        REQUIRE(pq.toString() == "1 value: banana\n2 value: apple\n5 value: cherry\n");
    }

    SECTION("Enqueue elements with duplicate priorities") {
        pq.clear();
        pq.enqueue("apple", 2);
        pq.enqueue("banana", 2);
        pq.enqueue("cherry", 2);
        REQUIRE(pq.toString() == "2 value: apple\n2 value: banana\n2 value: cherry\n");
    }
}

TEST_CASE("prqueue toString - Character Values") 
{
    prqueue<char> pq;

    SECTION("Empty queue should produce an empty string") {
        REQUIRE(pq.toString() == "");
    }

    SECTION("Enqueue elements and check the string representation") {
        pq.enqueue('A', 2);
        pq.enqueue('B', 1);
        pq.enqueue('C', 5);
        REQUIRE(pq.toString() == "1 value: B\n2 value: A\n5 value: C\n");
    }

    SECTION("Enqueue elements with duplicate priorities") {
        pq.clear();
        pq.enqueue('A', 2);
        pq.enqueue('B', 2);
        pq.enqueue('C', 2);
        REQUIRE(pq.toString() == "2 value: A\n2 value: B\n2 value: C\n");
    }
}

TEST_CASE("prqueue toString - Large Queue with Integer Values") 
{
    prqueue<int> pq;

    SECTION("Enqueue 20 elements with varying priorities") {
        for (int i = 1; i <= 20; i++) {
            pq.enqueue(i * 10, i);
        }

        // The string representation should have elements in ascending order of priorities.
        const std::string expected = 
            "1 value: 10\n2 value: 20\n3 value: 30\n4 value: 40\n5 value: 50\n"
            "6 value: 60\n7 value: 70\n8 value: 80\n9 value: 90\n10 value: 100\n"
            "11 value: 110\n12 value: 120\n13 value: 130\n14 value: 140\n15 value: 150\n"
            "16 value: 160\n17 value: 170\n18 value: 180\n19 value: 190\n20 value: 200\n";

        REQUIRE(pq.toString() == expected);
    }
}

TEST_CASE("prqueue clear") 
{
    SECTION("Clear an empty priority queue") 
    {
        prqueue<int> pq;
        pq.clear();
        REQUIRE(pq.size() == 0);
        REQUIRE(pq.toString() == "");
    }

    SECTION("Clear a priority queue with elements") {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);
        pq.enqueue(99, 3);
        pq.clear();
        REQUIRE(pq.size() == 0);
        REQUIRE(pq.toString() == "");
    }

    SECTION("Clear a priority queue with duplicate priorities") {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 2);
        pq.enqueue(99, 3);
        pq.enqueue(100, 5);
        pq.enqueue(225, 3);
        pq.enqueue(200, 1);
        pq.enqueue(120, 2);
        pq.clear();
        REQUIRE(pq.size() == 0);
        REQUIRE(pq.toString() == "");
    }

}

TEST_CASE("prqueue clear - Different Data Types") 
{
    SECTION("Clear an empty queue of integer values") {
        prqueue<int> pq;
        pq.clear();
        REQUIRE(pq.size() == 0);
    }

    SECTION("Clear a non-empty queue of string values") {
        prqueue<std::string> pq;
        pq.enqueue("apple", 2);
        pq.enqueue("banana", 1);
        pq.enqueue("cherry", 5);

        pq.clear();

        REQUIRE(pq.size() == 0);
        REQUIRE(pq.toString() == ""); // The string representation should be empty.
    }

    SECTION("Clear a queue of character values") {
        prqueue<char> pq;
        pq.enqueue('A', 2);
        pq.enqueue('B', 1);
        pq.enqueue('C', 5);

        pq.clear();

        REQUIRE(pq.size() == 0);
    }
}

TEST_CASE("Deqeue priority queue")
{
    SECTION("No duplicates")
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);
        pq.enqueue(99, 3);
        int data = pq.dequeue();
        REQUIRE(pq.size() == 2);
        REQUIRE(pq.toString() == "2 value: 42\n3 value: 99\n");
        REQUIRE(data == 17);
    }
    
    SECTION("deque with duplicate") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 6);
        pq.enqueue(17, 2);
        pq.enqueue(99, 3);
        pq.enqueue(100, 2);
        int data = pq.dequeue();
        REQUIRE(pq.toString() == "2 value: 100\n3 value: 99\n6 value: 42\n");
        REQUIRE(data == 17);
        data = pq.dequeue();
        REQUIRE(pq.toString() == "3 value: 99\n6 value: 42\n");
        REQUIRE(data == 100);
        data = pq.dequeue();
        REQUIRE(pq.toString() == "6 value: 42\n");
        REQUIRE(data == 99);
        data = pq.dequeue();
        REQUIRE(pq.toString() == "");
        REQUIRE(data == 42);
    
    }
    
    SECTION("deque with duplicate") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 5);
        pq.enqueue(100, 5);
        pq.enqueue(200, 8);
        pq.enqueue(300, 10);
        
        int data = pq.dequeue();
        REQUIRE(pq.size() == 3);
        REQUIRE(pq.toString() == "5 value: 100\n8 value: 200\n10 value: 300\n");
        REQUIRE(data == 42);
        data = pq.dequeue();
        REQUIRE(pq.size() == 2);
        REQUIRE(pq.toString() == "8 value: 200\n10 value: 300\n");
        REQUIRE(data == 100);
        data = pq.dequeue();
        REQUIRE(pq.toString() == "10 value: 300\n");
        data = pq.dequeue();
        REQUIRE(pq.size() == 0);
        REQUIRE(pq.toString() == "");
        
    }


    SECTION("No duplicates - String") 
    {
        prqueue<std::string> pq;
        pq.enqueue("Alice", 2);
        pq.enqueue("Bob", 1);
        pq.enqueue("Charlie", 3);
        std::string data = pq.dequeue();
        REQUIRE(pq.size() == 2);
        REQUIRE(pq.toString() == "2 value: Alice\n3 value: Charlie\n");
        REQUIRE(data == "Bob");
    }

    SECTION("Dequeue with duplicate - String") 
    {
        prqueue<std::string> pq;
        pq.enqueue("Alice", 6);
        pq.enqueue("Bob", 2);
        pq.enqueue("Charlie", 3);
        pq.enqueue("David", 2);
        std::string data = pq.dequeue();
        REQUIRE(pq.toString() == "2 value: David\n3 value: Charlie\n6 value: Alice\n");
        REQUIRE(data == "Bob");
        data = pq.dequeue();
        REQUIRE(pq.toString() == "3 value: Charlie\n6 value: Alice\n");
        REQUIRE(data == "David");
        data = pq.dequeue();
        REQUIRE(pq.toString() == "6 value: Alice\n");
        REQUIRE(data == "Charlie");
        data = pq.dequeue();
        REQUIRE(pq.toString() == "");
        REQUIRE(data == "Alice");
    }
}

TEST_CASE("Dequeue priority queue more test cases") 
{
    SECTION("No duplicates - Double")
    {
        prqueue<double> pq;
        pq.enqueue(42.5, 2);
        pq.enqueue(17.8, 1);
        pq.enqueue(99.3, 3);
        double data = pq.dequeue();
        REQUIRE(pq.size() == 2);
        REQUIRE(pq.toString() == "2 value: 42.5\n3 value: 99.3\n");
        REQUIRE(data == 17.8);
    }

    SECTION("Dequeue with duplicate - Char") 
    {
        prqueue<char> pq;
        pq.enqueue('A', 6);
        pq.enqueue('B', 2);
        pq.enqueue('C', 3);
        pq.enqueue('D', 2);
        char data = pq.dequeue();
        REQUIRE(pq.toString() == "2 value: D\n3 value: C\n6 value: A\n");
        REQUIRE(data == 'B');
        data = pq.dequeue();
        REQUIRE(pq.toString() == "3 value: C\n6 value: A\n");
        REQUIRE(data == 'D');
        data = pq.dequeue();
        REQUIRE(pq.toString() == "6 value: A\n");
        REQUIRE(data == 'C');
        data = pq.dequeue();
        REQUIRE(pq.toString() == "");
        REQUIRE(data == 'A');
    }
}

TEST_CASE("prqueue operator=") 
{
    SECTION("Assignment to itself") 
    {
        prqueue<int> pq;
        prqueue<int> pq1;
        pq.enqueue(42, 2);
        pq1 = pq;
        REQUIRE(pq.size() == 1);
        REQUIRE(pq.toString() == pq1.toString());
    }

    SECTION("Empty assignment") 
    {
        prqueue<int> pq1;
        prqueue<int> pq2;
        pq2 = pq1;
        REQUIRE(pq2.size() == 0);
        REQUIRE(pq2.toString() == "");
    }

    SECTION("Assignment from a non-empty prqueue") 
    {
        prqueue<int> pq1;
        pq1.enqueue(42, 2);
        pq1.enqueue(17, 1);

        prqueue<int> pq2;
        pq2 = pq1;

        REQUIRE(pq2.size() == pq1.size());
        REQUIRE(pq2.toString() == pq1.toString());
    }

    SECTION("Assignment from an empty prqueue to a non-empty prqueue") 
    {
        prqueue<int> pq1;

        prqueue<int> pq2;
        pq2.enqueue(99, 3);

        pq2 = pq1;

        REQUIRE(pq2.size() == pq1.size());
        REQUIRE(pq2.toString() == pq1.toString());
    }

    SECTION("copy priorities")
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 4);
        pq.enqueue(99, 6);
        pq.enqueue(100, 2);
        pq.enqueue(225, 3);
        pq.enqueue(200, 2);
        pq.enqueue(120, 3);
        prqueue<int> pq1;
        pq1 = pq;
        REQUIRE(pq1.toString() == pq.toString());
        REQUIRE(pq1.size() == pq.size());

    }
}

TEST_CASE("prqueue operator==") 
{
    SECTION("Equality of two empty prqueues") 
    {
        prqueue<int> pq1;
        prqueue<int> pq2;
        REQUIRE(pq1 == pq2);
    }

    SECTION("Equality of two identical non-empty prqueues") 
    {
        prqueue<int> pq1;
        pq1.enqueue(42, 2);
        pq1.enqueue(17, 1);

        prqueue<int> pq2;
        pq2.enqueue(42, 2);
        pq2.enqueue(17, 1);

        REQUIRE(pq1 == pq2);
    }

    SECTION("Inequality of two non-empty prqueues with different priorities") 
    {
        prqueue<int> pq1;
        pq1.enqueue(42, 2);
        pq1.enqueue(17, 1);

        prqueue<int> pq2;
        pq2.enqueue(42, 3);  // Different priorities
        pq2.enqueue(17, 1);

        REQUIRE_FALSE(pq1 == pq2);
    }

    SECTION("Inequality of two non-empty prqueues with different values") 
    {
        prqueue<int> pq1;
        pq1.enqueue(42, 2);
        pq1.enqueue(17, 1);

        prqueue<int> pq2;
        pq2.enqueue(99, 2);  // Different values
        pq2.enqueue(17, 1);

        REQUIRE_FALSE(pq1 == pq2);
    }

    SECTION("Inequality of two non-empty prqueues with different duplicates") 
    {
        prqueue<int> pq1;
        pq1.enqueue(42, 2);
        pq1.enqueue(17, 1);

        prqueue<int> pq2;
        pq2.enqueue(42, 2);
        pq2.enqueue(17, 1);
        pq2.enqueue(42, 2);  // Different duplicates

        REQUIRE_FALSE(pq1 == pq2);
    }

    SECTION("Inequality of empty and non-empty prqueues") 
    {
        prqueue<int> pq1;
        prqueue<int> pq2;
        pq2.enqueue(42, 2);

        REQUIRE_FALSE(pq1 == pq2);
    }
    
    SECTION("duplicate prioriteis")
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 4);
        pq.enqueue(99, 6);
        pq.enqueue(100, 2);
        pq.enqueue(225, 3);
        pq.enqueue(200, 2);
        pq.enqueue(120, 3);
        prqueue<int> pq1;
        pq1.enqueue(42, 2);
        pq1.enqueue(17, 4);
        pq1.enqueue(99, 6);
        pq1.enqueue(100, 2);
        pq1.enqueue(225, 3);
        pq1.enqueue(200, 2);
        pq1.enqueue(120, 3);
        
        REQUIRE(pq1 == pq);
    }
    SECTION("duplicate prioriteis")
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 4);
        pq.enqueue(99, 6);
        pq.enqueue(100, 3);
        pq.enqueue(225, 3);
        pq.enqueue(200, 2);
        pq.enqueue(120, 3);
        prqueue<int> pq1;
        pq1.enqueue(42, 2);
        pq1.enqueue(17, 4);
        pq1.enqueue(99, 6);
        pq1.enqueue(100, 2);
        pq1.enqueue(225, 3);
        pq1.enqueue(200, 2);
        pq1.enqueue(120, 3);
        
        REQUIRE_FALSE(pq1 == pq);
    }
}

TEST_CASE("prqueue peek") 
{
    SECTION("Peek from an empty prqueue") 
    {
        prqueue<int> pq;
        int result = pq.peek();
        REQUIRE(result == int());
    }

    SECTION("Peek from a non-empty prqueue with no duplicates") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);

        int result = pq.peek();
        REQUIRE(result == 17);
    }

    SECTION("Peek from a non-empty prqueue with duplicates") {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);
        pq.enqueue(99, 2);

        int result = pq.peek();
        REQUIRE(result == 17);
    }

    SECTION("Peek from a non-empty prqueue with multiple duplicates") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);
        pq.enqueue(99, 2);
        pq.enqueue(100, 1);

        int result = pq.peek();
        REQUIRE(result == 17);  
    }
}

TEST_CASE("more Peek priority queue") 
{
    SECTION("No duplicates - Integers")
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);
        pq.enqueue(99, 3);
        REQUIRE(pq.peek() == 17);

        pq.dequeue();
        REQUIRE(pq.peek() == 42);

        pq.dequeue();
        REQUIRE(pq.peek() == 99);
    }

    SECTION("Peek with duplicate - Doubles") 
    {
        prqueue<double> pq;
        pq.enqueue(42.5, 6);
        pq.enqueue(17.8, 2);
        pq.enqueue(99.3, 3);
        pq.enqueue(100.1, 2);
        REQUIRE(pq.peek() == 17.8);

        pq.dequeue();
        REQUIRE(pq.peek() == 100.1);

        pq.dequeue();
        REQUIRE(pq.peek() == 99.3);

        pq.dequeue();
        REQUIRE(pq.peek() == 42.5);
    }

    SECTION("No elements - Strings") 
    {
        prqueue<std::string> pq;
        REQUIRE(pq.peek() == "");
    }
}

TEST_CASE("prqueue begin and next") 
{
    prqueue<int> pq;

    SECTION("Inorder traversal of an empty priority queue") 
    {
        int value;
        int priority;

        pq.begin();
        REQUIRE_FALSE(pq.next(value, priority));
    }

    SECTION("Inorder traversal after enqueuing elements") 
    {
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);
        pq.enqueue(20, 5);
        pq.enqueue(100, 3);
        pq.enqueue(1000, 4);

        int value;
        int priority;
        int expectedPriorities[] = {1, 2, 3, 4, 5}; 

        pq.begin();
        for (int i = 0; i < 4; ++i) 
        {
            REQUIRE(pq.next(value, priority));
            REQUIRE(priority == expectedPriorities[i]);
        }
        REQUIRE_FALSE(pq.next(value, priority));
    }

    SECTION("Inorder traversal after enqueuing elements") 
    {
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);
        pq.enqueue(17, 2);
        pq.enqueue(20, 5);
        pq.enqueue(100, 3);
        pq.enqueue(1000, 4);

        int value;
        int priority;
    
        pq.begin();
        pq.next(value, priority);
        
        REQUIRE(value == 17);
        REQUIRE(priority == 1);

        pq.next(value, priority);

        REQUIRE(value == 42);
        REQUIRE(priority == 2);

        pq.next(value, priority);

        REQUIRE(value == 17);
        REQUIRE(priority == 2);
        
        REQUIRE(pq.next(value, priority) == true);
        
        REQUIRE(value == 100);
        REQUIRE(priority == 3);

        pq.next(value, priority);
        REQUIRE(value == 1000);
        REQUIRE(priority == 4);
        
        pq.next(value, priority);
        REQUIRE(value == 20);
        REQUIRE(priority == 5);

        REQUIRE_FALSE(pq.next(value, priority));
    }
    
    SECTION("Inorder traversal after enqueuing elements") 
    {
        pq.enqueue(42, 1);
        pq.enqueue(17, 3);
        pq.enqueue(17, 5);
        pq.enqueue(20, 5);
        pq.enqueue(100, 4);
        pq.enqueue(1000, 7);
        pq.enqueue(199, 7);
        pq.enqueue(220, 3);
        pq.enqueue(120, 5);

        int value;
        int priority;
        int expectedPriorities[] = {1, 3, 3, 4, 5, 5, 5, 7, 7}; // Expected priorities in ascending order.
        int expectedValues[] = {42, 17, 220, 100, 17, 20, 120, 1000, 199};
        pq.begin();
        
        for (int i = 0; i < 8; i++)
        {
            REQUIRE(pq.next(value, priority) == true);
            REQUIRE(value == expectedValues[i]);
            REQUIRE(priority == expectedPriorities[i]);
        }
        REQUIRE(pq.next(value, priority) == false);
    }

    SECTION("Inorder traversal after enqueuing elements") 
    {
        pq.enqueue(42, 2);
        pq.enqueue(17, 3);
        pq.enqueue(17, 2);
        int data = pq.dequeue();
        REQUIRE(data == 42);
        int value;
        int priority;
    
        pq.begin();
        pq.next(value, priority);
        
        REQUIRE(value == 17);
        REQUIRE(priority == 2);

        pq.next(value, priority);
        REQUIRE(value == 17);
        REQUIRE(priority == 3);

        REQUIRE_FALSE(pq.next(value, priority));

       
    }

    SECTION("Inorder traversal after enqueuing elements") 
    {
        pq.enqueue(1, 5);
        pq.enqueue(2, 5);
        pq.enqueue(3, 5);
        pq.enqueue(4, 2);
        pq.enqueue(5, 4);
        pq.enqueue(6, 10);
        pq.enqueue(7, 20);
        pq.enqueue(8, 2);
        pq.enqueue(9, 2);

        
        int value;
        int priority;
        int expectedPriorities[] = {2, 2, 2, 4, 5, 5, 5, 10, 20}; // Expected priorities in ascending order.
        int expectedValues[] = {4,8,9,5,1,2,3,6,7};
        pq.begin();
        for (int i = 0; i < 8; i++)
        {
            REQUIRE(pq.next(value, priority) == true);
            REQUIRE(value == expectedValues[i]);
            REQUIRE(priority == expectedPriorities[i]);
        }
        REQUIRE(pq.next(value, priority) == false);   
    }
}

TEST_CASE("more test preque begin nand next") 
{
    SECTION("Inorder traversal of an empty priority queue") 
    {
        prqueue<int> pq;
        pq.begin();
        int value, priority;
        REQUIRE(pq.next(value, priority) == false);
    }

    SECTION("Inorder traversal of a priority queue with one element") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.begin();
        int value, priority;
        REQUIRE(pq.next(value, priority) == false);
        REQUIRE(value == 42);
        REQUIRE(priority == 2);
        REQUIRE(pq.next(value, priority) == false);
    }

    SECTION("Inorder traversal of a priority queue with unique priorities") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);
        pq.enqueue(99, 3);
        pq.begin();
        int value, priority;
        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == 17);
        REQUIRE(priority == 1);
        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == 42);
        REQUIRE(priority == 2);
        REQUIRE(pq.next(value, priority) == false);
        REQUIRE(value == 99);
        REQUIRE(priority == 3);
    }

    SECTION("Inorder traversal of a priority queue with duplicate priorities") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 1);
        pq.enqueue(17, 2);
        pq.enqueue(99, 3);
        pq.begin();
        int value, priority;
        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == 42);
        REQUIRE(priority == 1);
        REQUIRE(pq.next(value, priority) == true);
        REQUIRE(value == 17);
        REQUIRE(priority == 2);
        REQUIRE(pq.next(value, priority) == false);
        REQUIRE(value == 99);
        REQUIRE(priority == 3);
    }

}

TEST_CASE("Extra prqueue dequeue") 
{
    
    SECTION("Dequeue from a priority queue with one element") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        int value = pq.dequeue();
        REQUIRE(value == 42);
        REQUIRE(pq.size() == 0);
    }

    SECTION("Dequeue from a priority queue with unique priorities") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 1);
        pq.enqueue(99, 3);
        int value1 = pq.dequeue();
        int value2 = pq.dequeue();
        int value3 = pq.dequeue();
        REQUIRE(value1 == 17);
        REQUIRE(value2 == 42);
        REQUIRE(value3 == 99);
        REQUIRE(pq.size() == 0);
    }

    SECTION("Dequeue from a priority queue with duplicate priorities") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        pq.enqueue(17, 2);
        pq.enqueue(99, 3);
        int value1 = pq.dequeue();
        int value2 = pq.dequeue();
        REQUIRE(value1 == 42);
        REQUIRE(value2 == 17);
        REQUIRE(pq.size() == 1);
    }
}

TEST_CASE("prqueue peek and operator==") 
{
    SECTION("Peek at a priority queue with one element") 
    {
        prqueue<int> pq;
        pq.enqueue(42, 2);
        int value = pq.peek();
        REQUIRE(value == 42);
        REQUIRE(pq.size() == 1);
    }

    SECTION("Equality operator between equal priority queues") 
    {
        prqueue<int> pq1;
        pq1.enqueue(42, 2);
        pq1.enqueue(17, 1);
        pq1.enqueue(99, 3);

        prqueue<int> pq2;
        pq2.enqueue(42, 2);
        pq2.enqueue(17, 1);
        pq2.enqueue(99, 3);

        REQUIRE(pq1 == pq2);
    }

    SECTION("Equality operator between unequal priority queues") 
    {
        prqueue<int> pq1;
        pq1.enqueue(42, 2);
        pq1.enqueue(17, 1);

        prqueue<int> pq2;
        pq2.enqueue(42, 2);
        pq2.enqueue(99, 3);

        REQUIRE(!(pq1 == pq2));
    }
}

// test cases from alexis UIN: 660086207

TEST_CASE("Testing Class prqueue")
{
    SECTION("Testing default constructor")
    {
        prqueue<int> pq;

        REQUIRE(pq.size() == 0);
        REQUIRE(pq.getRoot() == nullptr);
    }
}

TEST_CASE("Testing size fucntion")
{
    prqueue<int> pq;
    prqueue<string> pq1;
    prqueue<double> pq2;

    SECTION("Testing size function")
    {
        REQUIRE(pq.size() == 0);   
    }

    SECTION("Testing size function with duplicate values")
    {
        pq.enqueue(10, 1);
        pq.enqueue(10, 2);
        pq.enqueue(10, 3);

        REQUIRE(pq.size() == 3);
    }

    SECTION("Testing size of five")
    {

        pq.enqueue(10, 1);
        pq.enqueue(20, 2);
        pq.enqueue(30, 3);
        pq.enqueue(40, 4);
        pq.enqueue(50, 5);

        REQUIRE(pq.size() == 5);   
    }

    SECTION("Testing size of 10")
    {
        const int numElements = 10;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }

    SECTION("Testing size of 25")
    {
        const int numElements = 25;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }

    SECTION("Testing size of 35")
    {
        const int numElements = 35;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }

    SECTION("Testing size of 50")
    {
        const int numElements = 50;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }

    SECTION("Testing size of 75")
    {
        const int numElements = 75;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }
    
    SECTION("Testing size of 100")
    {
        const int numElements = 100;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }

    SECTION("Testing size of 125")
    {
        const int numElements = 125;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }

    SECTION("Testing size of 150")
    {
        const int numElements = 150;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }

    SECTION("Testing size of 175")
    {
        const int numElements = 175;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }

    SECTION("Testing size of 200")
    {
        const int numElements = 200;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }

    SECTION("Testing size of 300")
    {
        const int numElements = 300;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }

    SECTION("Testing size of 400")
    {
        const int numElements = 400;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }
    
    SECTION("Testing size of 500")
    {
        const int numElements = 500;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }

    SECTION("Testing size of 800")
    {
        const int numElements = 800;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }

    SECTION("Testing size of 1000")
    {
        const int numElements = 1000;
        for (int i = 0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }

    SECTION("Testing size with string values")
    {
        pq1.enqueue("Lisette", 1);
        pq1.enqueue("Adam", 2);
        pq1.enqueue("Diaz", 3);

        REQUIRE(pq1.size() == 3);
    }

    SECTION("Testing size with string values")
    {
        pq1.enqueue("Lisette", 1);
        pq1.enqueue("Adam", 2);
        pq1.enqueue("Diaz", 3);
        pq1.enqueue("Alex", 4);
        pq1.enqueue("Lexi", 5);
        pq1.enqueue("Emily", 10);
        pq1.enqueue("Giselle", 3);
        pq1.enqueue("Ashley", 4);
        pq1.enqueue("Ciro", 5);
        pq1.enqueue("Naty", 10);


        REQUIRE(pq1.size() == 10);
    }

    SECTION("Testing size of 1000")
    {
        const double numElements = 1000;
        for (double i = 0.0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
    }
}



TEST_CASE("Testing Enqueue")
{
    prqueue<int> pq;

    SECTION("Inserting into an empty queue")
    {
        pq.enqueue(10, 2);

        REQUIRE(pq.size() == 1);
    }


    SECTION("Testing inserting double elements using enqueue")
    {   prqueue<double> pq;
        pq.enqueue(1.1, 1);
        pq.enqueue(1.7, 2);

        REQUIRE(pq.size() == 2);
    }

    SECTION("Testing Enqueue")
    {
        pq.enqueue(10, 2);
        pq.enqueue(20, 1);
        pq.enqueue(30, 3);
        pq.enqueue(3, 6);
        pq.enqueue(1, 1); 

        REQUIRE(pq.size() == 5);
    }

    SECTION("Testing Enqueue with a single element")
    {
        prqueue<int> pq;

        pq.enqueue(10, 2);
        REQUIRE(pq.size() == 1);
    }
}




TEST_CASE("Testing toString()")
{
    prqueue<int> pq;
    prqueue<string> pq1;
    prqueue<double> pq2;

    SECTION("test 1")
    {
        pq.enqueue(10, 2);
        pq.enqueue(20, 1);
        pq.enqueue(30, 2);
        pq.enqueue(30, 3);

        string result = "1 value: 20\n2 value: 10\n2 value: 30\n3 value: 30\n";

        string actual = pq.toString();

        REQUIRE(result == actual);
    }

    SECTION("testing toString with one value")
    {
        pq.enqueue(10, 2);

        string result = "2 value: 10\n";

        string actual = pq.toString();

        REQUIRE(result == actual);
    }

    SECTION("testing toString with an empty queue")
    {
        string result = "";

        string actual = pq.toString();

        REQUIRE(result == actual);
    }

    SECTION("testing toString with 10 string values")
    {
        pq1.enqueue("Lisette", 1);
        pq1.enqueue("Adam", 2);
        pq1.enqueue("Diaz", 3);
        pq1.enqueue("Alex", 4);
        pq1.enqueue("Lexi", 5);
        pq1.enqueue("Emily", 10);
        pq1.enqueue("Giselle", 3);
        pq1.enqueue("Ashley", 4);
        pq1.enqueue("Ciro", 5);
        pq1.enqueue("Naty", 10);

        string result = "1 value: Lisette\n2 value: Adam\n3 value: Diaz\n3 value: Giselle\n4 value: Alex\n4 value: Ashley\n5 value: Lexi\n5 value: Ciro\n10 value: Emily\n10 value: Naty\n";

        string actual = pq1.toString();

        REQUIRE(result == actual);
    }
    
    SECTION("Testing toString after clearing")
    {
        pq1.enqueue("Emily", 1);
        pq1.enqueue("Ben", 2);
        pq1.enqueue("Joy", 3);

        string result = "1 value: Emily\n2 value: Ben\n3 value: Joy\n";

        string actual = pq1.toString();
        REQUIRE(result == actual);

        pq1.clear();
        string res = "";
        string afterClear = pq1.toString();

        REQUIRE(pq1.size() == 0);
        REQUIRE(res == afterClear);
    }

    SECTION("toString with double variables")
    {
        pq2.enqueue(1.5, 1);
        pq2.enqueue(2.1, 2);
        pq2.enqueue(3.5, 3);

        string result = "1 value: 1.5\n2 value: 2.1\n3 value: 3.5\n";
        string actual = pq2.toString();

        REQUIRE(result == actual);
    }

    SECTION("Testing toString with negative numbers")
    {
        pq.enqueue(-1, 1);
        pq.enqueue(-2, 2);
        pq.enqueue(-5, 3);

        string result = "1 value: -1\n2 value: -2\n3 value: -5\n";
        string actual = pq.toString();

        REQUIRE(result == actual);
    }

    SECTION("Testing toString with a mix of negative and positive numbers")
    {
        pq.enqueue(-1, 1);
        pq.enqueue(2, 2);
        pq.enqueue(-5, 3);
        pq.enqueue(3, 2);

        string result = "1 value: -1\n2 value: 2\n2 value: 3\n3 value: -5\n";
        string actual = pq.toString();

        REQUIRE(result == actual);
        REQUIRE(pq.size() == 4);
    }

    SECTION("Testing with special characters")
    {
        prqueue<char> pq3;

        pq3.enqueue('!', 1);
        pq3.enqueue('@', 2);
        pq3.enqueue('&', 3);

        string result = "1 value: !\n2 value: @\n3 value: &\n";
        string actual = pq3.toString();

        REQUIRE(result == actual);
    }

    SECTION("Testing with large numbers")
    {
        prqueue<long long> pq4;

        pq4.enqueue(1000000000, 1);
        pq4.enqueue(9999999999, 2);
        pq4.enqueue(9999999998, 3);

        string result = "1 value: 1000000000\n2 value: 9999999999\n3 value: 9999999998\n";
        string actual = pq4.toString();

        REQUIRE(result == actual);
    }

    SECTION("Test case from the PDF")
    {
        map<int, vector<int> > mp;
        int n = 9;
        int vals[] = {15, 16, 17, 6, 7, 8, 9, 2, 1};
        int prs[] = {1, 2, 3, 2, 2, 2, 2, 3, 3};
        prqueue<int> pq;
        for (int i = 0; i < n; i++) {
            pq.enqueue(vals[i], prs[i]);
            mp[prs[i]].push_back(vals[i]);
        }
        REQUIRE(pq.size() == 9);
        stringstream ss;
        for (const auto &e: mp) {
            int priority = e.first;
            vector <int> values = e.second;
            for (size_t j = 0; j < values.size(); j++){
                ss << priority << " value: " << values[j] << endl;
            }
        }
        REQUIRE(pq.toString() == ss.str());

    }
}



TEST_CASE("Testing clear()")
{
    prqueue<int> pq;
    prqueue<double> pq1;
    prqueue<string> pq2;
    prqueue<char> pq3;

    SECTION("Testing with an empty priority queue")
    {
        pq.clear();
        pq1.clear();
        pq2.clear();
        pq3.clear();

        REQUIRE(pq.size() == 0);
        REQUIRE(pq1.size() == 0);
        REQUIRE(pq2.size() == 0);
        REQUIRE(pq3.size() == 0);
    }

    SECTION("Clear() using 3 elements")
    {
        pq.enqueue(10, 1);
        pq.enqueue(20, 3);
        pq.enqueue(30, 2);
        
        REQUIRE(pq.size() == 3);
        
        pq.clear();

        REQUIRE(pq.size() == 0);
    }

    SECTION("clearing double integers")
    {
        pq1.enqueue(1.5, 1);
        pq1.enqueue(2.5, 2);
        pq1.enqueue(3.5, 3);

        pq1.clear();

        REQUIRE(pq1.size() == 0);
    }

    SECTION("clearing a large number of integers")
    {
        const int numElements = 100;
        for (double i = 0.0; i < numElements; i++)
        {
            pq.enqueue(i, rand() % 100);
        }

        REQUIRE(pq.size() == numElements);
        
        pq.clear();
        REQUIRE(pq.size() == 0);
    }

    SECTION("Clearing strings")
    {
        pq2.enqueue("Alex", 1);
        pq2.enqueue("Emily", 2);
        pq2.enqueue("Lexi", 3);

        REQUIRE(pq2.size() == 3);

        pq2.clear();
        REQUIRE(pq2.size() == 0);
    }

    SECTION("Testing with special characters")
    {
        prqueue<char> pq3;

        pq3.enqueue('!', 1);
        pq3.enqueue('@', 2);
        pq3.enqueue('&', 3);

        REQUIRE(pq3.size() == 3);

        pq3.clear();
        REQUIRE(pq3.size() == 0);

    }

    SECTION("Clearing negative numbers")
    {
        pq.enqueue(-1, 1);
        pq.enqueue(2, 2);
        pq.enqueue(-5, 3);
        pq.enqueue(3, 2);

        REQUIRE(pq.size() == 4);
        pq.clear();
        REQUIRE(pq.size() == 0);
    }

    SECTION("Testing with large numbers")
    {
        prqueue<long long> pq4;

        pq4.enqueue(1000000000, 1);
        pq4.enqueue(9999999999, 2);
        pq4.enqueue(9999999998, 3);

        REQUIRE(pq4.size() == 3);
        pq4.clear();
        REQUIRE(pq4.size() == 0);
    }
}

TEST_CASE("Testing operator=")
{
    prqueue<int> pq;
    prqueue<int> pq1;
    prqueue<string>pq2;
    prqueue<string>pq3;
    prqueue<char>pq4;
    prqueue<char>pq5;


    SECTION("Assingment from another queue")
    {
        pq.enqueue(10, 1);
        pq.enqueue(20, 2);
        pq.enqueue(30, 3);

        pq1.enqueue(50, 4);
        pq1.enqueue(60, 1);
        pq1.enqueue(70, 2);
        pq1.enqueue(80, 3);

        pq = pq1;

        REQUIRE(pq.size() == 4);
    }

    SECTION("Assignment to an empty queue")
    {
        pq.enqueue(10, 1);
        pq.enqueue(20, 2);
        pq.enqueue(30, 3);

        pq1 = pq;

        REQUIRE(pq1.size() == 3);
    }

    SECTION("Assignment with duplicate priorities")
    {
        pq.enqueue(10, 2);
        pq.enqueue(1, 2);
        pq.enqueue(20, 2);

        pq1 = pq;

        REQUIRE(pq1.size() == 3);
    }   

    SECTION("Testing assignment with string values")
    {
        pq2.enqueue("Alex", 1);
        pq2.enqueue("Emily", 2);
        pq2.enqueue("Sara", 3);

        pq3.enqueue("Lexi", 1);

        pq3 = pq2;

        REQUIRE(pq3.size() == 3);

    }

    SECTION("Testing assignment with characters")
    {
        pq4.enqueue('!', 1);
        
        
        pq5.enqueue('@', 1);
        pq5.enqueue('#', 2);
        pq5.enqueue('&', 2);

        // size of pq4 should be 4 
        pq4 = pq5;

        REQUIRE(pq4.size() == 3);
    }
}



TEST_CASE("Testing operator==")
{
    prqueue<int> pq, pq1;

    SECTION("Testing operator= on empty queue's")
    {
        REQUIRE(pq == pq1);
        REQUIRE(pq.size() == pq1.size());
    }
    SECTION("Testing with same values")
    {
        pq.enqueue(10, 1);
        pq.enqueue(20, 2);
        pq1.enqueue(10, 1);
        pq1.enqueue(20, 2);
        REQUIRE(pq == pq1);
    }

    SECTION("Testing with different values")
    {
        pq.enqueue(1, 1);
        pq.enqueue(2, 2);
        pq1.enqueue(10, 1);
        pq1.enqueue(20, 2);
        REQUIRE_FALSE(pq == pq1);
    }

    SECTION("Assigning a priority queue to an empty queue")
    {
        pq.enqueue(1, 1);
        pq.enqueue(2, 2);

        REQUIRE_FALSE(pq == pq1);
        
        pq1 = pq;
        REQUIRE(pq1.size() == 2);
        REQUIRE(pq.size() == 2);
        REQUIRE(pq == pq1);
    }

    SECTION("Testing operator= after clearing the queue")
    {
        pq.enqueue(11, 1);
        pq.enqueue(22, 2);
        pq.enqueue(33, 3);

        pq1.enqueue(11, 1);
        pq1.enqueue(22, 2);
        pq1.enqueue(33, 3);

        pq.clear();
        pq1.clear();

        // after clearing the queue both should be empty
        // and of size 0
        REQUIRE(pq == pq1);
        REQUIRE(pq.size() == pq1.size());
    }

    SECTION("Testing operator= with dup priority")
    {
        pq.enqueue(11, 1);
        pq.enqueue(22, 1);
        pq.enqueue(33, 1);

        pq1.enqueue(11, 1);
        pq1.enqueue(22, 1);
        pq1.enqueue(33, 1);

        REQUIRE(pq == pq1);
        REQUIRE(pq.size() == pq1.size());
    }

    SECTION("Testing operator= with dup priority and no dup values")
    {
        pq.enqueue(1, 1);
        pq.enqueue(2, 1);
        pq.enqueue(3, 1);

        pq1.enqueue(11, 1);
        pq1.enqueue(22, 1);
        pq1.enqueue(33, 1);

        REQUIRE_FALSE(pq == pq1);
        REQUIRE(pq.size() == pq1.size());
    }

    SECTION ("Testing operator= with characters")
    {
        prqueue<char> pq;
        prqueue<char> pq1;

        pq.enqueue('!', 1);
        pq.enqueue('#', 2);
        pq.enqueue('$', 3);

        pq1.enqueue('!', 1);
        pq1.enqueue('#', 2);
        pq1.enqueue('$', 3);

        REQUIRE(pq == pq1);
        REQUIRE(pq.size() == pq1.size());
    }
}

TEST_CASE("Testing begin and next")
{
    prqueue<int> pq;

    SECTION("Test begin and next on an empty queue")
    {
        pq.begin();
        int value, priority;
        bool result = pq.next(value, priority);

        // since the queue is empty, next() should return false
        REQUIRE(result == false);
    }
}

