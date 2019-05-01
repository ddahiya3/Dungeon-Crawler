#include "ofMain.h"

#include "Enemy.h"

void Enemy::setup(float max_enemy_shoot_interval, ofImage * enemy_image, string enemy_type) {

	pos.x = ofRandom(ofGetWidth() - 150);
	pos.y = ofRandom(ofGetHeight() - 150);
	img = enemy_image;
	width = img->getWidth();
	shoot_interval = ofRandom(0.5, max_enemy_shoot_interval);
	start_shoot = ofGetElapsedTimef();
	speed = ofRandom(1, 3);
	type_of_enenmy = enemy_type;
	health = calculate_health(enemy_type);

}
void Enemy::update() {

	pos.y += cos(ofGetElapsedTimef()) + ofRandom(-5, 5);
	pos.x += sin(ofGetElapsedTimef()) + ofRandom(-5, 5);
	
}
void Enemy::draw() const {
	img->draw(pos.x - width / 2, pos.y - width / 2);
}
bool Enemy::time_to_shoot() {
	if (ofGetElapsedTimef() - start_shoot > shoot_interval) {
		start_shoot = ofGetElapsedTimef();
		return true;
	}
	return false;
}

float Enemy::calculate_health(string enemy) {
	if (enemy == "base_enemy") {
		return 1.0;
	} else if (enemy == "second_form_enemy") {
		return 3.0;
	} 
}