#include "ListNode.h"
using namespace std;

namespace cs32 {

ListNode::ListNode( string v,
                    ListNode * node ) {
	value = v;
	next = node;
}

bool ListNode::nextIsNull() const {
	return( next == nullptr );
}

string ListNode::getElement() const {
	return( value );
}

ListNode * ListNode::getNext() const {
	return( next );
}

void ListNode::setNext( ListNode * node ) {
	next = node;
}

}


