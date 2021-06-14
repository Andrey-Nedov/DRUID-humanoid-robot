#define engine_ONE_PWM_DEFINE 5
#define engine_ONE_DIR_DEFINE 4

#define engine_TWO_PWM_DEFINE 7
#define engine_TWO_DIR_DEFINE 6

#define engine_THREE_PWM_DEFINE 11
#define engine_THREE_DIR_DEFINE 10

long timer = 0;
long counter = 0;

bool axel = true;
int promo_count = 0;
bool done = false;
    
int engine_ONE_DIR = 0;
int engine_TWO_DIR = 0;
int engine_THREE_DIR = 0;

int engine_ONE_PWM = 0;
int engine_TWO_PWM = 0;
int engine_THREE_PWM = 0;

int incomingByte;   //байты, приходящие по Serial

int rotation = 0;

/////////////* переменные для распаковки пакетов данных */////////////////////////
int dir = 0;
int dirPack[3];

int angle = 0;
int anglePack[2];
/////////////* переменные для распаковки пакетов данных */////////////////////////

bool lock = true;

/////////////* байты для поиска трех стартовых символов */////////////////////////
byte b1 = 0;    //
byte b2 = 0;    // 
byte b3 = 0;    //
/////////////* байты для поиска трех стартовых символов */////////////////////////

