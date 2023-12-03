#include <iostream>
#include <string>

using namespace std;

class User{
public:
//Attributes of user
string name; //For now only keeping it to name, we can later expand it according to our needs
User(){}
User(string s){
    name = s;
}
void set_name(string s){
    name = s;
}
string get_name(){
    return name;
}
};

void User_interface(User obj){
    cout<<"Welcome to the most optimized Flight reservation system ever : Mr/Mrs "<<obj.name<<endl;
    string src,dest;
    cout<<"Please enter your current location : ";
    cin>>src;
    cout<<"Please enter your destination : ";
    cin>>dest;
    int priority;
    cout<<"Select your prefered priority while travelling:\n";
    cout<<"1.Cost\t2.Time\n";
    cin>>priority;
    //Here we will show the available flights based on the choose priority by the user
}
int main() {
    User u1("Sadiq");
    User_interface(u1);
    return 0;
}