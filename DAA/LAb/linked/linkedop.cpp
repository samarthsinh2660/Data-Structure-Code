#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* crtlink(int x) {
    // Create a linked list from the integer, storing digits in reverse order.
    if (x == 0) {
        return createNode(0);
    }
    Node* head = createNode(x % 10);
    x /= 10;
    Node* temp = head;
    while (x > 0) {
        int tempVal = x % 10;
        x /= 10;
        temp->next = createNode(tempVal);
        temp = temp->next;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}


Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* sum(Node* a, Node* b) {
    int carry = 0, s;
    int counterSum = 0;
    Node* result = nullptr;
    Node* temp = nullptr;
    while (a != nullptr || b != nullptr || carry) {
        counterSum++;
        s = carry;
        if (a != nullptr) {
            s += a->data;
            a = a->next;
        }
        if (b != nullptr) {
            s += b->data;
            b = b->next;
        }
        Node* newNode = createNode(s % 10);
        carry = s / 10;
        if (result == nullptr) {
            result = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    cout << "Total addition iterations: " << counterSum << endl;
    return result;
}

Node* sub(Node* a, Node* b) {
    int carry = 0, s;
    int counterSub = 0;
    Node* result = nullptr;
    Node* temp = nullptr;
    while (a != nullptr || b != nullptr || carry) {
        counterSub++;
        s = 0;
        s -= carry;
        if (a != nullptr) {
            s += a->data;
            a = a->next;
        }
        if (b != nullptr) {
            s -= b->data;
            b = b->next;
        }
        if (s < 0) {
            s += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        Node* newNode = createNode(s % 10);
        if (result == nullptr) {
            result = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    cout << "Total subtraction iterations: " << counterSub << endl;
    return result;
}

Node* mult(Node* a, Node* b) {
    int positionA = 0, ta = 0;
    int counterMultOuter = 0;
    int counterMultInner = 0;
    while (a != nullptr) {
        counterMultOuter++;
        int carry = 0, positionB = 0;
        int tb = 0;
        Node* tempB = b;
        while (tempB != nullptr) {
            counterMultInner++;
            int mulVal = a->data * tempB->data + carry;
            carry = mulVal / 10;
            mulVal %= 10;
            // Adjust for the current position in B
            for (int i = 0; i < positionB; i++) {
                mulVal *= 10;
            }
            tb += mulVal;
            tempB = tempB->next;
            positionB++;
        }
        if (carry > 0) {
            for (int i = 0; i < positionB; i++) {
                carry *= 10;
            }
            tb += carry;
        }
        // Adjust for the current position in A
        for (int i = 0; i < positionA; i++) {
            tb *= 10;
        }
        ta += tb;
        a = a->next;
        positionA++;
    }
    Node* result = crtlink(ta);
    cout << "Total multiplication iterations: Outer = " << counterMultOuter 
         << ", Inner = " << counterMultInner << endl;
    return result;
}

Node* exponent(Node* a, Node* b) {
    int c = 0;
    int counterExpOuter = 0;
    int counterExpInner = 0;
    Node* result = a;
    while (b != nullptr) {
        counterExpOuter++;
        int n = b->data;
        for (int i = 0; i < c; i++) {
            n *= 10;
        }
        for (int i = 1; i < n; i++) {
            counterExpInner++;
            result = mult(result, a);
        }
        c++;
        b = b->next;
    }
    cout << "Total exponentiation iterations: Outer = " << counterExpOuter 
         << ", Inner = " << counterExpInner << endl;
    return result;
}

int main() {
    int a, b, choice = 0;
    Node* s = nullptr;
    while (choice != 5) {
        cout << "\n----------------------\n";
        cout << "Select the operation you want to perform:\n";
        cout << "1 for Addition\n";
        cout << "2 for Subtraction\n";
        cout << "3 for Multiplication\n";
        cout << "4 for Exponentiation\n";
        cout << "5 for Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        if (choice == 5) break;
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;
        Node* headA = crtlink(a);
        Node* hb = crtlink(b);
        
        switch (choice) {
            case 1:
                s = sum(headA, hb);
                break;
            case 2:
                if (a > b)
                    s = sub(headA, hb);
                else {
                    s = sub(hb, headA);
                    cout << "Result is a negative number." << endl;
                }
                break;
            case 3:
                s = mult(headA, hb);
                break;
            case 4:
                s = exponent(headA, hb);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }

        if (s != nullptr) {
            Node* reversedResult = reverseList(s);
            cout << "Final result (reversed): ";
            printList(reversedResult);
        }
    }
    return 0;
}
