#include <iostream>
#include <string>
#include <vector>
#include "class_Bank_account.h"
#include "Graph.h"
#include "FlightNew.h"
using namespace std;

/*
To do list/workflow:
1. Create a map/graph -- Done!
2. Create flights and tickets -- Done!
3. Ask user details(name,priority,Bank acc etc)
4. Find optimal path using appropriate algorithm
*/


class User{
public:
//Attributes of user
string name; //For now only keeping it to name, we can later expand it according to our needs
Bank_account b1;
User(){}
User(string s,int balance){
    name = s;
    b1.set_balance(balance);
}
void set_name(string s){
    name = s;
}
string get_name(){
    return name;
}
void buy_ticket(){
    //input ticket
    //if bank acc funds available...buy
    //else dont buy
}
};


class admin_control{
    public:
    string name;
    Graph g;
    vector<Flight> flights;
    admin_control(){}
    admin_control(string s){
        name = s;
    }
    void menu(){
        g.graph_menu();
    }
    void set_flights(){
        Flight temp;
        string s;
        int n;
        cout<<"Setting flight\n";
        while(1){
        cout<<"Enter Source : ";
        cin>>s;
        temp.setSource(s);
        cout<<"Enter destination : ";
        cin>>s;
        temp.setDestination(s);
        cout<<"Enter travel time : ";
        cin>>n;
        temp.travel_time = n;
        // cout<<"Flight no. : ";
        // cin>>n;
        // temp.setFlightNumber(n);
        // cout<<"Take off time : ";
        // cin>>n;
        // temp.setTakeOffTime(n);
        // cout<<"Boarding time : ";
        // cin>>n;
        //temp.setBoardingTime(n);
        cout<<"Price of ticket : ";
        cin>>n;
        temp.set_price(n);
        cout<<"Number of tickets : ";
        cin>>n;
        temp.set_num_of_tick(n);
        flights.push_back(temp);
        cout<<"1. Add more flights\t0. Exit\n";
        cin>>n;
        if(n == 0)
        break;
        }
        for(int i=0;i<flights.size();i++){
            flights[i].print_flight();
            cout<<endl;
        }

    }
    void print_purchased_flights(vector<Flight> purchased){
        cout<<"Printing flights purchased : \n";
        for(int i=0;i<purchased.size();i++){
            purchased[i].print_flight();
        }
    }

