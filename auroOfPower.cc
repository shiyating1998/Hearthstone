#include "auraOfPower.h"

AuraOfPower:: AuraOfPower(Player *o):{
    name = "AuraOfPower";
    cost = 1;
    description = "Whenever a minion enter a play under your control, it gains +1/+1"
    owner = o;

    ability = new Ability();
    ability.subscriptionType::minionBirth; // ????

    activationCost = 1;
    charges = 4;
}


AuraOfPower::void useAbility(Target *t=nullptr){
    if(canActivate()){
         // need to see implementation of minion
        charges -= activationCost;
    }
}
