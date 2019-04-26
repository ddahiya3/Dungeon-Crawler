#include "ofApp.h"


string game_state;
int score;
Player player_1;

//--------------------------------------------------------------
void ofApp::setup(){

	game_state = "start";

	enemy_image.load("enemy0.png");
	player_image.load("player.png");
	enemy_bullet_image.load("enemy_bullet.png");
	player_bullet_image.load("player_bullet.png");
	life_image.load("life_image.png");

	start_screen.load("start_screen.png");
	end_screen.load("end_screen.png");
	score_font.load("font2.otf", 48);

	player_1.setup(&player_image);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (game_state == "game") {
		if (key == OF_KEY_LEFT) {
			player_1.is_left_pressed = true;
		}

		if (key == OF_KEY_RIGHT) {
			player_1.is_right_pressed = true;
		}

		if (key == OF_KEY_UP) {
			player_1.is_up_pressed = true;
		}

		if (key == OF_KEY_DOWN) {
			player_1.is_down_pressed = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	if (game_state == "start") {
		game_state = "game";
		//level_controller.setup(ofGetElapsedTimeMillis());
	} else if (game_state == "game") {
		if (key == OF_KEY_LEFT) {
			player_1.is_left_pressed = false;
		}

		if (key == OF_KEY_RIGHT) {
			player_1.is_right_pressed = false;
		}

		if (key == OF_KEY_UP) {
			player_1.is_up_pressed = false;
		}

		if (key == OF_KEY_DOWN) {
			player_1.is_down_pressed = false;
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	Projectile new_projectile;
	ofPoint temp_point;
	temp_point.x = x;
	temp_point.y = y;
	new_projectile.setup(true, player_1.pos, temp_point, player_1.speed, &player_bullet_image);
	projectile_list.push_back(new_projectile);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::update_bullets() {
	for (int i = 0; i < projectile_list.size(); i++) {
		projectile_list[i].update();
		if (projectile_list[i].pos.y == projectile_list[i].mouse_clicked_at.y || projectile_list[i].pos.x == projectile_list[i].mouse_clicked_at.x) {
			projectile_list.erase(projectile_list.begin() + i);
		}
	}
	//check_bullet_collisions();
}
