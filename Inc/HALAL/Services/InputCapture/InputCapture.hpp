/*
 * InputCapture.hpp
 *
 *  Created on: 30 oct. 2022
 *      Author: aleja
 */

#pragma once
#include "ST-LIB.hpp"

class IC {
public:
	static map<uint8_t, Pin> serviceIDs;
	static map<Pin, TimerChannel> pinTimerMap;
	static map<TimerChannel, pair<int, int> > data;

	static forward_list<uint8_t> IDmanager;
	static optional<uint8_t> register_ic(Pin& pin);
	static void unregister_ic(uint8_t id);
	static void turn_on_ic(uint8_t);
	static void turn_off_ic(uint8_t);
	static float read_frequency(uint8_t id);
	static uint8_t read_duty_cycle(uint8_t id);
};
