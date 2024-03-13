// Friend function and Friend class
//1.keyword "friend" is used to make some(function or class) as friend of your class
//2.it can access private/public/protected data member or member function of another class.
//3.function cannot become friend of another function
//4.class cannot become friend of function
//5.friendship is not mutual.if a class A is friend of B,then B doesn't become friend of A automatically
//6.friendhip is not inherited  

#include <iostream>
using namespace std;
 
class base {
private:
    int private_variable;
 
protected:
    int protected_variable;
 
public:
    base()
    {private_variable = 0;
    protected_variable = 0;}
    base(int x,int y){
      private_variable = x;
    protected_variable = y;
    }
     
    
    friend void friendFunction(base& obj);
};
 
 
void friendFunction(base& obj)
{
    cout << "Private Variable: " << obj.private_variable
         << endl;
    cout << "Protected Variable: " << obj.protected_variable<<endl;
}
 

int main()
{
    base object1;
    base object2(2,3);
    friendFunction(object1);
    friendFunction(object2);
 
    return 0;
}