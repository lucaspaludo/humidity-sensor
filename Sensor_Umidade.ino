#include <LiquidCrystal.h>

//portas do sensor de umidade
#define pino_sinal_analogico A0
#define pino_led_vermelho 5
#define pino_led_amarelo 6
#define pino_led_verde 7

//portas do display LCD
#define RS 12
#define EN 4
#define D4 8
#define D5 9
#define D6 10
#define D7 11

//valor da umidade
int valor_analogico;

//instancia objeto do tipo LiquidCrystal
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
 
void setup()
{
  Serial.begin(9600);
  pinMode(pino_sinal_analogico, INPUT);
  pinMode(pino_led_vermelho, OUTPUT);
  pinMode(pino_led_amarelo, OUTPUT);
  pinMode(pino_led_verde, OUTPUT);
  lcd.begin(16, 2);
}
 
void loop()
{
  //Le o valor do pino A0 do sensor
  valor_analogico = analogRead(pino_sinal_analogico);

  //limpa o display
  lcd.clear();
  
  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Porta analogica: ");
  Serial.print(valor_analogico);
 
  //Solo umido, acende o led verde
  if (valor_analogico > 0 && valor_analogico < 600)
  {
    Serial.println(" Status: Solo umido");
    apagaleds();
    digitalWrite(pino_led_verde, HIGH);
    lcd.print("UMIDADE BOA");
  }
 
  //Solo com umidade moderada, acende led amarelo
  if (valor_analogico > 600 && valor_analogico < 800)
  {
    Serial.println(" Status: Umidade moderada");
    apagaleds();
    digitalWrite(pino_led_amarelo, HIGH);
    lcd.print("UMIDADE MODERADA");
  }
 
  //Solo seco, acende led vermelho
  if (valor_analogico > 800 && valor_analogico < 1024)
  {
    Serial.println(" Status: Solo seco");
    apagaleds();
    digitalWrite(pino_led_vermelho, HIGH);
    lcd.print("UMIDADE BAIXA");

  }
  delay(100);
}
 
void apagaleds()
{
  digitalWrite(pino_led_vermelho, LOW);
  digitalWrite(pino_led_amarelo, LOW);
  digitalWrite(pino_led_verde, LOW);
}