void setup()
{
  for(int i = 4; i <= 11; i++)
    pinMode(i, OUTPUT);
    
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop()
{
/////////////////// отправляем тестовую информацию по Serial (в данном случае счетчик)
  
//  timer++;
  
//  if(timer == 100000)
//  {
//    counter++;
//    Serial1.print("$&^");     //открывающие три байта
//    Serial1.print(counter);   //тут нужная нам информация
//    Serial1.print("*&^");     //закрывающие три байта
//
//    //вывод на комп для отладки
//    Serial.println();
//    Serial.print("Send to Raspberry by Serial >>> ");   //тут нужная нам информация
//    Serial.println(counter);   //тут нужная нам информация
//    timer = 0;
//  }
  
/////////////////// отправляем тестовую информацию по Serial (в данном случае счетчик) конец
  
  if (Serial1.available() > 0)
  {
    incomingByte = Serial1.read();

    if(angle > 0)//////* читаем байты угла */////////////////////////////////////////////////
    {
        lock = false;
        
        if(angle < 2)
        {
            anglePack[angle - 1] = incomingByte;
            angle++;
        }
        else
        {
            anglePack[angle - 1] = incomingByte;
            angle = 0;

            angleParsePWM(anglePack[0], anglePack[1]);

            Serial.println();
            Serial.print("Angle: ");
            Serial.print(String(anglePack[0]));
            Serial.print("/");
            Serial.print(String(anglePack[1]));
        }
    }//////* читаем байты угла */////////////////////////////////////////////////
    
    else

    if(dir > 0)//////* читаем байты направления */////////////////////////////////////////////////
    {
        lock = false;
        
        if(dir < 3)
        {
            dirPack[dir - 1] = incomingByte;
            dir++;
        }
        else
        {
            dirPack[dir - 1] = incomingByte;
            dir = 0;

            dirParsePWM(dirPack[0], dirPack[1], dirPack[2]);

//            Serial.println();
//            Serial.print("Direction: ");
//            Serial.print(String(dirPack[0]));
//            Serial.print("/");
//            Serial.print(String(dirPack[1]));
//            Serial.print("; PWR: ");
//            Serial.print(String(dirPack[2]));
        }
    }//////* читаем байты направления */////////////////////////////////////////////////

    else  ///* если мы еще не распознали пакет, то ищем начальные символы *//////////////
    {
        b3 = b2;
        b2 = b1;
        b1 = incomingByte;
    
        if((b1 == 37)&&(b2 == 36)&&(b3 == 35))
          angle++;
    
        if((b1 == 38)&&(b2 == 36)&&(b3 == 35))
          dir++;
    
        if((b1 == 39)&&(b2 == 36)&&(b3 == 35))
        {
            lock = true;
            Serial.println();
            Serial.print("Lock"); 
        }
    }
  }

  if (lock)
  {
    engine_ONE_PWM = 0;
    engine_TWO_PWM = 0;
    engine_THREE_PWM = 0;
  }

  //Serial.print(engine_ONE_PWM);
//  Serial.print("/");
//  Serial.print(engine_TWO_PWM);
//  Serial.print("/");
//  Serial.println(engine_THREE_PWM);

//  int pwm_norm_one = int(pow(float(engine_ONE_PWM) / 255.0, 2) * 255.0);
//  int pwm_norm_two = int(pow(float(engine_TWO_PWM) / 255.0, 2) * 255.0);
//  int pwm_norm_three = int(pow(float(engine_THREE_PWM) / 255.0, 2) * 255.0);
  
  analogWrite(engine_ONE_PWM_DEFINE, engine_ONE_PWM);    
  analogWrite(engine_TWO_PWM_DEFINE, engine_TWO_PWM);
  analogWrite(engine_THREE_PWM_DEFINE, engine_THREE_PWM);  

} ///* если мы еще не распознали пакет, то ищем начальные символы *//////////////

int angleParsePWM(int b1, int b2)
{
    int angle = b1 + b2;

    if (angle > rotation)
    {
      digitalWrite(engine_ONE_DIR_DEFINE, false);
      digitalWrite(engine_TWO_DIR_DEFINE, false);
      digitalWrite(engine_THREE_DIR_DEFINE, false);
    }
    else
    {
      digitalWrite(engine_ONE_DIR_DEFINE, true);
      digitalWrite(engine_TWO_DIR_DEFINE, true);
      digitalWrite(engine_THREE_DIR_DEFINE, true);
    }

    rotation = angle;

    lock = 0;
    analogWrite(engine_ONE_PWM_DEFINE, 170);    
    analogWrite(engine_TWO_PWM_DEFINE, 170);
    analogWrite(engine_THREE_PWM_DEFINE, 170);  

    delay(50);
    lock = 1;
}

int dirParsePWM(int b1, int b2, int pwr)     //исполнение команд пакета Direction
{
    if (!done) 
    {
      //forward ttf
      //left ftt
      //right tft
      
      //(роутер - нос)
      
      // low - лево
      // right - право

      // forward_f_dir
      // forward_b_dir
      // left_f_dir
      // left_b_dir
      // right_f_dir
      // right_b_dir
      
      // left_dir
      // right_dir

      // speed_up(form, to, acceleration, one, two, three)
      // speed_down(form, to, acceleration, one, two, three)
      // go(time, power, one, two, three)
      

//      left_dir();
//      speed_up(0, 150, 2, true, true, true);
//      go(60000, 150, true, true, true);
//      speed_down(150, 0, 2, true, true, true);

//      sinusoid();
//      coltsoid();
//      tudasudoid();
//      walsoid();
//      tangoid();
//      walsoid2();
//      tantsoid();
//      pulsoid();
//      curve();   
//      waltz();
        

      done = true;
    }    
}


/////////////////////////////////////////////////////////////// LIB - begin

void sinusoid()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(engine_ONE_DIR_DEFINE, LOW);
    digitalWrite(engine_TWO_DIR_DEFINE, LOW);
    digitalWrite(engine_THREE_DIR_DEFINE, LOW);

    int alfa = 0;
    float a = 0;
    float b = 0;
    float c = 0;

    while (true)
    {
      a = sin(alfa * PI/180);
      b = sin((alfa) * PI/180);
      c = sin((alfa) * PI/180);

      if (a > 0)
        digitalWrite(engine_ONE_DIR_DEFINE, LOW);
      else
        digitalWrite(engine_ONE_DIR_DEFINE, HIGH);

      if (b > 0)
        digitalWrite(engine_TWO_DIR_DEFINE, LOW);
      else
        digitalWrite(engine_TWO_DIR_DEFINE, HIGH);

      if (c > 0)
        digitalWrite(engine_THREE_DIR_DEFINE, LOW);
      else
        digitalWrite(engine_THREE_DIR_DEFINE, HIGH);

      a = abs(a);
      b = abs(b);
      c = abs(c);

      analogWrite(engine_ONE_PWM_DEFINE, int(255 * a));  
      analogWrite(engine_TWO_PWM_DEFINE, int(255 * b));  
      analogWrite(engine_THREE_PWM_DEFINE, int(255 * c));      

      delay(10);

      alfa++;
      
      if (alfa > 360)
        alfa = 0;
    }
  
  }
}

