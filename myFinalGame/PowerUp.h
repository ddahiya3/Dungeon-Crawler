#pragma once

class PowerUp {

public :

	bool time_effect;

	float time_of_boost;

	float start_time;

	string stat_boosted;

	float affect;

	void setup(bool time_based, string stat);

	float calculate_affected_stat(string stat);


};
