#include <LiquidCrystal.h>

class MensagemRolante
{
  private:
    LiquidCrystal* liquidCrystal;
    int colunas, linhas;
    char* mensagem;
    int pos;
  public:
    MensagemRolante(LiquidCrystal *liquidCrystal, int colunas, int linhas);
    void exibir(char* mensagem);
    void rolar();
};

MensagemRolante::MensagemRolante(LiquidCrystal *liquidCrystal, int colunas, int linhas)
{
  MensagemRolante::liquidCrystal = liquidCrystal;
  MensagemRolante::colunas = colunas;
  MensagemRolante::linhas = linhas;  
  MensagemRolante::pos = 0;  
}

void MensagemRolante::exibir(char* mensagem)
{
  MensagemRolante::mensagem = mensagem;
}

void MensagemRolante::rolar()
{
  String msg = MensagemRolante::mensagem;
  int pos1 = MensagemRolante::pos;
  int pos2 = MensagemRolante::pos + MensagemRolante::colunas;
  int length = 20;
  msg = msg.substring(pos1, pos2) + "        ";

  MensagemRolante::liquidCrystal->setCursor(0,0);
  MensagemRolante::liquidCrystal->print(msg);

  MensagemRolante::pos++;
  if (MensagemRolante::pos > length)
  {
    MensagemRolante::pos = 0;
  }
}

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
MensagemRolante mensagemRolante(&lcd, 8, 2);

void setup()
{
  pinMode(1, OUTPUT);
  mensagemRolante.exibir("Hello World");
}

void loop()
{
  mensagemRolante.rolar();
  Beep();
}

void Beep()
{
  digitalWrite(1, HIGH);
  tone(2, 600);
  delay(50);
  noTone(2);
  delay(70);
  digitalWrite(1, LOW);
  delay(500);
}
