/*
Navya Mishra
Summer 2022
Lab 3.1
Description of problem:
This is the same code as problem 2.2
except now it has a friend function to 
convert the weight from kg to lbs. 


*/

#include <iostream>
#include <string>
#include <iomanip>
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

void kilotopound( Cargo Cargo){
    cout<< "Weight in pounds: " <<Cargo.weight*2.2<<endl;
}

int main()
{
    Cargo *cPtr = new Cargo;  ///create Cargo object on the heap
    cPtr->input(cPtr);///cPtr->input replaces (*cPtr).input(*cPtr)
    cPtr->output(cPtr);
    kilotopound(*cPtr);
    delete cPtr;///kill full constructor object
    Cargo *dPtr = new Cargo;  ///default Cargo object on the heap
    dPtr->output(dPtr);
    delete dPtr;///kill the default object
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