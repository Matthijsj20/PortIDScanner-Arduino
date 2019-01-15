String message = "";
String value = "";
int check = 0;
int check2 = 0;
bool remoteactivated = false;
bool serieelcheck()  //kijkt of er een bericht klaar staat
{

  if (Serial.available() > 0) //kijkt of er een teken klaar staat
  {
    char readchar = (char) Serial.read(); //leest de SeriÃƒÆ’Ã‚Â«le poort
    if (readchar == '#')    //kijkt of het bericht met een # begint.
    {
      message = "";   //reset string message
      check = 1;      //zet de check op 1
    }
    else if (check == 1 && readchar != '%') // kijkt of check 1 is (dus of hij # ontvangen heeft) en of er geen % is binnen gekomen
    {
      message = message + readchar;       //plakt het bericht aan elkaar
    }
    if (readchar == '%')        //kijkt of er een % is binnen gekomen
    {
      check = 0;      //reset check
      return true;
    }
  }
  return false;
}

void serieel()
{

  if (message == "scan")    //kijkt of het binnenkomde bericht "REMOTE_CONTROL" is
  {
    RFIDREAD();
  }

}

void agecheck()
{
  if (message.indexOf("$") > 0)
  {
    int age = message.toInt();
    if (age >= 18)   
    {
     setgreen();
    }
    else
    {
      //redled functie
    }
  }
  
}
