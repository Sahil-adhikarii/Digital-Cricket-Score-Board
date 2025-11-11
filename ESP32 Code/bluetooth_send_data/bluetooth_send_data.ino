#include<BluetoothSerial.h>
BluetoothSerial bt;


//pins For score, over, wicket,target and led
#define S_1 32
#define S_2 35
#define S_3 34
#define O_1 39
#define O_2 36
#define O_3 15
#define led 2
#define W_1 4
#define W_2 16
#define T_1 17
#define T_2 5
#define T_3 18


//pins for data
const int a = 13;
const int b = 12;
const int c = 14;
const int d = 27;
const int e = 26;
const int f = 25;
const int g = 33;

// variables
int d1_w = 0,  d2_w = 0;
int d1_trg = 0,  d2_trg = 0,  d3_trg = 0;


int Score = 0, ball = 0, wicket = 0, Target = 0;
int firstComma, secondComma;
int  main_score = 0, main_over = 0, main_wicket = 0;
int prev_score = 0,prev_over = 0, prev_wicket = 0;
String str_prev_over;
int ovr = 0;
int balls =0 ,ovvr = 0; 
String str_ovr,str_balls,str_ovvr;
String MSG;


//Functions

void show(int num) 
{
  
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);

  
  switch (num) {
    case 0:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      break;

    case 1:
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      break;

    case 2:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(g, HIGH);     
      break;

    case 3:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(g, HIGH);    
      break;

    case 4:
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);    
      break;

    case 5:
      digitalWrite(a, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);   
      break;

    case 6:
      digitalWrite(a, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);  
      break;

    case 7:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH); 
      break;

    case 8:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;

    case 9:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;

    default:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
  }
}


void score(int number) 
{
  int d1_s = (number / 100) % 10;
  int d2_s = (number / 10) % 10;
  int d3_s = number % 10;

  show(d1_s);
  digitalWrite(S_1, LOW);
  delay(2);
  digitalWrite(S_1, HIGH);

  show(d2_s);
  digitalWrite(S_2, LOW);
  delay(2);
  digitalWrite(S_2, HIGH);

  show(d3_s);
  digitalWrite(S_3, LOW);
  delay(2);
  digitalWrite(S_3, HIGH);
}

void over(int number) 
{
  int d1_o = (number / 100) % 10;
  int d2_o = (number / 10) % 10;
  int d3_o = number % 10;

  show(d1_o);
  digitalWrite(O_1, LOW);
  delay(2);
  digitalWrite(O_1, HIGH);

  show(d2_o);
  digitalWrite(O_2, LOW);
  delay(2);
  digitalWrite(O_2, HIGH);

  show(d3_o);
  digitalWrite(O_3, LOW);
  delay(2);
  digitalWrite(O_3, HIGH);
}

void Wicket(int number) 
{
  int d1_w = (number / 10) % 10;
  int d2_w = number % 10;

  show(d1_w);
  digitalWrite(W_1, LOW);
  delay(2);
  digitalWrite(W_1, HIGH);

  show(d2_w);
  digitalWrite(W_2, LOW);
  delay(2);
  digitalWrite(W_2, HIGH);
}

void target(int number) 
{
  int d1_trg = (number / 100) % 10;
  int d2_trg = (number / 10) % 10;
  int d3_trg = number % 10;

  show(d1_trg);
  digitalWrite(T_1, LOW);
  delay(2);
  digitalWrite(T_1, HIGH);

  show(d2_trg);
  digitalWrite(T_2, LOW);
  delay(2);
  digitalWrite(T_2, HIGH);

  show(d3_trg);
  digitalWrite(T_3, LOW);
  delay(2);
  digitalWrite(T_3, HIGH);
}

















void setup() {
  
  bt.begin("ESP32_BT",true);
  bt.setPin("214876",6);

  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(35,OUTPUT);
  pinMode(34,OUTPUT);
  pinMode(39,OUTPUT);
  pinMode(36,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(18,OUTPUT);
  


  digitalWrite(S_1, HIGH);
  digitalWrite(S_2, HIGH);
  digitalWrite(S_3, HIGH);
  digitalWrite(O_1, HIGH);
  digitalWrite(O_2, HIGH);
  digitalWrite(O_3, HIGH);
  digitalWrite(W_1, HIGH);
  digitalWrite(W_2, HIGH);
  digitalWrite(T_1, HIGH);
  digitalWrite(T_2, HIGH);
  digitalWrite(T_3, HIGH);

}


void loop() {

  if(bt.hasClient())
  {
    digitalWrite(led,1);

    if(bt.available())
    {

      String input = bt.readStringUntil('\n');

    if (input.indexOf(',') != -1) // when there is comma
    {
      prev_score = main_score;
      prev_over = main_over;
      prev_wicket = main_wicket;

      firstComma = input.indexOf(',');
      secondComma = input.indexOf(',', firstComma + 1);

      if (firstComma != -1 && secondComma != -1)
      {
        if(input.substring(0, firstComma) == "E")
        {
          firstComma = input.indexOf(',',firstComma + 1);
          secondComma = input.indexOf(',',firstComma + 1);

          main_score = input.substring(input.indexOf(',') + 1,firstComma).toInt();
          main_over = input.substring(firstComma + 1,secondComma).toInt();
          main_wicket = input.substring(secondComma + 1).toInt();

          balls = input.substring(secondComma-1,secondComma).toInt();
          ovr = input.substring(firstComma+1,secondComma-1).toInt();
         

          prev_score = main_score;
          prev_over = main_over;
          prev_wicket = main_wicket;
        }
        else
        {
          Score = input.substring(0, firstComma).toInt();
          main_score += Score;

          ball = input.substring(firstComma + 1, secondComma).toInt();
          balls += ball;

          if (balls == 6)
          { 
            ovr += 1;
            balls = 0;



          }
          str_ovr = String(ovr);
          str_balls = String(balls);
          str_ovvr = str_ovr + str_balls;
          ovvr = str_ovvr.toInt();

          main_over = ovvr;

          wicket = input.substring(secondComma + 1).toInt();
          main_wicket += wicket;
        }


        // Serial.println("score: " + String(Score));
        // Serial.println("ball : " + String(ball));
        // Serial.println("wicket : " + String(wicket));
        // Serial.println("\n\n");


      }
    }
    else if(input == "Stop"){

       main_score = 0;
        main_over = 0;
        main_wicket = 0;
        ovr = 0;
        balls = 0;
    }
    
      
    else if(input == "P"){
        main_score = prev_score;
        main_over = prev_over;
        str_prev_over = String(prev_over);

        // Serial.println(str_prev_over);

        ovr = str_prev_over.substring(0,str_prev_over.length()-1).toInt();
        balls = str_prev_over.substring(str_prev_over.length()-1).toInt();
        main_wicket = prev_wicket;

        // Serial.println("prev: s -> "+ String(prev_score) +", o -> "+ String(prev_over) +", w -> "+ String(prev_wicket));
        // Serial.println("main: s -> "+ String(main_score) +", o -> "+ String(main_over) +", w -> "+ String(main_wicket));
      }
    else{
        Target = input.toInt();
      }
      

      MSG = String(main_score) + "," + String(main_over/10) + "," + String(main_over % 10) + "," + String(main_wicket) + "," + String(Target);


   bt.println(MSG);
      
    }
    
  }
  else
  {
    digitalWrite(led,0);
  }

  score(main_score);
  over(main_over);
  Wicket(main_wicket);
  target(Target);
  
}
