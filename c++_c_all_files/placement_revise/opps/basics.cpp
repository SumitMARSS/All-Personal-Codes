#include <bits/stdc++.h>

#include "demo.cpp"  //just to get access of other file's class into the file

using namespace std;

class hero{

    int health;
    public:

    static int timetocompete; //define


    char level;
    hero(){
        cout<<"Defautl constructor called "<<endl;
    }
    hero(int h){
        cout<<"this -> "<<this<<endl;
        this->health = h;
        cout<<"parameterised constructor called with health only "<<endl;
    }
    hero(int h,char ch){
        cout<<"this -> "<<this<<endl;
        this->level = ch;
        this->health = h;
        cout<<"parameterised constructor called with health and level both "<<endl;
    }
    hero(hero &temp){
        this->health = temp.health;
        this->level = temp.level;
        cout<<" copy constructor called "<<endl;
    }
    int gethealth(){
        return health;
    }
    void sethealth(int h){
        this->health = h;
    }
    void print(){
        cout<<"Health -> "<<this->health <<endl;
        cout<<"Level -> "<<this->level<<endl;
    }
    static int random(){
        return timetocompete;
    }
    ~hero(){
        cout<<"  Destructor callled  "<<endl;
    }
};

//initialization 
int hero::timetocompete = 5;

int main(){

    //always prefered
    cout<<"Time to compete -> "<<hero::timetocompete<<endl;
    cout<<"Time to compete checking static function -> "<<hero::random()<<endl; //only static members are allowed
    //static object
    cout<<"***************************"<<endl;
    hero s (100,'B');
    cout<<"s time -> "<<s.timetocompete<<endl;  //not prefered to access through object
    s.print();
    cout<<"*************  copy constructor **************"<<endl;
    //copy constructor -> no need to make in class as it is auto generated
    hero p(s);
    p.print();
    cout<<"***************************"<<endl;
    //copy assignment operator
    hero l(200,'c');
    l=s;
    l.print();
    //for 3 static object destructor will be called

    //dynamic object
    hero *h = new hero(50,'D');
    h->print();
    cout<<"************  copy constructor ***************"<<endl;
    //copy constructor -> no need to make in class as it is auto generated
    hero *k = new hero(*h);
    k->print();
    cout<<"***************************"<<endl;
    //for dynamic object destructor will be manually called
    cout<<"***************************"<<endl;
    cout<<"For dynamic deallocation of memory : -> "<<endl;
    delete h;
    delete k;
    cout<<"***************************"<<endl;
    
    

}








// int main(){

//     //parameterised constructor called

//     //statically object creation
//     cout<<"***************************"<<endl;
//     hero h1(10);
//     cout<<"Address of h1 object -> "<<&h1<<endl;
//     cout<<"h1 health is -> "<<h1.gethealth()<<endl;
//     cout<<"***************************"<<endl;
//     //dynamically object creation
//     hero *h2 = new hero(100);
//     cout<<"Address of h2 object -> "<<h2<<endl;
//     cout<<"h2 health is -> "<<h2->gethealth()<<endl;
//     cout<<"***************************"<<endl;
//     //dynamically object creation
//     hero *h4 = new hero(100,'X');
//     cout<<"Address of h4 object -> "<<h4<<endl;
//     cout<<"h4 health is -> "<<h4->gethealth()<<endl;
//     cout<<"h4 level is -> "<<h4->level<<endl;
//     cout<<"***************************"<<endl;

//     //default constructor called
//     hero *h3 = new hero();
//     cout<<"Address of h3 object -> "<<h3<<endl;
//     cout<<"h3 health is -> "<<h3->gethealth()<<endl;
//     cout<<"***************************"<<endl;

// }





// //class -> a blueprint of an object
// //size of class is same as (size of total properties)

// class hero{
//     //default all properties are set as private 
//     private: //no need default
//     int health; //having int so class size is of 4

//     //so to get access we have to make it public
//     public:
//     char level;

//     int gethealth(){
//         return health;
//     }
//     void setHealth(int h){
//         health = h;
//         //we can make some condn also like  if password = "smsks" then only set
//     }

// };

// int main(){

//     //static allocation of object

//     hero h1; //make an object on hero's class blueprint
//     cout<<"Size of h1 object -> "<<sizeof(h1)<<endl;
//     demo d1; //1 just for identification purpose
//     cout<<"Size of d1 object -> "<<sizeof(d1)<<endl;  //1 just to keep track on that class having no properties

//     hero remesh;
//     remesh.level = 'a';
//     //using getter and setter to get access private properties
//     remesh.setHealth(70); //setter
//     cout<<"Health of ramesh: -> "<<remesh.gethealth()<<endl; //getter
//     //public direct access
//     cout<<"level of ramesh: -> "<<remesh.level<<endl;

//     //dynamic allocation of object

//     hero *ram = new hero;

//     //setting values
//     ram->level = 'B';
//     ram->setHealth(80);

//     //Approch 1 to get access as ram is a pointer pointing an address so first we have to dereference it

//     // cout<<"Health of ram: -> "<<(*ram).gethealth()<<endl; //getter
//     // //public direct access
//     // cout<<"level of ram: -> "<<(*ram).level<<endl;

//     //Approch 2
//     cout<<"Health of ram: -> "<<ram->gethealth()<<endl; //getter
//     //public direct access
//     cout<<"level of ram: -> "<<ram->level<<endl;

// }