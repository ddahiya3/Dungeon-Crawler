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

		ofImage enemy_base_form;
		ofImage enemy_second_form;

		ofImage start_screen;
		ofImage end_screen_loss;ofImage pause_screen;
		ofImage end_screen_win;

		ofImage background_game;

		ofImage invincible_text;

		ofImage berzerker_right;
		ofImage berzerker_left;
		ofImage berzerker_up;

		ofImage clown_right;
		ofImage clown_left;
		ofImage clown_up;

		ofImage rogue_right;
		ofImage rogue_left;
		ofImage rogue_up;

		ofImage ninja_right;
		ofImage ninja_left;
		ofImage ninja_up;

		ofImage knight_right;
		ofImage knight_left;
		ofImage knight_up;

		ofImage priest_right;
		ofImage priest_left;
		ofImage priest_up;

		ofImage shottyguy_right;
		ofImage shottyguy_left;
		ofImage shottyguy_up;

		ofImage engineer_right;
		ofImage engineer_left;
		ofImage engineer_up;

		ofImage wizard_right;
		ofImage wizard_left;
		ofImage wizard_up;

		ofImage doctor_right;
		ofImage doctor_left;
		ofImage doctor_up;

		ofImage powerup_speed;
		ofImage powerup_health;
		ofImage powerup_damage;

		ofxIntSlider spritenumbers;

		ofxPanel panel;

		ofxButton play_1;
		ofxButton play_2;
		ofxButton stop;

		void play_pressedGUGD();
		void play_pressedSSS();
		void stop_pressed();


		ofTrueTypeFont score_font;

		ofSoundPlayer collision_sound;
		ofSoundPlayer hit_player;
		ofSoundPlayer GUGD_sound;
		ofSoundPlayer SSS_sound;


		vector<Projectile> projectile_list;
		vector<Enemy> enemies;
		vector <PowerUp> power_ups;

		float max_enemy_shoot_interval = 1.0;

		GameBrain game_brain;

		void update_projectiles();

		void check_collisions();

		void change_current_level();

		void enemy_and_projectiles_out_of_bounds();

		void draw_invincible();

		void check_powerup_collision();

		void change_sprite(int sprite_number);

		void reset_pause_timers();
		
		void spawn_random_powerups();

		void spawn_needed_enemy();
};
