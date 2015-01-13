/*
 * Probe.cpp
 *
 *  Created on: 13 Jan, 2015
 *      Author: Travis
 */

#include "Probe.h"

namespace RTGrapher {

Probe::Probe(double *value) {
	this->value=*value;
	activated=true;
	probeList.push_back(*this);
	reference=value;
}
Probe::Probe(int *value) {
	this->value=*value;
	activated=true;
	probeList.push_back(*this);
	reference=value;
}
Probe::Probe(float *value) {
	this->value=*value;
	activated=true;
	probeList.push_back(*this);
	reference=value;
}
Probe::Probe(long *value) {
	this->value=*value;
	activated=true;
	probeList.push_back(*this);
	reference=value;
}
Probe::Probe(short *value) {
	this->value=*value;
	activated=true;
	probeList.push_back(*this);
	reference=value;
}
void Probe::Probe::update(){
	if(Probe::probeList.size()==0)return;
	for(std::list<Probe>::iterator it=Probe::probeList.begin();
			it!=probeList.end();it++){
		if(it->isActivated()){
			it->value=*(it->reference);
		}
	}
}
void Probe::Probe::broadcast(){
	if(!Probe::Probe::broadcaster)return;
	update();
	if(Probe::probeList.size()!=0){
		for(std::list<Probe>::iterator it=Probe::probeList.begin();
					it!=probeList.end();it++){
				if(it->isActivated()){
					broadcaster(it->value);
				}
		}
	}
}
void Probe::Probe::activateAll(){
	if(Probe::probeList.size()==0)return;
		for(std::list<Probe>::iterator it=Probe::probeList.begin();
				it!=probeList.end();it++){
			it->setActivate(true);
		}
}
void Probe::Probe::deactivateAll(){
	if(Probe::probeList.size()==0)return;
		for(std::list<Probe>::iterator it=Probe::probeList.begin();
				it!=probeList.end();it++){
			it->setActivate(false);
		}
}

void Probe::Probe::setActivate(bool flag){
	activated=flag;
}
bool Probe::Probe::isActivated(){
	return activated;
}
template<typename T>
void Probe::Probe::setBroadcaster(std::function<void(T)> broadcaster){
	Probe::Probe::broadcaster=broadcaster;
}
Probe::~Probe() {
	// TODO Auto-generated destructor stub
	delete reference;
	Probe::probeList.erase(std::find(Probe::probeList.begin()
			, Probe::probeList.end(),1));
}

} /* namespace RTGrapher */
