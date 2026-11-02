#pragma once

class State {
public:
	virtual void update() = 0;
	virtual void transition(void (*funcPtr)()) = 0;
};