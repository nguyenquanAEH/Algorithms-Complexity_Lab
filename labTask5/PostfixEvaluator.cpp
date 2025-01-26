#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

// 1) A simple array-based stack
template <typename T, int MAX_SIZE>
class Stack {
private:
    T arr[MAX_SIZE];
    int topIndex;
public:
    // Constructor
    Stack() : topIndex(-1) {}

    // Push a new element onto the stack
    void push(const T& element) {
        if (topIndex == MAX_SIZE - 1) {
            throw std::overflow_error("Stack is full");
        }
        arr[++topIndex] = element;
    }

    // Pop the top element from the stack
    T pop() {
        if (topIndex == -1) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[topIndex--];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return (topIndex == -1);
    }

    // Return how many elements are in the stack
    int size() const {
        return (topIndex + 1);
    }
};

// Helper function to check if a token is an operator
bool isOperator(const std::string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

int main()
{
    // Prompt the user for input
    std::cout << "Enter a postfix expression (e.g., '2 3 + 4 *'): ";
    std::string inputLine;
    std::getline(std::cin, inputLine); // read the entire line

    // Prepare a string stream to split into tokens
    std::istringstream ss(inputLine);

    // Create the stack (capacity of 100)
    Stack<int, 100> stack;

    // Read tokens one by one
    std::string token;
    while (ss >> token) {
        // If it's an operator, pop two operands and apply
        if (isOperator(token)) {
            if (stack.size() < 2) {
                std::cerr << "Error: not enough operands for operator '" << token << "'.\n";
                return 1; // exit with error
            }
            int rightOperand = stack.pop();
            int leftOperand = stack.pop();

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
                    return 1; // exit with error
                }
                result = leftOperand / rightOperand; // integer division
            }
            // Push the result back
            stack.push(result);
        }
        else {
            // Otherwise, we assume it's an integer
            try {
                int number = std::stoi(token);
                stack.push(number);
            }
            catch (...) {
                std::cerr << "Error: invalid token '" << token << "'.\n";
                return 1; // exit with error
            }
        }
    }

    // After processing all tokens, there should be exactly one number on the stack
    if (stack.size() != 1) {
        std::cerr << "Error: invalid postfix expression. Stack size = "
            << stack.size() << "\n";
        return 1;
    }

    // The final value on the stack is our result
    int finalResult = stack.pop();
    std::cout << "Result = " << finalResult << std::endl;

    // Pause for user to see the result (optional on some systems)
    // system("pause"); // Uncomment if you want to pause the console window

    return 0;
}
