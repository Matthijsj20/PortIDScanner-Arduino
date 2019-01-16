

void correct()
{
  int potread = analogRead(potmeter);
  for (int i = 0; i < 7; i++)
  {
    tone(buzzer, potread);
    setgreen();
    delay(100);
    setoff();
    noTone(buzzer);
    delay(100);
  }
}

void fail()
{
  int potread = analogRead(potmeter);
  tone(buzzer, potread);
  setred();
  delay(1000);
  setoff();
  noTone(buzzer);


}
