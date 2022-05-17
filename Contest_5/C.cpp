#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::string;
class Qeuee {
 public:
     int* arr;
     int head = 0;
     int tail = head;
     int middle = head;
     int size = 0;
     Qeuee() {
         arr = new int[100001];
     }
     void Push(int elem) {
         arr[tail] = elem;
         ++tail;
         ++size;
         if (size % 2 == 0) {
             middle = head + size / 2;
         } else {
             middle = head + size / 2 + 1;
         }
     }
     int Pop() {
         size--;
         if (size % 2 == 1) {
             middle++;
         }
         return arr[head++];
     }
     void Push_mid(int elem) {
         int k = 0;
         int i = tail;
         while (k < size / 2) {
             arr[i] = arr[i - 1];
             i--;
             k++;
         }
         arr[middle] = elem;
         ++size;
         ++tail;
         if (size % 2 == 0) {
             middle = head + size / 2;
         } else {
             middle = head + size / 2 + 1;
         }
     }
};
int main() {
    Qeuee q;
    string com;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        int driver;
        cin >> com;
        if (com == "+") {
            cin >> driver;
            q.Push(driver);
        }
        if (com == "*") {
            cin >> driver;
            q.Push_mid(driver);
        }
        if (com == "-") {
            cout << q.Pop() << '\n';
        }
    }
}
