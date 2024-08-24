#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<map>
#include<vector>

using namespace std;

class Customers
{
public:
    string name, gender, address, mobile;
    int age, customerId;

    void getDetails()
    {

        ofstream out("customers.txt", ios::app);
        if(!out)
        {
            cout<<"Error creating File"<<endl;
            return;
        }
        {
            cout<<"\n\n\n\t\t";
            cout<<"Enter Name: ";
            getline(cin,name);

            cout<<"\t\t";
            cout<<"Enter Customer ID: ";
            cin>>customerId;

            cout<<"\t\t";
            cout<<"Enter Age: ";
            cin>>age;

            cin.ignore();

            cout<<"\t\t";
            cout<<"Gender: ";
            getline(cin, gender);

            cout<<"\t\t";
            cout<<"Address: ";
            getline(cin, address);

            cout<<"\t\t";
            cout<<"Mobile: ";
            cin>>mobile;
        }

        out<<"\nCustomer Id: "<<customerId<<"\nName: "<<name<<"\nAge: "<<age<<"\nGender"<<gender<<"\nMobile: "<<mobile<<"\nAddress: "<< address<<endl;
        out.close();

        cout<<"Record Saved"<<endl;
    }

    void showDetails()
    {
        ifstream in("customers.txt");

        if(!in)
        {
            cout<<"File Opening Error"<<endl;
            return;
        }

        string line;
        while(getline(in, line))
        {
            cout<<line<<endl;
        }
        in.close();

    }
};

class Cabs{
public:
    int cabChoice = 0;
    float Kilometers = 0;
    float cost = 0;

    void menu()
    {
        cout<<"\n\n\t\t";
        cout<<"Get the best cab service in town"<<endl;
        cout<<"\t\t-------------ABC CABS-----------"<<endl;
        cout<<"\t\t1.standard cab - Rs.15 per KM   "<<endl;
        cout<<"\t\t2.premium cab - Rs.25 per KM    "<<endl;
        cout<<"\t\t3.Quit   "<<endl;

        cout<<"\t\tEnter Your Choice: ";
        cin>>cabChoice;

        switch(cabChoice)
        {
            case 1: costCalculator(15);
                    break;
            case 2: costCalculator(25);
                    break;
            case 3: return;
            default: cout<<"\t\tInvalid Choice";
        }


    }

    void costCalculator(int rate)
    {
        cout<<"\n\n\t\tEnter the journey Distance in Km: ";
        cin>>Kilometers;

        cost = rate*Kilometers;
        int confirmation = 0;

        if(cost)
        {
            cout<<"\t\tThat will be: "<<cost<<" Rs"<<endl;
            cout<<"\n\n\t\tDo you want to Book this cab, 1-yes, 2-no, select another cab, 3-Quit: ";
            cin>>confirmation;
            switch(confirmation)
            {
                case 1:bookRide();
                        break;
                case 2: system("CLS");
                        menu();
                        break;
                case 3: return;
                default: cout<<"\t\tInvalid Choice"<<endl;
            }
        }
        else
        {
            cout<<"\t\tYou entered Invalid Distance, Redirecting to Previous menu \n\t\t Please wait";
            Sleep(3000);
            system("CLS");
            costCalculator(rate);
        }


    }

    void bookRide()
    {
        if(cabChoice==1)
            cout<<"\t\tYour standard cab is booked for "<< Kilometers <<" kilometers, happy Journey"<<endl;
        else
            cout<<"\t\tYour luxury cab is booked for "<< Kilometers <<" kilometers, happy Journey"<<endl;


        Sleep(3000);
        menu();
    }
};

class Hotels{
    public:

        map<int,pair<string, vector<int>>>hotels = {
            {1, {"Leeela", {500, 3000, 5000}}},
            {2, {"Ravis", {1000, 5000, 10000}}},
            {3, {"La French", {15000, 25000, 30000}}}
            };

            void menu()
            {
                int hotelChoice = -1;
                cout<<"\n\n\t\tWelcome to Hotel Booking Service"<<endl;
                cout<<"\n\t\tThese are our selection of hotels"<<endl;

                for(auto hotel:hotels)
                {
                    cout<<"\t\t";
                    cout<<hotel.first<<". "<<hotel.second.first<<endl;

                }

                cout<<"\t\tEnter your hotel number to continue and 0 to quit: ";

                cin>>hotelChoice;
                system("CLS");

                if(hotels.find(hotelChoice)!=hotels.end())
                {
                    cout<<"\t\tSelect from the different packages available for "<<hotels[hotelChoice].first << endl;
                    int i = 1;
                    for(auto package:hotels[hotelChoice].second)
                    {
                        cout<<"\t\t"<<i<<". "<<package<<"Rs"<<" Per Night"<<endl;
                        i++;
                    }
                }
                else if(hotelChoice == 0)
                {
                    return;
                }
                else
                {
                    menu();
                }

            }

};

class Charges{

};

int main()
{
    Customers customer;
    Cabs cab;
    Hotels hotel;
    //customer.getDetails();
    //customer.showDetails();
    //cab.menu();
    hotel.menu();
    

    return 0;
}