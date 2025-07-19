
#include"login.h"

void  Login::LoginWindow()
{
        
       
        
        int choice1;
        cout<<"                              *****WELCOME TO INDIAN RAILWAY TICKET BOOKING*****"<<endl;
        cout<<"                              *******************LOGIN**************************"<<endl;
        cout<<endl;
        cout<<"                                            1. LOGIN"<<endl;
        cout<<"                                            2. SIGNUP"<<endl;
        cout<<"                                            3. ADMIN"<<endl;
        cout<<"                                            4. EXIT"<<endl;
        cout<<"                                          CHOOSE ANY ONE : ";
        cin>>choice1;
        switch (choice1)
        {
        case 1:
                UserLoginWindow();
            break;
        case 2:
                NewUser();

            break;    
        case 3:
              AdminLoginWindow();

            break;
        case 4:
                cout<<"                             THANKYOU";
                cout<<endl;
                cout<<endl;
                exit(0);
            break;
        }
}
