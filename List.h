#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include "ListNode.h"

namespace cs32 {

class List {
public:
	List();
	List( const List& rhs );
	~List();

	bool isEmpty() const;
	void makeEmpty();
    void addToFront( const std::string & data );
    void addToRear( const std::string & data );
    void deleteItem( const std::string & data );
    bool findItem( const std::string & data );
    std::string printItems( );
	
	const List& operator =( const List& rhs );
    
    size_t size() const;
    int position( const std::string& data ) const;
    bool before( const std::string& before, const std::string& after ) const;
    bool get( int i, std::string& data ) const;
    std::string min( ) const;
    void removeAllBiggerThan( const std::string& data );
    
private:
	ListNode * head;
	
};

}
#endif
