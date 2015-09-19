#ifndef ENGINE_H
#define ENGINE_H

#include "Debug.h"
#include "State.h"
#include "EngineStates.h"

class Engine
{
private:
	Engine();

	FiniteStateMachine state_;
	static Engine* instance_;

public:
	static Engine* getInstance();

	virtual ~Engine();

	void handle();

	bool shouldStop();
};

Engine* Engine::instance_ = nullptr;

Engine::Engine()
{
	debugging( "ENGINE INSTANTIZED" );
	FiniteStateMachine state_( new EngineStart );
}

Engine::~Engine()
{
	delete instance_;
}

Engine* Engine::getInstance()
{
	Engine* instance = instance_;

	if( !instance_ )
	{
		instance_ = new Engine;
	}
	
	return instance;
}

void Engine::handle()
{
	FiniteStateMachine.handle();
}

bool Engine::shouldStop()
{
	if( state_.getState() == nullptr )
	{
		return true;
	}

	return false;
}

#endif
