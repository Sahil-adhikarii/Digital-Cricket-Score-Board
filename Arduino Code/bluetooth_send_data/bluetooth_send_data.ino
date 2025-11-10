
#define S_1 6
#define S_2 5
#define S_3 4
#define O_1 3
#define O_2 2
#define O_3 A0
#define W_1 A1
#define W_2 A2
#define T_1 A3
#define T_2 A4
#define T_3 A5



const int a = 13;
const int b = 12;
const int c = 11;
const int d = 10;
const int e = 9;
const int f = 8;
const int g = 7;
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
char MSG[15];

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
  delay(500);
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

  Serial.begin(9600);
  // Serial.println("Ready to Receive value....");

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);


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
  
        

  if (Serial.available() > 0)
  {
    
    String input = Serial.readStringUntil('\n');

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
      sprintf(MSG, "%d,%d,%d,%d,%d", main_score, main_over/10, main_over % 10,main_wicket, Target);


   Serial.println(MSG);
    
  }

  score(main_score);
  over(main_over);
  Wicket(main_wicket);
  target(Target);


   



}
