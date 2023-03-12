#include <LiquidCrystal.h>
const int tempo = 100;//atraso
int BOTAO1 = 7;//volta personagem
int BOTAO2 = 6;//ida personagem
LiquidCrystal lcd (13,12,11,10,9,8);
byte personagem[8] =
{
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B01010,
  B01010,
};
int colunas=0;
bool start = false;

void setup()
{
  // Configura os pinos
  pinMode(BOTAO1, INPUT_PULLUP);
  pinMode(BOTAO2, INPUT_PULLUP);
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("***** JOGO *****");
  lcd.createChar(0,personagem);
}

void loop()
{
  // repete-se consecutivamente enaqunto a placa estiver ligada
  delay(tempo);
  
  if(digitalRead(BOTAO1)==LOW)//personagem vai para esquerda
  {
    lcd.clear();
    lcd.print("***** JOGO *****");
    
    if(colunas==0 && !start)//se o jogo começar com o jogador
    {//apertando o botao1 o persongame ira começar da ultima coluna
      start= true;
      colunas=15;
      delay(tempo);
    }
    lcd.setCursor(colunas,1);
    lcd.write(byte(0));
    delay(tempo);
    colunas--;
    
      if(colunas<0)//se colunas menor que 0 volta para coluna 15
      {
      colunas= 15;
      delay(tempo);
      }
  }
  
  else if(digitalRead(BOTAO2)==LOW)//personagem vai para direita
  {
    lcd.clear();
    lcd.print("***** JOGO *****");
    lcd.setCursor(colunas,1);
    lcd.write(byte(0));
    delay(tempo);
    colunas++;
    
      if(colunas>15)//se colunas maior que 15 volta para coluna 0
      {
      colunas=0;
      delay(tempo);
      }
  }  
}

