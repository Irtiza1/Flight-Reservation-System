#include<iostream>
#include<string>
using namespace std;
#ifndef FLIGHT_H
#define FLIGHT_H

class Flight{
    private:
        string source;
        string destination;
        int PersonCapacity;
        int FlightNumber;
        int TakeOffTime;
        int BoardingTime;

    public:
        Flight(){
            source='\0';
            destination='\0';
            PersonCapacity=0;
            FlightNumber=0;
            TakeOffTime=0;
            BoardingTime=0;
        }

        Flight(string src, string des, int prscap, int fltno,int tktime, int bt){
            source=src;
            destination=des;
            PersonCapacity=prscap;
            FlightNumber=fltno;
            TakeOffTime=tktime;
            BoardingTime=bt;
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

    
        int getPersonCapacity()
        {
            return this->PersonCapacity;
        }

    
        void setPersonCapacity(int PersonCapacity)
        {
            this->PersonCapacity = PersonCapacity;
        }

    
        int getFlightNumber()
        {
            return this->FlightNumber;
        }

    
        void setFlightNumber(int FlightNumber)
        {
            this->FlightNumber = FlightNumber;
        }

    
        int getTakeOffTime()
        {
            return this->TakeOffTime;
        }

    
        void setTakeOffTime(int TakeOffTime)
        {
            this->TakeOffTime = TakeOffTime;
        }

    
        int getBoardingTime()
        {
            return this->BoardingTime;
        }

    
        void setBoardingTime(int BoardingTime)
        {
            this->BoardingTime = BoardingTime;
        }
};
#endif