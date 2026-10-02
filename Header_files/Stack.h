class Stack {
public:
    int top;
    int *a;
    int max;

    Stack() {
        max = 100;
        top = -1;
        a = new int[100];
    }

    Stack(int size) {
        max = size;
        top = -1;
        a = new int[size];
    }

    void push(int x) {
        if (top == max - 1) {
            cout << "OVERFLOW\n";
            return;
        }
        top++;
        a[top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "UNDERFLOW\n";
            return;
        }
        top--;
    }

    int Top() {
        if (top == -1) {
            return -1;
        }
        return a[top];
    }
};
