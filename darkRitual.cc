
#include "darkRitual.h"


DarkRitual:: DarkRitual(Player *o):{
    name = "DarkRitual";
    cost = 0;
    description = "At the start of your turn, gain 1 magic"
    owner = o;

    ability = new Ability();
    ability.subscriptionType::startTurn; // ????

    activationCost = 1;
    charges = 5;
}



DarkRitual::void useAbility(Target *t=nullptr){
    if(canActivate()){
        o->gainMP();
        charges -= activationCost;
    }
}
