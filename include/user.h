// DECLARATION OF USER FUNCTION 


#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>




using namespace std;
// ***********MEMBER FUNCTION OF USER IN CLASS CuserLogin*************
class Userlogin{
        private:
        std::string USERID;
        std::string USERPASS;
        public:
       
        void UserLoginWindow();      //Login window where user can login into user.


        void UserLoginMenu();       //login window where user can perform user functions.


        void NewUser();        //new user can be created


        void ViewTrainsUser();         //to view trains

        void AddBookingUser();      //to view trains


        void ViewBookingUser();     //to view booking


        void CancelBookingUser(const char*);  //to cancel booking


      
        
                                
        

};
