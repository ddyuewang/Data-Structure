#include <iostream>
#include "Node.h"
#include <stdio.h>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include <cassert>
#include <string>

using namespace std;

//int main() {
//    Node<int> n(5);
//    Node<int> m(3);
//    n.Set(m);
//    n.Value() = 7;
//    cout << n.Value() << endl;
//    return 0;
//}

//int main(int argc, char* argv[]) {
int main(){
    LinkedList<int> i1;
    assert (i1.Size() == 0);
    assert (i1.Empty());

    i1.Add(1);
    assert (i1.Size() == 1);
    assert (!i1.Empty());

    i1.Add(2);
    i1.Insert(3,3);
    //i1.Remove(3);
    i1.Print();
    cout << i1.Size() << endl;

    LinkedList<int> i2 = i1;
    cout << i2.Size() << endl;
    i2.Print();

    assert (!i1.Empty());
    cout << i1.IndexOf(1) << endl;
    cout << i1.Size() << endl;
    assert (i2.Size() == 3);
    i1.Remove(0);
    assert (i1.Size() == 2);
    assert (i2.Size() == 3);


    i2.Print();
    LinkedList<string> s;
    cout << s.Size() << endl;
    s.Insert("third",0);
    s.Insert("second",0);
    s.Insert("first",0);
    cout << s.IndexOf("second") << endl;
    cout << s.IndexOf("third") << endl;
    s.Print();

    return 0;
}

