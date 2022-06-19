#include <iostream>
#include "dynamicArray.h"
#include "dynamicArray.cpp"
/*#include "linkedList.h"
#include "linkedList.cpp"
#include "circularList.h"
#include "circularList.cpp"
#include "stack.h"
#include "stack.cpp"
#include "queue.h"
#include "queue.cpp"
#include "priorityQueue.h"
#include "priorityQueue.cpp"*/

using namespace std;

void task1();
/*void task2();
void task3();
void task4();
void task5();
void task6();*/

int main()
{
    // Uncomment these as you implement the tasks.
    task1();
//    task2();
//    task3();
//    task4();
//    task5();
//    task6();
    // Add your own code for more thorough testing!
    // These examples will not be used on Fitchfork, but testing will be similar

    return 0;
}

void task1() {
    DynamicArray<int> arr1(1);
    DynamicArray<int> arr2(arr1);
    DynamicArray<int> arr3(5);
    arr3 = arr2;

    cout << arr1 << endl;
    cout << arr2 << endl;
    cout << arr3 << endl;

    cout << endl;

    arr1.insert(0,5);
    cout << arr1 << endl;

    arr2.insert(0,2);
    arr2.insert(0,7);
    cout << arr2 << endl;

    arr3.insert(1,8);
    cout << arr3 << endl;

    cout << endl;

    cout << arr2.get(1) << endl;
    cout << arr2.remove(0) << endl;
    cout << arr2 << endl;

    cout << endl;

    arr3.clear();
    if(arr3.isEmpty()) cout << "Clear works correctly" << endl;
    cout << arr3 << endl;

    cout << endl;

    DynamicArray<int> * aPtr = arr2.clone();
    cout << *aPtr << endl;
    aPtr->insert(10,3);
    cout << *aPtr << endl;
    cout << arr2 << endl;
    delete aPtr;
}

