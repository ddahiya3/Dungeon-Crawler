#include "ofMain.h"

#include "GameBrain.h"

void GameBrain::setup(float s_t, float i_t) {

	start_time = s_t;
	interval_time_enemies = i_t;
	current_level = 0;

}

bool GameBrain::should_spawn_enemies() {

	if (ofGetElapsedTimeMillis() - start_time > interval_time_enemies) {

		start_time = ofGetElapsedTimeMillis();
		return true;

	}
	return false;
}

bool GameBrain::should_spawn_powerups(int enemies_killed) {

	if (enemies_killed == 0) {
		return false;
	}
	return (enemies_killed % 5 == 0);

}