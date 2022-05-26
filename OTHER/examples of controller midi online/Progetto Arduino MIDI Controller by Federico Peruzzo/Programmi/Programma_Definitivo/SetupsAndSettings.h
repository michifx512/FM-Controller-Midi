
//Settings defines
#define NOTEMAX 127
#define NOTEMIN 0
#define CHANNEL 1
#define RESET_SLIDERS_TIME 3000


//PIN defines
//Led Pins
#define Led1_pin 30   //Scanner 1 LED
#define Led2_pin 28   //Scanner 2 LED
#define Led3_pin 26   //Scanner 3 LED
#define Led4_pin 24   //Scanner 4 LED
#define Led5_pin 22   //Scanner 5 LED
#define Led6_pin 20   //Scanner 6 LED
#define Led7_pin 18   //Scanner 12 LED
#define Led8_pin 16   //Scanner 11 LED
#define Led9_pin 14   //Scanner 10 LED
#define Led10_pin 12  //Scanner 9 LED
#define Led11_pin 10  //Scanner 8 LED
#define Led12_pin 8   //Scanner 7 LED
#define Led13_pin 6   //PAGE 2 LED
#define Led14_pin 4   //PAGE 1 LED
//Slider Pins
#define Sli1_pin A10  //Slider 1
#define Sli2_pin A1   //Slider 2
#define Sli3_pin A11  //Slider 3
#define Sli4_pin A3   //Slider 4
#define Sli5_pin A4   //Slider 5
#define Sli6_pin A5   //Slider 6
#define Sli7_pin A6   //Slider 7
#define Sli8_pin A7   //Slider 8
#define Sli9_pin A8   //Slider 9
#define Sli10_pin A9  //Slider 10
//Columns Button Matrix Pins
#define Col1_pin 52
#define Col2_pin 50
#define Col3_pin 48
#define Col4_pin 47
#define Col5_pin 46
//Rows Button Matrix Pins
#define Row1_pin 42
#define Row2_pin 43
#define Row3_pin 41
#define Row4_pin 39
#define Row5_pin 37
#define Row6_pin 35
#define Row7_pin 33
#define Row8_pin A15

//Variables
byte SliVal[10];
byte SliVal_pre[10];

bool Button[40];
bool Button_pre[40];
bool change[40];

enum PageDef{PAGE1=0, PAGE2}page;

bool ButtonRows[8];

const byte PAGE1_SliNotes[8]={0, 1, 2, 3, 4, 5, 6, 7};
const byte PAGE2_SliNotes[8]={8, 9, 10, 11, 12, 13, 14, 15};

unsigned long int ResetSliders_EndTime=0;

//Setup functions
void PinSetup(){
  pinMode(Led1_pin, OUTPUT);
  pinMode(Led2_pin, OUTPUT);
  pinMode(Led3_pin, OUTPUT);
  pinMode(Led4_pin, OUTPUT);
  pinMode(Led5_pin, OUTPUT);
  pinMode(Led6_pin, OUTPUT);
  pinMode(Led7_pin, OUTPUT);
  pinMode(Led8_pin, OUTPUT);
  pinMode(Led9_pin, OUTPUT);
  pinMode(Led10_pin, OUTPUT);
  pinMode(Led11_pin, OUTPUT);
  pinMode(Led12_pin, OUTPUT);
  pinMode(Led13_pin, OUTPUT);
  pinMode(Led14_pin, OUTPUT);

  pinMode(Col1_pin, OUTPUT);
  pinMode(Col2_pin, OUTPUT);
  pinMode(Col3_pin, OUTPUT);
  pinMode(Col4_pin, OUTPUT);
  pinMode(Col5_pin, OUTPUT);
  
  pinMode(Row1_pin, INPUT_PULLUP);
  pinMode(Row2_pin, INPUT_PULLUP);
  pinMode(Row3_pin, INPUT_PULLUP);
  pinMode(Row4_pin, INPUT_PULLUP);
  pinMode(Row5_pin, INPUT_PULLUP);
  pinMode(Row6_pin, INPUT_PULLUP);
  pinMode(Row7_pin, INPUT_PULLUP);
  pinMode(Row8_pin, INPUT_PULLUP);
}

void InitialLEDSetup(){
  digitalWrite(Led1_pin, HIGH);
  digitalWrite(Led2_pin, HIGH);
  digitalWrite(Led3_pin, HIGH);
  digitalWrite(Led4_pin, HIGH);
  digitalWrite(Led5_pin, HIGH);
  digitalWrite(Led6_pin, HIGH);
  digitalWrite(Led7_pin, HIGH);
  digitalWrite(Led8_pin, HIGH);
  digitalWrite(Led9_pin, HIGH);
  digitalWrite(Led10_pin, HIGH);
  digitalWrite(Led11_pin, HIGH);
  digitalWrite(Led12_pin, HIGH);
  digitalWrite(Led13_pin, HIGH);
  digitalWrite(Led14_pin, LOW);
}

void InitialButtonSetup(){
  digitalWrite(Col1_pin, HIGH);
  digitalWrite(Col2_pin, HIGH);
  digitalWrite(Col3_pin, HIGH);
  digitalWrite(Col4_pin, HIGH);
  digitalWrite(Col5_pin, HIGH);
}
