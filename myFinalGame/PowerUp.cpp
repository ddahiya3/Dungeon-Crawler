#include "ofMain.h"

#include "PowerUp.h"

void PowerUp::setup(bool time_based, string stat) {

	if (time_based) {
		time_effect = true;
	} else {
		time_effect = false;
	}
	affect = calculate_affected_stat(stat);

	if (time_based) {
		time_of_boost = 5;
	}

	start_time = ofGetElapsedTimeMillis();

	stat_boosted = stat;
}

float PowerUp::calculate_affected_stat(string stat) {
	
	if (stat == "health") {
		return 10;
	} else if (stat == "speed") {
		return 5;
	} else if (stat == "damage") {
		return 3;
	} else {
		return 100;
	}
}
