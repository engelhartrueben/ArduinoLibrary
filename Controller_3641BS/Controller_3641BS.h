#ifndef _CONTROLLER_3641BS
#define _CONTROLLER_2641BS

class Controller_3641BS
{
	public:
		Controller_3641BS(
			int B_L,
			int B,
			int B_R,
			int D,
			int M,
			int T_L,
			int T,
			int T_R,
			int P_1,
			int P_2,
			int P_3,
			int P_4
		) {
			BOTTOM_LEFT = B_L;
			BOTTOM = B;
			BOTTOM_RIGHT = B_R;
			DOT = D;
			MIDDLE = M;
			TOP_LEFT = T_L;
			TOP = T;
			TOP_RIGHT = T_R;

			displayPins[0] = BOTTOM_LEFT;
			displayPins[1] = BOTTOM;
			displayPins[2] = BOTTOM_RIGHT;
			displayPins[3] = DOT;
			displayPins[4] = MIDDLE;
			displayPins[5] = TOP_LEFT;
			displayPins[6] = TOP;
			displayPins[7] = TOP_RIGHT;

			p_1 = P_1;
			p_2 = P_2;
			p_3 = P_3;
			p_4 = P_4;

			digitPins[0] = p_1;
			digitPins[1] = p_2;
			digitPins[2] = p_3;
			digitPins[3] = p_4;
		}

		/* Turns off display completely
		 * Similar to refresh	
		*/
		void setup()
		{
			for(int x: displayPins)
			{
				pinMode(x, OUTPUT);
			}

			for(int y: digitPins)
			{
				pinMode(y, OUTPUT);
			}

			refresh();
		}

		void refresh()
		{
			for(int x: displayPins)
			{
				digitalWrite(x, HIGH);
			}

			for(int y: digitPins)
			{
				digitalWrite(y, LOW);
			}

		}

		// Turns the individual segment on and off
		// Removes full refresh cycle +
		// reduces the amount of resistors needed on the board!
		void oscillate(int segment)
		{
			digitalWrite(segment, LOW);
			digitalWrite(segment, HIGH);
		}

		// Consider making thise private so a helper function
		// can be created to determine which cell to display
		void one()
		{
			oscillate(TOP_RIGHT);
			oscillate(BOTTOM_RIGHT);
		}

		void two()
		{
			oscillate(TOP);
			oscillate(TOP_RIGHT);
			oscillate(MIDDLE);
			oscillate(BOTTOM_LEFT);
			oscillate(BOTTOM);
		}

		void three()
		{
			oscillate(TOP);
			oscillate(TOP_RIGHT);
			oscillate(MIDDLE);
			oscillate(BOTTOM_RIGHT);
			oscillate(BOTTOM);
		}

		void four()
		{
			oscillate(TOP_LEFT);
			oscillate(TOP_RIGHT);
			oscillate(MIDDLE);
			oscillate(BOTTOM_RIGHT);
		}

		void five()
		{
			oscillate(TOP);
			oscillate(TOP_LEFT);
			oscillate(MIDDLE);
			oscillate(BOTTOM_RIGHT);
			oscillate(BOTTOM);
		}

		void six()
		{
			oscillate(TOP);
			oscillate(TOP_LEFT);
			oscillate(MIDDLE);
			oscillate(BOTTOM_RIGHT);
			oscillate(BOTTOM_LEFT);
			oscillate(BOTTOM);
		}

		void seven()
		{
			oscillate(TOP);
			oscillate(TOP_RIGHT);
			oscillate(BOTTOM_RIGHT);
		}

		void eight()
		{
			oscillate(TOP);
			oscillate(TOP_RIGHT);
			oscillate(TOP_LEFT);
			oscillate(MIDDLE);
			oscillate(BOTTOM_RIGHT);
			oscillate(BOTTOM_LEFT);
			oscillate(BOTTOM);
		}

		void nine()
		{
			oscillate(TOP);
			oscillate(TOP_LEFT);
			oscillate(TOP_RIGHT);
			oscillate(MIDDLE);
			oscillate(BOTTOM_RIGHT);			
		}
		
		void zero()
		{
			oscillate(TOP);
			oscillate(TOP_RIGHT);
			oscillate(TOP_LEFT);
			oscillate(BOTTOM_RIGHT);
			oscillate(BOTTOM_LEFT);
			oscillate(BOTTOM);
		}

		void dot()
		{
			oscillate(DOT);
		}

		void display(int number, int dotDigit, bool avg)
		{
			if (number < 0 || number > 9999) {
				number = 0;
			}
			int scale = 1000;

			if (avg)
			{
				avg[avgCount % 5] = number;
				
				int temp;

				for(int x = 0; x < 5 || x < avgCount; x++)
				{
					if(avgCount / 5 < 1)
					{

					}
				}

				avgCount++; 
			}

			for (int x = 0; x < 4; x++) 
			{
				int n = number / scale;
				number -= (number / scale) * scale;
				scale /= 10;
				digitalWrite(digitPins[x], HIGH);
				switch (n)
				{
					case 0:
						zero();
						break;
					case 1:
						one();
						break;
					case 2:
						two();
						break;
					case 3:
						three();
						break;
					case 4:
						four();
						break;
					case 5:
						five();
						break;
					case 6:
						six();
						break;
					case 7:
						seven();
						break;
					case 8:
						eight();
						break;
					case 9:
						nine();
						break;
					default:
						zero();
						break;
				}
				digitalWrite(digitPins[x], LOW);
			}

			if (dotDigit == -1 || dotDigit > 4) {
				return;
			}

			digitalWrite(digitPins[dotDigit], HIGH);
			dot();
			digitalWrite(digitPins[dotDigit], HIGH);
			
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

		int displayPins[8];

		int p_1,  // way right display
			p_2,
			p_3,
			p_4;  // way left display

		int digitPins[4];

		int powerOf10s[4] = {
			1,
			10,
			100,
			1000
		};

		int avg[5];
		int avgCount;
};

#endif
