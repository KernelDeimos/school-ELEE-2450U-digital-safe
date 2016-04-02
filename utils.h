#ifndef UTILS_H
#define UTILS_H

boolean in_interval(int start,int value,int bound) {
	if (start <= value && value < bound)
		return true;
	return false;
}

#endif
