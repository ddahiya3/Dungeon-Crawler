#pragma once

class PowerUp {

public :

	ofPoint pos;

	float width;

	bool time_effect;

	float time_of_boost;

	float start_time;

	string stat_boosted;

	float affect;

	void setup(bool time_based, string stat, ofImage * _img);

	float calculate_affected_stat(string stat);

	void draw();

	ofImage * img;
};
