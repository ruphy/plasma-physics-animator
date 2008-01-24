#include <iostream>

using namespace std;

float s0=0;

float getXInRebounce(float time, float initialSpeed = 0)
{
    int m = 1;
//     double time = 0.01;
    double mu = 0.5;
    float g  = 9.81;
    float k = 9.81;
    float deltax = 1;
    float speed = 0;

    if (initialSpeed != s0) {
      s0 = initialSpeed;
    }

    float vincularForce = m*g;
    float friction = vincularForce*mu;
    float springForce = deltax*k;
    float totalForce = springForce - friction;

    if ((speed < 0.1 && totalForce < 0.1) || deltax < 0.1) {
	totalForce = 0;
	speed = 0;
	deltax = 0;
	return 0;
    }

    float a = totalForce/m;
    //float a=1;

    speed += a*time;

    deltax -= speed*time;

    cout << "time is:      " << time <<  " and the spring force is:   " << springForce  << endl;
    cout << "a is:   " << a << " while delta X is:    " << deltax << endl << endl;

    return deltax;
}

int main()
{


    for (double t=0; t<1; t+=0.01) { 

	if (getXInRebounce(t) == 0) {
	    break;
	}
    }

}

