#ifndef FINITESTATEMACHINE_H
#define FINITESTATEMACHINE_H

#include <stack>

/*
	This is a finite state machine that utilizes a stack of function
	pointers to switch between states. To switch between states, use 
	the pushState and popState.

	Each mob has a FSM as a "mind" and so to use it, you need to define 
	the mob's different behaviors as void funcs.
*/ 

typedef void(*voidptr)(); // dear god, I hate this syntax

class FiniteStateMachine
{
private:
	std:stack <voidptr> stack;

public:
	FiniteStateMachine();
	~FiniteStateMachine();
	
	void process();
	void pushState( voidptr state );

	voidptr popState();
	voidptr getState();
};

FiniteStateMachine::FiniteStateMachine()
{

}

FiniteStateMachine::~FiniteStateMachine()
{

}

void FiniteStateMachine::process()
{
	voidptr state = getState();

	if( state != nullptr )
	{
		state();
	}
}

void FiniteStateMachine::pushState( voidptr state )
{
	if( state != getState() )
	{
		stack.push( state );
	}
}

voidptr FiniteStateMachine::popState()
{
	if( stack.size() > 0 )
	{
		return stack.pop();
	}
	else
	{
		return nullptr;
	}
}

voidptr FiniteStateMachine::getState()
{
	if( stack.size() > 0 )
	{
		return stack.top();
	}
	else
	{
		return nullptr;
	}
}

#endif
