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

	collision_sound.load("hitsound.wav");

	player_1.setup(&player_image);
}

//--------------------------------------------------------------
void ofApp::update(){

	if (game_state == "start") {

	} else if (game_state == "game") {
		player_1.update();
		update_projectiles();
		enemy_and_projectiles_out_of_bounds();

		for (int i = 0; i < enemies.size(); i++) {
			enemies[i].update();
			if (enemies[i].time_to_shoot()) {
				Projectile new_projectile;
				new_projectile.setup(false, enemies[i].pos, empty_point, enemies[i].speed, &enemy_bullet_image, player_1.pos,"base_enemy");
				projectile_list.push_back(new_projectile);
			}
		}

		if (game_brain.should_spawn()) {
			Enemy new_enemy;
			new_enemy.setup(max_enemy_shoot_interval, &enemy_image, "base_enemy");
			enemies.push_back(new_enemy);
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
		draw_lives();

		for (int i = 0; i < enemies.size(); i++) {
			enemies[i].draw();
		}

		for (int i = 0; i < projectile_list.size(); i++) {
			projectile_list[i].draw();
		}
	} else if (game_state == "end_loss") {
		end_screen.draw(0, 0);
		//draw_score();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (game_state == "game") {
		if (key == OF_KEY_LEFT || key == 'A' || key == 'a') {
			player_1.is_left_pressed = true;
		}

		if (key == OF_KEY_RIGHT || key == 'D' || key == 'd') {
			player_1.is_right_pressed = true;
		}

		if (key == OF_KEY_UP || key == 'W' || key == 'w') {
			player_1.is_up_pressed = true;
		}

		if (key == OF_KEY_DOWN || key == 'S' || key == 's') {
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
		if (key == OF_KEY_LEFT || key == 'A' || key == 'a') {
			player_1.is_left_pressed = false;
		}

		if (key == OF_KEY_RIGHT || key == 'D' || key == 'd') {
			player_1.is_right_pressed = false;
		}

		if (key == OF_KEY_UP || key == 'W' || key == 'w') {
			player_1.is_up_pressed = false;
		}

		if (key == OF_KEY_DOWN || key == 'S' || key == 's') {
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
	new_projectile.setup(true, player_1.pos, temp_point, player_1.speed, &player_bullet_image,player_1.pos,"base_player");
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
		check_collisions();
	}
}


//--------------------------------------------------------------
void ofApp::check_collisions() {
	for (int i = 0; i < projectile_list.size(); i++) {
		if (projectile_list[i].from_player) {
			for (int e = enemies.size() - 1; e >= 0; e--) {
				if (ofDist(projectile_list[i].pos.x, projectile_list[i].pos.y, enemies[e].pos.x, enemies[e].pos.y) < (enemies[e].width + projectile_list[i].width) / 2) {
					if (enemies[e].health - projectile_list[i].damage_per_hit <= 0) {
						enemies.erase(enemies.begin() + e);
						score += 10;
					} else {
						enemies[e].health -= projectile_list[i].damage_per_hit;
					}
					projectile_list.erase(projectile_list.begin() + i);
					collision_sound.play();
				}
			}
		} else {
			if (ofDist(projectile_list[i].pos.x, projectile_list[i].pos.y, player_1.pos.x, player_1.pos.y) < (projectile_list[i].width + player_1.width) / 2) {
				if (player_1.damage_taken_per_life + projectile_list[i].damage_per_hit >= 10) {
					player_1.lives--;
					player_1.damage_taken_per_life = 0; 
				} else {
					player_1.damage_taken_per_life += projectile_list[i].damage_per_hit;
				}

				projectile_list.erase(projectile_list.begin() + i);
				
				if (player_1.lives <= 0) {
					game_state = "end_loss";
				}
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::change_current_level() {

	if (score > 300) {
		game_state = "end_win";
	} else if (score >= 200) {
		game_brain.current_level = 2;
	} else if (score >= 100) {
		game_brain.current_level = 1;
	}

}

//--------------------------------------------------------------
void ofApp::enemy_and_projectiles_out_of_bounds() {

	for (int i = 0; i < projectile_list.size(); i++) {
		if (projectile_list[i].pos.x > ofGetWidth() || projectile_list[i].pos.x < 0 || projectile_list[i].pos.y > ofGetHeight() || projectile_list[i].pos.y < 0) {
			projectile_list.erase(projectile_list.begin() + i);
		}
	}
	
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i].pos.x > ofGetWidth() || enemies[i].pos.x < 0 || enemies[i].pos.y > ofGetHeight() || enemies[i].pos.y < 0) {
			enemies.erase(enemies.begin() + i);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw_lives() {

	for (int i = 0; i < player_1.lives; i++) {
		player_image.draw(i * player_image.getWidth() + 10, ofGetHeight() - player_image.getHeight() - 5);
	}

}


