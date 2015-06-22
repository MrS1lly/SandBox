//
//  Contact.h
//  Sandbox
//
//  Created by David Silvester on 21/06/2015.
//  Copyright (c) 2015 David Silvester. All rights reserved.
//

#pragma once
#include <string>

class Contact
{
public:
    
    Contact(const std::string& name, const uint16_t& number);

    ~Contact(void);
    
    uint16_t Number(void) { return m_number; };
    std::string Name(void) { return m_name; };
    
private:
    
    Contact(void);
    
    std::string m_name;
    uint16_t m_number;
};
