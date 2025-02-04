#ifndef _CONTROLLER_5161AS_H
#define _CONTROLLER_5161AS_H


class Controller_5161AS
{
	public:
		Controller_5161AS(
			int B_L, 
			int B,
			int B_R,
			int D,
			int M,
			int T_L,
			int T,
			int T_R
				) {
			BOTTOM_LEFT = B_L;
			BOTTOM = B;
			BOTTOM_RIGHT = B_R;
			DOT = D;
			MIDDLE = M;
			TOP_LEFT = T_L;
			TOP = T;
			TOP_RIGHT = T_R;

			// I hate this, but I don't know enough about c++
			arrPins[0] = BOTTOM_LEFT;
			arrPins[1] = BOTTOM;
			arrPins[3] = BOTTOM_RIGHT;
			arrPins[4] = DOT;
			arrPins[5] = MIDDLE;
			arrPins[6] = TOP_LEFT;
			arrPins[7] = TOP;
			arrPins[8] = TOP_RIGHT;
		}

		void setup() {
			for (int i = 0; i < 9; i++) {
				pinMode(arrPins[i], OUTPUT);
			}
		}

		void resetDisplay() {
			for (int i = 0; i < 9; i++) {
				digitalWrite(arrPins[i], LOW);
			}
		}

		void displayValue(int n) {
			// if (num.length() > 1) {
			// 	Serial.println("Controller_5161AS::displayValue - Number too big " + n);
			// }
			// char firstCharacter = num[0];

			switch(n) {
				case 0: { DisplayZero(); }
					break;
				case 1: { DisplayOne(); }
					break;
				case 2: { DisplayTwo(); }
					break;
				case 3: { DisplayThree(); }
					break;
				case 4: { DisplayFour(); }
					break;
				case 5: { DisplayFive(); }
					break;
				case 6: { DisplaySix(); }
					break;
				case 7: { DisplaySeven(); }
					break;
				case 8: { DisplayEight(); }
					break;
				case 9: { DisplayNine(); }
					break;
				default: {
					Serial.println("No value given: " + String(n));
				}
					break;
			}

			// TODO: Figure out why this doesn't work in a class
			// Works on standalone program for some reason.
			//
			// void (*findMatch[])(void) = {
			// 	DisplayZero,
    		// 	DisplayOne,
    		// 	DisplayTwo,
    		// 	DisplayThree,
    		// 	DisplayFour,
			// 	DisplayFive,
			// 	DisplaySix,
			// 	DisplaySeven,
			// 	DisplayEight,
    		// 	DisplayNine
			// };

			// for (int i = 0; i < 10; i++) {
			// 	if (number[0] == i) {
			// 		(*findMatch[i])();
			// 		return;
			// 	}
			// }
		}

		int displayValue(unsigned int n) {
			displayValue(int(n));
		}

		int displayValue(float n) {
			displayValue(int(n));
		}

		int displayValue(long n) {
			displayValue(int(n));
		}

		int displayValue(unsigned long n) {
			displayValue(int(n));
		}

		// C++ is hard. What are pointers lol. 
		int* returnPinLayOut() {
			int arr[8] = {
				BOTTOM_RIGHT,
				BOTTOM,
				BOTTOM_LEFT,
				DOT,
				MIDDLE,
				TOP_LEFT,
				TOP,
				TOP_RIGHT
			};

			return arr;
		}

		void DisplayZero() {
			resetDisplay();
			digitalWrite(TOP_LEFT, HIGH);
			digitalWrite(TOP, HIGH);
  			digitalWrite(TOP_RIGHT, HIGH);
  			digitalWrite(BOTTOM_RIGHT, HIGH);
  			digitalWrite(BOTTOM, HIGH);
  			digitalWrite(BOTTOM_LEFT, HIGH);
		}

		void DisplayOne() { 
			resetDisplay();
			digitalWrite(TOP_RIGHT, HIGH);
  			digitalWrite(BOTTOM_RIGHT, HIGH);
		}

		void DisplayTwo() {
			resetDisplay();
  			digitalWrite(TOP, HIGH);
  			digitalWrite(TOP_RIGHT, HIGH);
  			digitalWrite(MIDDLE, HIGH);
  			digitalWrite(BOTTOM_LEFT, HIGH);
  			digitalWrite(BOTTOM, HIGH);
		}

		void DisplayThree() {
			resetDisplay();
  			digitalWrite(TOP, HIGH);
  			digitalWrite(TOP_RIGHT, HIGH);
  			digitalWrite(MIDDLE, HIGH);
  			digitalWrite(BOTTOM_RIGHT, HIGH);
  			digitalWrite(BOTTOM, HIGH);
		}

		void DisplayFour() {
			resetDisplay();
  			digitalWrite(TOP_LEFT, HIGH);
  			digitalWrite(MIDDLE, HIGH);
  			digitalWrite(TOP_RIGHT, HIGH);
  			digitalWrite(BOTTOM_RIGHT, HIGH);
		}

		void DisplayFive() {
			resetDisplay();
			digitalWrite(TOP, HIGH);
			digitalWrite(TOP_LEFT, HIGH);
			digitalWrite(MIDDLE, HIGH);
			digitalWrite(BOTTOM_RIGHT, HIGH);
			digitalWrite(BOTTOM, HIGH);
		}

		void DisplaySix() {
			resetDisplay();
			digitalWrite(TOP, HIGH);
			digitalWrite(TOP_LEFT, HIGH);
			digitalWrite(BOTTOM_RIGHT, HIGH);
			digitalWrite(BOTTOM, HIGH);
			digitalWrite(BOTTOM_LEFT, HIGH);
			digitalWrite(MIDDLE, HIGH);
		}

		void DisplaySeven() {
			resetDisplay();
		  	digitalWrite(TOP, HIGH);
		  	digitalWrite(TOP_RIGHT, HIGH);
		  	digitalWrite(BOTTOM_RIGHT, HIGH);
		}

		void DisplayEight() {
			resetDisplay();
		  	digitalWrite(MIDDLE, HIGH);
		  	digitalWrite(TOP_LEFT, HIGH);
		  	digitalWrite(TOP, HIGH);
		  	digitalWrite(TOP_RIGHT, HIGH);
		  	digitalWrite(BOTTOM_RIGHT, HIGH);
		  	digitalWrite(BOTTOM, HIGH);
		  	digitalWrite(BOTTOM_LEFT, HIGH);
		}

		void DisplayNine() {
			resetDisplay();
		  	digitalWrite(MIDDLE, HIGH);
		  	digitalWrite(TOP_LEFT, HIGH);
		  	digitalWrite(TOP, HIGH);
		  	digitalWrite(TOP_RIGHT, HIGH);
		  	digitalWrite(BOTTOM_RIGHT, HIGH);
		}

		void DisplayDot() {
			resetDisplay();
		  	digitalWrite(DOT, HIGH);
		}

	private:
		int BOTTOM_LEFT,
		    BOTTOM,
		    BOTTOM_RIGHT,
		    DOT,
		    MIDDLE,
		    TOP_LEFT,
		    TOP,
		    TOP_RIGHT;

		int arrPins[8];
};

#endif // _CONTROLLER_5616A1
