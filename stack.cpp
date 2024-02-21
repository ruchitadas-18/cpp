#include <iostream>

class Stack{
    private:
    int store[6];
    public: 
    int top;

    Stack(){ top = 0; }

    void push(int val){
        store[++top] = val;
    }
    int pop(){
        return store[top--];
    }

    int ifFull(){
        top--;
        return store[top++];
    }

};

class BugFix : public Stack{

    public: 
    void push(int x){
        if(top<5){
            Stack::push(x);
        }
    }

    int pop(){
        if(top<=0){
            std::cout<<"Stack is empty"<<std::endl;
        }else{
            return Stack::pop();
        }
        return 0;
    }
};

class BugComposition{
    public: 
    Stack stack;
    BugComposition(Stack stack): stack(stack){}

    void push(int x){
        if(stack.top<5){
            stack.push(x);
        }
    }

    int pop(){
        if(stack.top<=0){
            std::cout<<"Stack is empty"<<std::endl;
        }else{
            return stack.pop();
        }
        return 0;
    }
};


int main(){
    Stack stack; // object of the class
    //BugFix s; // using inheritance
    BugComposition s(stack); //composition
    s.push(10);
    s.push(20);
    s.push(450);
    s.push(50);
    s.push(60);
    s.push(80);
    s.push(10);
    s.push(90);
    s.push(100);

    
    std::cout<<s.pop()<<std::endl;
    std::cout<<s.pop()<<std::endl;
    std::cout<<s.pop()<<std::endl;
    std::cout<<s.pop()<<std::endl;
    std::cout<<s.pop()<<std::endl;
    return 0;
}