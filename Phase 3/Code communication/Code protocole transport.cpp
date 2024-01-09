#include <VirtualWire.h>

const int portRecepteur = ,// Port récepteur
const int portEmetteur = ; // Port émetteur

// Tableau de correspondance de caractères pour crypter et décrypter les messages
const std::pair<char, char> encryptage[] = {
    {'A', 'A'}, {'B', 'Z'}, {'C', 'Y'}, {'D', 'X'}, {'E', 'W'}, {'F', 'V'}, {'G', 'U'},
    {'H', 'T'}, {'I', 'S'}, {'J', 'R'}, {'K', 'P'}, {'L', 'O'}, {'M', 'N'}, {'N', 'M'},
    {'O', 'L'}, {'P', 'K'}, {'Q', 'J'}, {'R', 'I'}, {'S', 'H'}, {'T', 'G'}, {'U', 'F'},
    {'V', 'E'}, {'W', 'D'}, {'X', 'C'}, {'Y', 'B'}, {'Z', 'A'}, {'a', 'a'}, {'b', 'e'},
    {'c', 'i'}, {'d', 'f'}, {'e', 'b'}, {'f', 'k'}, {'g', 'd'}, {'h', 'c'}, {'i', 'm'},
    {'j', 'l'}, {'k', 'j'}, {'l', 'x'}, {'m', 'g'}, {'n', 'o'}, {'o', 's'}, {'p', 'z'},
    {'q', 'h'}, {'r', 't'}, {'s', 'p'}, {'t', 'w'}, {'u', 'y'}, {'v', 'u'}, {'w', 'n'},
    {'x', 'r'}, {'y', 'q'}, {'z', 'v'}, {'0', '2'}, {'1', '7'}, {'2', '8'}, {'3', '6'},
    {'4', '9'}, {'5', '0'}, {'6', '1'}, {'7', '5'}, {'8', '3'}, {'9', '4'}, {'.', '.'}
};

// Fonction pour crypter le message
char encrypt(char char_trame) {
    for (const auto& pair : encryptage) {
        if (char_trame == pair.first) {
            return pair.second;
        }
    }
    return char_trame; // Si le caractère n'a pas été trouvé dans le tableau, on le renvoie tel quel
}

// Fonction pour décrypter le message
char decrypt(char char_trame) {
    for (const auto& pair : encryptage) {
        if (char_trame == pair.second) {
            return pair.first;
        }
    }
    return char_trame; // Si le caractère n'a pas été trouvé dans le tableau, on le renvoie tel quel
}