    void User_interface_better(User obj, Graph g){
        vector<Flight> purchased;
        cout<<"Welcome Mr/Mrs "<<obj.name<<endl;
        int src_id,dest_id;
        string src_name,dest_name;
        //Taking Source
        enter_src_dest:
        cout<<"Enter Source name : ";
        cin>>src_name;
        //Finding ID of given source name
        for(int i=0;i<g.vertices.size();i++){
            if(g.vertices[i].state_name == src_name){
                src_id = g.vertices[i].state_id;
                break;
            }
        }
        //Taking dest
        cout<<"Enter Destination name : ";
        cin>>dest_name;
        //Finding ID
        for(int i=0;i<g.vertices.size();i++){
            if(g.vertices[i].state_name == dest_name){
                dest_id = g.vertices[i].state_id;
                break;
            }
        } 
        int ch_prior;
        cout<<"Enter your priority:\n1.Time\t2.Cost\n";
        cin>>ch_prior;

        if(ch_prior == 1){
        time_priority:    
        vector<int> shortestDistances = g.dijkstraWeight(src_id, dest_id);
        // Print the shortest distance to the dest_id vertex
        cout << "Fastest route from " << src_id << " to " << dest_id << ": " << shortestDistances[dest_id] <<" hrs"<< endl;
        // Print the shortest path
        g.printShortestPathWeight(src_id, dest_id);  //weigth = time
        cout<<endl;
        for(int i=0;i<flights.size();i++){
            //Basic condition for any flight to be printed i.e it has tickets available for sale!
            if(flights[i].number_of_tickets!=0){
                if(flights[i].travel_time <= shortestDistances[dest_id]){
                    cout<<"OPTIMAL FLIGHT FOUND!\n";
                    flights[i].print_flight();
                }
                else{
                    flights[i].print_flight();
                }

            }
                int ch_buy;
                cout<<"Do you want to buy?\n1.Yes\t2.No\n";
                cin>>ch_buy;
                if(ch_buy == 1){
                //verifying amount
                cout<<"Verifying amount...\n";
                cout<<"Bank balance : "<<obj.b1.get_balance()<<" Ticket price : "<<flights[i].price_of_ticket<<endl;
                // amount verified
                if(obj.b1.get_balance() >= flights[i].price_of_ticket){
                    cout<<"Amount verified..Buying Ticket\n";
                    obj.b1.credit_amount(flights[i].price_of_ticket);
                    flights[i].decrement_ticket_if_sold(); 
                    purchased.push_back(flights[i]); //saving all purchased flights
                    int ch_further_opt;
                    cout<<"Now select:\n1.Continue Shopping\t2.Finish\n";
                    cin>>ch_further_opt;
                    if(ch_further_opt == 1){
                        goto enter_src_dest;
                    }
                    else{
                        print_purchased_flights(purchased);
                        exit(1);
                    }
                }
                //Amount not verified
                else{
                    cout<<"Unable to verify amount\n";
                    int ch_amount_unverified;
                    same_options:
                    cout<<"Select options: \n1.Continue displaying more flights\t2.Re-enter src & dest\t3.Exit\n";
                    cin>>ch_amount_unverified;
                    if(ch_amount_unverified == 1){
                        continue;
                    }
                    else if(ch_amount_unverified == 2){
                        goto enter_src_dest;
                    }
                    else{
                        cout<<"Exiting\n";
                        exit(1);
                    }
                }
                }
                //Dont want to buy
                else{
                    goto same_options;
                }
        }
            if(purchased.size() == 0){
                int ch_no_purchase;
                cout<<"You purchased no flights till now\nSelect:\n1. Re-enter src and dest\t2.Swicth priority\t3. Exit\n";
                if(ch_no_purchase == 1){
                    goto enter_src_dest;
                }
                else if(ch_no_purchase == 2){
                    goto cost_priority;
                }
                else{
                    cout<<"Exiting\n";
                    exit(1);
                }
            }
            else{
                cout<<"All available flights displayed\n";
                print_purchased_flights(purchased);
            }            
        }
        else{
        cost_priority:
        vector<int> shortestDistances = g.dijkstraCost(src_id, dest_id);
        // Print the shortest distance to the dest_id vertex
        cout << "Minimum cost from " << src_id << " to " << dest_id << ": " << shortestDistances[dest_id] <<" hrs"<< endl;
        // Print the shortest path
        g.printShortestPathWeight(src_id, dest_id);  //weigth = time
        cout<<endl;

        for(int i=0;i<flights.size();i++){
            //Basic condition for any flight to be printed i.e it has tickets available for sale!
            if(flights[i].number_of_tickets!=0){
                if(flights[i].price_of_ticket <= shortestDistances[dest_id]){
                    cout<<"OPTIMAL FLIGHT FOUND!\n";
                    flights[i].print_flight();
                }
                else{
                    flights[i].print_flight();
                }

            }
                int ch_buy;
                cout<<"Do you want to buy?\n1.Yes\t2.No\n";
                cin>>ch_buy;
                if(ch_buy == 1){
                //verifying amount
                cout<<"Verifying amount...\n";
                cout<<"Bank balance : "<<obj.b1.get_balance()<<" Ticket price : "<<flights[i].price_of_ticket<<endl;
                // amount verified
                if(obj.b1.get_balance() >= flights[i].price_of_ticket){
                    cout<<"Amount verified..Buying Ticket\n";
                    obj.b1.credit_amount(flights[i].price_of_ticket);
                    flights[i].decrement_ticket_if_sold(); 
                    purchased.push_back(flights[i]); //saving all purchased flights
                    int ch_further_opt;
                    cout<<"Now select:\n1.Continue Shopping\t2.Finish\n";
                    cin>>ch_further_opt;
                    if(ch_further_opt == 1){
                        goto enter_src_dest;
                    }
                    else{
                        print_purchased_flights(purchased);
                        exit(1);
                    }
                }
                //Amount not verified
                else{
                    cout<<"Unable to verify amount\n";
                    int ch_amount_unverified;
                    same_options2:
                    cout<<"Select options: \n1.Continue displaying more flights\t2.Re-enter src & dest\t3.Exit\n";
                    cin>>ch_amount_unverified;
                    if(ch_amount_unverified == 1){
                        continue;
                    }
                    else if(ch_amount_unverified == 2){
                        goto enter_src_dest;
                    }
                    else{
                        cout<<"Exiting\n";
                        exit(1);
                    }
                }
                }
                //Dont want to buy
                else{
                    goto same_options2;
                }
        }
            if(purchased.size() == 0){
                int ch_no_purchase;
                cout<<"You purchased no flights till now\nSelect:\n1. Re-enter src and dest\t2.Swicth priority\t3. Exit\n";
                if(ch_no_purchase == 1){
                    goto enter_src_dest;
                }
                else if(ch_no_purchase == 2){
                    goto time_priority;
                }
                else{
                    cout<<"Exiting\n";
                    exit(1);
                }
            }
            else{
                cout<<"All available flights displayed\n";
                print_purchased_flights(purchased);
            }
        }
        





    }




