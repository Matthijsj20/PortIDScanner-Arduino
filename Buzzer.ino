const int buzzer = 6;

void buzzercorrect()
{

  tone(buzzer, 2000,200);
  delay(50);
  tone(buzzer, 0);
  delay(50);
}

void buzzerfail()
{

  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
}
