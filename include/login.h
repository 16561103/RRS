// DECLARATION OF LOGIN FUNCTION
#include<iostream>
#include"admin.h"
#include"user.h"

using namespace std;
// MEMBER FUNCTION OF ADMIN AND USER IN CLASS Login
class Login:public Adminlogin,public Userlogin
{
    public:
    virtual void LoginWindow();
    
    

};