void tudasudoid()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(engine_ONE_DIR_DEFINE, LOW);
    digitalWrite(engine_TWO_DIR_DEFINE, LOW);
    digitalWrite(engine_THREE_DIR_DEFINE, LOW);

    int alfa = 0;
    float a = 0;
    float b = 0;
    float c = 0;

    while (true)
    {
      a = sin(alfa * PI/180);
      b = sin((alfa) * PI/180);
      c = sin((alfa) * PI/180);

      if (a > 0)
        digitalWrite(engine_ONE_DIR_DEFINE, LOW);
      else
        digitalWrite(engine_ONE_DIR_DEFINE, HIGH);

      if (b > 0)
        digitalWrite(engine_TWO_DIR_DEFINE, LOW);
      else
        digitalWrite(engine_TWO_DIR_DEFINE, HIGH);

      if (c > 0)
        digitalWrite(engine_THREE_DIR_DEFINE, LOW);
      else
        digitalWrite(engine_THREE_DIR_DEFINE, HIGH);

      a = abs(a);
      b = abs(b);
      c = abs(c);

      analogWrite(engine_ONE_PWM_DEFINE, int(255 * a));  
      analogWrite(engine_TWO_PWM_DEFINE, int(255 * b));  
      analogWrite(engine_THREE_PWM_DEFINE, int(255 * c));      

      delay(10);

      alfa++;
      
      if (alfa > 360)
        alfa = 0;
    }
  
  }
}

void tangoid()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(engine_ONE_DIR_DEFINE, HIGH);
    digitalWrite(engine_TWO_DIR_DEFINE, LOW);
    digitalWrite(engine_THREE_DIR_DEFINE, LOW);

    int alfa = 0;
    float a = 0;
    float b = 0;
    float c = 0;

    while (true)
    {
      a = abs(sin(alfa * PI/180));
      b = abs(sin((alfa+120) * PI/180));
      c = abs(sin((alfa+240) * PI/180));

      Serial.println(a);

      analogWrite(engine_ONE_PWM_DEFINE, int(255 * a));  
      analogWrite(engine_TWO_PWM_DEFINE, int(255 * b));  
      analogWrite(engine_THREE_PWM_DEFINE, int(255 * c));      

      delay(30);

      alfa++;
      
      if (alfa > 360)
        alfa = 0;
    }
  
  }
}

void walsoid2()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(engine_ONE_DIR_DEFINE, LOW);
    digitalWrite(engine_TWO_DIR_DEFINE, LOW);
    digitalWrite(engine_THREE_DIR_DEFINE, LOW);

    int alfa = 0;
    float a = 0;
    float b = 0;
    float c = 0;

    while (true)
    {
      a = abs(sin(alfa * PI/180));
      b = abs(sin((alfa+90) * PI/180));
      c = abs(sin((alfa+120) * PI/180));

      Serial.println(a);

      analogWrite(engine_ONE_PWM_DEFINE, int(255 * a));  
      analogWrite(engine_TWO_PWM_DEFINE, int(255 * b));  
      analogWrite(engine_THREE_PWM_DEFINE, int(255 * c));      

      delay(30);

      alfa++;
      
      if (alfa > 360)
        alfa = 0;
    }
  
  }
}

