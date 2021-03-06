 #ifndef FINITESTATEMACHINE_H
#define FINITESTATEMACHINE_H

#include "State.h"

/*
	This is a finite state machine, which uses various instances
	of State. Each State is responsible for transitioning into
	the next appropriate state, as well as any processing the state
	should do.
*/

class FiniteStateMachine
{
protected:
	void cleanup();

	State* state_;

public:
	FiniteStateMachine();
	FiniteStateMachine( State* const state ); // To force a state on initialization
	~FiniteStateMachine();

	void changeState(); // Just call this to process the current state
	void forceState( State* const state ); // Call this to force the state machine to assume the given state

	State* const currentState(); // Returns the current state
	
	char const* getStateName(); // Returns the name of the current state
};

#endif
