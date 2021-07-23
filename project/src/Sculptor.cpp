/**
 *
 * Created by Layza on 21/07/2021
*/

#include "Sculptor.hpp"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Class builder
 *
 * @param _nx first dimension of the 3D matrix
 * @param _ny second dimension of the 3D matrix
 * @param _nz third dimension of the 3D matrix
 */

Sculptor::Sculptor(int _nx, int _ny, int _nz) {

    /// Allocate memory blocks of size _nx
    this->v = new Voxel**[_nx];
    /// Allocate variables in memory
    this->nx = _nx;
    this->ny = _ny;
    this->nz = _nz;
    this->r = 0.0;
    this->g = 0.0;
    this->b = 0.0;
    this->a = 0.0;


    for (int i = 0; i < _nx; i++) {

        /// Allocate memory blocks for
        /// rows of each 2D array
        this->v[i] = new Voxel*[_ny];

        for (int j = 0; j < _ny; j++) {

            /// Allocate memory blocks for
            /// columns of each 2D array
            this->v[i][j] = new Voxel[_nz];
        }
    }
}

/**
 * Class destroyer
 */
Sculptor::~Sculptor() {
    /// Deallocate memory
    for (int i = 0; i < this->nx; i++) {
        for (int j = 0; j < this->ny; j++) {
            delete[] this->v[i][j];
        }
        delete[] this->v[i];
    }
    delete[] this->v;
}

/**
 * Sets current drawing color
 *
 * @param r dosage of red to compose a specific color
 * @param g dosage of green to compose a specific color
 * @param b dosage of blue to compose a specific color
 * @param alpha transparency property
 */
void Sculptor::setColor(float r, float g, float b, float alpha) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;
}

/**
 * Activates the voxel at position (x,y,z) (by making isOn = true)
 * and assigns it the current drawing color
 *
 * @param x position x
 * @param y position y
 * @param z position z
 */
void Sculptor::putVoxel(int x, int y, int z) {
    this->v[x][y][z].isOn = true;
    this->v[x][y][z].r = this->r;
    this->v[x][y][z].g = this->g;
    this->v[x][y][z].b = this->b;
    this->v[x][y][z].a = this->a;
}

/**
 * Disable voxel at position (x,y,z) (making isOn = false)
 *
 * @param x position x
 * @param y position y
 * @param z position z
 */

void Sculptor::cutVoxel(int x, int y, int z) {
    this->v[x][y][z].isOn = false;
}


/**
 * Turns on all voxels in the range x ∈ [x0,x1], y ∈ [y0,y1], z ∈ [z0,z1]
 * and assigns them the current drawing color
 *
 * @param x0 start of interval x
 * @param x1 end of interval x
 * @param y0 start of interval y
 * @param y1 end of interval y
 * @param z0 start of interval z
 * @param z1 end of interval z
 */
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {

    int startX = x0 < 0 ? 0 : x0;
    int endX = x1 > this->nx ? this->nx : x1;

    int startY = y0 < 0 ? 0 : y0;
    int endY = y1 > this->ny ? this->ny : y1;

    int startZ = z0 < 0 ? 0 : z0;
    int endZ = z1 > this->nz ? this->nz : z1;

    for(int i = startX; i <= endX; i++){
        for(int j = startY; j <= endY; j++){
            for(int k = startZ; k <= endZ; k++){
                if(this->v[i][j][k].isOn){
                    this->putVoxel(i,j,k);
                }
            }
        }
    }
}


/**
 * Turns off all voxels in the range x ∈ x0,x1], y ∈ [y0,y1], z ∈ [z0,z1]
 * and assigns them the current drawing color
 *
 * @param x0 start of interval x
 * @param x1 end of interval x
 * @param y0 start of interval y
 * @param y1 end of interval y
 * @param z0 start of interval z
 * @param z1 end of interval z
 */
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for(int i = x0; i <= x1; i++){
        for(int j = y0; j <= y1; j++){
            for(int k = z0; k <= z1; k++){
                if(this->v[i][j][k].isOn){
                    this->cutVoxel(i,j,k);
                }
            }
        }
    }
}


/**
 * writes the sculpture in OFF format to file filename
 *
 * @param filename name for the file
 */
void Sculptor::writeOFF(const char *filename) {
    ofstream myFile(filename);

    /// check if the file is not open
    if(!myFile.is_open()){
        cout << "Failed to open file";
        exit(1);
    }

    int active = 0;
    int countActives = 0;

    /// count the amount of active voxels
    for(int i = 0; i < this->nx; i++){
        for(int j = 0; j < this->nx; j++){
            for(int k = 0; k < this->nx; k++){
                if(this->v[i][j][k].isOn){
                    active ++;
                }
            }
        }
    }

    /// write the word off in the file
    myFile << "OFF" << endl;
    /// write the number of vertices in the file
    myFile << 8 * active << " " << 6 * active << " 0" << endl;

    /// writes the number of three-dimensional
    /// spatial coordinates of the vertices in the file
    for(int i = 0; i < this->nx; i++){
        for(int j = 0; j < this->nx; j++){
            for(int k = 0; k < this->nx; k++){
                if(this->v[i][j][k].isOn){
                    myFile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    myFile << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    myFile << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    myFile << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    myFile << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    myFile << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    myFile << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    myFile << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                }
            }
        }
    }

    /// write the specifications of the faces to the file
    for(int i = 0; i < this->nx; i++){
        for(int j = 0; j < this->nx; j++){
            for(int k = 0; k < this->nx; k++){
                if(this->v[i][j][k].isOn){
                    myFile << "4 " << countActives * 8 + 0 << " " << countActives * 8 + 3 << " " << countActives * 8 + 2 << " " << countActives * 8 + 1 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << countActives * 8 + 4 << " " << countActives * 8 + 5 << " " << countActives * 8 + 6 << " " << countActives * 8 + 7 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << countActives * 8 + 0 << " " << countActives * 8 + 1 << " " << countActives * 8 + 5 << " " << countActives * 8 + 4 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << countActives * 8 + 0 << " " << countActives * 8 + 4 << " " << countActives * 8 + 7 << " " << countActives * 8 + 3 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << countActives * 8 + 3 << " " << countActives * 8 + 7 << " " << countActives * 8 + 6 << " " << countActives * 8 + 2 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << countActives * 8 + 1 << " " << countActives * 8 + 2 << " " << countActives * 8 + 6 << " " << countActives * 8 + 5 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    countActives++;
                }
            }
        }
    }

    /// close the file
    myFile.close();
}