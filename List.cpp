
//************************************************************
//Navya Mishra
//nmishra3
//PA 5
//***********************************************************
#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"


// Node constructor
List::Node::Node(ListElement x){
   data = x;
   next = nullptr;
   prev = nullptr;
}


List::List(){
   frontDummy =  new Node(-1);
   backDummy = new Node (-2);
   frontDummy->next = backDummy;
   backDummy->prev = frontDummy;


   beforeCursor = frontDummy;
   afterCursor = backDummy;
   pos_cursor = 0;
   num_elements = 0; 
   //delete(frontDummy);
   //delete(backDummy);
}

List::List(const List& L){
   frontDummy = new Node(-1);
   backDummy = new Node (-2);
   frontDummy->next = backDummy;
   backDummy->prev = frontDummy;

   beforeCursor = frontDummy;
   afterCursor = backDummy;
   pos_cursor = 0;
   num_elements = 0; 

   //load elements
   Node* N = L.frontDummy->next;
   while (N!= L.backDummy){
    insertBefore(N->data);
    N = N->next;

   }
   moveFront();

}

List::~List(){
   // if (num_elements>0){
        clear();
        delete(frontDummy);
        delete(backDummy);
        //delete(this);
        //*this = nullptr;
    //} //delete them all
}


int List::length() const{
    return (num_elements);
}

ListElement List::front() const{
    if (num_elements > 0){
        return (frontDummy->next->data);
    }
    
    throw std::length_error("List: front(): empty list");
}

ListElement List::back() const{
    if (num_elements > 0){
        return (backDummy->prev->data);
    }
    throw std::length_error("List: back(): empty list");
}

int List::position() const{
    return (pos_cursor);
}

ListElement List::peekNext() const{
    if(pos_cursor < length()) {
       return(afterCursor->data); 
    }
    throw std::range_error("List: peekNext(): cursor at back");
}

ListElement List::peekPrev() const{
    if(pos_cursor > 0) {
        return(beforeCursor->data); 
    }
     throw std::range_error("List: peekPrev(): cursor at front");
    
}

void List::clear(){
    moveFront();
    while (length() > 0){
        eraseAfter();
    }
  
   
}

 void List::moveFront(){ 
   
    beforeCursor = frontDummy;
    afterCursor = frontDummy->next;
    pos_cursor = 0;
 }

 void List::moveBack(){
    //while(beforeCursor->next != nullptr){
       // afterCursor = afterCursor->next;
        //beforeCursor = beforeCursor->next;
   // }
    beforeCursor = backDummy->prev;
    afterCursor = backDummy;
    pos_cursor = num_elements;

 }

 ListElement List::moveNext(){
    if (pos_cursor < num_elements){
        beforeCursor = afterCursor;
        afterCursor = afterCursor->next;
        pos_cursor = pos_cursor + 1;
       // std::cout<<"movenext"<<std::endl;
        //std::cout<<pos_cursor<<std::endl;
        return (beforeCursor->data);

    }
    throw std::range_error("List: moveNext(): cursor at back");
        
 }

 ListElement List::movePrev(){
    if (pos_cursor > 0){
       afterCursor = beforeCursor;
    beforeCursor = beforeCursor->prev;
    pos_cursor = pos_cursor - 1;
    //std::cout<<"moveprev"<<std::endl;
    //std::cout<<pos_cursor<<std::endl;
    return (afterCursor->data);

    }
    throw std::range_error("List: movePrev(): cursor at front");
    
 }

  void List::insertAfter(ListElement x){
    Node *N = new Node(x);
    
    N->next = afterCursor;
    N->prev = beforeCursor;
    afterCursor->prev = N;
    beforeCursor->next = N;
    afterCursor = N;
    num_elements = num_elements+1; //returns number of elements correctly



  }

void List::insertBefore(ListElement x){
    Node *N = new List::Node(x);
    
    N->next = afterCursor;
    N->prev = beforeCursor;
    afterCursor->prev = N;
    beforeCursor->next = N;
    beforeCursor = N;
    num_elements = num_elements+1;
    pos_cursor ++;

}

void List::setAfter(ListElement x){
    if (pos_cursor < num_elements){
        afterCursor->data = x;
    }else{throw std::range_error("List: setAfter(): cursor at back");}
}

