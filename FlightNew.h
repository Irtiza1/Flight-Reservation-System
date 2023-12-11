#include<iostream>
#include<string>
using namespace std;
#ifndef FLIGHTNEW_H
#define FLIGHTNEW_H

class Flight{
    public:
        string source;
        string destination;
        //int FlightNumber;
        //int TakeOffTime;
        //int BoardingTime;
        int travel_time;
        int price_of_ticket;
        int number_of_tickets;
        Flight(){
            source='\0';
            destination='\0';
            //FlightNumber=0;
            //TakeOffTime=0;
            //BoardingTime=0;
            travel_time = 0;
            price_of_ticket = 0;
            number_of_tickets = 0;
        }

        // Flight(string src, string des, int fltno,int tktime, int bt,int p,int n){
        //     source=src;
        //     destination=des;
        //     FlightNumber=fltno;
        //     TakeOffTime=tktime;
        //     BoardingTime=bt;
        //     price_of_ticket = p;
        //     number_of_tickets = n;
        // }

        Flight(string src, string des, int tt,int p,int n){
            source=src;
            destination=des;
            travel_time = tt;
            price_of_ticket = p;
            number_of_tickets = n;
        } 
        
        
        string getSource()
        {
            return this->source;
        }

    
        void setSource(string source)
        {
            this->source = source;
        }

    
        string getDestination()
        {
            return this->destination;
        }

    
        void setDestination(string destination)
        {
            this->destination = destination;
        }
    
        // int getFlightNumber()
        // {
        //     return this->FlightNumber;
        // }

    
        // void setFlightNumber(int FlightNumber)
        // {
        //     this->FlightNumber = FlightNumber;
        // }

    
        // int getTakeOffTime()
        // {
        //     return this->TakeOffTime;
        // }

    
        // void setTakeOffTime(int TakeOffTime)
        // {
        //     this->TakeOffTime = TakeOffTime;
        // }

    
        // int getBoardingTime()
        // {
        //     return this->BoardingTime;
        // }

    
        // void setBoardingTime(int BoardingTime)
        // {
        //     this->BoardingTime = BoardingTime;
        // }

        void set_price(int p){
            price_of_ticket = p;
        }
        int get_price(){
            return price_of_ticket;
        }
        void set_num_of_tick(int n){
            number_of_tickets = n;
        }
        int get_num_of_tick(){
            return number_of_tickets;
        }
        void decrement_ticket_if_sold(){
            number_of_tickets--;
        }
        void print_flight(){
            cout<<"Source : "<<source<<endl;
            cout<<"Dest : "<<destination<<endl;
            cout<<"Travel time : "<<travel_time<<endl;
            // cout<<"Flight no : "<<FlightNumber<<endl;
            // cout<<"Takeoff time : "<<TakeOffTime<<endl;
            // cout<<"Boarding Time : "<<BoardingTime<<endl;
            cout<<"Price of ticket : "<<price_of_ticket<<endl;
            cout<<"Number of tickets : "<<number_of_tickets<<endl;
        }

};
#endif