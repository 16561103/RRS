#include<iostream>
#include<fstream>
#include<cstdlib>


using namespace std;
class Trainclass
{
    public:


        int TRAINNO;

    public:

       

        void TrainMenu();

        void ViewTrains();//to view trains


        void AddTrains();//to add trains


        void DeleteTrains(const char*);//to delete trains
};