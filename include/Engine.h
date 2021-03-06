#ifndef ENGINE_H
#define ENGINE_H

#include "Debug.h"
#include "EngineStateMachine.h"
#include "State.h"

class Engine
{
private:
	Engine();

	EngineStateMachine state_;
	static Engine* instance_;

public:
	static Engine* getInstance();
	static void resetInstance();
	static unsigned int getRand( unsigned int mod = 0 );

	virtual ~Engine();

	void handle();

	bool shouldStop();
};

#endif
