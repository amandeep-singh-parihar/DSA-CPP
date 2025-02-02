// #include <bits/stdc++.h>
// using namespace std;
// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();
// DATA ABSTRACTION
//  #include <bits/stdc++.h>
//  using namespace std;
//  static const bool __boost = []()
//  {
//      cin.tie(nullptr);
//      cout.tie(nullptr);
//      return ios_base::sync_with_stdio(false);
//  }();

// class shape
// {
// public:
//     virtual double area() = 0;
// };

// class circle : public shape
// {
// private:
//     double radius;

// public:
//     circle(double radius)
//     {
//         this->radius = radius;
//     }
//     double area() override
//     {
//         return 3.14 * radius * radius;
//     }
// };

// class rectangle : public shape
// {
// private:
//     int width, length;

// public:
//     rectangle(int width, int length)
//     {
//         this->width = width;
//         this->length = length;
//     }

//     double area() override
//     {
//         return width * length;
//     }
// };

// int main()
// {
//     shape *s1 = new circle(1);
//     shape *s2 = new rectangle(1, 2);
//     cout << s1->area() << endl;
//     cout << s2->area() << endl;
//     return 0;
// }

// ENCAPSULATION
//  #include<bits/stdc++.h>
//  using namespace std;
//  static const bool __boost = []()
//  {
//      cin.tie(nullptr);
//      cout.tie(nullptr);
//      return ios_base::sync_with_stdio(false);
//  }();

// class person{
//     private:
//         int age;

//     public:
//         void setAge(int a)
//         {
//             if(a>0)
//             {
//                 age=a;
//             }
//         }

//         int getAge(){
//             return age;
//         }
// };

// int main()
// {
//     person p1;
//     p1.setAge(10);
//     cout<<p1.getAge()<<endl;
//     return 0;
// }

// INHERITANCE
//  #include<bits/stdc++.h>
//  using namespace std;
//  static const bool __boost = []()
//  {
//      cin.tie(nullptr);
//      cout.tie(nullptr);
//      return ios_base::sync_with_stdio(false);
//  }();

// class animal{
//     public:
//         void eat(){
//             cout<<"this animal eats food"<<endl;
//         }
// };

// class dog:public animal{
//     public:
//         void bark(){
//             cout<<"the dog barks"<<endl;
//         }
// };

// int main()
// {
//     dog myDog;
//     myDog.bark();
//     myDog.eat();
//     return 0;
// }

// METHOD OVERRIDING -> RUNTIME POLYMORPHISM
//  #include<bits/stdc++.h>
//  using namespace std;
//  static const bool __boost = []()
//  {
//      cin.tie(nullptr);
//      cout.tie(nullptr);
//      return ios_base::sync_with_stdio(false);
//  }();

// class animal{
//     public:
//         virtual void sound(){
//             cout<<"some animal sound!"<<endl;
//         }
// };

// class dog:public animal{
//     public:
//         void sound() override{
//             cout<<"dog barks!"<<endl;
//         }
// };

// class cat:public animal{
//     public:
//     void sound() override{
//         cout<<"cat meows!"<<endl;
//     }
// };

// int main()
// {
//     animal* a1=new dog;
//     animal* a2=new cat;
//     a2->sound();
//     a1->sound();
//     return 0;
// }

// METHOD OVERLOADING -> COMPILE TIME POLYMORPHISM
//  #include<bits/stdc++.h>
//  using namespace std;
//  static const bool __boost = []()
//  {
//      cin.tie(nullptr);
//      cout.tie(nullptr);
//      return ios_base::sync_with_stdio(false);
//  }();

// class A{
//     public:
//         void print(int i)
//         {
//             cout<<"Integer : "<<i<<endl;
//         }

//         void print(double d)
//         {
//             cout<<"Double : "<<d<<endl;
//         }

//         void print(string s)
//         {
//             cout<<"String : "<<s<<endl;
//         }
// };

// int main()
// {
//     A a;
//     a.print(15);
//     a.print(123.311);
//     a.print("amandeep singh parihar");
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();

// class example
// {
// public:
//     static int a;
// };
// int example::a;

// class counter{
//     public:
//         static int count;

//     counter(){
//         ++count;
//     }
// };
// int counter::count;

// class Test{
//     public:
//         static int x;

// };

// int Test::x;

// int main()
// {
//     cout<<Test::x<<endl;
//     Test::x=10;
//     cout<<Test::x<<endl;
//     // example ex;
//     // ex.a = 10;
//     // cout << ex.a << endl;
//     // counter count;
//     // counter a,b,c;
//     // cout<<counter::count<<endl;
//     return 0;
// }

// class Test
// {
// public:
//     static int x;

//     static void display()
//     {
//         cout << "value of x : " << x << endl;
//     }
// };

// int Test::x;

// int_fast32_t main()
// {
//     // cout<<"a";
//     Test::display();
//     Test::x = 20;
//     Test::display();
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();

// class node{
// public:
//     int data;
//     node* next;
//     node(int data){
//         this->data=data;
//         this->next=NULL;
//     }

//     node(){
//         this->data=0;
//         this->next=NULL;
//     }
// };

// void print(node* head)
// {
//     node* temp=head;
//     while(temp!=NULL)
//     {
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
// }

// int main()
// {
//     node* first=new node(10);
//     node* second=new node(20);
//     node* third=new node(30);
//     first->next=second;
//     second->next=third;
//     print(first);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();
// int main()
// {
//     cout<<"ha";
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();

// class student{
//     private:
//         string name;
//         int age;
//     public:
//         student(string name,int age){
//             this->name=name;
//             this->age=age;
//         }
//         void display(){
//             cout<<"Name : "<<name<<" Age : "<<age<<endl;
//         }
// };
// int main()
// {
//     student s("amandeep",20);
//     s.display();
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();

