#include "ofMain.h"

#include "GameBrain.h"

void GameBrain::setup(float s_t, float i_t) {
	start_time = s_t;
	interval_time = i_t;
}
bool GameBrain::should_spawn() {
	if (ofGetElapsedTimeMillis() - start_time > interval_time) {
		start_time = ofGetElapsedTimeMillis();
		return true;
	}
	return false;
}