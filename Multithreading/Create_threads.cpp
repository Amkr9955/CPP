//1.Function pointer thread
// void fun(int x){
//     while(x-->0){
//         cout<<x<<endl;
//     }
// }
// int main(){
//     std::thread t1(fun,11);
//     std::thread t2(fun,10);
//     t1.join();
//     t2.join();
//     return 0;

// }

//2.lamda function thread
// int main(){
   
//     std::thread t1([](intx){
//         while(x-->0){
//             cout<<x<<endl;
//         }
//     },10);
//     t1.join();
//     return 0;

// }

//3.functors thread(functor object) //operator overlaod
// class Base{
//     public:
//     void operator ()(int x){
//         while(x-->0){
//           cout<<x<<endl;
//         }
//     }
// };
// int main(){
//     std::thread t((Base()),10);
//     t.join();
//     return 0;
// }


//4.Non-static member function
// class Base{
//     public:
//     void run(int x){
//         while(x-->0){
//           cout<<x<<endl;
//         }
//     }
// };
// int main(){
//     Base b;
//     std::thread t(&Base::run,&b,10);
//     t.join();
//     return 0;
// }


//5.Static member function
// class Base{
//     public:
//     void run(int x){
//         while(x-->0){
//           cout<<x<<endl;
//         }
//     }
// };
// int main(){
//  
//     std::thread t(&Base::run,10);
//     t.join();
//     return 0;
// }