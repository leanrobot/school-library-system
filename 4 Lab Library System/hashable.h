//-----------------------------------------------------------------------------
// HASHABLE.H
// Hashable Class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// Hashable class: is a an abstract class which is a representaion of class
// which can be hashed
//-----------------------------------------------------------------------------
#ifndef __HASHABLE_H
#define __HASHABLE_H

class Hashable {
public:
    
    // hash
    // Pure virtual method which will be implementd in child classes
    virtual char hash() const = 0;
};

#endif /*HASHABLE_H*/
