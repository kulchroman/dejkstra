#include "graph.h"

using namespace std;

void test1()
{
    // A-0
    // B-1
    // C-2
    // D-3
    // E-4
    // F-5
    // G-6
    Graph graph(0, 1);
    // A-C
    graph.addPath(0, 2, 3);
    // A-F
    graph.addPath(0, 5, 2);
    // F-C
    graph.addPath(5, 2, 2);
    // F-B
    graph.addPath(5, 1, 6);
    // F-G
    graph.addPath(5, 6, 5);
    // C-E
    graph.addPath(2, 4, 1);
    // C-D
    graph.addPath(2, 3, 4);
    // E-B
    graph.addPath(4, 1, 2);
    // G-B
    graph.addPath(6, 1, 2);
    // D-B
    graph.addPath(3, 1, 1);
    graph.calculatePath();
}

void test2()
{
    Graph graph(/*start*/ 0, /*finish*/ 1);
    graph.addPath(/*start*/ 0, /*finish*/ 2, /*cost*/ 3);
    graph.addPath(/*start*/ 2, /*finish*/ 1, /*cost*/ 4);
    graph.addPath(/*start*/ 0, /*finish*/ 1, /*cost*/ 10);
    graph.calculatePath();
}

void test3()
{
    Graph graph(0, 5);
    graph.addPath(0, 1, 2);
    graph.addPath(0, 2, 4);
    graph.addPath(1, 2, 1);
    graph.addPath(1, 3, 7);
    graph.addPath(2, 4, 3);
    graph.addPath(3, 5, 1);
    graph.addPath(4, 3, 2);
    graph.addPath(4, 5, 5);
    graph.calculatePath();
}

void test4()
{
    Graph graph(0, 9);
    graph.addPath(0, 1, 4);
    graph.addPath(0, 7, 8);
    graph.addPath(1, 2, 8);
    graph.addPath(1, 7, 11);
    graph.addPath(2, 3, 7);
    graph.addPath(2, 8, 2);
    graph.addPath(2, 5, 4);
    graph.addPath(3, 4, 9);
    graph.addPath(3, 5, 14);
    graph.addPath(4, 5, 10);
    graph.addPath(5, 6, 2);
    graph.addPath(6, 7, 1);
    graph.addPath(6, 8, 6);
    graph.addPath(7, 8, 7);
    graph.addPath(8, 9, 3);
    graph.addPath(4, 9, 5);
    graph.calculatePath();
}

void test5()
{
    Graph graph(0, 10);
    graph.addPath(0, 1, 5);
    graph.addPath(0, 2, 3);
    graph.addPath(1, 3, 6);
    graph.addPath(2, 3, 2);
    graph.addPath(2, 4, 4);
    graph.addPath(3, 5, 1);
    graph.addPath(4, 5, 1);
    graph.addPath(5, 6, 7);
    graph.addPath(5, 7, 3);
    graph.addPath(6, 8, 2);
    graph.addPath(7, 8, 2);
    graph.addPath(8, 9, 1);
    graph.addPath(9, 10, 1);
    graph.addPath(3, 6, 15);
    graph.addPath(1, 4, 10);
    graph.addPath(0, 10, 50);
    graph.calculatePath();
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
