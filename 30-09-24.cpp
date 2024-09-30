class CustomStack {
private:
    list<int> stack;
    int maxSize;

public:
    CustomStack(int maxSize) { this->maxSize = maxSize; }

    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    int pop() {
        if (stack.empty()) return -1;
        int topElement = stack.back();
        stack.pop_back();
        return topElement;
    }

    void increment(int k, int val) {
        auto it = stack.begin();
        for (int i = 0; i < k && it != stack.end(); i++, it++) {
            *it += val;
        }
    }
};