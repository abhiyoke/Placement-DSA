/*
Approach 1 (Using 2 queues):
We maintain two queues, que1 and que2.
When pushing a new element, we push it onto que2 and then move all elements from que1 to que2, effectively making the newly pushed element at the front of que2. Then, we swap the names of que1 and que2.
Pop, top, and empty operations are straightforward, as they directly operate on que1.

Approach 2 (Using 1 queue):
We maintain a single queue que.
When pushing a new element, we first push it onto the queue. Then, we rotate the queue by pushing and popping elements until the newly pushed element becomes the front.
Pop, top, and empty operations are straightforward, as they directly operate on the single queue.
*/

#include<bits/stdc++.h>
using namespace std;
class Stack {
  queue < int > q;
  public:
    void Push(int x) {
      int s = q.size();
      q.push(x);
      for (int i = 0; i < s; i++) {

        q.push(q.front());
        q.pop();
      }
    }
  int Pop() {
    int n = q.front();
    q.pop();
    return n;
  }
  int Top() {
    return q.front();
  }
  int Size() {
    return q.size();
  }
};
int main() {
  Stack s;
  s.Push(3);
  s.Push(2);
  s.Push(4);
  s.Push(1);
  cout << "Top of the stack: " << s.Top() << endl;
  cout << "Size of the stack before removing element: " << s.Size() << endl;
  cout << "The deleted element is: " << s.Pop() << endl;
  cout << "Top of the stack after removing element: " << s.Top() << endl;
  cout << "Size of the stack after removing element: " << s.Size();
}