/*
void task2() {
    LinkedList<char> list1;
    for(char i = 'a'; i < 'f'; i++) {
        list1.insert(0,i);
    }
    cout << list1 << endl;

    LinkedList<char> list2;
    for(char i = 'a', j = 0; i < 'f'; i++, j++) {
        list2.insert(j,i);
    }
    cout << list2 << endl;

    cout << endl;

    list1.remove(2);
    cout << list1 << endl;
    list1.remove(3);
    cout << list1 << endl;
    list1.remove(0);
    cout << list1 << endl;

    cout << endl;

    LinkedList<char> list3(list1);
    list2 = list1;

    list1.clear();
    if(list1.isEmpty()) cout << "Clear works correctly" << endl;
    cout << list1 << endl;
    cout << list2 << endl;
    cout << list3 << endl;
    cout << endl;

    Node<char> * node = list3.getLeader();
    node->element = 'z';
    cout << list3 << endl;
    cout << endl;

    LinkedList<char> * lPtr = list2.clone();
    cout << *lPtr << endl;
    cout << lPtr->get(0) << " " << lPtr->get(1) << endl;
    cout << *lPtr << endl;

    try { lPtr->get(10); } catch (const char * e) { cout << e << endl; }

    delete lPtr;
}

void task3() {
    CircularList<int> clist;
    cout << clist << endl;
    clist.insert(0,8);
    cout << clist << endl;
    clist.insert(1,5);
    cout << clist << endl;
    clist.insert(2,4);
    cout << clist << endl;
    clist.insert(0,0);
    cout << clist << endl;
    clist.insert(3,7);
    cout << clist << endl;
    clist.insert(5,9);
    cout << clist << endl;

    try { clist.insert(10,99); } catch (const char * e) { cout << e << endl; }

    cout << endl;

    CircularList<int> clist2(clist);

    cout << clist.remove(5) << ": " << clist <<  endl;
    cout << clist.remove(1) << ": " << clist << endl;
    cout << clist.remove(0) << ": " << clist << endl;;

    cout << endl;

    cout << clist2 << endl;
    clist = clist2;
    clist2.clear();
    if(clist2.isEmpty()) cout << "Clear works correctly" << endl;
    cout << clist2 << endl;
    cout << clist << endl;
    cout << endl;

    CircularList<int> * cPtr = clist.clone();
    cout << *cPtr << endl;
    cout << cPtr->get(3) << " " << cPtr->get(0) << " " << cPtr->get(5) << endl;
    cout << *cPtr << endl;
    delete cPtr;
}

void task4() {
    Stack<char> s1(new LinkedList<char>() );
    Stack<char> s2(new CircularList<char>() );
    Stack<char> s3(new DynamicArray<char>(1) );

    for(char i = 'a'; i < 'h'; i++) {
        s1.insert(i-25);
        s2.insert(i+5);
        s3.insert(i);
    }

    cout <<  *(s1.getImplementation()) << endl;
    cout <<  *(s2.getImplementation()) << endl;
    cout <<  *(s3.getImplementation()) << endl;

    cout << endl;

    s1.reverse();
    s2.reverse();
    s3.reverse();

    cout <<  *(s1.getImplementation()) << endl;
    cout <<  *(s2.getImplementation()) << endl;
    cout <<  *(s3.getImplementation()) << endl;

    cout << endl;

    while(!s1.isEmpty()) {
        cout << s1.remove() << ": " << *(s1.getImplementation()) << endl;
    }
    cout << endl;

    while(!s2.isEmpty()) {
        cout << s2.remove() << ": " << *(s2.getImplementation()) << endl;
    }
    cout << endl;

    while(!s3.isEmpty()) {
        cout << s3.remove() << ": " << *(s3.getImplementation()) << endl;
    }
}

void task5() {
    Queue<char> q1(new LinkedList<char>() );
    Queue<char> q2(new CircularList<char>() );
    Queue<char> q3(new DynamicArray<char>(1) );

    for(char i = 'a'; i < 'h'; i++) {
        q1.insert(i-15);
        q2.insert(i+3);
        q3.insert(i-32);
    }

    cout <<  *(q1.getImplementation()) << endl;
    cout <<  *(q2.getImplementation()) << endl;
    cout <<  *(q3.getImplementation()) << endl;

    cout << endl;

    q1.reverse();
    q2.reverse();
    q3.reverse();

    cout <<  *(q1.getImplementation()) << endl;
    cout <<  *(q2.getImplementation()) << endl;
    cout <<  *(q3.getImplementation()) << endl;

    cout << endl;

    while(!q1.isEmpty()) {
        cout << q1.remove() << ": " << *(q1.getImplementation()) << endl;
    }
    cout << endl;

    while(!q2.isEmpty()) {
        cout << q2.remove() << ": " << *(q2.getImplementation()) << endl;
    }
    cout << endl;

    while(!q3.isEmpty()) {
        cout << q3.remove() << ": " << *(q3.getImplementation()) << endl;
    }
}

void task6() {
    PriorityQueue<int> pq1(new LinkedList<int>() );
    PriorityQueue<int> pq2(new CircularList<int>() );
    PriorityQueue<int> pq3(new DynamicArray<int>(1) );

    pq1.insert(2);
    pq1.insert(5);
    pq1.insert(7);
    pq1.insert(1);
    pq1.insert(6);
    pq1.insert(3);
    pq1.insert(8);

    cout <<  *(pq1.getImplementation()) << endl;

    pq2.insert(1);
    pq2.insert(5);
    pq2.insert(3);
    pq2.insert(0);
    pq2.insert(2);
    pq2.insert(7);
    pq2.insert(4);

    cout <<  *(pq2.getImplementation()) << endl;

    pq3.insert(9);
    pq3.insert(1);
    pq3.insert(2);
    pq3.insert(6);
    pq3.insert(7);
    pq3.insert(3);
    pq3.insert(5);

    cout <<  *(pq3.getImplementation()) << endl;

    cout << endl;

    pq1.reverse();
    pq2.reverse();
    pq3.reverse();

    cout <<  *(pq1.getImplementation()) << endl;
    cout <<  *(pq2.getImplementation()) << endl;
    cout <<  *(pq3.getImplementation()) << endl;
    cout << endl;

    pq1.insert(25);
    pq1.insert(-1);

    pq2.insert(25);
    pq2.insert(-1);

    pq3.insert(25);
    pq3.insert(-1);

    cout <<  *(pq1.getImplementation()) << endl;
    cout <<  *(pq2.getImplementation()) << endl;
    cout <<  *(pq3.getImplementation()) << endl;
}
*/