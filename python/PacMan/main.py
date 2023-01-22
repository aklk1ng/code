import pygame

pygame.init()
map_image = pygame.image.load('images/map.png')
_, _, WITDTH, HEIGHT = map_image.get_rect()

display = pygame.display.set_mode(WITDTH, HEIGHT)
