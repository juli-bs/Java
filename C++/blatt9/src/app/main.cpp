   // Slightly modified version of the "smallpt"
#include <cstdlib> // path tracer by Kevin Beason.
 // http://www.kevinbeason.com/smallpt/

 //BONUS-AUFGABE 2 nicht mehr benötigte Bibliotheken entfernt
 // Und stdlib.h durch cstdlib ersetzt

#include <chrono>
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

#include "app.h"
#include "Constants.h"


int main(int argc, char *argv[]) {

    int samples = (argc == 2) ? (atoi(argv[1]) / 4) : 1; // # samples

    Ray camera(Vec(50, 52, 295.6), Vec(0, -0.042612, -1).norm()); // cam pos, dir

    Vec directionX = Vec(WIDTH * .5135 / HEIGHT);
    Vec directionY = (directionX % camera.d).norm() * .5135;
    Vec r;
    //Vec *c = new Vec[WIDTH * HEIGHT];
    vector<Vec> pixelArray (WIDTH * HEIGHT);


    auto begin = std::chrono::system_clock::now();

    loopOverImage(samples, camera, directionX, directionY, r, pixelArray);

    auto end = std::chrono::system_clock::now();
    double durationInSeconds = ((double)std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() / 1000);
    cout << "\n\nDuration: " << durationInSeconds << "sec" << endl;

    /*
     * VOR den Optimierungen in einem Bereich von 1,14s - 1,2s (in 10 Probeläufen)
     */
    /*
     * NACH den Optimierungen in einem Bereich von 0,72s - 0,77s (in 10 Probeläufen)
     */
    /*
     * NACH AUFGABE 5 in einem Bereich von 0,61s - 0,65s (in 10 Probeläufen)
     */

    writeFile(pixelArray);

}
