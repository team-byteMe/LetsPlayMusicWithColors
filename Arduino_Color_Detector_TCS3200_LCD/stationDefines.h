// TCS230 or TCS3200 pins wiring to Arduino
#define s0 6
#define s1 4
#define  s2  2
#define  s3  3
#define outPin 5

boolean DEBUG = true;

// Variables
int red;
int grn;
int blu;
String color ="";
int count = 0;
long startTiming = 0;
long elapsedTime =0;
