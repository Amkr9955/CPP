#include<string>
#include<iostream>

using namespace std;

class Phone{
   private:
   string p_name;
   string p_number;

   public:

   Phone(string name,string number){
       p_name=name;
       p_number=number;
   }

   void makeCall(){
     cout<<"Making call Using "<<p_name<<endl;
   }

   void receiveCall(){
     cout<<"Receiving call Using "<<p_name<<endl;
   }
};

int main(){
    Phone iphone("Iphone","9955");
    iphone.makeCall();
    iphone.receiveCall();
    return 0;
}