void List::setBefore(ListElement x){
    if (pos_cursor > 0){
        beforeCursor->data = x;
    }else{ throw std::range_error("List: setBefore(): cursor at front");}
   
}

void List::eraseAfter(){
    if (pos_cursor < num_elements){
        //Node *A;
        //Node *P;
        //Node *del;
        //P = beforeCursor;
        //A = afterCursor;
        beforeCursor->next = afterCursor->next;
        afterCursor->next->prev = beforeCursor;
        Node *N = afterCursor;
        delete(N);
        afterCursor = beforeCursor->next;
        num_elements = num_elements -1;
       // del = afterCursor->next;
        //P->next = A;
       // A->prev = P;
        //del = NULL;

    }else{
     throw std::range_error("List: eraseAfter(): cursor at back"); 
    }
}


void List::eraseBefore(){
    if (pos_cursor > 0){
        //Node *A;
        //Node *P;
        //Node *del;
        //P = beforeCursor;
        //A = afterCursor;
        afterCursor->prev = beforeCursor->prev;
        beforeCursor->prev->next = afterCursor;
        Node *N = beforeCursor;
        delete(N);
        beforeCursor = afterCursor->prev;
        pos_cursor = pos_cursor -1;
        num_elements--;

        //del  = beforeCursor->next;
        //P->next = A;
        //A->prev = P;
        //del = NULL; //setting to null does nothing. must actually delete it

    }else{
    throw std::range_error("List: eraseBefore(): cursor at front");

}}


int List::findNext(ListElement x){
    /*if(position() == length()){ //nothing to see after this
            pos_cursor = length();
            return (-1);
        }*/
        
    ListElement E = moveNext();
    while(E != x){
        if(afterCursor == backDummy){
            pos_cursor = length();
            return (-1);
        }
        //if(pos_cursor < length()) {
            E = moveNext();
            
    }
    
    //std::cout<<"findnext: ";
    //std::cout<<pos_cursor<<std::endl;
    return (pos_cursor);
}


int List::findPrev(ListElement x){
   /* if(position() == 0){ //nothing to see before this
            pos_cursor = 0;
            return (-1);
        }*/
    
    ListElement E = movePrev();
    while(E != x){
        if(beforeCursor== frontDummy){
            pos_cursor = 0;
            return (-1);
        }
        E = movePrev();
       
    }
   //std::cout<<"findprev"<<std::endl;
    //std::cout<<pos_cursor<<std::endl;
    return (pos_cursor);
}

//change these starting here
void List::cleanup(){
    //there are no dictionaries in cpp 
    //i don't know maps
    Node *temp, *teemp; //two pointers
    
    int z = 0;
   // int y = pos_cursor;
    for (temp = frontDummy->next; temp !=backDummy; temp = temp->next ){
        //iterate through the list
        //std::cout<<"check2"<<std::endl;
        int x = z+1;
        int y = pos_cursor;
        teemp = temp->next;
        while (teemp != backDummy){ //iterate through list ahead of first pointer to remove dupes
        //std::cout<<pos_cursor<<std::endl;
        // std::cout<<to_string()<<std::endl;
            if(temp->data == teemp->data){ //wait where is the cursor???
                Node *del = teemp; //mark to delete
                Node *moveN = teemp->next;
                //make case if cursor is there and if cursor is not there
               // std::cout<<"check4"<<std::endl;
                if ( beforeCursor == teemp){
                    //std::cout<<"check5"<<std::endl;
                    /*if (x<y){
                     pos_cursor--;
                }*/
                    beforeCursor = beforeCursor->prev;
                    //pos_cursor--;
                }else if (afterCursor == teemp){
                    //std::cout<<"check6"<<std::endl;
                   /* if (x<y){
                     pos_cursor--;
                }*/
                    afterCursor = afterCursor->next;
                    //pos stays the same?
                } 
            
                teemp->prev->next = teemp->next;
                teemp->next->prev = teemp->prev;
                delete(del);
                teemp = moveN;
                //teemp = teemp->next;
                num_elements--;
                if (x<y){
                     pos_cursor--;
                }
                //std::cout<<"check8"<<std::endl;


            }else{
                teemp = teemp->next;
                //std::cout<<"check9"<<std::endl;
            }
            x++;
             //std::cout<<pos_cursor<<std::endl;
        }
        z++;
       
    }

}



   /* List *L = new List(); 
    Node *temp = frontDummy->next; //head
    Node *teemp = nullptr;
    Node *t = nullptr;
    int x = 0;
    int y = pos_cursor;
    while (temp != backDummy) { //while in range of list
       teemp =  L->frontDummy->next;
        while(teemp != L->backDummy){
            if (temp != teemp) {//temp not in L, add it and move next
               teemp = teemp->next; 
            }else{
                t = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete(temp);
                num_elements = num_elements -1;;
                if(x < y) {
                        pos_cursor = pos_cursor -1;
                }
                temp = t;

                //if it is already in new list, delete from main list
            }
        }
        //movenext element in main list
        x++;
    }*/


    


