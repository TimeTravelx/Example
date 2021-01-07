/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/demo/template_demo.cpp
 * @Date: 2021-01-07 11:17:47
 * @Description: 探索一下 template & class
 */

template<class Type>
class Stack
{
public:
    Stack() {}
    ~Stack() {}
    
    enum {MAX=10};
    
    bool isempty() {}
    bool isfull() {}
    bool push(const Type& item) {}
    bool pop(Type& item) {}

private:
    Type items[MAX]; 
};

class HStack : public Stack
{
public:
    HStack() {}
    ~HStack() {}
};

int main() 
{

    return;
}