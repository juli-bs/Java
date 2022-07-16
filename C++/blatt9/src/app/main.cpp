#include <math.h>   // Slightly modified version of the "smallpt"
#include <stdlib.h> // path tracer by Kevin Beason.
#include <stdio.h>  // http://www.kevinbeason.com/smallpt/

#include <chrono>
#include <iostream>
using std::cout;
using std::endl;

#include "app.h"
#include "Constants.h"


int main(int argc, char *argv[]) {

    int samples = (argc == 2) ? (atoi(argv[1]) / 4) : 1; // # samples

    Ray camera(Vec(50, 52, 295.6), Vec(0, -0.042612, -1).norm()); // cam pos, dir

    Vec directionX = Vec(WIDTH * .5135 / HEIGHT);
    Vec directionY = (directionX % camera.d).norm() * .5135;
    Vec r;
    Vec *c = new Vec[WIDTH * HEIGHT];


    auto begin = std::chrono::system_clock::now();

    loopOverImage(samples, camera, directionX, directionY, r, c);

    auto end = std::chrono::system_clock::now();
    double durationInSeconds = ((double)std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() / 1000);
    cout << "\n\nDuration: " << durationInSeconds << "sec" << endl;

    /*
     * VOR den Optimierungen in einem Bereich von 1,72s - 2.798s (in 8 Probeläufen)
     */
    /*
     * NACH den Optimierungen in einem Bereich von 0,89s - 1,04s (in 8 Probeläufen)
     */

    writeFile(c);

}