void walsoid()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(engine_ONE_DIR_DEFINE, LOW);
    digitalWrite(engine_TWO_DIR_DEFINE, LOW);
    digitalWrite(engine_THREE_DIR_DEFINE, LOW);

    int alfa = 0;
    float a = 0;
    float b = 0;
    float c = 0;

    while (true)
    {
      a = abs(sin(alfa * PI/180));
      b = abs(sin((alfa+90) * PI/180));
      c = abs(sin((alfa+180) * PI/180));

      Serial.println(a);

      analogWrite(engine_ONE_PWM_DEFINE, int(255 * a));  
      analogWrite(engine_TWO_PWM_DEFINE, int(255 * b));  
      analogWrite(engine_THREE_PWM_DEFINE, int(255 * c));      

      delay(40);

      alfa++;
      
      if (alfa > 360)
        alfa = 0;
    }
  
  }
}

void tantsoid()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(engine_ONE_DIR_DEFINE, LOW);
    digitalWrite(engine_TWO_DIR_DEFINE, HIGH);
    digitalWrite(engine_THREE_DIR_DEFINE, LOW);

    int alfa = 0;
    float a = 0;
    float b = 0;
    float c = 0;

    while (true)
    {
      a = abs(sin(alfa * PI/180));
      b = abs(sin((alfa+90) * PI/180));
      c = abs(sin((alfa+180) * PI/180));

      Serial.println(a);

      analogWrite(engine_ONE_PWM_DEFINE, int(255 * a));  
      analogWrite(engine_TWO_PWM_DEFINE, int(255 * b));  
      analogWrite(engine_THREE_PWM_DEFINE, int(255 * c));      

      delay(10);

      alfa++;
      
      if (alfa > 360)
        alfa = 0;
    }
  
  }
}

void pulsoid()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(engine_ONE_DIR_DEFINE, LOW);
    digitalWrite(engine_TWO_DIR_DEFINE, LOW);
    digitalWrite(engine_THREE_DIR_DEFINE, LOW);

    int alfa = 0;
    float a = 0;
    float b = 0;
    float c = 0;

    while (true)
    {
      a = abs(sin(alfa * PI/180));
      b = abs(sin((alfa) * PI/180));
      c = abs(sin((alfa) * PI/180));

      Serial.println(a);

      analogWrite(engine_ONE_PWM_DEFINE, int(255 * a));  
      analogWrite(engine_TWO_PWM_DEFINE, int(255 * b));  
      analogWrite(engine_THREE_PWM_DEFINE, int(255 * c));      

      delay(10);

      alfa++;
      
      if (alfa > 360)
        alfa = 0;
    }
  
  }
}

void curve()
{
  digitalWrite(engine_ONE_DIR_DEFINE, LOW);
  digitalWrite(engine_TWO_DIR_DEFINE, HIGH);
  digitalWrite(engine_THREE_DIR_DEFINE, LOW);

  analogWrite(engine_ONE_PWM_DEFINE, 255);  
  analogWrite(engine_TWO_PWM_DEFINE, 85);  
  analogWrite(engine_THREE_PWM_DEFINE, 255-85);  

  delay(15000);
}

void waltz()
{
  for (int i = 0; i < 2; i++)
  {
    forward_f_dir();
    speed_up(0, 255, 1, true, true, false);
    go(2000, 255, true, true, false);
    speed_down(255, 0, 1, true, true, false);

    right_dir();
    speed_up(0, 255, 1, true, true, true);
    go(2000, 255, true, true, true);
    speed_down(255, 0, 1, true, true, true);   

    right_f_dir();
    speed_up(0, 255, 1, true, false, true);
    go(2000, 255, true, false, true);
    speed_down(255, 0, 1, true, false, true);  

    right_dir();
    speed_up(0, 255, 1, true, true, true);
    go(2000, 255, true, true, true);
    speed_down(255, 0, 1, true, true, true);   

    left_f_dir();
    speed_up(0, 255, 1, false, true, true);
    go(2000, 255, false, true, true);
    speed_down(255, 0, 1, false, true, true);   

    right_dir();
    speed_up(0, 255, 1, true, true, true);
    go(2000, 255, true, true, true);
    speed_down(255, 0, 1, true, true, true);   
  }
}