List List::concat(const List& L) const { //broken here
   /* List *l = new List(*this);
    l->moveBack();
    Node *temp = L.frontDummy->next; //set temp to actual front
    while (temp != L.backDummy) { //while in range
        l->insertBefore(temp->data); //insert into l and go backwarsd to connect
        temp = temp->next;
    }
    l->moveFront();
    return *l;*/


    List l = L;
    l.moveFront();
    Node *temp = this->backDummy->prev; //set temp to actual front
    while (temp != this->frontDummy) { //while in range
        l.insertAfter(temp->data); //insert into l and go backwarsd to connect
        temp = temp->prev;
    }
    l.moveFront();
    return l;
    //std::cout << pos_cursor<< std::endl;
    //std::cout << l->pos_cursor<< std::endl; //prints twice??
    //std::cout << "concat"<< std::endl;
     //return new list 
    //l is a pointer. return the LIST
    //List *l;
    //Node *temp frontDummy->next; //head of the real list
    //while (temp != backDummy){

    //}

     //List *l = new List();
    //l = this;
     //List *l(*this); //do we need "this" here??? 
    //just copy it in like normal if copy list works
    //copying the original list to l
    //Node* N = this->frontDummy->next;
    //while (N!= this->backDummy){
    //l->insertBefore(N->data); //copying the list to l
   // N = N->next;
    //}
    //can't move back if there's no LIST
}


std::string List::to_string() const {
    std::string s = "";
    Node *temp = frontDummy->next; //set to head
    while (temp != backDummy) { //while not out of scope
        s = s + std::to_string(temp->data);
       // s = s + "temp->data" //add to string
        if (temp->next != backDummy) {
            s = s + "";
        }
        temp = temp->next;
    }
     return (s = s + ""); //can put this after iterating through whole list
   
}


bool List::equals(const List& R) const { 
    bool eq = false;
   Node* N = nullptr;
   Node* M = nullptr;

   eq = ( this->num_elements == R.length() );
   N = this->frontDummy->next;
   M = R.frontDummy->next;
   while( eq && N!=backDummy){
      eq = (N->data==M->data);
      N = N->next;
      M = M->next;
   }
   return eq;
   
   
    //return to_string() == R.to_string();
 }

std::ostream& operator<<( std::ostream& stream, const List& L ) {
    stream << L.to_string();
    return stream;
}

bool operator==( const List& A, const List& B ) {
    return A.equals(B);
}

List& List::operator=( const List& L ) {
    if( this != &L ){ // not self assignment
    //this->moveFront();
    //while (this->length() != 0) {
       //this->eraseAfter();
   //} //make sure this is clear first
   //then assign
    
   List temp = L; //make a copy into this
   std::swap(frontDummy, temp.frontDummy);
   std::swap(backDummy, temp.backDummy);
   std::swap(beforeCursor, temp.beforeCursor);
   std::swap(afterCursor, temp.afterCursor);
   std::swap(pos_cursor, temp.pos_cursor);
   std::swap(num_elements, temp.num_elements);
   //this->concat(L); //this should concat to an empty list this right??
   
   //std::cout << "concat called by operator"<< std::endl;
   //std::cout << this->length()<< std::endl; 
   //std::cout << L.length()<< std::endl; 
    }
    
   return *this; //this is a pointer so return deferenced
}





























