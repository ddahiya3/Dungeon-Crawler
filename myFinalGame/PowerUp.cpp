#include "ofMain.h"

#include "PowerUp.h"

void PowerUp::setup(bool time_based, string stat, ofImage * _img) {

	if (time_based) {
		time_effect = true;
	} else {
		time_effect = false;
	}
	affect = calculate_affected_stat(stat);

	if (time_based) {
		time_of_boost = 5000;
	}

	start_time = ofGetElapsedTimeMillis();

	stat_boosted = stat;

	img = _img;

	pos.x = ofRandom(0, ofGetWidth());

	pos.y = ofRandom(0, ofGetHeight());

	width = img->getWidth();
}

float PowerUp::calculate_affected_stat(string stat) {

	if (stat == "health_no_time" && !time_effect) {
		return 1;
	} else if (stat == "health_time") {
		return 100;
	} else if (stat == "speed") {
		return 5;
	} else if (stat == "damage") {
		return 3;
	} 
}

void PowerUp::draw() {
	
	img->draw(pos.x - width / 2, pos.y - width / 2);

}
