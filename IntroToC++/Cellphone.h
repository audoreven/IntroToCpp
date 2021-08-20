#pragma once
#include <string>

class Old_cell_phone
{
public:
	const int MIN_CAP = 10;
	const int MAX_CAP = 1000;

private:
	string description;
	int    mem_capacity;
	bool   with_camera;
	bool   with_gps;

public:
	Old_cell_phone(int mem, bool cam, bool gps);
	bool set_mem_capacity(int mem);
	void set_camera(bool has_cam) { with_camera = has_cam; }
	void set_gps(bool has_gps) { with_gps = has_gps; }
};

