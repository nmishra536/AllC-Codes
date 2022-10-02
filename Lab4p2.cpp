/*
Navya Mishra
Summer 2022
Lab 4.2
Description of problem:
This problem requires the code to 
get data from files and not from human
input.

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> /*sorry i thought i saved it properly*/
using namespace std;
class Cargo{
private:
    string uldtype;  ///unit load type, container or pallet
    string abbrev;   ///three letters AYF, PAG etc.
    string uldid;
    int aircraft;
    double weight;
    string destination;
public:
    friend void kilotopound(Cargo);
    friend bool operator ==(Cargo &,Cargo &);
    Cargo(Cargo & c){
        uldtype = c.uldtype;
        abbrev = c.abbrev;
        uldid = c.uldid;
        aircraft = c.aircraft;
        weight = c.weight;
        destination = c.destination;
    }
    ///constructor prototypes
    Cargo();  ///default constructor prototype, see below main for code
    Cargo(const string uldtype,
          const string abbrev,
          const string uldid,
          const int plane,
          const double weight);///full constructor, needs more parameters
    ///Destructor prototype
    ~Cargo();
    ///Mutator (setters) prototypes, six needed
    void setuldtype(string);
    void setabbrev (string);
    void setuldid(string);
    void setaircraft(int);
    void setweight(double);
    ///Accessor (getters) prototypes, six needed
    string getuldtype() const;
    string getabbrev() const;
    string getuldid() const;
    int getaircraft() const;
    double getweight() const;
    void input(Cargo *);
    void output(Cargo *);
}; ///end of class Cargo

void input(){
    ifstream inputFile;
    string uld; string abbrev; string uldid; int aircraft; double weight ; string destination;
    inputFile.open("cardata4.txt");
    if(!inputFile){
        cout << "Error: File not opened"<< endl;
        exit(0);
    }
    else{
        while(inputFile.peek() != EOF) {
            while (inputFile.peek() == ' ')
                inputFile.get();
            inputFile >> uld >> abbrev >> uldid >> aircraft >> weight >> destination;
            Cargo temp(uld, abbrev, uldid, aircraft, weight, destination);
            temp.print();
        }
    }
    inputFile.close();

}
/*void kilotopound( Cargo Cargo){
    cout<< "Weight in pounds: " <<Cargo.weight*2.2<<endl;
}*/

bool operator ==(Cargo &a, Cargo &b){//as given in the question only two values are compared
    if((a.abbrevn==b.abbrev) && (a.uldid==b.uldid)){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    /*Cargo *cPtr = new Cargo;  ///create Cargo object on the heap
    cPtr->input(cPtr);///cPtr->input replaces (*cPtr).input(*cPtr)
    cPtr->output(cPtr);
    kilotopound(*cPtr);
    cout<<"*************************************"<<endl;
    Cargo *cPtr2(cPtr);
    kilotopound(*cPtr2);
    cPtr2->output(cPtr2);
    
    Cargo unit1;
    unit1.uld="Pallet";
    unit1.abbrev="PAG";
    unit1.uldid="PAG32597IB";
    unit1.aircraft=737;
    unit1.weight=3321;
    unit1.destination="SEA";
    Cargo unit2(unit1),unit3(cPtr);

if (unit1 == unit2)
  cout << "\n unit1 is the same as unit2 \n";
else
  cout << " \nunit1 is not the same as unit2 \n";
if (unit2 == unit3)
  cout << " \nunit2 is the same as unit3 \n";
else
  cout << " \nunit2 is not the same as unit3\n";

    delete cPtr;///kill full constructor object
    delete cPtr2;
    Cargo *dPtr = new Cargo;  ///default Cargo object on the heap
    dPtr->output(dPtr);
    delete dPtr;///kill the default object
    */
    input();
    return 0;
}
///Default constructor, six assignments needed
    Cargo::Cargo( )
    {
        uldtype = "none";
        abbrev = "none";
        uldid = "";
        aircraft = 700;
        weight = 0;
        destination = "none";
    }
///constructor needs to take six parameters
    Cargo::Cargo(const string type,
                 const string abrv,
                 const string did,
                 const int plane,
                 const double wt)
    {
        uldtype = type;
        abbrev = abrv;
        uldid = did;
        aircraft = plane;
        weight = wt;
    }
    Cargo::~Cargo()
    {
        cout << "Cargo destructor called\n";
    }
    void Cargo::setuldtype(string type)
    {
        uldtype = type;
    }
    void Cargo::setabbrev(string abrv)
    {
        abbrev = abrv;
    }
    void Cargo::setuldid(string did)
    {
        uldid = did;
    }
    void Cargo::setaircraft(int plane)
    {
        aircraft = plane;
    }
    void Cargo::setweight(double wt)
    {
        weight = wt;
    }
    string Cargo::getuldtype() const
    {
        return uldtype;
    }
    string Cargo::getabbrev() const
    {
        return abbrev;
    }
    string Cargo::getuldid() const
    {
        return uldid;
    }
    int Cargo::getaircraft() const
    {
        return aircraft;
    }
    double Cargo::getweight() const
    {
        return weight;
    }
    void Cargo::output(Cargo *cPtr)///need to output six pieces of data
    {
        cout << setw(19) << "Unit load type: " << getuldtype() << endl;
        cout << setw(19) << "Abbreviation: " << getabbrev() << endl;
        cout << setw(19) << "Unit load id: " << getabbrev() << getuldid() << endl;
        cout << setw(19) << "Aircraft: " << getaircraft() << endl;
        cout << setw(19) << "Weight: " << getweight() << endl;
        ///more output goes here
        cout << "-----------------------" << endl;
    return;
    }
    void Cargo::input(Cargo *cPtr) ///need to input six pieces of data
    {
///local variables for load from keyboard
        string type;
        string abrv;
        string did;
        int plane;
        double wt;
        string dest;
        cout << "Please input load information\n";
        cout << "Container or Pallet?  ";
        //cin >> type;
        getline(cin,type);
        setuldtype(type);
        cout << "Please input abbreviation 3 characters ";
        getline(cin, abrv);
        setabbrev(abrv);
        cout << "Please input unit load id " << abrv;
        getline(cin, did);
        setuldid(did);
        cout << "Please enter aircraft type, 3 digits ";
        cin >> plane;
        setaircraft(plane);
        cout << "Please enter weight ";
        cin >> wt;
        setweight(wt);
    return;
    }