/**
 * @file HarryFactory.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_HARRYFACTORY_H
#define CANADIANEXPERIENCE_HARRYFACTORY_H

#include "Actor.h"

/**
 * Factory class that builds the Harold character
 */
class HarryFactory {
private:

public:
    std::shared_ptr<Actor> Create(std::wstring imagesDir);

};

#endif //CANADIANEXPERIENCE_HARRYFACTORY_H
