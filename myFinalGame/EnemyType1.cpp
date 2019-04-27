#include "ofMain.h"

#include "EnemyType1.h"

void EnemyType1::setup(float max_enemy_amplitude, float max_enemy_shoot_interval, ofImage * enemy_image) {
	pos.x = ofRandom(ofGetWidth());
	pos.y = ofRandom(ofGetHeight());
	img = enemy_image;
	width = img->getWidth();
	speed = ofRandom(2, 7);
	amplitude = ofRandom(max_enemy_amplitude);
	shoot_interval = ofRandom(0.5, max_enemy_shoot_interval);
	start_shoot = ofGetElapsedTimef();
}
void EnemyType1::update() {
	pos.y += amplitude * cos(ofGetElapsedTimef());
	pos.x += amplitude * sin(ofGetElapsedTimef());
}
void EnemyType1::draw() const {
	img->draw(pos.x - width / 2, pos.y - width / 2);
}
bool EnemyType1::time_to_shoot() {
	if (ofGetElapsedTimef() - start_shoot > shoot_interval) {
		start_shoot = ofGetElapsedTimef();
		return true;
	}
	return false;
}