#include "ofApp.h"


string game_state;
int score;
Player player_1;
ofPoint temp_point;

ofPoint empty_point;

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

	if (game_state == "start") {

	} else if (game_state == "game") {
		player_1.update();
		update_projectiles();

		for (int i = 0; i < enemies_type_1.size(); i++) {
			enemies_type_1[i].update();
			if (enemies_type_1[i].time_to_shoot()) {
				Projectile new_projectile;
				new_projectile.setup(false, enemies_type_1[i].pos, empty_point, enemies_type_1[i].speed, &enemy_bullet_image, player_1.pos);
				projectile_list.push_back(new_projectile);
			}
		}

		if (game_brain.should_spawn()) {
			EnemyType1 new_enemy;
			new_enemy.setup(max_enemy_amplitude, max_enemy_shoot_interval, &enemy_image);
			enemies_type_1.push_back(new_enemy);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	if (game_state == "start") {
		start_screen.draw(0, 0);
	} else if (game_state == "game") {
		ofBackground(0, 0, 0);
		player_1.draw();

		for (int i = 0; i < enemies_type_1.size(); i++) {
			enemies_type_1[i].draw();
		}

		for (int i = 0; i < projectile_list.size(); i++) {
			projectile_list[i].draw();
		}
	} else if (game_state == "end") {
		end_screen.draw(0, 0);
		//draw_score();
	}
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
		game_brain.setup(ofGetElapsedTimeMillis(), 5000);

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
	
	temp_point.x = x;
	temp_point.y = y;
	new_projectile.setup(true, player_1.pos, temp_point, player_1.speed, &player_bullet_image,player_1.pos);
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
void ofApp::update_projectiles() {
	for (int i = 0; i < projectile_list.size(); i++) {
		projectile_list[i].update();
		if (projectile_list[i].pos.y == projectile_list[i].mouse_clicked_at.y && projectile_list[i].pos.x == projectile_list[i].mouse_clicked_at.x) {
			projectile_list.erase(projectile_list.begin() + i);
		}
	}
}
