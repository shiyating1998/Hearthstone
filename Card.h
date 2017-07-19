
#include <vector>
#include <string>
#include "Player.h"

class Card { // abstract class

	string name;
	int cost;
	string description;
	Player *Owner;

public:

	virtual ~Card();
	enum cardType {Minion = 0, Spell, Enchantment, Ritual}
	virtual cardType getType()=0;

};

std::ostream &operator<<(std::ostream &out, const Card &c);
