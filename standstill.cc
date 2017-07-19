#include "standstill.h"

Standstill:: Standstill(Player *o):{
    name = "Standstill";
    cost = 3;
    description = "Whenever a minion enters play, destroy it"
    owner = o;

    ability = new Ability();
    ability.subscriptionType::minionBirth; // ????

    activationCost = 2;
    charges = 4;
}


Standstill::void useAbility(Target *t=nullptr){
    if(canActivate()){
         // need to see implementation of minion
        charges -= activationCost;
    }
}
