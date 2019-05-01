#pragma once

#include "ofMain.h"
#include "ofxGui.h"


#include "../Player.h"
#include "../Projectile.h"
#include "../Enemy.h"
#include "../GameBrain.h"
#include "../PowerUp.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		ofImage enemy_bullet_image;
		ofImage player_bullet_image;
		ofImage enemy_image;
		ofImage life_image;
		ofImage start_screen;
		ofImage end_screen;

		ofImage background_game;

		ofImage invincible_text;

		ofImage berzerker_right;
		ofImage berzerker_left;

		ofImage clown_right;
		ofImage clown_left;

		ofImage rogue_right;
		ofImage rogue_left;

		ofImage ninja_right;
		ofImage ninja_left;

		ofImage knight_right;
		ofImage knight_left;

		ofImage priest_right;
		ofImage priest_left;

		ofImage shottyguy_right;
		ofImage shottyguy_left;

		ofImage engineer_right;
		ofImage engineer_left;

		ofImage wizard_right;
		ofImage wizard_left;

		ofImage doctor_right;
		ofImage doctor_left;

		ofxIntSlider spritenumbers;

		ofxPanel panel;


		ofTrueTypeFont score_font;

		ofSoundPlayer collision_sound;


		vector<Projectile> projectile_list;
		vector<Enemy> enemies;
		//vector<Life> bonuses;
		vector <PowerUp> power_ups;

		float max_enemy_shoot_interval = 1.0;

		GameBrain game_brain;

		void update_projectiles();

		void check_collisions();

		void change_current_level();

		void enemy_and_projectiles_out_of_bounds();

		void draw_lives();

		void check_powerup_collision();

		void change_sprite(int sprite_number);

		void reset_pause_timers();
		
		void spawn_random_powerups();
};
