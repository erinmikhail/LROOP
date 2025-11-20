#include <iostream>
#include "fix_memory_res.h"
#include "stack.h"

using namespace std;

struct ComplexType {
    int id;
    double value;
    string name;

    ComplexType(int i, double v, const string& n) 
        : id(i), value(v), name(n) {}

    friend ostream& operator<<(ostream& os, const ComplexType& obj) {
        return os << "ComplexType{id=" << obj.id 
                  << ", value=" << obj.value 
                  << ", name=\"" << obj.name << "\"}";
    }
};

void demo_simple_types() {
    cout << "=== DEMO WITH SIMPLE TYPES (int) ===\n";
    
    FixedMemoryResource memory_resource(256);
    Stack<int> stack(&memory_resource);
    
    for (int i = 1; i <= 3; ++i) {
        stack.push(i * 10);
        cout << "Pushed: " << i * 10 << endl;
    }
    
    cout << "\nStack size: " << stack.size() << endl;
    cout << "Memory used: " << memory_resource.get_used_size() 
              << "/" << memory_resource.get_total_size() << " bytes\n";
    
    cout << "Stack contents (using iterator): ";
    for (auto it = stack.begin(); it != stack.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    while (!stack.empty()) {
        cout << "Popped: " << stack.top() << endl;
        stack.pop();
    }
    
    cout << "After popping all - Memory used: " << memory_resource.get_used_size() 
              << "/" << memory_resource.get_total_size() << " bytes\n";
}

void demo_memory_reuse_with_reset() {
    cout << "\n=== DEMO MEMORY REUSE WITH RESET ===\n";
    
    FixedMemoryResource memory_resource(512);
    
    {
        Stack<int> stack1(&memory_resource);
        stack1.push(100);
        stack1.push(200);
        stack1.push(300);
        
        cout << "First stack - Memory used: " << memory_resource.get_used_size() 
                  << "/" << memory_resource.get_total_size() << " bytes\n";
    }
    
    cout << "After first stack destruction - Memory used: " << memory_resource.get_used_size() 
              << "/" << memory_resource.get_total_size() << " bytes\n";
    
    memory_resource.reset();
    
    {
        Stack<int> stack2(&memory_resource);
        stack2.push(400);
        stack2.push(500);
        
        cout << "Second stack - Memory used: " << memory_resource.get_used_size() 
                  << "/" << memory_resource.get_total_size() << " bytes\n";
        
        cout << "Second stack contents: ";
        for (const auto& item : stack2) {
            cout << item << " ";
        }
        cout << endl;
    }
}

void demo_complex_types() {
    cout << "\n=== DEMO WITH COMPLEX TYPES ===\n";
    
    FixedMemoryResource memory_resource(1024);
    Stack<ComplexType> stack(&memory_resource);
    
    stack.push(ComplexType(1, 3.14, "Pi"));
    stack.push(ComplexType(2, 2.71, "Euler"));
    
    cout << "Stack size: " << stack.size() << endl;
    cout << "Memory used: " << memory_resource.get_used_size() 
              << "/" << memory_resource.get_total_size() << " bytes\n";
    
    cout << "Stack contents:\n";
    for (const auto& item : stack) {
        cout << "  " << item << endl;
    }
}

int main() {
    try {
        demo_simple_types();
        demo_memory_reuse_with_reset();
        demo_complex_types();
        
        cout << "\nAll demonstrations completed successfully!\n";
        return 0;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}