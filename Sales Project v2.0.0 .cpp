#include <iostream>
#include <string.h>
#include <iomanip>   // To use setprecision() and setw()

using namespace std;

    float sales[8][6] {0};  // 2D array of sales with sales person as a column and product types as a row
    string salespersons[6] = {"Products","SalesPerson 1","SalesPerson 2","SalesPerson 3","SalesPerson 4","Product Total"};
    string products[8] = {"Product0","Product1","Product2","Product3","Product4","Product5","Total Sale","Bonus (5%)"};

// Prototypes / Function declaration
void menu();
void slip();
bool again();
void display();
void total();
void bonus();
void findSP();
void findP();
void SpRank();
void changeN();
void changeSPN();
void changePN();
void devs();
inline void cont();
inline void clear();

// Main
int main(){
// credit@ ASCII ART
cout <<" ===============================================================" << endl;
cout <<"  _    _      _                             ______                " << endl;
cout <<" | |  | |    | |                            | ___ \\               " << endl;
cout <<" | |  | | ___| | ___ ___  _ __ ___   ___    | |_/ / ___  ___ ___  " << endl;
cout <<" | |/\\| |/ _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\   | ___ \\/ _ \\/ __/ __| " << endl;
cout <<" \\  /\\  /  __/ | (_| (_) | | | | | |  __/   | |_/ / (_) \\__ \\__ \\ " << endl;
cout <<"  \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|   \\____/ \\___/|___/___/ " << endl;
cout <<" ===============================================================" << endl;

    menu();
    return 0;
}

// Menu
void menu(){
    char choice;
    cout << endl <<"\t\tMAIN MENU" << endl<< endl;
    cout <<"\tHere are the Options:\n" << endl;
    cout <<"\tEnter 1 - Add slip" << endl;
    cout <<"\tEnter 2 - View Summary Table" << endl;
    cout <<"\tEnter 3 - Find specific SalesPerson info" << endl;
    cout <<"\tEnter 4 - Find specific Product info" << endl;
    cout <<"\tEnter 5 - Salespersons LeaderBoard" << endl;
    cout <<"\tEnter 6 - Change Name" << endl;
    cout <<"\tEnter 7 - Developers" << endl;
    cout <<"\tEnter 0 - Exit" << endl;
    cout <<"\nChoose Options:  " ;
    cin >> choice;
    switch(choice){
        case '1':
            do{slip();}while(again());
            break;
        case '2':
            display();
            break;
        case '3':
            findSP();
            break;
        case '4':
            findP();
            break;
        case '5':
            SpRank();
            break;
        case '6':
            changeN();
            break;
        case '7':
            devs();
            break;
        case '0':
            cout <<endl << "\tGood Bye. See you :) " << endl;
            exit(0);
            break;
        default:
            cout << "Invalid Choice" << endl << endl;
            break;
    }
    if(choice !='1' && choice != '6')
        cont();
    clear();
    menu();
}

// Add daily salesperson slip
void slip(){
    clear();
    int snum, pnum;
    float pvalue;
    cout << endl << endl << "\t\t ADD SLIP DATA\n" << endl;
    cout << "\tEnter salesperson number [1-4] : " ;
    cin >> snum;
    cout << "\tEnter sold product number [1-5]: " ;
    cin >> pnum;
    cout << "\tHow much money sold (in birr) : " ;
    cin >> pvalue;
    sales[pnum][snum] += pvalue;

    if (snum < 5 && pnum < 6 && snum > 0 && pnum > 0 )
        cout << endl <<"\tSlip data added Successfully!" << endl;
    else
        cout << endl <<"\tInvalid input. Slip Adding failed..." << endl;
}

// Ask if user wants to add another slip Again
bool again(){
    bool again = false;
    char x;
    cout << endl << "\tWanna add again? Y/N : ";
    cin >> x;
    switch(x){
        case 'Y':
        case 'y':
            again = true;
            break;
        case 'N':
        case 'n':
        default:
            again = false;
    }
    clear();
    return again;
}

