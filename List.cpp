#include "List.h"

using namespace std;

namespace cs32 {

List::List() {
	head = nullptr;
}

List::List( const List& rhs ) {
    if (rhs.head == nullptr) head = nullptr;
    else {
        head = new ListNode( rhs.head->getElement() );
        ListNode *q = head;
        ListNode *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new ListNode( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            p = p->getNext( );
            q = q->getNext( );
        }
    }
}

List::~List() {
	makeEmpty();
}

bool List::isEmpty() const {
	return( head == nullptr );
}

void List::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

void List::addToFront( const std::string & data )
{
    ListNode * newnode = new ListNode( data );
    newnode->setNext( head );
    head = newnode;
}

void List::addToRear( const std::string & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode * newnode = new ListNode( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

void List::deleteItem( const std::string & data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;

        while( node != nullptr )
        {
            if (node->getElement() == data)
            {
                if (priornode != nullptr)
                    priornode->setNext( node->getNext( ) );
                else
                    head = node->getNext();
                delete( node );
                break;
            }
            priornode = node;
            node = node->getNext();
        }
}

bool List::findItem( const std::string & data )
{
    bool result = false;
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            result = true;
            break;
        }
        node = node->getNext();
    }
    return( result );
}

std::string List::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += node->getElement();
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}


// Deep copy of linked list
const List& List::operator =( const List& rhs ) {
	if (this != &rhs) {
		makeEmpty();

        ListNode * right = rhs.head;

		while( right != nullptr )
        {
            addToRear( right->getElement() );
            right = right->getNext();
		}
	}

	return( *this );
}


size_t List::size() const {
    ListNode * node = head; //make a node to track location
    int num = 0;
    while( node != nullptr ){
        num++; //increase the number of the node
        node = node->getNext(); //set the node to the next node
    }
    return num; //return the total number of data values on the list
}

int List::position( const std::string& data ) const {
    ListNode * node = head; //to track location
    int index=0;
    while( node != nullptr ){
        if( node->getElement() == data ) //if data is found
            return index;
        index++; //increase the index
        node = node->getNext(); //set the node to the next node
    }
    return -1; //if the data is not found
}

bool List::before( const std::string& before, const std::string& after ) const {
    if( position(before) == -1 || position(after) == -1 ) //if neither values not exists
        return false;
    ListNode * node = head; //to track location
    int index = 0 , iBefore = 0 , iAfter = 0; //total index, index of before value, index of after value
    while( node != nullptr ){ //first seek the index of before value
        if( node->getElement() == before ){ //if before value is found,
            iBefore = index; //set before index as the current index
            break; //and get out of the loop
        }
        index++; //if before value not found, increase index
        node = node->getNext(); //move to next node
    }
    while( node != nullptr ){ //seek index of after value
        if ( node->getElement() == after ){ //if after value is found,
            iAfter = index; //set after index as the current index
            break; //and get out of the loop
        }
        index++; //if after value not found, increase index
        node = node->getNext(); //move to next node
    }
    if( iBefore < iAfter) //if before index is smaller then after index
        return true;
    return false; //if before index is same or greater than after index
}

bool List::get( int i, std::string& data ) const {
    ListNode * node = head; //to track location
    int index=0;
    while( node != nullptr ){
        if(index == i ){ //if index reaches the i value
            data = node->getElement(); //set  data value as the element of node
            return true;
        }
        index++; //if index is not the i value, increase index
        node = node->getNext(); //move to next node
    }
    return false;
}

std::string List::min( ) const {
    if( isEmpty() )
        return "";
    ListNode * node = head; //to track location
    string min = node -> getElement(); //set min as the first element of list
    while( node != nullptr ){
        if( min > node->getElement() ) //if min value is bigger than the current element
            min = node->getElement(); //set min value as the current element
        node = node->getNext(); //move to next node
    }
    return min;
}

//Alters the list by removing all the items bigger than data that were originally on the list.   HINT: std::string supports < and > to do string comparisons
void List::removeAllBiggerThan( const std::string& data ) {
    ListNode * node = head; //to track location
    ListNode * priornode = nullptr; //to track location of the prior node
    
    while( node != nullptr ){
        if( node->getElement() > data ){ //if the current element is bigger than data value
            ListNode * tempNode = node; //set a temporary node to delete (preventing error)
            if( priornode != nullptr ){ //if the current node is not the first node
                priornode->setNext(node->getNext()); //set next value of the prior node as the next value of current node
            } else { //if the current node is the first node
                head = node->getNext(); //move the head value to next node
            }
            node = node->getNext(); //set node as the next node
            delete( tempNode ); //delete temporary node
        } else { //if the current element is the smae or smaller than data value
            priornode = node; //move prior node to the current node
            node = node->getNext(); //move node to the next node
        }
    }
}

}
