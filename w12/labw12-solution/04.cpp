#include <iostream>
using namespace std;

class Transportation
{
public:
    virtual double fare() = 0;
};

class BTS : public Transportation      
{
private:                                     
    int startFare = 15;                      
    int station = 0;                         
public:                                      
    void setStation(int station)             
    {                                        
        this->station = station;             
    }                                        
    double fare()                            
    {                                        
        return startFare + 5 * station;      
    }                                        
};

int main()
{
    int tc;
    cin >> tc;
    if (tc == 1) {
        int station;
        cin >> station;
        BTS bts;
        bts.setStation(station);
        cout << "BTS fare: "
             << bts.fare() << endl;
    } else if(tc == 2) {
        int station;
        cin >> station;
        BTS bts;
        bts.setStation(station);
        Transportation *transport = &bts;
        cout << "Transporataion fare: "
             << transport->fare() << endl;
    }
}