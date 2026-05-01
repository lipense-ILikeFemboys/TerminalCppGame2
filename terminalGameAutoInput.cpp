#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include <string>
#include <cmath>

/* 26/04/2026, dom, 835pm (back from ouro preto)
 returning at 908pm
 returned at 27/04/2026, monday, 8:26am.
 Fixed world size & running (u could leave the map running by 1 step of distance
 from the bounds of the world)
*/

using namespace std;

int worldXSize = 60;
int worldYSize = 20;
int halfWorldXSize = floor(worldXSize / 2);
int halfWorldYSize = floor(worldYSize / 2);

int playerPositionX = halfWorldXSize;
int playerPositionY = halfWorldYSize;

int playerStepY = 1;
int playerStepX = 1;

bool running = false; // ENTER to run!

string playerSymbol = "O";
string worldSymbol = "*";


template <typename any>
void print(any what){
	cout << what << '\n';
}

void wait(double time){

	this_thread::sleep_for(chrono::duration<double>(time));

}

void renderWorld(){

	print("////////////////////////////////");

	for(int y = 0; y <= worldYSize; y++){

		string line;

		for(int x = 0; x <= worldXSize; x++){

			if(x == playerPositionX && y == playerPositionY){

				line.append(playerSymbol);

			} else {

				line.append(worldSymbol);

			}

		}

		print(line);
		print("");
	}

	print("////////////////////////////////");

}



void checkInput(){

	if(GetAsyncKeyState('W') && playerPositionY > 0){
			playerPositionY -= playerStepY;
	}
	if(GetAsyncKeyState('S') && playerPositionY < worldYSize){
			playerPositionY += playerStepY;
	}
	if(GetAsyncKeyState('A') && playerPositionX > 0){
		if(running && playerPositionX == 1){
			playerPositionX -= 1;
		} else{
			playerPositionX -= playerStepX;
		}
	}
	if(GetAsyncKeyState('D') && playerPositionX < worldXSize){
		if(running && playerPositionX == (worldXSize - 1)){
			playerPositionX += 1;
		} else{
			playerPositionX += playerStepX;
		}
	}
	if(GetAsyncKeyState(VK_RETURN)){
		running = not running;
		running ? playerStepX = 2 : playerStepX = 1;
	}

}


int main(){

while(true){
	checkInput();
	renderWorld();
	wait(0.2);
}

	return 0;
}
