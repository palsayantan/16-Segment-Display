// array of row pins
const byte row[4] = {5, 16, 4, 13};

// array of column pins
const byte col[4] = {14, 12, 0, 2};

// The display buffer
byte A[] = {B0011, B0100, B0011, B1101};
byte B[] = {B0110, B0100, B1110, B0100};
byte C[] = {B0011, B0111, B1010, B1110};
byte D[] = {B0110, B0101, B1110, B0100};
byte E[] = {B0011, B0111, B0010, B1110};
byte F[] = {B0011, B0111, B0011, B1111};
byte G[] = {B0011, B0110, B1010, B1100};
byte H[] = {B1011, B1100, B0011, B1101};
byte I[] = {B0110, B0111, B1110, B0110};
byte J[] = {B1111, B1101, B1010, B1100};
byte K[] = {B1011, B1011, B0011, B1011};
byte L[] = {B1011, B1111, B1010, B1110};
byte M[] = {B1001, B1001, B1011, B1101};
byte N[] = {B1001, B1101, B1011, B1001};
byte O[] = {B0011, B0101, B1010, B1100};
byte P[] = {B0011, B0100, B0011, B1111};
byte Q[] = {B0011, B0101, B1010, B1000};
byte R[] = {B0011, B0100, B0011, B1011};
byte S[] = {B0011, B0110, B0110, B1100};
byte T[] = {B0110, B0111, B1111, B0111};
byte U[] = {B1011, B1101, B1010, B1100};
byte V[] = {B1011, B1011, B1001, B1111};
byte W[] = {B1011, B1101, B1001, B1001};
byte X[] = {B1101, B1011, B1101, B1011};
byte Y[] = {B1011, B1100, B0110, B1100};
byte Z[] = {B0111, B0011, B1100, B1110};

byte d[] = {B1111, B1111, B1111, B1111};  //space

byte n0[] = {B0011, B0001, B1000, B1100};
byte n1[] = {B1111, B1001, B1111, B1101};
byte n2[] = {B0111, B0100, B0010, B1110};
byte n3[] = {B0111, B0100, B1110, B1100};
byte n4[] = {B1011, B1100, B0111, B1101};
byte n5[] = {B0011, B0111, B0110, B1010};
byte n6[] = {B0011, B0110, B0010, B1100};
byte n7[] = {B0111, B0101, B1111, B1101};
byte n8[] = {B0011, B0100, B0010, B1100};
byte n9[] = {B0011, B0100, B0110, B1100};

float timeCount = 0;

void setup() {
  Serial.begin(115200);
  for (int pin = 0; pin < 4; pin++)
  {
    // initialize the I/O pins as outputs
    pinMode(row[pin], OUTPUT);
    pinMode(col[pin], OUTPUT);
    // take the row pins (i.e. the cathodes) high to ensure that the LEDs are off:
    digitalWrite(row[pin], HIGH);
  }
}

void loop() {
  delay(5);
  timeCount += 1;

  if (timeCount <  20)
  {
    drawScreen(n1);
  }
  else if (timeCount <  40)
  {
    drawScreen(n6);
  }
  else if (timeCount <  60)
  {
    drawScreen(d);
  }
  else if (timeCount <  80)
  {
    drawScreen(S);
  }
  else if (timeCount <  100)
  {
    drawScreen(E);
  }
  else if (timeCount <  120)
  {
    drawScreen(G);
  }
  else if (timeCount <  140)
  {
    drawScreen(M);
  }
  else if (timeCount <  160)
  {
    drawScreen(E);
  }
  else if (timeCount <  180)
  {
    drawScreen(N);
  }
  else if (timeCount <  200)
  {
    drawScreen(T);
  }
  else if (timeCount <  220)
  {
    drawScreen(d);
  }
  else if (timeCount <  240)
  {
    drawScreen(D);
  }
  else if (timeCount <  260)
  {
    drawScreen(I);
  }
  else if (timeCount <  280)
  {
    drawScreen(S);
  }
  else if (timeCount <  300)
  {
    drawScreen(P);
  }
  else if (timeCount <  320)
  {
    drawScreen(L);
  }
  else if (timeCount <  340)
  {
    drawScreen(A);
  }
  else if (timeCount <  360)
  {
    drawScreen(Y);
  }
  else if (timeCount <  380)
  {
    drawScreen(d);
  }
  else {
    // back to the start
    timeCount = 0;
  }

}

void  drawScreen(byte buffer[])
{
  // Turn on each row in series
  for (byte i = 0; i < 4; i++)        // count next row
  {
    digitalWrite(row[i], HIGH);    //initiate whole row
    for (byte a = 0; a < 4; a++)    // count next row
    {
      digitalWrite(col[a], (buffer[i] >> a) & 0x01); // initiate whole column
      delay(1);
      digitalWrite(col[a], HIGH);      // reset whole column
    }
    digitalWrite(row[i], LOW);     // reset whole row
  }
}
