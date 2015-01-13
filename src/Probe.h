/*
 * Probe.h
 *
 *  Created on: 13 Jan, 2015
 *      Author: Travis
 */

#ifndef PROBE_H_
#define PROBE_H_
#include <list>
#include <cstdlib>
#include <cstdio>
#include <functional>
namespace RTGrapher {

class Probe {
public:
	Probe(double *value);
	Probe(int *value);
	Probe(float *value);
	Probe(long *value);
	Probe(short *value);
	virtual ~Probe();
	static std::list<Probe> probeList;
	static void update();
	static void broadcast();
	static void deactivateAll();
	static void activateAll();
	template<typename T>
	static void setBroadcaster(std::function<void(T)> broadcaster);
	void setActivate(bool flag);
	bool isActivated();
private:
	double value;
	bool activated;
	auto reference;
	static auto broadcaster;
};

} /* namespace RTGrapher */

#endif /* PROBE_H_ */
