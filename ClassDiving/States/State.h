#pragma once

class State {
public:
	virtual void update(Entity& entity) = 0;
	virtual void transition(Entity& entity) = 0;
};