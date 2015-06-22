//
//  main.cpp
//  Sandbox
//
//  Created by David Silvester on 21/06/2015.
//  Copyright (c) 2015 David Silvester. All rights reserved.
//

#include <iostream>
#include "stdafx.h"
#include "Contact.h"

bool NameIsFrank(std::unique_ptr<Contact>& contact)
{
    if (contact->Name() == "Frank")
    {
        return true;
    }   else return false;
}

int main(int argc, const char * argv[]) {

    std::cout << "Running Sandbox\n\n";
    
    // Vector to store some contacts
    std::vector<std::unique_ptr<Contact>> contactList;
    
    // Some contacts to put in our list
    std::unique_ptr<Contact> george(new Contact("George", 149));
    std::unique_ptr<Contact> ben(new Contact("Ben", 149));
    std::unique_ptr<Contact> frank(new Contact("Frank", 149));
    
    if ( NameIsFrank(frank) )
    {
        std::cout << "It's Franks!" << std::endl;
    }
    
    // Add the contacts to the list
    contactList.push_back(std::move(george));
    contactList.push_back(std::move(ben));
    contactList.push_back(std::move(frank));
    
    // TEST
    
    
    // Print out the names of the contacts
    for (auto it = contactList.cbegin(); it < contactList.cend(); ++it)
    {
        Contact temp = *it->get();
        std::cout << temp.Name() << std::endl;
        
    }
    
    // Find the first contact whose name is Ben
    auto it = std::find_if(contactList.cbegin(), contactList.cend(),
                           [&] (std::unique_ptr<Contact> const& contact) { return contact.get()->Name() == "Ben"; } );
    
    // Must check nullptr in case Ben wasn't found
    if (*it != nullptr)
    {
        Contact temp = *it->get();
        std::cout << "Ben's number is: " << temp.Number() << std::endl;
    }
    
    return 0;
}