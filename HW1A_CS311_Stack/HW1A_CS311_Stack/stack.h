#ifndef stack_h
#define stack_h


const int MAX = 10;
typedef char el_t;


class stack{
    
private:
    el_t el[MAX];
    int top;
    
public:
    stack();
    ~stack();
    bool isEmpty();
    bool isFull();
    void push(el_t);
    void pop(el_t&);
    void displayAll();
    void topElem(el_t&);
    void clearIt();
   
    
    class Overflow{};
    class Underflow{};
    
};


#endif /* stack_h */
