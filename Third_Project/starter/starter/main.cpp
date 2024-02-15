#include <iostream>
#include "deque.h"
using namespace std;

int main() {
    // Test insertFirst
    {
        Deque<int> q;
        q.insertFirst(3);
        q.insertFirst(2);
        q.insertFirst(1);

        // Now the deque should be [1, 2, 3]
        
        if (q.size() != 3) {
            cout << "Test insertFirst failed: Incorrect size" << endl;
            
        } else if (q.first() != 1 || q.last() != 3) {
            cout << "Test insertFirst failed: Incorrect elements" << endl;
   
        } else {
            cout << "Test insertFirst passed" << endl;
        }
        
    }
    
    // Test insertLast
    {
        Deque<int> q;
        q.insertLast(1);
        q.insertLast(2);
        q.insertLast(3);
        
        // Now the deque should be [1, 2, 3]
        int x = q.removeFirst(); //2 , 3
        cout << x << endl;
        int y = q.removeLast();// 2
        cout << y << endl;
        cout << q.first() << " " << q.last() << endl;
        if (q.size() != 1) {
            cout << "Test insertLast failed: Incorrect size" << endl;
        } else if (q.first() != 2 || q.last() != 2) {
            cout << "Test insertLast failed: Incorrect elements" << endl;
        } else {
            cout << "Test insertLast passed" << endl;
        }

        Deque<int> r = q; //r=2
        if (q.size() != r.size()) {
            cout << "Test insertLast failed: Incorrect size" << endl;
        } else if (q.first() != r.first() || q.last() != r.last()) {
            cout << "Test insertLast failed: Incorrect elements" << endl;
        } else {
            cout << "Test copy assignment passed" << endl;
        }

        r.insertLast(1);//r = 2, 1, 2, 3
        r.insertLast(2);
        r.insertLast(3);
        cout << r.first() << " " << r.last() << " " << r.size() << endl;


        q = r;//q = 2, 1, 2, 3
        if (q.size() != r.size()) {
            cout << "Test insertLast failed: Incorrect size" << endl;
        } else if (q.first() != r.first() || q.last() != r.last()) {
            cout << "Test insertLast failed: Incorrect elements" << endl;
        } else {
            cout << "Test copy assignment passed" << endl;
        }

        int l = q.removeFirst();//q = 1, 2, 3
        int n = q.removeLast();//q = 1, 2

        q.insertLast(1);//q = 1, 2, 1, 2, 3
        q.insertLast(2);
        q.insertLast(3);

        int a = q.removeFirst();
        int e = q.removeLast();
        int d = q.removeLast();
        int g = q.removeFirst();
        
        cout << q.first() << " " << q.last() << " " << q.size() << endl;
        if (q.size() != 1) {
            cout << "Test insertLast failed: Incorrect size" << endl;
        } else if (q.first() != 1 || q.last() != 1) {
            cout << "Test insertLast failed: Incorrect elements" << endl;
        } else {
            cout << "Test insertLast passed" << endl;
        }
        
    }

    return 0;
}