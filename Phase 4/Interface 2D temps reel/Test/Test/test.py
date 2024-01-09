import pygame
import sys
from logic import* 

# Configuration de la fenêtre de pygame
largeur_fenetre = 800
hauteur_fenetre = 600
fenetre = pygame.display.set_mode((largeur_fenetre, hauteur_fenetre))
pygame.display.set_caption("INTERFACE 2D SIMULATION")

# Chargement de l'image du circuit
image_circuit = pygame.image.load('c:/Users/paoss/Desktop/Icons/circuit.png')
image_circuit = pygame.transform.scale(image_circuit, (largeur_fenetre, hauteur_fenetre))

# Chargement de l'image du sticker (véhicule)
image_sticker = pygame.image.load('c:/Users/paoss/Desktop/Icons/car.png')
largeur_sticker = 30  # Taille du sticker
hauteur_sticker = 30  # Taille du sticker
image_sticker = pygame.transform.scale(image_sticker, (largeur_sticker, hauteur_sticker))

# Variables de position des véhicules
vehicule1_x = 100
vehicule1_y = 100

vehicule2_x = 500
vehicule2_y = 100

vehicule3_x = 100
vehicule3_y = 100
 
index = 0  # Index pour parcourir les coordonnées
reversed_index = 0  # Index pour parcourir les coordonnées en sens inverse

def actualiser_position():
    """Met à jour les coordonnées des véhicules en suivant la logique des coordonnées fournies"""
    global vehicule1_x, vehicule1_y, vehicule2_x, vehicule2_y, vehicule3_x, vehicule3_y, index, reversed_index
    if index < len(coordonnees):
        vehicule1_x, vehicule1_y = coordonnees[index]
        vehicule2_x, vehicule2_y = coordonnees2[index]
        vehicule3_x, vehicule3_y = coordonnees3[index]
        index += 1
    elif reversed_index < len(coordonnees):
        vehicule1_x, vehicule1_y = coordonnees[len(coordonnees) - reversed_index - 1]
        vehicule2_x, vehicule2_y = coordonnees2[len(coordonnees) - reversed_index - 1]
        vehicule3_x, vehicule3_y = coordonnees3[len(coordonnees) - reversed_index - 1]
        reversed_index += 1

# Variables pour l'animation
clock = pygame.time.Clock()
delta_t = 0
vitesse = 1  # Vitesse de déplacement en pixels par seconde

# Boucle principale du programme
running = True
restart_program = False

while running:
    if restart_program:
        vehicule1_x = 100
        vehicule1_y = 100
        vehicule2_x = 200
        vehicule2_y = 200
        vehicule3_x = 300
        vehicule3_y = 300
        index = 0
        reversed_index = 0
        restart_program = False    # Gestion des événements
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_a and pygame.key.get_mods() & pygame.KMOD_CTRL:
                # Actualiser la position des véhicules en suivant les coordonnées
                actualiser_position()
            elif event.key == pygame.K_r:
                # Redémarrer le programme
                restart_program = True

    # Calcul du temps écoulé depuis la dernière frame
    dt = clock.tick(60) / 1000  # En secondes
    delta_t += dt

    # Animation des véhicules
    while delta_t >= 1/vitesse:
        actualiser_position()
        delta_t -= 1/vitesse

    # Dessiner l'image du circuit
    fenetre.blit(image_circuit, (0, 0))
    # Dessiner les véhicules à leurs positions actuelles
    fenetre.blit(image_sticker, (vehicule1_x - largeur_sticker // 2, vehicule1_y - hauteur_sticker // 2))
    fenetre.blit(image_sticker, (vehicule2_x - largeur_sticker // 2, vehicule2_y - hauteur_sticker // 2))
    fenetre.blit(image_sticker, (vehicule3_x - largeur_sticker // 2, vehicule3_y - hauteur_sticker // 2))
    # Actualiser l'affichage
    pygame.display.flip()

pygame.quit()
sys.exit()
