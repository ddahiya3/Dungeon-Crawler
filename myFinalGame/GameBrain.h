#pragma once

class GameBrain {
public:
	float start_time;
	float interval_time;

	void setup(float s_t, float i_t);
	bool should_spawn();
};