// class x{
//     private:
//         int *age;
//     public:
//         // x()
//         // {
//         //     cout<<"default construtor is called"<<endl;
//         // }
//         // x(const x&obj)
//         // {
//         //     cout<<"copy cnostrutor is called"<<endl;
//         // }
//         // x(string name="Unknown"){
//         //     cout<<"Hello "<<name<<"!"<<endl;
//         // }
//         x(int a)
//         {
//             age=new int(a);
//             cout<<"Age : "<<a<<endl;
//         }
//         ~x(){
//             delete age;
//         }
// };

// int main()
// {
//     // x a("amandeep");
//     // x b;
//     // x a=b;
//     // x a;
//     x a(21);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();

// class Box{
//     private:
//         int length;
//     public:
//         Box(int length)
//         {
//             this->length=length;
//         }

//         friend void printLength(Box b);
// };

// void printLength(Box b){
//     cout<<"The length of the box is : "<<b.length<<endl;
// }

// int main()
// {
//     Box b(10);
//     printLength(b);
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();

// class student
// {
// private:
//     string name;
//     int age;

// public:
//     student(string name = "Unknown", int age = 0)
//     {
//         this->name = name;
//         this->age = age;
//     }

//     void display()
//     {
//         cout << "Name : " << name << ", Age : " << age << endl;
//     }
// };

// int main()
// {
//     student s[3] = {
//         student("amandeep", 21),
//         student("abhay", 22),
//         student(),
//     };
//     for (int i = 0; i < 3; ++i){
//         s[i].display();
//     }
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();

// class base{
//     public:
//         void display()
//         {
//             cout<<"this is base class"<<endl;
//         }
// };

// class derive : public base{
//     public:
//         void display()
//         {
//             cout<<"this is derive class"<<endl;
//         }

//         void show(){
//             base::display();
//             display();
//         }

// };

// int main()
// {
//     derive d1;
//     d1.show();
//     return 0;
// }
// int main()
// {
//     int a=30;
//     const int b=20;
//     int *ptr=&a;
//     const int *ptrToConst=&b;
//     int *const constPtr=&a;

//     //void pointer
//     void *voidPtr;
//     voidPtr=&a;
//     cout<<*(int*)voidPtr<<endl;
//     cout<<sizeof(voidPtr)<<endl;
//     return 0;
// }

// class a
// {
// public:
//     int val;
//     int operator*(a&obj2){
//         int value1=this->val;
//         int value2=obj2.val;
//         cout<<(value1/value2)<<endl;
//     }
// };

// int main()
// {
//     a x,y;
//     x.val=10;
//     y.val=100;
//     y*x;
//     return 0;
// }

// class shape
// {
// public:
//     virtual void area() = 0;
// };

// class circle : public shape
// {
// private:
//     float radius;

// public:
//     circle(float r)
//     {
//         radius = r;
//     }
//     void area() override
//     {
//         cout << "Circle Area : " << 3.14 * radius * radius << endl;
//     }
// };

// class Rectangle : public shape
// {
//     float length, breadth;

// public:
//     Rectangle(float l, float b) : length(l), breadth(b) {}
//     void area() override
//     {
//         cout << "Rectangle Area: " << length * breadth << endl;
//     }
// };

// int main()
// {
//     circle c(5);
//     Rectangle r(4, 6);
//     shape *shape1 = &c;
//     shape *shape2 = &r;
//     shape1->area();
//     shape2->area();
//     return 0;
// }
// #include<bits/stdc++.h>>
// using namespace std;
// namespace first
// {
//     void display(){
//         cout<<"First"<<endl;
//     }
// }
// namespace second{
//     void display(){
//         cout<<"Second"<<endl;
//     }
// }
// using namespace second;
// // #define what 1.4;
// int main(){
//     int _Oka=15;
//     display();
//     const float PI=3.14;
//     // PI+=PI;
//     // what=4;

//     return 0;
// // }
// enum Days{sun,mon,tues,wed};
// int main(){
//     Days today=wed;
//     cout<<today<<endl;
// }

// inline int sq(int x) { return x * x; }

// int main()
// {
//     int num=-10;
//     cout<<sq(num)<<endl;
//     return 0;
// }
// #define ll long long
// #define square(x) ((x) * (x))
// int main()
// {
//     ll a = 15;
//     cout << square(a) << endl;
// }

// int main()
// {
//     double pi = 3.14159;
//     int ans=(int)pi;
//     cout<<ans<<endl;
// }
// class Engine{
//     public:
//         void start(){
//             cout<<"Enging starts"<<endl;
//         }
// };

// class car{
//     private:
//         Engine engine;
//     public:
//         void startCar(){
//             cout<<"Car starts"<<endl;
//         }
// };

// int main(){
//     car c;
//     c.startCar();
// }

// void modify(int &x){
//     x=20;
//     cout<<"inside function : "<<x<<endl;
// }

// int main(){
//     int a=-11;
//     cout<<a<<endl;
//     modify(a);
//     cout<<a<<endl;
// }
// class param{
//     public:
//         int val;

//         friend void operator+(param&obj1,param&obj2);
// };

// // void operator+(param&obj1,param&obj2){
// //     int value1=obj1.val;
// //     int value2=obj2.val;
// //     cout<<(value1-value2)<<endl;
// // }

// // int main(){
// //     param a,b;
// //     a.val=100;
// //     b.val=10;
// //     a+b;
// //     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;
// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();

// void starPattern(int n)
// {
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = 0; j < i; ++j)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;
//     starPattern(n);
//     return 0;
// }