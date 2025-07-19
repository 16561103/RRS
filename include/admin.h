// DECLARATION OF ADMIN FUNCTIONS
#include<iostream>
#include<fstream>
#include<cstdlib>

#include"train.h"
#include"booking.h"


using namespace std;
//      ***********MEMBER FUNCTION OF ADMIN IN CLASS Adminlogin*************
class Adminlogin:public Trainclass,public Bookingclass
{
        private:
                std::string ADMINID;
                std::string PASSWORD;              
        public:
       
        
        void AdminLoginWindow();//Admin login function


        void AdminLoginMenu();//admin menu window


        

        void UserData();  //to view user informnation


        
};

