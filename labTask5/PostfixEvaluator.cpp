#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

// 1) Array-based stack template
template <typename T, int MAX_SIZE>
class Stack {
private:
    T arr[MAX_SIZE];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    void push(const T& element) {
        if (isFull()) {
            throw std::overflow_error("Stack is full");
        }
        arr[++topIndex] = element;
    }

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[topIndex--];
    }

    bool isEmpty() const {
        return (topIndex == -1);
    }

    bool isFull() const {
        return (topIndex == MAX_SIZE - 1);
    }

    int size() const {
        return (topIndex + 1);
    }
};

int main()
{
    // 2) Read the entire postfix expression from user input
    std::cout << "Enter a postfix expression (e.g. '10 4 + 2 * 3 -'): ";
    std::string input;
    std::getline(std::cin, input);

    // 3) Use stringstream to break the expression into tokens
    std::stringstream ss(input);

    // Create a stack for integer operands
    Stack<int, 100> stack;  // capacity can be adjusted as needed

    std::string token;
    while (ss >> token)
    {
        // 4) Check if the token is an operator or a number
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Pop top two elements
            if (stack.size() < 2) {
                std::cerr << "Error: not enough operands for operator '" << token << "'.\n";
                return 1; // Exit with error
            }
            int rightOperand = stack.pop();
            int leftOperand = stack.pop();

            // Apply the operator
            int result = 0;
            if (token == "+") {
                result = leftOperand + rightOperand;
            }
            else if (token == "-") {
                result = leftOperand - rightOperand;
            }
            else if (token == "*") {
                result = leftOperand * rightOperand;
            }
            else if (token == "/") {
                if (rightOperand == 0) {
                    std::cerr << "Error: division by zero.\n";
                    return 1; // Exit with error
                }
                // integer division
                result = leftOperand / rightOperand;
            }
            // Push the result back onto the stack
            stack.push(result);
        }
        else {
            // 5) Otherwise, assume it's a number
            try {
                int number = std::stoi(token);
                stack.push(number);
            }
            catch (std::invalid_argument&) {
                std::cerr << "Invalid token encountered: " << token << "\n";
                return 1; // Exit with error
            }
        }
    }

    // 6) At the end, the stack should have exactly one element (the final result)
    if (stack.size() != 1) {
        std::cerr << "Error: invalid postfix expression. Stack size = "
            << stack.size() << "\n";
        return 1;
    }

    // 7) Get the final result from the stack
    int finalResult = stack.pop();
    std::cout << "Result: " << finalResult << std::endl;

    return 0; // success
}
