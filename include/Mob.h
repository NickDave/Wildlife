#ifndef MOB_H
#define MOB_H

#include <vector>
#include "FiniteStateMachine.h"
#include "Coord.h"

class Mob
{
private:
	FiniteStateMachine mind_;

	Mob* target_;

	Coord pos_;

	float x_vel_;
	float y_vel_;

	void initiliaze();

public:
	static std::vector<Mob*> container;

	Mob();
	~Mob();

	static void deleteAll();

	static int mobCount();

	static float getVertices();

	int xPos();
	int yPos();
	
	Mob* getMob();
	Mob* target();

	void xPos( int const x_pos );
	void yPos( int const y_pos );
	void target( Mob* const target );
	void process();
};

#endif
