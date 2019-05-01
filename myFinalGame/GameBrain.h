#pragma once

class GameBrain {
public:
	float start_time;
	float interval_time_enemies;
	

	int current_level;

	void setup(float s_t, float i_t);

	bool should_spawn_enemies();
	bool should_spawn_powerups(int enemies_killed);
};
