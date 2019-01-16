
void setred()
{
  analogWrite(ledr, 255);
  analogWrite(ledg, 0);
  analogWrite(ledb, 0);

}


void setgreen()
{
  analogWrite(ledr, 0);
  analogWrite(ledg, 255);
  analogWrite(ledb, 0);

}


void setblue()
{
  analogWrite(ledr, 0);
  analogWrite(ledg, 0);
  analogWrite(ledb, 255);


}
void setall()
{
  analogWrite(ledr, 255);
  analogWrite(ledg, 255);
  analogWrite(ledb, 150);
}

void setoff()
{
  digitalWrite(ledr, LOW);
  digitalWrite(ledg, LOW);
  digitalWrite(ledb, LOW);
}
