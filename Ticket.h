#include<iostream>
#include<string>
using namespace std;
#ifndef TICKET_H
#define TICKET_H


class Ticket{
    private:
        int date;
        static int seatNumber;
        string source;
        string destination;
        string PassName;
        int boardingTime;
        string seatType;
        string AirlineName;
        int GateNumber;
        string FlightName;
    public:
        Ticket(){
            date=0;
            ++seatNumber;
            source='\0';
            destination='\0';
            PassName='\0';
            boardingTime=0;
            seatType='\0';
            AirlineName='\0';
            GateNumber=0;
            FlightName='\0';
        }

        Ticket(int d,string nme, string src, string des, string sttpe,string airname,int Gate,string Fn){
            date=d;
            PassName=nme;
            source=src;
            destination=des;
            seatType=sttpe;
            boardingTime= (PassName.length()/10)* 1000;
            AirlineName=airname;
            GateNumber=Gate;
            FlightName=Fn;
        }

        int getDate()
        {
            return this->date;
        }

    
        void setDate(int date)
        {
            this->date = date;
        }

    
        int getSeatNumber()
        {
            return this->seatNumber;
        }

    
        void setSeatNumber(int seatNumber)
        {
            this->seatNumber = seatNumber;
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

    
        string getPassName()
        {
            return this->PassName;
        }

    
        void setPassName(string name)
        {
            this->PassName = name;
        }

    
        int getBoardingTime()
        {
            return this->boardingTime;
        }

    
        void setBoardingTime(int boardingTime)
        {
            this->boardingTime = boardingTime;
        }

    
        string getSeatType()
        {
            return this->seatType;
        }

    
        void setSeatType(string seatType)
        {
            this->seatType = seatType;
        }
    
        string getAirlineName()
        {
            return this->AirlineName;
        }
    
        void setAirlineName(string AirlineName)
        {
            this->AirlineName = AirlineName;
        }
   
        int getGateNumber()
        {
            return this->GateNumber;
        }
    
        void setGateNumber(int GateNumber)
        {
            this->GateNumber = GateNumber;
        }

        string getFlightName()
        {
            return this->FlightName;
        }

        void setFlightName(string FlightName)
        {
            this->FlightName = FlightName;
        }


        void PrintTicket(){
            cout<<AirlineName<<"\t\t"<<seatType<<endl;
            cout<<"Name: "<<"\t\t"<<"Date: \t\t"<<"Time: "<<endl; 
            cout<<PassName<<"\t"<<date<<"\t"<<time<<endl;
            cout<<"From: "<<"\t\t"<<"Flight: \t\t"<<"Seat: "<<endl; 
            cout<<source<<"\t"<<FlightName<<"\t"<<seatNumber<<endl;
            cout<<"Destination: "<<"\t\t"<<"Gate: \t\t"<<"Boarding Till: "<<endl; 
            cout<<destination<<"\t"<<GateNumber<<"\t"<<boardingTime<<endl;
            
            
        }

};

#endif