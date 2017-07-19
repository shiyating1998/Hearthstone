#include <vector>
#include <string>
#include <Card.h>
class Ritual: public Card { //abstract

	Ability *ability;
	int activationCost;
	int charges;

public:
    Boolean canActivate();
    virtual void useAbility(Target *t=nullptr)=0;
	virtual ~Ritual();

};