    //Donot use this funcitons
    void User_interface(User obj,Graph g){
    cout<<"Welcome to the most optimized Flight reservation system ever : Mr/Mrs "<<obj.name<<endl;
    //string src,dest;
    int source_id,destination_id;
    string source_name,destination_name;
   // cout<<"Please enter your current location id : ";
    //cin>>source_id;
    re_enter_src_dest:
    cout<<"Please enter your location name : ";
    cin>>source_name;
    //finding source id
    for(int i=0;i<g.vertices.size();i++){
        if(g.vertices[i].state_name == source_name){
            source_id = g.vertices[i].state_id;
            break;
        }
    }
    //cout<<"Please enter your destination id : ";
    //cin>>destination_id;
    cout<<"Please enter your destination name : ";
    cin>>destination_name;
    //Finding destination id
    for(int i=0;i<g.vertices.size();i++){
        if(g.vertices[i].state_name == destination_name){
            destination_id = g.vertices[i].state_id;
            break;
        }
    }
    int priority;
    bool switch_priority = false;
    while(1){
    if(!switch_priority){
    cout<<"Select your prefered priority while travelling:\n";
    cout<<"1.Cost\t2.Time\n";
    cin>>priority;
    }
    //Here we will show the available flights based on the choose priority by the user
    if(priority == 2 || switch_priority){
        switch_priority = false;
        vector<int> shortestDistances = g.dijkstraWeight(source_id, destination_id);

        // Print the shortest distance to the destination_id vertex
        cout << "Fastest route from " << source_id << " to " << destination_id << ": " << shortestDistances[destination_id] <<" hrs"<< endl;

        // Print the shortest path
        g.printShortestPathWeight(source_id, destination_id);  //weigth = time

        bool found = false;
        cout<<"\nFinding the flight with above given fastest route\n";
        for(int i=0;i<flights.size();i++){
            if(flights[i].travel_time <= shortestDistances[destination_id]){
                found = true;
                flights[i].print_flight();
                int ch;
                cout<<"Do you want to purchase the ticket?\n1.Yes\t2.No\n";
                cin>>ch;
                if(ch == 1){
                    //user want to purchase ticket
                    cout<<"Verifying user current bank account balance... \n";
                    cout<<"Current Balance : "<<obj.b1.get_balance()<<" Flight price : "<<flights[i].price_of_ticket<<endl;
                    if(obj.b1.get_balance() >= flights[i].price_of_ticket){
                        cout<<"Ticket bought successfully\n";   
                        obj.b1.credit_amount(flights[i].price_of_ticket);
                        flights[i].decrement_ticket_if_sold();
                        goto re_enter_src_dest;
                    }
                    else{
                        cout<<"You have insufficent balance to buy the least costly ticket for this flight\n";
                        cout<<"Exiting...\n";
                        exit(1);
                    }
                }
                else{
                    int opt;
                    cout<<"Choose from following options : \n";
                    cout<<"1.Re-enter souce and destination\t2.Switch priority to cost\t3.Exit\n";
                    cin>>opt;
                    if(opt == 1){
                        goto re_enter_src_dest;
                    }
                    else if(opt == 2){
                        goto priority_switched;
                    }
                    else{
                        exit(1);
                    }
                }
                break;
            }
        }
        if(!found){
            cout<<"Sorry no flights with the given fastest route are available\n";
            int c;
            cout<<"1. Show all available flights\t2. Show flights by prioritizing cost\t3.Exit\n";
            cin>>c;
            if(c == 1){  
            cout<<"\nPrinting all available flights from given source and destination \n";
            for(int i=0;i<flights.size();i++){
            if(flights[i].source == source_name && flights[i].destination == destination_name)
            flights[i].print_flight();
            cout<<endl;
        }
            }
            else if(c == 2){
                switch_priority = true;
            }
        }

        
    }
    if(priority == 1 || switch_priority){
        priority_switched:
        switch_priority = false;
        vector<int>shortestDistances = g.dijkstraCost(source_id, destination_id);

        // Print the shortest distance to the destination_id vertex
        cout << "Minimum cost from " << source_id << " to " << destination_id << ": " << shortestDistances[destination_id] <<" unit price"<<endl;

        // Print the shortest path
        g.printShortestPathCost(source_id, destination_id);

        bool found = false;
        cout<<"\nFinding the flight with above given minumim cost\n";
        for(int i=0;i<flights.size();i++){
            if(flights[i].price_of_ticket <= shortestDistances[destination_id]){
                found = true;
                flights[i].print_flight();
                int ch;
                cout<<"Do you want to purchase the ticket?\n1.Yes\t2.No\n";
                cin>>ch;
                if(ch == 1){
                    //user want to purchase ticket
                    cout<<"Verifying user current bank account balance... \n";
                    cout<<"Current Balance : "<<obj.b1.get_balance()<<" Flight price : "<<flights[i].price_of_ticket<<endl;
                    if(obj.b1.get_balance() >= flights[i].price_of_ticket){
                        cout<<"Ticket bought successfully\n";   
                        obj.b1.credit_amount(flights[i].price_of_ticket);
                        flights[i].decrement_ticket_if_sold();
                        goto re_enter_src_dest;
                    }
                    else{
                        cout<<"You have insufficent balance to buy the least costly ticket for this flight\n";
                        cout<<"Exiting...\n";
                        exit(1);
                    }
                }
                else{
                    int opt;
                    cout<<"Choose from following options : \n";
                    cout<<"1.Re-enter souce and destination\t2.Switch priority to cost\t3.Exit\n";
                    cin>>opt;
                    if(opt == 1){
                        goto re_enter_src_dest;
                    }
                    else if(opt == 2){
                        goto priority_switched;
                    }
                    else{
                        exit(1);
                    }
                }
                break;
            }
        }
        if(!found){
            cout<<"Sorry no flights with the given fastest route are available\n";
            int c;
            cout<<"1. Show all available flights\t2. Show flights by prioritizing Time\t3.Exit\n";
            cin>>c;
            if(c == 1){  
            cout<<"\nPrinting all available flights from given source and destination \n";
            for(int i=0;i<flights.size();i++){
            if(flights[i].source == source_name && flights[i].destination == destination_name)
            flights[i].print_flight();
            cout<<endl;
        }
            }
            else if(c == 2){
                switch_priority = true;
            }
        }

    }
    int c;
    cin>>c;
    if(c==0)break;
    }
}
};


int main() {
    admin_control a1("Irtiza");
    a1.set_flights();
     a1.menu();
     User u1("Sadiq",100000);
    // u1.b1.print_details();
     a1.User_interface_better(u1,a1.g);
    return 0;
}