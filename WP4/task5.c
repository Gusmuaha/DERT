/* ====================================
File name: task1.c (or cpp)
Date: 2020-mm-dd
Group nr 17
Members that contribute to the solutions
Hassan Mualla
Hannah Maltkvist
Carl Nihlmar
Member not present at demonstration time: 
Demonstration code : []
 Important, No code no exercise points!
====================================== */

const byte in[4] = {4,5,6,7} ;
const byte out[4] = {8,9,10,11};
char last = 'x';

void setup()
{
  Serial.begin(9600);
  for ( int i = 0; i < 4; i++){
  	pinMode(out[i], OUTPUT);
  }
  
}

void loop()
{
  char pressed = checkPress();
  if (pressed != 'x' && pressed != last) {
  	Serial.println(pressed);
   delay(1000);
  }
  last = pressed;
}

char checkPress (){
  int i = 0;
  for (int j = 0; j < 4; j++) {
    if (digitalRead(in[i]) != LOW) {
    	i = 1;
    }
  }
  if (i = 0) {
  } else {
    for (byte j = 0; j < 4; j++) {
            digitalWrite(out[j], LOW);
        } 
        for (byte k = 0; k < 4; k++) {
            if (digitalRead(in[k]) == LOW) {
                for (byte l = 0; l < 4; l++) {
                    digitalWrite(out[l], HIGH);
                    if (digitalRead(in[k]) == HIGH) {
                        for (byte j = 0; j < 4; j++) {
                            digitalWrite(out[j], LOW);
                        }
                      	int inKey = k + (l * 4);
                        return findInput (inKey);
                    }
                }
            }
        }
  }
  
}
char findInput (int key) {
  switch (key) {
    case 0:
        return 'D';
    case 1:
        return '#';
    case 2:
        return '0';
    case 3:
        return '*';
    case 4:
        return 'C';
    case 5:
        return '9';
    case 6:
        return '8';
    case 7:
        return '7';
    case 8:
        return 'B';
    case 9:
        return '6';
    case 10:
        return '5';
    case 11:
        return '4';
    case 12:
        return 'A';
    case 13:
        return '3';
    case 14:
        return '2';
    case 15:
        return '1';
    default:
        return 'x';
    }
}
