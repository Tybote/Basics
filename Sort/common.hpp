#include <cstdlib>
#include <time.h>

class Common {
	int size;
public:
	Common();
	Common(int s);
	~Common();	
	int *IntArray;
	float *FloatArray;
	void setSize(int s);
	int getSize();
};