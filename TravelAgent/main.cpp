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
    float carCost = 0;

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

        carCost = rate*Kilometers;
        int confirmation = 0;

        if(carCost)
        {
            cout<<"\t\tThat will be: "<<carCost<<" Rs"<<endl;
            cout<<"\n\n\t\tDo you want to Book this cab, 1-yes, 2-no, select another cab, 3-Quit: ";
            cin>>confirmation;
            switch(confirmation)
            {
                case 1:bookRide();
                        break;
                case 2: system("CLS");
                        carCost = 0;
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
            int hotelCharge = 0;

            void menu()
            {
                int hotelChoice = -1;
                int packChoice = -1;
                int nights = -1;

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

                    cout<<"\n\t\tEnter Your choice:";
                    cin>>packChoice;
                    packChoice-=1;

                    if(packChoice<=hotels[hotelChoice].second.size() && packChoice>=0)
                    {
                        cout<<"\t\tEnter number of nights: ";
                        cin>>nights;
                        if(nights>=0)
                        {
                            cout<<"\n\n\t\tYour Booking is successfull for "<<nights<<" nights at "<<hotels[hotelChoice].first<<endl;
                            hotelCharge = nights*hotels[hotelChoice].second[packChoice];
                            cout<<"\t\tFinal amount is: "<<hotelCharge;
                        }
                        else
                        {
                            cout<<"You Entered an Invalid choice:- ";
                            system("CLS");
                            menu();
                        }

                        
                    }
                    else
                    {
                        menu();
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

class Charges:public Hotels, public Cabs, public Customers 
{   
public:
    void printBill() {
        float totalAmount = carCost + hotelCharge;
        ofstream outf("receipt.txt");
        {
        outf << "\n\n\t\t----------Bill Details----------" << endl;
        outf << "\t\tCustomer ID: " << customerId << " " << endl;
        outf << "\t\tCab Charges: " << carCost << " Rs" << endl;
        outf << "\t\tHotel Charges: " << hotelCharge << " Rs" << endl;
        outf << "\t\t--------------------------------" << endl;
        outf << "\t\tTotal Amount: " << totalAmount << " Rs" << endl;
        outf << "\t\t--------------------------------" << endl;
        }

        outf.close();
    }
    void showBill()
    {
        ifstream bill("receipt.txt");
        if(!bill)
        {
            cout<<"File opening error"<<endl;
            return;
        }

        string line;
        while(getline(bill, line))
        {
            cout<<line;
        }

        bill.close();

    }


};

void mainMenu() {
    int choice;
    Customers customer;
    Charges charge;

    while (true) {
        system("CLS"); // Clear the screen
        cout << "\n\n\t\t----------MAIN MENU----------" << endl;
        cout << "\t\t1. Enter Customer Details" << endl;
        cout << "\t\t2. Show Customer Details" << endl;
        cout << "\t\t3. Book a Cab" << endl;
        cout << "\t\t4. Book a Hotel" << endl;
        cout << "\t\t5. Print Receipt" << endl;
        cout << "\t\t6. Show Receipt" << endl;
        cout << "\t\t7. Exit" << endl;
        cout << "\n\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // To handle the newline character left in the input buffer
                customer.getDetails();
                break;
            case 2:
                customer.showDetails();
                break;
            case 3:
                charge.Cabs::menu();
                break;
            case 4:
                charge.Hotels::menu();
                break;
            case 5:
                charge.printBill();
                break;
            case 6:
                charge.showBill();
                break;
            case 7:
                cout << "\n\t\tThank you for using our service!" << endl;
                Sleep(2000); // Pause for 2 seconds before exiting
                exit(0);
            default:
                cout << "\n\t\tInvalid choice! Please try again." << endl;
                Sleep(2000); // Pause for 2 seconds before redisplaying the menu
        }
    }
}

int main()
{
    mainMenu();
    return 0;
}