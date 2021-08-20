#pragma once
#include <string>
#include <iostream>

class Old_Cellphone
{
public:
	const int MIN_CAP = 10;
	const int MAX_CAP = 1000;

private:
	int    mem_capacity;
	bool   with_camera;
	bool   with_gps;

public:
	Old_Cellphone(int mem, bool cam, bool gps) {
		mem_capacity = mem;
		with_camera = cam;
		with_gps = gps;
	};
	bool set_mem_capacity(int mem);
	void set_camera(bool has_cam) { with_camera = has_cam; }
	void set_gps(bool has_gps) { with_gps = has_gps; }
	bool add_memory(int mem_add)
	{
		if (mem_add + mem_capacity > MAX_CAP) {
			return false;
		}
		mem_capacity += mem_add;
		return true;
	};
};