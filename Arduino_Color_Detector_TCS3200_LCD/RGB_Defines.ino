
/* Based on RGB components ==> Determine color */
int getColor(int red, int grn, int blu)
{  
  int ans = -1;
  //readRGB();
  if (red > 4 && red < 10 && grn > 0 && grn <= 10 && blu > 0 && blu < 16) ans = 1;
  else if (red >= 10 && red < 17 && grn > 10 && grn < 20 && blu > 15 && blu < 25) ans = 2;
  else if (red > 20 && red < 30 && grn > 40 && grn < 70 && blu > 33 && blu < 70) ans = 3;
  else if (red > 15 && red < 25 && grn > 35 && grn < 70 && blu > 45 && blu < 85) ans = 4;
  else if (red > 10 && red < 20 && grn > 10 && grn < 25 && blu > 20 && blu < 38) ans = 5;
  else if (red > 65 && red < 125 && grn > 65 && grn < 115 && blu > 32 && blu < 65) ans = 6;
  else  ans = 7;
  return ans;
}

/* read RGB components */
int readRGB(int s2, int s3, int outPin) 
{

  Serial.println("read RGB");
    int red = 0;
  int grn = 0;
  int blu = 0;
  int n = 10;
  for (int i = 0; i < n; ++i)
  {
    //read red component
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    red = red + pulseIn(outPin, LOW);
  
   //read green component
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    grn = grn + pulseIn(outPin, LOW);
    
   //let's read blue component
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    blu = blu + pulseIn(outPin, LOW);
    delay(50);
  }
  red = red/n;
  grn = grn/n;
  blu = blu/n;
  //Serial.println("New");
  //Serial.println(red);
  //Serial.println(grn);
  //Serial.println(blu);
  return getColor(red, grn, blu);
  }
