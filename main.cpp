//
//  main.cpp
//  MenuDrivenList
//
//  Created by Danielle Choi on 11/2/23.
//  Copyright © 2023 SMC Software. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
#include "List.h"
#include "ListNode.h"

int main()
{
    using namespace std;
    using namespace cs32;

    // test code

    // the get function enables a client to iterate over all elements of a List
    List l1;
    assert( l1.min() == "" );
    l1.addToFront("Hawkeye");
    l1.addToFront("Thor");
    l1.addToFront("Hulk");
    l1.addToFront("Black Widow");
    l1.addToFront("Iron Man");
    l1.addToFront("Captain America");
    for (int k = 0; k < l1.size(); k++)
    {
        string x;
        l1.get(k, x);
        cout << x << endl;
    }
    // should print:
    // Captain America
    // Iron Man
    // Black Widow
    // Hulk
    // Thor
    // Hawkeye

    assert( l1.position( "Hawkeye" ) == 5 );
    assert( l1.position( "Thor" ) == 4 );
    assert( l1.position( "Hulk" ) == 3 );
    assert( l1.position( "Black Widow" ) == 2 );
    assert( l1.position( "Iron Man" ) == 1 );
    assert( l1.position( "Captain America" ) == 0 );
    assert( l1.position( "Not there" ) == -1 );

    assert( l1.before( "Not there", "Hulk" ) == false );
    assert( l1.before( "Hulk", "Not there" ) == false );
    assert( l1.before( "Hulk", "Captain America" ) == false );
    assert( l1.before( "Black Widow", "Hulk" ) == true );
    assert( l1.before( "Captain America", "Hulk" ) == true );
    assert( l1.before( "Captain America", "Captain America" ) == false );

    assert( l1.min() == "Black Widow" );

    l1.removeAllBiggerThan( "Happy" );
    // now just "Captain America", "Black Widow"
    assert( l1.size() == 2 );
    assert( l1.position( "Hawkeye" ) == -1 );
    assert( l1.position( "Thor" ) == -1 );
    assert( l1.position( "Hulk" ) == -1 );
    assert( l1.position( "Black Widow" ) == 1 );
    assert( l1.position( "Iron Man" ) == -1 );
    assert( l1.position( "Captain America" ) == 0 );
    assert( l1.position( "Not there" ) == -1 );
    
    List l2;
    assert( l2.min() == "" );
    l2.addToFront("b");
    l2.addToFront("a");
    l2.addToFront("c");
    l2.addToFront("d");
    l2.addToFront("a");
    assert( l2.before( "a", "d" ) == true ); //adcab
    assert( l2.before( "b", "d" ) == false );
    assert( l2.size() == 5 );
    assert( l2.min() == "a" );
    assert( l2.position("a") == 0 );
    for (int i = 0; i < l2.size(); i++)
    {
        string x;
        l2.get(i, x);
        cout << x << endl;
    }
    l2.removeAllBiggerThan( "b" ); //aab
    assert( l2.size() == 3 );

    cout << "all tests passed!" << endl;
    return( 0 );
}
