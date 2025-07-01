#include <bits/stdc++.h>
using namespace std;

struct Node {
    int d;
    Node* next;
};

Node* create_node(int d) {
    Node* node = new Node();
    node->d = d;
    node->next = nullptr;
    return node;
}

// Insert each character of the string into the linked list (in reverse order)
// Also prints the number of iterations (counter)
void insert(string a, Node* &head) {
    int counterInsert = 0;
    for (int i = 0; i < a.length(); i++) {
        counterInsert++;
        Node* ptr = create_node(a[i] - '0');
        ptr->next = head;
        head = ptr;
    }
    cout << "Insert iterations: " << counterInsert << endl;
}

void print(Node* ptr) {
    while(ptr != nullptr) {
        cout << ptr->d << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Adds two numbers represented by linked lists
int add(Node* ptr1, Node* ptr2) {
    int c = 0, val = 0, ans = 0, m = 1, a = 0, p1, p2;
    int counterAdd = 0;
    while(ptr1 != nullptr || ptr2 != nullptr || c) {
        counterAdd++;
        if(ptr1 == nullptr)
            p1 = 0;
        else {
            p1 = ptr1->d;
            ptr1 = ptr1->next;
        }
        if(ptr2 == nullptr)
            p2 = 0;
        else {
            p2 = ptr2->d;
            ptr2 = ptr2->next;
        }
        val = p1 + p2 + c;
        c = val / 10;
        a = val % 10;
        ans = a * m + ans;
        m *= 10;
    }
    cout << "Add iterations: " << counterAdd << endl;
    return ans;
}

// Subtracts the second number from the first (both represented by linked lists)
int sub(Node* ptr1, Node* ptr2) {
    int a = 0, c = 0, val = 0, ans = 0, m = 1, p1, p2, l = 0;
    int counterSub = 0;
    while(ptr1 != nullptr || ptr2 != nullptr) {
        counterSub++;
        if(ptr1 == nullptr)
            p1 = 0;
        else {
            p1 = ptr1->d;
            ptr1 = ptr1->next;
        }
        if(ptr2 == nullptr)
            p2 = 0;
        else {
            p2 = ptr2->d;
            ptr2 = ptr2->next;
        }
        p2 = 9 - p2;
        val = p1 + p2 + c;
        c = val / 10;
        a = val % 10;
        ans = a * m + ans;
        m *= 10;
        l++;
    }
    // Adjustment phase for final carry/borrow
    if(c) {
        ans++;
    } else {
        m = 1;
        a = 0;
        for(int i = 0; i < l; i++) {
            a = 9 * m + a;
            m *= 10;
        }
        ans = ans - a;
    }
    cout << "Sub iterations: " << counterSub << " (plus additional adjustment loop of " << l << " iterations)" << endl;
    return ans;
}

// Multiplies two numbers represented by linked lists
long long mul(Node* ptr1, Node* ptr2) {
    int c = 0, val = 0, m = 1, a = 0, p1, p2, m2 = 1;
    long long f = 0, ans = 0;
    Node* head = ptr1;
    int counterMulOuter = 0, counterMulInner = 0;
    while(ptr2 != nullptr) {
        counterMulOuter++;
        ptr1 = head;
        p2 = ptr2->d;
        m = 1;
        ans = 0;
        c = 0; // reset carry for inner loop
        while(ptr1 != nullptr || c) {
            counterMulInner++;
            if(ptr1 != nullptr) {
                p1 = ptr1->d;
                ptr1 = ptr1->next;
            } else {
                p1 = 0;
            }
            val = p1 * p2 + c;
            c = val / 10;
            a = val % 10;
            ans = a * m + ans;
            m *= 10;
        }
        f = ans * m2 + f;
        ptr2 = ptr2->next;
        m2 *= 10;
    }
    cout << "Mul outer iterations: " << counterMulOuter 
         << ", inner iterations: " << counterMulInner << endl;
    return f;
}

// Exponentiation: computes (base)^(exponent) where base is represented by ptr1 and exponent by ptr2
long long expo(Node* ptr1, Node* ptr2) {
    int m = 1, p2;
    long long ans = 1, a = 0;
    int counterExpoOuter = 0, counterExpoInner = 0;
    while(ptr2 != nullptr) {
        counterExpoOuter++;
        p2 = ptr2->d;
        // Scale the digit by its positional weight.
        p2 = p2 * m;
        // Create a node representing the number 1.
        Node* node = create_node(1);
        // Multiply 'ans' by (base) p2 times.
        while(p2--) {
            counterExpoInner++;
            a = mul(ptr1, node);
            ans *= a;
        }
        m *= 10;
        ptr2 = ptr2->next;
    }
    cout << "Expo outer iterations: " << counterExpoOuter 
         << ", inner iterations: " << counterExpoInner << endl;
    return ans;
}

int main() {
    string a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    
    insert(a, head1);
    insert(b, head2);
    
    cout << "Number 1 (stored in reverse order): ";
    print(head1);
    cout << "Number 2 (stored in reverse order): ";
    print(head2);
    int choice;
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Exponentiation" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                int addition = add(head1, head2);
                cout << a << " + " << b << " = " << addition << endl;
                break;
            }
            case 2: {
                int subtraction = sub(head1, head2);
                cout << a << " - " << b << " = " << subtraction << endl;
                break;
            }
            case 3: {
                long long multiplication = mul(head1, head2);
                cout << a << " * " << b << " = " << multiplication << endl;
                break;
            }
            case 4: {
                long long exponentiation = expo(head1, head2);
                cout << a << " ^ " << b << " = " << exponentiation << endl;
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}