// calculate Total sales values
void total(){
    // row total
    for(int i=1;i<6;i++){
            sales[i][5] = 0;
        for ( int j =1; j<5; j++){
            sales[i][5] += sales[i][j];
        }
    }
    // column total
    for(int i=1;i<6;i++){
            sales[6][i] = 0;
        for ( int j =1; j<6; j++){
            sales[6][i] += sales[j][i];
        }
    }
}
// Calculate 5% Bonus of each salesperson
void bonus(){
    for(int i=1;i<6;i++){
        sales[7][i] = (0.05) * sales[6][i];   // Bonus = 5% of Total sale
    }
}

// Display Table
void display(){
    clear();
    total();
    bonus();

    cout << endl << endl << endl << "\t";
    cout << "\t\t\t\t SUMMARY OF TOTAL SALE\n\t";
    cout << "-----------------------------------------------------------------------------------------------------" << endl<< "\t";
    for(int i=0; i<6; i++)
        cout << left << setw(15) << salespersons[i]<< "| ";
    cout << endl<< "\t";
    cout << "-----------------------------------------------------------------------------------------------------" << endl << "\t";

    for(int i=1; i<8; i++){
        cout  << fixed << setprecision(2) << left << setw(15) << products[i]<< "| ";
        for (int j=1; j<6; j++){
            cout << setw(15) << sales[i][j] << "| ";
        }
        cout << endl << "\t";
        if(i==5)
            cout << "-----------------------------------------------------------------------------------------------------" << endl<< "\t";
    }
    cout << "-----------------------------------------------------------------------------------------------------" << endl<< "\t";
    cout << endl<< "\t";
}

// clear screen for a better view
inline void clear(){
    system("CLS");
}

// Go to menu
inline void cont(){
    string n;
    cout << endl << "Press Enter to continue: ";
    cin.ignore();
    getchar();
}