void forward_f_dir()
{
  digitalWrite(engine_ONE_DIR_DEFINE, LOW);
  digitalWrite(engine_TWO_DIR_DEFINE, HIGH);
}

void forward_b_dir()
{
  digitalWrite(engine_ONE_DIR_DEFINE, HIGH);
  digitalWrite(engine_TWO_DIR_DEFINE, LOW);
}

void left_f_dir() // влево
{
  digitalWrite(engine_TWO_DIR_DEFINE, LOW);
  digitalWrite(engine_THREE_DIR_DEFINE, HIGH);
}

void left_b_dir()  // влево
{
  digitalWrite(engine_TWO_DIR_DEFINE, HIGH);
  digitalWrite(engine_THREE_DIR_DEFINE, LOW);
}

void right_b_dir() // вперёд
{
  digitalWrite(engine_ONE_DIR_DEFINE, LOW);
  digitalWrite(engine_THREE_DIR_DEFINE, HIGH);
}

void right_f_dir() // вперёд
{
  digitalWrite(engine_ONE_DIR_DEFINE, HIGH);
  digitalWrite(engine_THREE_DIR_DEFINE, LOW);
}

void left_dir()
{
  digitalWrite(engine_ONE_DIR_DEFINE, LOW);
  digitalWrite(engine_TWO_DIR_DEFINE, LOW);
  digitalWrite(engine_THREE_DIR_DEFINE, LOW);
}

void right_dir()
{
  digitalWrite(engine_ONE_DIR_DEFINE, HIGH);
  digitalWrite(engine_TWO_DIR_DEFINE, HIGH);
  digitalWrite(engine_THREE_DIR_DEFINE, HIGH);
}

void go(int delay_ms, int power, bool one, bool two, bool three)
{
  if (one)
    analogWrite(engine_ONE_PWM_DEFINE, power);  
    else
    analogWrite(engine_ONE_PWM_DEFINE, 0);  
  if (two)
    analogWrite(engine_TWO_PWM_DEFINE, int(float(power)*0.5));
    else
    analogWrite(engine_TWO_PWM_DEFINE, 0);
  if (three)
    analogWrite(engine_THREE_PWM_DEFINE, power);
    else
    analogWrite(engine_THREE_PWM_DEFINE, 0);

  delay(delay_ms);
}

void speed_up(int from, int to, int del, bool one, bool two, bool three)
{
  for (int i = from; i < to; i++)
  {
    if (one)
      analogWrite(engine_ONE_PWM_DEFINE, i);  
      else
      analogWrite(engine_ONE_PWM_DEFINE, 0);  
    if (two)
      analogWrite(engine_TWO_PWM_DEFINE, int(float(i)*0.7));
      else
      analogWrite(engine_TWO_PWM_DEFINE, 0);
    if (three)
      analogWrite(engine_THREE_PWM_DEFINE, i);
      else
      analogWrite(engine_THREE_PWM_DEFINE, 0);
    delay (del);
  }
}

void speed_down(int from, int to, int del, bool one, bool two, bool three)
{
  for (int i = from; i > to; i--)
  {
    if (one)
      analogWrite(engine_ONE_PWM_DEFINE, i);  
      else
      analogWrite(engine_ONE_PWM_DEFINE, 0);  
    if (two)
      analogWrite(engine_TWO_PWM_DEFINE, int(float(i)*0.7));
      else
      analogWrite(engine_TWO_PWM_DEFINE, 0);
    if (three)
      analogWrite(engine_THREE_PWM_DEFINE, i);
      else
      analogWrite(engine_THREE_PWM_DEFINE, 0);
    delay (del);
  }
}

/////////////////////////////////////////////////////////////// LIB - end


int breaker()
{}
