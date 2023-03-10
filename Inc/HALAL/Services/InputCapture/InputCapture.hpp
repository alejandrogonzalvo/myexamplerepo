/*
 * InputCapture.hpp
 *
 *  Created on: 30 oct. 2022
 *      Author: aleja
 */

#pragma once
#include "ST-LIB.hpp"

#define IC_OVERFLOW 0xffffffff

static map<uint32_t, uint32_t> channel_dict = {
	{HAL_TIM_ACTIVE_CHANNEL_1, TIM_CHANNEL_1},
	{HAL_TIM_ACTIVE_CHANNEL_2, TIM_CHANNEL_2},
	{HAL_TIM_ACTIVE_CHANNEL_3, TIM_CHANNEL_3},
	{HAL_TIM_ACTIVE_CHANNEL_4, TIM_CHANNEL_4},
	{HAL_TIM_ACTIVE_CHANNEL_5, TIM_CHANNEL_5},
	{HAL_TIM_ACTIVE_CHANNEL_6, TIM_CHANNEL_6}
};

class IC {
public:
	class Instance {
	public:
		uint8_t id;
		Pin pin;
		TIM_HandleTypeDef* timer;
		uint32_t channel_rising;
		uint32_t channel_falling;
		uint32_t frequency;
		uint8_t duty_cycle;

		Instance() = default;
		Instance(Pin pin, TIM_HandleTypeDef* timer, uint32_t channel_rising, uint32_t channel_falling);
	};

	static map<uint8_t, IC::Instance> instances;
	static map<Pin, IC::Instance> instances_data;
	static forward_list<uint8_t> id_manager;

	static optional<uint8_t> register_ic(Pin& pin);
	static void unregister_ic(uint8_t id);
	static void turn_on_ic(uint8_t id);
	static void turn_off_ic(uint8_t id);
	static uint32_t read_frequency(uint8_t id);
	static uint8_t read_duty_cycle(uint8_t id);
	static Instance find_instance_by_channel(uint32_t channel);
};