// Search for specific salesperson information
void findSP(){
    int spnum, total=0;
    cout << endl << endl;
    cout << "\tEnter Sales person number: ";
    cin >> spnum;

    if (spnum >0 && spnum < 5){
        clear();
        cout << endl << endl;
        cout << "\n\tSalesperson " << spnum << " sale information: "<< endl <<endl;
        for (int i=1;i<6;i++){
            cout << "\tProduct "<< i <<" sale:\t"<< sales[i][spnum] << " birr"<< endl;
            total += sales[i][spnum];
        }
        cout << "\t---------------------------------" << endl;
        cout << "\tTotal sale: \t" << sales[6][spnum] << " birr" << endl << endl;
        cout << "\tBonus (5%): \t" << sales[7][spnum] << " birr" << endl << endl;
    }
    else
        cout << "\tInvalid Input." <<  endl;
}
// Search for specific product information
void findP(){
    int pnum, total=0;
    cout << endl << endl;
    cout << "\tEnter Product number: ";
    cin >> pnum;
    if (pnum >0 && pnum < 6){
        clear();
        cout << endl << endl;
        cout << "\n\tProduct " << pnum <<" sales information:" << endl << endl;
        for (int i=1;i<5;i++){
            cout << "\tSale by Salesperson "<< i <<":\t"<< sales[pnum][i] << " birr"<< endl;
            total += sales[pnum][i];
        }
        cout << "\t---------------------------------" << endl;
        cout << "\tTotal sale of the Product: " << sales[pnum][5] << " birr" << endl << endl;
    }
    else
        cout << "\tInvalid Input." <<  endl;
}
// Rank of salespersons / leader board
void SpRank(){
    total();
    clear();
    float Top[5];
    string Rank[5];

    for(int i=1;i<5;i++){  // copy
        Top[i]= sales[6][i];
        Rank[i]= salespersons[i];
    }
    for(int i=1;i<5;i++){  //sort
        for(int j=1;j<5;j++){
            if (Top[i]> Top[j]){
                swap(Top[i], Top[j]);
                swap(Rank[i], Rank[j]);
    }}}
    cout << endl << endl << endl;
    cout << "\t\tLEADERBOARD\n"<< endl;
    cout << "\tRank" << "\t" << "\t\tTotal Sale" << endl;
    cout << "\t---------------------------------\n";
    for(int i=1;i<5;i++){
        cout << "\t"<< i << "\t" << left << setw(15)<< Rank[i] << "\t";
        cout << fixed << setprecision(2) << Top[i]<< " birr" <<endl;
    }
}
// Group Members ( Developers) Name and ID No.
void devs(){
    clear();
    string memebers[][2] = {{"Birhanu Worku", "ETS 0279/13"},{"Biruk Mesfin","ETS 0290/13"},{"Bisrat Kebere","ETS 0306/13"},{"Biyaol Mesay","ETS 0309/13"},{"Dagim Tezerawork","ETS 0333/13"}};
    cout << endl << endl;
    cout << "\t   ADDIS ABABA SCIENCE AND TECHNOLOGY UNIVERSITY\n";
    cout << "\t COLLEGE OF ELECTRICAL AND MECHANICAL ENGINEERING\n";
    cout << "\t\tDEPARTMENT OF SOFTWARE ENGINEERTING\n";
    cout << "\t\t\t\tSECTION A\n" << endl << endl;

    cout << "\t\t" << left << setw(3) << "No" << setw(20) << "Name" << setw(25) << "ID" << endl;
    cout << "\t\t" << setw(3) << "--" << setw(20) << "----------" << setw(25) << "------------" << endl;

    for (int i = 0; i < 5; i++){
        cout << "\t\t" << setw(3) << i + 1 << setw(20) << memebers[i][0] << setw(25) << memebers[i][1] << endl;
    }
    cout << endl << "\tInstructor: Eleni T." << endl << "\tSubmitted on: 25th April, 2022"<< endl;
}
// Menu to change Change Product and Salesperson Names
void changeN(){
    clear();
fail:
    char type;
    cout << endl << "\t\tCHANGE NAME" << endl << endl;
    cout << "\tHere are the Options\n" << endl;
    cout << "\tEnter 1 - Set / Change SalesPerson name"<< endl;
    cout << "\tEnter 2 - Set / Change Product name"<< endl;
    cout << "\tEnter 3 - Back to Menu" << endl;
    cout << "\nChoose Options:  ";
    cin >> type;

    switch(type){
        case '1':
            changeSPN();
            break;
        case '2':
            changePN();
            break;
        case '3':
            break;
        default:
            clear();
            cout << "\n\nInvalid input. Try Again." << endl;
            goto fail;
            break;
    }
    if(type!='3')
        cont();
}
// Change Sales person name
void changeSPN(){
    int spnum;
    cout << "Enter sales person number[1-4]: ";
    cin >> spnum;

    if(spnum > 0 && spnum < 5){
        cout << endl << endl<<"Current name: " << salespersons[spnum] << endl;
        cout << "Enter new name: ";
        cin >> salespersons[spnum];
        cout << "Name Successfully changed!" << endl;
    }
    else
        cout << "Invalid salesperson number. You should enter [1-4]."<< endl;
}
// Change Product name
void changePN(){
    int pnum;
    cout << "Enter product number[1-5]: ";
    cin >> pnum;

    if(pnum > 0 && pnum < 6){
        cout << endl << endl<<"Current name: " << products[pnum] << endl;
        cout << "Enter new name: ";
        cin >> products[pnum];
        cout << "Name Successfully changed!" << endl;
    }
    else
        cout << "Invalid product number. You should enter [1-5]."<< endl;
}

// Instructor: Eleni T.
// Submission date: April 25, 2022.
// 2022 @ AASTU. Department of Software Engineering. Section A.
