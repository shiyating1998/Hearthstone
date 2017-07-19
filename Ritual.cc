#include "Ritual.h"
Ritual::~Ritual(){
    delete ability;
}

Ritual::getType() {
    return cardType::Ritual;
}

Ritual::canActivate(){
    return (charges - activationCost) > 0;
}
