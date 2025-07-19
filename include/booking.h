#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
class Bookingclass
{
        private:

                std::string BOOKINGID;

        public:

        void BookingMenu();

        void AddBooking();//to add booking


        void DeleteBooking(const char*);//to delete booking


        
        void ViewBooking();//to view booking


        
};