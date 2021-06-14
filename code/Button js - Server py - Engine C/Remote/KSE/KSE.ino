#define engine_ONE_PWM_DEFINE 5
#define engine_ONE_DIR_DEFINE 4

#define engine_TWO_PWM_DEFINE 7
#define engine_TWO_DIR_DEFINE 6

#define engine_THREE_PWM_DEFINE 11
#define engine_THREE_DIR_DEFINE 10

long timer = 0;
long counter = 0;
    
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
    int angle_in = b1 + b2;
    
    engine_ONE_PWM = 255 * sin( (angle_in - 30)*PI/180 );
    engine_TWO_PWM = 255 * sin( (angle_in - 150)*PI/180 );
    engine_THREE_PWM = 255 * sin( (angle_in - 270)*PI/180 );
    

    if(engine_ONE_PWM > 0)
      engine_ONE_DIR = false;
    else
      engine_ONE_DIR = true;

    if(engine_TWO_PWM > 0)
      engine_TWO_DIR = false;
    else
      engine_TWO_DIR = true;

    if(engine_THREE_PWM > 0)
      engine_THREE_DIR = false;
    else
      engine_THREE_DIR = true;

    digitalWrite(engine_ONE_DIR_DEFINE, engine_ONE_DIR);
    digitalWrite(engine_TWO_DIR_DEFINE, engine_TWO_DIR);
    digitalWrite(engine_THREE_DIR_DEFINE, engine_THREE_DIR);

    if (engine_ONE_PWM < 0)
      engine_ONE_PWM = engine_ONE_PWM * -1;

    if (engine_TWO_PWM < 0)
      engine_TWO_PWM = engine_TWO_PWM * -1;

    if (engine_THREE_PWM < 0)
      engine_THREE_PWM = engine_THREE_PWM * -1;    
}

int breaker()
{}
