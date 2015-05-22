/*
  sensorin raja-arvot Octopusin kotisivujen mukaan
  0  ~300     kuiva
  300~700     märkä
  700~950     vedessä
  arvioitu maksimi arvo on 622 vedessä - testataan vielä raja-arvoja

  Työvaiheet:
  - kytketään Octopus sensori Analog 1 pinniin.
  - kytketään ledit pinneihin: sininen 3, vihreä 4, keltainen 5
  - virtalähteenä toimii 9v patteri
  - kotelointi?

  16.5.2015
  Jukka Juslin, Katri Vilonen, Olli Vilonen
  Lähteet:
  http://www.elecfreaks.com/wiki/index.php?title=Octopus_Soil_Moisture_Sensor_Brick
  http://kasvinkosteus.blogspot.fi/
  https://www.youtube.com/watch?v=W-T4Sq0VmGk Kuinka tehdä pattereilla toimiva arduino
*/

// led muuttujat

int ledSininen = 3;  //vedessä
int ledVihrea = 4;  //kostea
int ledKeltainen = 5;  //kuiva

void setup() {

  Serial.begin(9600); // octopussin baudinopeus

  //led pinnien alustus
  pinMode(3, OUTPUT); //sininen-vedessä
  pinMode(4, OUTPUT); //vihreä-kostea
  pinMode(5, OUTPUT); //keltainen-kuiva

}

void loop() {

  Serial.print("Kasvin kosteustilanne: ");
  int kosteusarvo = analogRead(1);  // luetaan Analog pinnin 1 arvo
  Serial.println(kosteusarvo);
  if (kosteusarvo >= 0 && kosteusarvo <= 580) {
    Serial.println("Kasvisi on liian kuivassa mullassa.");
    //Keltainen päälle
    digitalWrite(ledSininen, LOW);
    digitalWrite(ledVihrea, LOW);
    digitalWrite(ledKeltainen, HIGH);

  } else if (kosteusarvo < 890) {
    Serial.println("Kasvisi on sopivan kosteassa mullassa.");
    //Vihreä päälle
    digitalWrite(ledSininen, LOW);
    digitalWrite(ledVihrea, HIGH);
    digitalWrite(ledKeltainen, LOW);

  } else {
    Serial.println("Kasvisi on liian marassä mullassa.");
    //Sininen päälle
    digitalWrite(ledSininen, HIGH);
    digitalWrite(ledVihrea, LOW);
    digitalWrite(ledKeltainen, LOW);

  }
  delay(2000);

}
