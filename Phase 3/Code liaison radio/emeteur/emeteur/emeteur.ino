

#include <string.h>

#include <VirtualWire.h>

// Tableau de correspondance
char correspondance[][2] = {
{'a', 'z'}, {'b', 'y'}, {'c', 'x'}, {'d', 'w'}, {'e', 'v'}, {'f', 'u'},
    {'g', 't'}, {'h', 's'}, {'i', 'r'}, {'j', 'q'}, {'k', 'p'}, {'l', 'o'},
    {'m', 'n'}, {'n', 'm'}, {'o', 'l'}, {'p', 'k'}, {'q', 'j'}, {'r', 'i'},
    {'s', 'h'}, {'t', 'g'}, {'u', 'f'}, {'v', 'e'}, {'w', 'd'}, {'x', 'c'},
    {'y', 'b'}, {'z', 'a'},

  
};

void setup() {
  vw_set_tx_pin(13);  // Broche de transmission VirtualWire
  vw_setup(2000);     // Vitesse de transmission en bits par seconde

  Serial.begin(9600);
}

void loop() {
  char message[] = " ton message est transmis en toute securite ";  // Message à envoyer (en clair)
  char messageCrypte[sizeof(message)];

  // Cryptage du message
  for (int i = 0; i < sizeof(message); i++) {
    char caractere = message[i];

    // Recherche de la correspondance dans le tableau
    for (int j = 0; j < sizeof(correspondance) / 2; j++) {
      if (correspondance[j][0] == caractere) {
        caractere = correspondance[j][1];
        break;
      }
    }

    messageCrypte[i] = caractere;
  }

  // Envoi du message crypté
  vw_send((uint8_t*)messageCrypte, sizeof(messageCrypte));

  vw_wait_tx();
Serial.println("      Message envoyé      ");
//Serial.println("message :"+message);
String text = "message: " + String(messageCrypte);
  Serial.println(text.c_str());
  delay(1000);
}
